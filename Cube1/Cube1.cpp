// glut3D_template.cpp  ��������� ���� ��� ����������  3D-�����

#include <iostream>
#include <GL/glut.h>
#include <math.h>

//------------------��������� �� �������Ͳ �̲�Ͳ-------------------------

int Width = 800, Height = 800; //�������� ���� ������
#define Pi  3.1415926535897932384

//-------------------���������� ��--------------------------------------
void coordinate_axis(void)
{

	glLineWidth(2);
	glColor3d(1, 1, 1);
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0); glVertex3d(5, 0, 0); //Ox
	glVertex3d(4.8, 0.1, 0); glVertex3d(5, 0, 0);
	glVertex3d(4.8, -0.1, 0); glVertex3d(5, 0, 0);

	glVertex3d(0, 0, 0); glVertex3d(0, 5, 0); //oy
	glVertex3d(0.1, 4.8, 0); glVertex3d(0, 5, 0);
	glVertex3d(-0.1, 4.8, 0); glVertex3d(0, 5, 0);

	glVertex3d(0, 0, 0); glVertex3d(0, 0, 5);//oz
	glVertex3d(-0.1, 0.1, 4.8); glVertex3d(0, 0, 5);
	glVertex3d(0.1, -0.1, 4.8); glVertex3d(0, 0, 5);
	glEnd();
}

//������� ������� ���� ���������!!!!!!!!!!!!!!!!!!!!!!!!!!----------------------
void keyboard(unsigned char key, int x0, int y0)
{
	//-----------�������,  ����������� �������� ������ "x "

	if (key == 'x')
	{
		glRotated(10, 1, 0, 0);//������� �������� ������� �� Ox
		glutPostRedisplay();// ������� ����
	}
	//-----------�������,  ����������� �������� ������ "y "

	if (key == 'y')
	{

		glRotated(10, 0, 1, 0); //������� �������� ������� �� Oy
		glutPostRedisplay();// ������� ����
	}
	//-----------�������,  ����������� �������� ������ "z "

	if (key == 'z')
	{
		glRotated(10, 0, 0, 1); //������� �������� ������� �� Oz
		glutPostRedisplay();// ������� ����
	}

}

//��������� ������� �� �����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------------
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//========================================================================

	coordinate_axis(); //���������� ���������� ��


	glColor3d(1, 0, 0);
	glutSolidSphere(1, 50, 50);//�����

	//=======================================================================
	glutSwapBuffers();
}



//��������� ���������� ��������� �����!!!!!!!!!!!!!!!!!!!!!------------------------
void scene(void)
{
	glClearColor(0, 0, 0, 0);//���� ����

	//��������� �������� �� ������ �����
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };  //���� ��������� ���������
	GLfloat light_position[] = { 3.0, 3.0, -3.0, 1.0 }; // ��������� ������� ����� 
	GLfloat light_dir[] = { 1.0,1.0,1.0,1.0 }; //������ �����

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
	glEnable(GL_LIGHTING);//��������� ����� ������������ ���������
	glEnable(GL_LIGHT0);//�������� ������� �����

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);//����� ��� ����� ����������� ������� �� �� �������


	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-5, 5, -5, 5, 2, 15);//������������ ��������
	gluLookAt(0.0, 0.0, 5.0, // ��������� �����������: ����� ������������� (0,0,5) */
		0.0, 0.0, 0.0,      /* ����� ����� �� ����������� � ����� ������ ������ (0,0,0) */
		0.0, 1.0, 0.);      /*������� ������ ��  �Y */
}


//�����������  GLUT-�������!!!!!!!!!!!!!!!!!----------------------------------
void main(int argc, char** argv)
{
	glutInit(&argc, argv); //�-� ������� �������� �������� �������� ��� �������� ���� �������
	glutInitWindowPosition(0, 0); //��������� ����
	glutInitWindowSize(Width, Height); //����� ����
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);// ������ ����������� ���������� (���� �: ������� �������, �������� �������, ����� RGB ������ � ��������)
	glutCreateWindow("glut_3D"); //����� 

	scene();

	glutDisplayFunc(display); // ��������� �� �������� � ��� ������� ��� �����  ������������ ���
	glutKeyboardFunc(keyboard); //��������� �� �-� Keyboard(��� ��������� ������� �� ���������) ���� ����������� ��� ������������ ���

	glutMainLoop();// �������� ���� GLUT
}



