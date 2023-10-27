#include "EdgeFigure.h"
#include <GL/glut.h>

class GraphicDrawer3D
{
public:
	static void drawEdgeFigure(EdgeFigure figure) {
		Matrix points;
		vector<double> point;
		glBegin(GL_LINES);
		for (int i = 0; i < figure.getEdgesNumber(); i++) {
			points = figure.getEdge(i);
			point = points.getRow(0);
			glVertex3d(point[0], point[1], point[2]);
			point = points.getRow(1);
			glVertex3d(point[0], point[1], point[2]);
		}
		glEnd();
	}
};
