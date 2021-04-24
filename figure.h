#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include "vertex.h"
#include "edge.h"
#include "sceneobject.h"

using namespace std;

class Figure : public SceneObject
{
    vector<Vertex>* _vertices;
    vector<Edge>* _edges;

public:
    Figure();
    Figure(vector<Vertex> *vertices, vector<Edge> *edges);
    vector<Vertex>* get_vertices();
    vector<Edge>* get_edges();
    void set_vertices(vector<Vertex> *vertices);
    void Transform(TransformMatrix mat);
    ~Figure();
};

#endif // FIGURE_H
