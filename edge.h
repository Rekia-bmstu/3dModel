#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

class Edge
{

private:
    Vertex* _begin;
    Vertex* _end;

public:
    Edge(Vertex& begin, Vertex& end);
    Vertex* get_begin();
    Vertex* get_end();
};

#endif // EDGE_H
