#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#define PI 3.1416

typedef struct point {
	GLfloat x, y;
};

void binomial(int n, int *C) {
	// all loops with end included
	for (int k = 0; k <= n; k++) {
		C[k] = 1;
		for (int i = n; i >= k + 1; i--) C[k] *= i;
		for (int i = n - k; i >= 2; i--) C[k] /= i;
	}
}

void computeBezPoints(float u, point *flagPoint, int cPt, point *ctrlPts, int *C) {
	float bezBlendFcn;
	int n = cPt - 1;

	flagPoint->x = flagPoint->y = 0;
	for (int k = 0; k < cPt; k++) {
		bezBlendFcn = C[k] * pow(u, k) * pow(1 - u, n - k);
		flagPoint->x += ctrlPts[k].x * bezBlendFcn;
		flagPoint->y += ctrlPts[k].y * bezBlendFcn;
	}
}

void bezier(point *ctrlPts, int cPt, int bPt) {
	point flagPoint;
	float u;
	int *C;
	C = new int[cPt];
	binomial(cPt - 1, C);

	glBegin(GL_LINE_STRIP);
	for (int k = 0; k <= bPt; k++) {
		u = (float)k / (float)bPt;
		computeBezPoints(u, &flagPoint, cPt, ctrlPts, C);
		glVertex2f(flagPoint.x, flagPoint.y);
	}
	glEnd();

	delete[]C;
}

float theta;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	point ctrlPts[4] = { {100,400}, {150,450}, {250,350}, {300,400} };
	int cPt = 4, bPt = 20;

	ctrlPts[1].x += 50 * sin(theta * PI / 180);
	ctrlPts[1].y += 25 * sin(theta * PI / 180);
	ctrlPts[2].x -= 50 * sin(theta * PI / 180);
	ctrlPts[2].y -= 25 * sin(theta * PI / 180);
	ctrlPts[3].x -= 50 * sin(theta * PI / 180);
	ctrlPts[3].y += sin(theta * PI / 180);
	theta += 0.2;

	glLineWidth(5);

	glPushMatrix();
	glColor3f(1, 0.4, 0.2);
	for (int i = 0; i < 50; i++) {
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts, cPt, bPt);
	}

	glColor3f(1, 1, 1);
	for (int i = 0; i < 50; i++) {
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts, cPt, bPt);
	}

	glColor3f(0, 1, 0);
	for (int i = 0; i < 50; i++) {
		glTranslatef(0, -0.8, 0);
		bezier(ctrlPts, cPt, bPt);
	}
	glPopMatrix();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	glVertex2f(100, 400);
	glVertex2f(100, 40);
	glEnd();

	glutPostRedisplay();
	glutSwapBuffers();
}

void init() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // IMPORTANT: GLUT_DOUBLE
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier curve flag");
	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
