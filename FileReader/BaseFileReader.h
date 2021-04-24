#include <fstream>
#include <iostream>
#include "scene.h"
#include "normalizationparameters.h"

using namespace std;

class BaseFileReader
{
public:
   virtual Scene* ReadScene(string filename, NormalizationParameters params) = 0;
   virtual ~BaseFileReader() {}
};
