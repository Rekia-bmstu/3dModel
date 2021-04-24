#ifndef TRANSFROMMATRIXBUILDER_H
#define TRANSFROMMATRIXBUILDER_H
#include "transformmatrix.h"

class TransfromMatrixBuilder
{
private:
    TransformMatrix create_rotate_matrix_x(float x);
    TransformMatrix create_rotate_matrix_y(float y);
    TransformMatrix create_rotate_matrix_z(float z);
public:
    TransfromMatrixBuilder();
    TransformMatrix create_move_matrix(float x, float y, float z);
    TransformMatrix create_scale_matrix(float x, float y, float z);
    TransformMatrix create_rotate_matrix(float x, float y, float z);
};

#endif // TRANSFROMMATRIXBUILDER_H
