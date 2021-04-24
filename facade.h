#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include "scenedrawerbase.h"
#include <QPicture>
#include "FileReader/FileReader.h"
#include "facadeoperationresult.h"

using namespace std;

class Facade
{
private:
    BaseFileReader* _fileReader;
    Scene* _scene;
    SceneDrawerBase *_sceneDrawer;
    Facade();
public:
    Facade(BaseFileReader* fileReader, SceneDrawerBase* _sceneDrawer);
    FacadeOperationResult LoadScene(string filename, NormalizationParameters params);
    FacadeOperationResult DrawScene();
    FacadeOperationResult MoveScene(float x, float y, float z);
    FacadeOperationResult ScaleScene(float x, float y, float z);
    FacadeOperationResult RotateScene(float x, float y, float z);
    ~Facade();
};

#endif // FACADE_H
