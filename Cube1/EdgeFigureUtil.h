#include "EdgeFigure.h"
#include "MatrixUtil.h"
#include "Edges.h"

#pragma once

class EdgeFigureUtil
{
public:
	//Cube from lab 1
	static EdgeFigure getCube();

    static EdgeFigure rotateCubeAroundY(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundY(90);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateCubeAroundX(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundX(90);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateCubeAroundZ(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundZ(-30);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure mirrorXY(EdgeFigure figure) {
        Matrix mirrorMatrix = MatrixUtil::Mirroring_XY();

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), mirrorMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure mirrorXZ(EdgeFigure figure) {
        Matrix mirrorMatrix = MatrixUtil::Mirroring_XZ();

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), mirrorMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure mirrorYZ(EdgeFigure figure) {
        Matrix mirrorMatrix = MatrixUtil::Mirroring_YZ();

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), mirrorMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure move(EdgeFigure figure, vector<long double> vec) {
        Matrix moveMatrix = MatrixUtil::vectorMove(vec);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), moveMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure scale(EdgeFigure figure, double scalar) {
        vector<long double> massCenter = figure.getMassCenter();
        Matrix scaleMatrix = MatrixUtil::scaleWithoutMoving(scalar, massCenter);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), scaleMatrix),
            figure.getEdges()
        );
    }
};

