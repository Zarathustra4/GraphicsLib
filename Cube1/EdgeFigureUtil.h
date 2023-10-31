#include "EdgeFigure.h"
#include "MatrixUtil.h"
#include "Edges.h"

#pragma once

class EdgeFigureUtil
{
public:
	//Cube from lab 1
	static EdgeFigure getCube();

    static EdgeFigure getPiramid();

    static EdgeFigure rotateAroundY(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundY(90);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateAroundX(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundX(90);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateAroundZ(EdgeFigure figure) {
        Matrix rotationMatrix = MatrixUtil::rotateAroundZ(-30);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateAroundYX(EdgeFigure figure, double yAngle, double xAngle) {
        Matrix yRotationMatrix = MatrixUtil::rotateAroundY(yAngle);
        Matrix xRotationMatrix = MatrixUtil::rotateAroundX(xAngle);

        Matrix rotationMatrix = MatrixUtil::matrixProduct(yRotationMatrix, xRotationMatrix);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), rotationMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateAroundXY(EdgeFigure figure, double xAngle, double yAngle) {
        Matrix xRotationMatrix = MatrixUtil::rotateAroundX(xAngle);
        Matrix yRotationMatrix = MatrixUtil::rotateAroundY(yAngle);

        Matrix rotationMatrix = MatrixUtil::matrixProduct(xRotationMatrix, yRotationMatrix);

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

    static EdgeFigure move(EdgeFigure figure, vector<double> vec) {
        Matrix moveMatrix = MatrixUtil::vectorMove(vec);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), moveMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure scale(EdgeFigure figure, double scalar) {
        vector<double> massCenter = figure.getMassCenter();
        Matrix scaleMatrix = MatrixUtil::scaleWithoutMoving(scalar, massCenter);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), scaleMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure rotateAroundEdge(EdgeFigure figure, double angle, int edgeIndex) {

        vector<double> a = figure.getEdge(edgeIndex).getRow(0);
        vector<double> b = figure.getEdge(edgeIndex).getRow(1);

        Matrix transMatrix = MatrixUtil::rotateAroundEdge(angle, a, b);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), transMatrix),
            figure.getEdges()
        );
    }

    //user has to give indexes of points of the diagonal
    static EdgeFigure rotateAroundDiagonal(EdgeFigure figure, double angle, int startIndex, int endIndex) {
        vector<double> a = figure.getMatrix().getRow(startIndex);
        vector<double> b = figure.getMatrix().getRow(endIndex);

        vector<double> diagonal = vector<double>({ b[0] - a[0], b[1] - a[1], b[2] - a[2] });

        Matrix transMatrix = MatrixUtil::rotateAroundEdge(angle, a, b);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), transMatrix),
            figure.getEdges()
        );
    }

    static EdgeFigure mirrorAtPlane(EdgeFigure figure, int aIndex, int bIndex, int cIndex) {
        vector<double> a = figure.getMatrix().getRow(aIndex);
        vector<double> b = figure.getMatrix().getRow(bIndex);
        vector<double> c = figure.getMatrix().getRow(cIndex);

        Matrix plane = Matrix(3, 4);
        plane.setRow(0, a);
        plane.setRow(1, b);
        plane.setRow(2, c);

        Matrix transMatrix = MatrixUtil::mirrorOnPlane(plane);

        return EdgeFigure(
            MatrixUtil::matrixProduct(figure.getMatrix(), transMatrix),
            figure.getEdges()
        );
    }
};

