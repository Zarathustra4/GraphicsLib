// glut3D_template.cpp  Шаблонний файл для візуалізації  3D-обєктів

#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "GraphicUtil.h"
#include "EdgeFigureUtil.h"
#include "GraphicDrawer3D.h"

//------------------КОНСТАНТИ ТА ГЛОБАЛЬНІ ЗМІННІ-------------------------

const int WIDTH = 800, HEIGHT = 800; //парметри вікна виводу
GraphicUtil GRAPHIC_U = GraphicUtil(WIDTH, HEIGHT);
#define Pi  3.1415926535897932384

//-------------------Координатні осі--------------------------------------
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

//Функції обробки подій клавіатури!!!!!!!!!!!!!!!!!!!!!!!!!!----------------------
void keyboard(unsigned char key, int x0, int y0)
{
	//-----------функція,  викликається натиском клавіші "x "
	switch (key)
	{
	case 'x':
		glRotated(10, 1, 0, 0);//поворот простору навколо осі Ox
		break;
	case 'y':
		glRotated(10, 0, 1, 0); //поворот простору навколо осі Oy
		break;
	case 'z':
		glRotated(10, 0, 0, 1); //поворот простору навколо осі Oz
		break;
	case '1':
		GraphicDrawer3D::drawEdgeFigure(
			EdgeFigureUtil::getCube()
		);
		break;
	default:
		break;
	}
	
	glutPostRedisplay();// оновити вікно
}

//Управління виводом на екран!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------------
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//========================================================================

	coordinate_axis(); //відобразити координатні осі

	glColor3d(1, 0, 0);
	GraphicDrawer3D::drawEdgeFigure(
		EdgeFigureUtil::getCube()
	);
	//glutSolidSphere(1, 50, 50);//сфера

	//=======================================================================
	glutSwapBuffers();
}



//Параметри візуалізації тривимірної сцени!!!!!!!!!!!!!!!!!!!!!------------------------
void scene(void)
{
	glClearColor(0, 0, 0, 0);//колір фону

	//Параметри матеріалів та джерел світла
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };  //колір дифузного освітлення
	GLfloat light_position[] = { 3.0, 3.0, -3.0, 1.0 }; // розміщення джерела світла 
	GLfloat light_dir[] = { 1.0,1.0,1.0,1.0 }; //напрям світла

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
	glEnable(GL_LIGHTING);//дозволити режим використання освітлення
	glEnable(GL_LIGHT0);//увімкнути джерело світла

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);//режим при якому видаляються невидимі лінії та поверхні


	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-5, 5, -5, 5, 2, 15);//ортографічна проекція
	gluLookAt(0.0, 0.0, 5.0, // положення спостерігача: точка спостереження (0,0,5) */
		0.0, 0.0, 0.0,      /* центр сцени що проектується в центр області виводу (0,0,0) */
		0.0, 1.0, 0.);      /*додатній напрям осі  ОY */
}


//Ініціалізація  GLUT-додатку!!!!!!!!!!!!!!!!!----------------------------------
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //ф-я здійснює необхідні початкові значення для побудови вікна додатку
	glutInitWindowPosition(0, 0); //положення вікна
	glutInitWindowSize(WIDTH, HEIGHT); //розмір вікна
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);// режими відображення інформації (вікно з: буфером глибини, подвійним буфером, режим RGB роботи з кольором)
	glutCreateWindow("glut_3D"); //назва 

	scene();

	glutDisplayFunc(display); // вказується що малювати у вікні додатку при кожній  перемальовці вікні
	glutKeyboardFunc(keyboard); //вказується що ф-я Keyboard(яка опрацьовує виклики із клавіатури) буде викликатися при перемальовці вікні

	glutMainLoop();// Основний цикл GLUT

	return 0;
}



