#include "transformmatrix.h"

TransformMatrix::TransformMatrix()
{
    mat.resize(4);
    for (int i = 0; i < 4; i++)
    {
        mat[i].resize(4);
    }
}

TransformMatrix::TransformMatrix(vector<vector<float>> _mat)
{
    mat = _mat;
}

Point3D TransformMatrix::transform_point(Point3D point)
{
    Point3D P;
    P.X = point.X * mat[0][0] + point.Y * mat[0][1] + point.Z * mat[0][2] + mat[0][3];
    P.Y = point.X * mat[1][0] + point.Y * mat[1][1] + point.Z * mat[1][2] + mat[1][3];
    P.Z = point.X * mat[2][0] + point.Y * mat[2][1] + point.Z * mat[2][2] + mat[2][3];
    return P;
}

TransformMatrix TransformMatrix::multiply(TransformMatrix left, TransformMatrix right)
{
    TransformMatrix res;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           res.mat[i][j] = left.mat[i][0] * right.mat[0][j] + left.mat[i][1] * right.mat[1][j] +
                           left.mat[i][2] * right.mat[2][j] + left.mat[i][3] * right.mat[3][j];
        }
    }
    return res;
}

