#include "normalizer.h"

Normalizer::Normalizer(NormalizationParameters& params) : _params(params)
{

}

bool Normalizer::normalize(vector<Vertex> *vertices)
{
    bool ok = true;
    _params.max = get_max(vertices);
    _params.min = get_min(vertices);
    Point3D* point;
    for (int i = 0; i < vertices->size(); i++)
    {
        point = vertices->at(i).get_position();
        point->Z = _params.start + ((point->Z - _params.min)*(_params.end - _params.start) / (_params.max - _params.min));
    }
    return ok;
}

double Normalizer::get_max(vector<Vertex> *vertices)
{
    Point3D* point = vertices->at(0).get_position();
    double max = point->Z;
    for (int i = 0; i < vertices->size(); i++)
    {
        point = vertices->at(i).get_position();
        if (max < point->Z)
        {
            max = point->Z;
        }
    }
    return max;
}

double Normalizer::get_min(vector<Vertex> *vertices)
{
    Point3D* point = vertices->at(0).get_position();
    double min = point->Z;
    for (int i = 0; i < vertices->size(); i++)
    {
        point = vertices->at(i).get_position();
        if (min > point->Z)
        {
            min = point->Z;
        }
    }
    return min;
}
