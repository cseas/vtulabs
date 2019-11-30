#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

GLfloat vertices[4][3] = {
	{0, 0, 1},
	{0, 1, 0},
	{-1, -0.5, 0},
	{1, -0.5, 0}
};

GLfloat colors[4][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{0, 0, 0} };

void triangle(GLfloat *a, GLfloat *b, GLfloat *c) {
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}

void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d) {
	glColor3fv(colors[0]);
	triangle(a, b, c);

	glColor3fv(colors[1]);
	triangle(a, c, d);

	glColor3fv(colors[2]);
	triangle(a, d, b);

	glColor3fv(colors[3]);
	triangle(b, d, c);
}

void divide_tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int n) {
	GLfloat mid[6][3];
	if (n > 0) {
		for (int i = 0; i < 3; i++) mid[0][i] = (a[i] + b[i]) / 2;
		for (int i = 0; i < 3; i++) mid[1][i] = (a[i] + c[i]) / 2;
		for (int i = 0; i < 3; i++) mid[2][i] = (a[i] + d[i]) / 2;
		for (int i = 0; i < 3; i++) mid[3][i] = (b[i] + c[i]) / 2;
		for (int i = 0; i < 3; i++) mid[4][i] = (c[i] + d[i]) / 2;
		for (int i = 0; i < 3; i++) mid[5][i] = (d[i] + b[i]) / 2;

		divide_tetra(a, mid[0], mid[1], mid[2], n - 1);
		divide_tetra(mid[0], b, mid[3], mid[5], n - 1);
		divide_tetra(mid[1], mid[3], c, mid[4], n - 1);
		divide_tetra(mid[2], mid[5], mid[4], d, n - 1);
	}
	else
		tetra(a, b, c, d);
}

int n; // no. of divisions

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // IMPORTANT

	glBegin(GL_TRIANGLES); // IMPORTANT
	divide_tetra(vertices[0], vertices[1], vertices[2], vertices[3], n);
	glEnd();

	glFlush();
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	glOrtho(-2, 2, -2, 2, -2, 2);
	glutPostRedisplay(); // IMPORTANT
}

int main(int argc, char **argv) {
	puts("No. of divisions:");
	scanf("%d", &n);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski 3D gasket");

	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
