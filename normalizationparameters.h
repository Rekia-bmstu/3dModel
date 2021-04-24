#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H


class NormalizationParameters
{
public:
    float max;
    float min;
    float start;
    float end;
    NormalizationParameters(float _max, float _min, float _start, float _end);
};

#endif // NORMALIZATIONPARAMETERS_H
