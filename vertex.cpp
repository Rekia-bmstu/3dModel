#include "vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(Point3D point)
{
    _position = new Point3D(point);
}

Point3D* Vertex::get_position()
{
    return _position;
}

void Vertex::set_position(Point3D *point)
{
    _position = point;
}

void Vertex::Transform(TransformMatrix mat)
{
    Point3D res;
    res = mat.transform_point(*_position);
    _position->X = res.X;
    _position->Y = res.Y;
    _position->Z = res.Z;
}

Vertex::~Vertex()
{
    delete _position;
}
