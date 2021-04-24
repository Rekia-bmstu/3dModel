#include "transfrommatrixbuilder.h"
#include <math.h>

TransfromMatrixBuilder::TransfromMatrixBuilder()
{

}

TransformMatrix TransfromMatrixBuilder::create_move_matrix(float x, float y, float z)
{
    vector<vector<float>> mat = {{ 1, 0, 0, x},
                                 { 0, 1, 0, y},
                                 { 0, 0, 1, z},
                                 { 0, 0, 0, 1}};
    TransformMatrix matrix(mat);
    return matrix;
}

TransformMatrix TransfromMatrixBuilder::create_scale_matrix(float x, float y, float z)
{
    vector<vector<float>> mat = {{ x, 0, 0, 0},
                                 { 0, y, 0, 0},
                                 { 0, 0, z, 0},
                                 { 0, 0, 0, 1}};
    TransformMatrix matrix(mat);
    return matrix;
}


TransformMatrix TransfromMatrixBuilder::create_rotate_matrix_x(float x)
{
    float radX = (M_PI / 180) * x;
    vector<vector<float>> mat = {{1, 0, 0, 0},
                                 {0, cos(radX), -sin(radX), 0},
                                 {0, sin(radX), cos(radX), 0},
                                 {0, 0, 0, 1}, };
    TransformMatrix matrix(mat);
    return matrix;
}

TransformMatrix TransfromMatrixBuilder::create_rotate_matrix_y(float y)
{
    float radY = (M_PI / 180) * y;
    vector<vector<float>> mat = {{cos(radY), 0, sin(radY), 0},
                                {0, 1, 0, 0},
                                {-sin(radY), 0, cos(radY), 0},
                                {0, 0, 0, 1}, };
    TransformMatrix matrix(mat);
    return matrix;
}

TransformMatrix TransfromMatrixBuilder::create_rotate_matrix(float x, float y, float z)
{
    TransformMatrix matX =  create_rotate_matrix_x(x);
    TransformMatrix matY =  create_rotate_matrix_y(y);
    TransformMatrix res = TransformMatrix::multiply(matX, matY);
    return res;
}
