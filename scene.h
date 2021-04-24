#ifndef SCENE_H
#define SCENE_H
#include "figure.h"


class Scene
{
private:
    Figure *_figure;

public:
    Scene();
    Scene(vector<Vertex> *vertices, vector<Edge> *edges);
    Figure* get_figure();
    void set_figure(Figure figure);//
    void Transform(TransformMatrix mat);
    ~Scene();
};

#endif // SCENE_H
