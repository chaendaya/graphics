#include <glut.h>

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

	glColor3f(1.0, 0.0, 0.0);	// red
	drawquad();		// back _ 기본

	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);	// green
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// back(red)을 y축에 대해 90도 회전
	drawquad();		// left
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);	// blue
	glRotatef(90.0, 1.0, 0.0, 0.0);		// back(red)을 x축에 대해 90도 회전
	drawquad();		// bottom
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);	// yellow
	glTranslatef(0.0, 0.0, 0.3);		// back(red)을 z축으로 평행이동
	drawquad();		// front
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);	// 형광 green
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// left(green)을 
	glTranslatef(0.0, 0.0, -0.3);		// 평행이동
	drawquad();		// right
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);	// 형광 blue
	glRotatef(90.0, 1.0, 0.0, 0.0);		// bottom(blue)을
	glTranslatef(0.0, 0.0, -0.3);		// 평행이동
	drawquad();		// top
	glPopMatrix();

}
void DoDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// 정육면체
	quads();

	// 연노랑 Sphere
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(0.5, 0.0, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glFlush();
	glPopMatrix();

	// 연보라 Cone
	glPushMatrix();
	glColor3f(0.8, 0.8, 1.0);
	glTranslatef(-0.5, 0.0, 0.0);
	glutSolidCone(0.1, 0.3, 100, 100);
	glFlush();
	glPopMatrix();

	// 연초록 Torus
	glPushMatrix();
	glColor3f(0.5, 1.0, 0.8);
	glTranslatef(-0.3, 0.3, -0.5);
	glutSolidTorus(0.1, 0.2, 100, 100);
	glFlush();
	glPopMatrix();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);


	glClearColor(0, 0, 0, 0);

	glutInitWindowPosition(300, -200);
	glutInitWindowSize(900, 900);
	glutCreateWindow("HW #1");


	glutDisplayFunc(DoDisplay);

	glutMainLoop();

	return 0;
}