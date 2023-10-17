#include "EdgeFigure.h"

#pragma once

class EdgeFigureUtil
{
public:
	//Cube from lab 1
	EdgeFigure getCube();

    EdgeFigure rotateCubeAroundY(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.rotateAroundY(90);

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure rotateCubeAroundX(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.rotateAroundX(90);

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure rotateCubeAroundZ(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.rotateAroundZ(-30);

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure MirrorXY(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.Mirroring_XY();

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure MirrorXZ(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.Mirroring_XZ();

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure MirrorYZ(EdgeFigure figure) {
        Matrix rotationMatrix = matrixUtil.Mirroring_YZ();

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    EdgeFigure Move(EdgeFigure figure, vector<long double> vec) {
        Matrix rotationMatrix = matrixUtil.vectorMove(vec);

        return EdgeFigure(
            matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }


};

