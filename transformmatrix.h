#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H
#include "point3d.h"
#include <iostream>
#include <vector>

using namespace std;

class TransformMatrix
{
    vector<vector<float>> mat;
public:
    TransformMatrix();
    TransformMatrix(vector<vector<float>> _mat);
    Point3D transform_point(Point3D point);
    static TransformMatrix multiply(TransformMatrix left, TransformMatrix right);
};


#endif // TRANSFORMMATRIX_H
