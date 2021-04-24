#include "BaseFileReader.h"

class FileReader : public BaseFileReader
{
public:
   Scene* ReadScene(string filename, NormalizationParameters params);

private:
   vector<vector<string>> get_data(string filename);
   vector<vector<double>> convert_to_double(vector<vector<string>> &data);
   vector<Vertex>* compose_vertices(vector<vector<double>>& values);
   vector<Edge>* make_edges(vector<Vertex> *vertices);
   void normalize_vertices();
};
