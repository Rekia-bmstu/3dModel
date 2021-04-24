#include "FileReader.h"
#include "stringmanager.h"
#include "normalizer.h"
#include "edge.h"
#include "exceptionloadfile.h"
#include <math.h>

Scene* FileReader::ReadScene(string filename, NormalizationParameters params)
{
        vector<vector<string>> data = get_data(filename);
        vector<vector<double>> values = convert_to_double(data);
        vector<Vertex>* vertices = compose_vertices(values);
        Normalizer normalizer(params);
        normalizer.normalize(vertices);
        vector<Edge>* edges = make_edges(vertices);
        Scene *scene = new Scene(vertices, edges);
        return scene;
}

vector<vector<string>> FileReader::get_data(string filename)
{
    fstream file(filename);
    if (!file)
    {
        throw ExceptionLoadFile("could not open file");
    }
    vector<vector<string>> data;
    vector<string> tmp;
    string str;
    while(getline(file, str))
    {
        if (!str.length())
        {
            throw ExceptionLoadFile("Line is empty");
        }
        StringManager str_mng(str);
        tmp = str_mng.separate_str(',');
        data.push_back(tmp);
    }
    if (data.size() != data[0].size())
        throw ExceptionLoadFile("not correct file");
    return data;
}

vector<vector<double>> FileReader::convert_to_double(vector<vector<string>> &data)
{
    vector<vector<double>> values;
    vector<double> tmp;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j ++)
        {
            tmp.push_back(atof(data[i][j].c_str()));
        }
        values.push_back(tmp);
        tmp.clear();
    }
    return values;
}

vector<Vertex>* FileReader::compose_vertices(vector<vector<double>> &values)
{
    vector<Vertex>* vertices = new vector<Vertex>();
    int counter = 0;
    vertices->resize(values.size() * values.size());
    for (int i = 0; i < values.size(); i++)
    {
        for (int j = 0; j < values[i].size(); j++)
        {
            Point3D *point = new Point3D(i, j, values[i][j]);
            vertices->at(counter).set_position(point);
            counter++;
        }
    }
    return vertices;
}

vector<Edge>* FileReader::make_edges(vector<Vertex> *vertices)
{
    vector<Edge>* edges = new vector<Edge>();
    int size = vertices->size();
    int start = (size / sqrt(size)) - 1;
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {

        }
        else if(i == (start + (sqrt(size) * counter))) // только вниз
        {
            Edge edge = Edge(vertices->at(i), vertices->at(i + sqrt(size)));
            edges->push_back(edge);
            counter++;
        }
        else if (i >= (size - sqrt(size))) // только вправо
        {
            Edge edge = Edge(vertices->at(i), vertices->at(i + 1));
            edges->push_back(edge);
        }
        else // вниз и вправо
        {
            Edge edge1 = Edge(vertices->at(i), vertices->at(i + 1));
            Edge edge2(vertices->at(i), vertices->at(i + sqrt(size)));
            edges->push_back(edge1);
            edges->push_back(edge2);
        }
    }
    return edges;
}


