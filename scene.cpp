#include "scene.h"

Scene::Scene()
{

}

Scene::Scene(vector<Vertex>* vertices, vector<Edge>* edges)
{
     _figure = new Figure(vertices, edges);
}

Figure* Scene::get_figure()
{
    return _figure;
}

void Scene::Transform(TransformMatrix mat)
{
    _figure->Transform(mat);
}

Scene::~Scene()
{
    delete _figure;
}
