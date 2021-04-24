#include "figure.h"

Figure::Figure()
{

}

Figure::Figure(vector<Vertex> *vertices, vector<Edge> *edges) : _vertices(vertices), _edges(edges)
{

}

vector<Vertex>* Figure::get_vertices()
{
    return _vertices;
}

vector<Edge>* Figure::get_edges()
{
    return _edges;
}

void Figure::set_vertices(vector<Vertex> *vertices)
{
    _vertices = vertices;
}

void Figure::Transform(TransformMatrix mat)
{
    for (int i = 0; i < _vertices->size(); i++)
    {
        _vertices->at(i).Transform(mat);
    }
}

Figure::~Figure()
{
    delete _vertices;
    delete _edges;
}
