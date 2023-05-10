#include <glut.h>

GLfloat angle = 0.0;


void drawquad() {	// 사각형 그리는 함수

	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glVertex3f(0.3, 0.3, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glEnd();
	glFlush();
}

void quads() {
	
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);	// red
	drawquad();		// back _ 기본
	glEnd();

	glPushMatrix();
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// back(red)을 y축에 대해 90도 회전
	glColor3f(0.0, 0.5, 0.0);	// green
	drawquad();		// left
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);		// back(red)을 x축에 대해 90도 회전
	glColor3f(0.0, 0.0, 1.0);	// blue
	drawquad();		// bottom
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.3);		// back(red)을 z축으로 평행이동
	glColor3f(1.0, 1.0, 0.0);	// yellow
	drawquad();		// front
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.0);		// 평행이동
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// left(green)을 
	glColor3f(0.0, 1.0, 0.0);	// 형광 green
	drawquad();		// right
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0.0, 0.3, 0.0);		// 평행이동
	glRotatef(90.0, 1.0, 0.0, 0.0);		// bottom(blue)을
	glColor3f(0.0, 1.0, 1.0);	// 형광 blue
	drawquad();		// top
	glPopMatrix();

	
}

void drawSphere() {
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(0.5, 0.0, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glFlush();
	glPopMatrix();

}

void drawCone() {
	
	glPushMatrix();
	glColor3f(0.8, 0.8, 1.0);
	glTranslatef(-0.5, 0.0, 0.0);
	glutSolidCone(0.1, 0.3, 100, 100);
	glFlush();
	glPopMatrix();

}

void drawTorus() {

	glPushMatrix();
	glColor3f(0.5, 1.0, 0.8);
	glTranslatef(-0.3, 0.3, -0.5);
	glutSolidTorus(0.1, 0.2, 100, 100);
	glFlush();
	glPopMatrix();

}


void DoDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	quads();
	drawSphere();
	drawCone();
	drawTorus();

	glRotatef(angle, -0.1, 0.1, 0.1);
	glutSwapBuffers();
	angle += 0.00001;

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
	glutInitWindowPosition(300, -200);
	glutInitWindowSize(900, 900);
	glutCreateWindow("HW #2");
	
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, 900, 900);
	glClearColor(0, 0, 0, 0);

	glutDisplayFunc(DoDisplay);
	glutIdleFunc(DoDisplay);
	glutMainLoop();

	return 0;
}