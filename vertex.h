#ifndef VERTEX_H
#define VERTEX_H
#include "point3d.h"
#include "sceneobject.h"

class Vertex : SceneObject
{
private:
   Point3D *_position;

public:
    Vertex();
    Vertex(Point3D point);
    Point3D* get_position();
    void set_position(Point3D *point);
    void Transform(TransformMatrix mat);
    ~Vertex();
};

#endif // VERTEX_H
