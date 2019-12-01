#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float x1 = 100, y1 = 300, x2 = 200, y2 = 400, x3 = 300, y3 = 300, x4 = 200, y4 = 200;
int fillFlag = 0;

void draw_pixel(float x, float y) {
	glColor3f(0, 0, 1); // yellow
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void edgeDetect(float x1, float y1, float x2, float y2, float *le, float *re) {
	// le = left edge
	float mx, x, temp;

	// DON'T FORGET
	if (y2 < y1) {
		temp = y1; y1 = y2; y2 = temp;
		temp = x1; x1 = x2; x2 = temp;
	}

	if (y2 != y1)
		mx = (x2 - x1) / (y2 - y1);
	else
		mx = (x2 - x1);

	x = x1;
	for (int i = y1; i <= y2; i++) {
		if (x < le[i]) le[i] = x;
		if (x > re[i]) re[i] = x;
		x += mx;
	}
}

void scanFill() {
	float le[500], re[500];

	for (int i = 0; i < 500; i++) {
		le[i] = 500;
		re[i] = 0;
	}

	edgeDetect(x1, y1, x2, y2, le, re);
	edgeDetect(x2, y2, x3, y3, le, re);
	edgeDetect(x3, y3, x4, y4, le, re);
	edgeDetect(x4, y4, x1, y1, le, re);

	// DON'T FORGET
	// For every y, draw pixels from le to re
	for (int y = 0; y < 500; y++) {
		for (int i = le[y]; i < re[y]; i++)
			draw_pixel(i, y);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 1); // blue
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	if (fillFlag == 1) scanFill();
	glFlush();
}

void init() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);

	glPointSize(1);
}

void mouseMenu(int option) {
	if (option == 1) fillFlag = 1;
	if (option == 2) fillFlag = 0;
	display();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Scanline polygon filling");
	// custom init comes after creating window
	init();

	glutDisplayFunc(display);

	glutCreateMenu(mouseMenu);
	glutAddMenuEntry("Fill Polygon", 1);
	glutAddMenuEntry("Empty Polygon", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}
