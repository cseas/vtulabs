#include <gl/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
	int i, pk, inc1, inc2;;

	int dx = abs(x2 - x1); // absolute value
	int dy = abs(y2 - y1);
	
	int incx = (x1 < x2) ? 1 : -1;
	int incy = (y1 < y2) ? 1 : -1;
	
	int x = x1; 
	int y = y1; // initialise
	
	if (dx > dy) {
		draw_pixel(x, y);
		pk = 2*dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (pk >= 0) { // increment both
				y += incy;
				pk += inc1;
			} else
				pk += inc2;
			
			x += incx;
			draw_pixel(x, y);
		}
	} else {
		draw_pixel(x, y);
		pk = 2*dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		
		for (i = 0; i < dy; i++) {
			if (pk >= 0) {
				x += incx;
				pk += inc1;
			} else
				pk += inc2;
			
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	draw_line(x1, y1, x2, y2);
	glFlush();
}

void main(int argc, char **argv) {
	printf("Enter (x1, y1, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
