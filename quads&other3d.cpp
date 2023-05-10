#include <glut.h>

void drawquad() {	// �簢�� �׸��� �Լ�
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
	drawquad();		// back _ �⺻

	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);	// green
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// back(red)�� y�࿡ ���� 90�� ȸ��
	drawquad();		// left
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);	// blue
	glRotatef(90.0, 1.0, 0.0, 0.0);		// back(red)�� x�࿡ ���� 90�� ȸ��
	drawquad();		// bottom
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);	// yellow
	glTranslatef(0.0, 0.0, 0.3);		// back(red)�� z������ �����̵�
	drawquad();		// front
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);	// ���� green
	glRotatef(-90.0, 0.0, 1.0, 0.0);	// left(green)�� 
	glTranslatef(0.0, 0.0, -0.3);		// �����̵�
	drawquad();		// right
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);	// ���� blue
	glRotatef(90.0, 1.0, 0.0, 0.0);		// bottom(blue)��
	glTranslatef(0.0, 0.0, -0.3);		// �����̵�
	drawquad();		// top
	glPopMatrix();

}
void DoDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// ������ü
	quads();

	// ����� Sphere
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glTranslatef(0.5, 0.0, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glFlush();
	glPopMatrix();

	// ������ Cone
	glPushMatrix();
	glColor3f(0.8, 0.8, 1.0);
	glTranslatef(-0.5, 0.0, 0.0);
	glutSolidCone(0.1, 0.3, 100, 100);
	glFlush();
	glPopMatrix();

	// ���ʷ� Torus
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