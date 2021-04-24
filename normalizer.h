#ifndef NORMALIZER_H
#define NORMALIZER_H
#include <vector>
#include "normalizationparameters.h"
#include "vertex.h"

using namespace std;

class Normalizer
{
private:
    NormalizationParameters _params;

public:
    Normalizer(NormalizationParameters& params);
    bool normalize(vector<Vertex>* vertices);
    double get_max(vector<Vertex>* vertices);
    double get_min(vector<Vertex>* vertices);
};

#endif // NORMALIZER_H
