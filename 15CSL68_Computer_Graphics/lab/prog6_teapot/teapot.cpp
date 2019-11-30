#include<GL/glut.h>

// thick = 0.02
// width = 0.6
// len = 0.3

void wall(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslatef(x, y, z);
		glScalef(1.0, 1.0, 0.02); // remember these x,y,z values
	glutSolidCube(1.0);
	glPopMatrix();
}

void tableLeg(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslatef(x, y, z);
		glScalef(0.02, 0.3, 0.02); // thick, len, thick
	glutSolidCube(1.0);
	glPopMatrix();
}

void tableTop(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslatef(x, y, z);
		glScalef(0.6, 0.02, 0.6); // width, thick, width
	glutSolidCube(1.0);
	glPopMatrix();
}

void teapot(GLfloat x, GLfloat y, GLfloat z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	// no scale
	glutSolidTeapot(0.1);
	glPopMatrix();
}

void light() {
	GLfloat mat_ambient[] = { 1, 1, 1, 1 };
	GLfloat mat_diffuse[] = { 1, 1, 1, 1 };
	GLfloat mat_specular[] = { 1, 1, 1, 1 };
	GLfloat mat_shininess[] = { 50 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
	GLfloat light_position[] = { 2, 6, 3, 1 };
	GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}

void display() {
	GLfloat teapotP = -0.07, tabletopP = -0.15, tablelegP = 0.20, wallP = 0.50;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	gluLookAt(-2.0, 2.0, 5.0, 
		0.0, 0.0, 0.0, 
		0.0, 1.0, 0.0);
	
	light(); //Adding light source to your project
	teapot(0.0, teapotP, 0.0); //Create teapot
	tableTop(0.0, tabletopP, 0.0); //Create table’s top
	tableLeg(tablelegP, -0.3, tablelegP); //Create 1st leg
	tableLeg(-tablelegP, -0.3, tablelegP); //Create 2nd leg
	tableLeg(-tablelegP, -0.3, -tablelegP); //Create 3rd leg
	tableLeg(tablelegP, -0.3, -tablelegP); //Create 4th leg
	
	wall(0, 0, -wallP); //Create 1st wall
	glRotatef(90, 1, 0, 0);
	
	wall(0, 0, wallP); //Create 2nd wall
	glRotatef(90, 0, 1, 0);
	
	wall(0.0, 0.0, wallP); //Create 3rd wall
	
	glFlush();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 10);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Teapot on a table");
	myinit();
	
	glutDisplayFunc(display);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glutMainLoop();
}
