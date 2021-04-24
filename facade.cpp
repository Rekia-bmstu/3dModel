#include "facade.h"
#include "qtscenedrawer.h"
#include "transfrommatrixbuilder.h"
#include "QPainter"
#include "exceptionloadfile.h"


Facade::Facade()
{

}

Facade::~Facade()
{
    delete _scene;
    delete _sceneDrawer;
    delete _fileReader;
    _scene = nullptr;
    _sceneDrawer = nullptr;
    _fileReader = nullptr;
}

Facade::Facade(BaseFileReader* fileReader, SceneDrawerBase* _sceneDrawer) :
    _fileReader(fileReader), _sceneDrawer(_sceneDrawer)
{
    _scene = nullptr;
}

FacadeOperationResult Facade::LoadScene(string filename, NormalizationParameters params)
{
    FacadeOperationResult _res;
    try
    {
        Scene* temp = _fileReader->ReadScene(filename, params);
        if (_scene != nullptr)
        {
            delete _scene;
            _scene = nullptr;
        }
        _scene = temp;
    }
    catch(ExceptionLoadFile ex)
    {
        _res.set_error(ex.getError());
    }
    catch(...)
    {
        _res.set_error("unknown error");
    }
    return _res;
}

FacadeOperationResult Facade::DrawScene()
{
    FacadeOperationResult _res;
    _sceneDrawer->DrawScene(_scene);
    return _res;
}

FacadeOperationResult Facade::MoveScene(float x, float y, float z)
{
    FacadeOperationResult _res;
    TransfromMatrixBuilder builder;
    TransformMatrix mat = builder.create_move_matrix(x, y, z);
    _scene->Transform(mat);
    return _res;
}

FacadeOperationResult Facade::ScaleScene(float x, float y, float z)
{
    FacadeOperationResult _res;
    TransfromMatrixBuilder builder;
    TransformMatrix mat = builder.create_scale_matrix(x, y, z);
    _scene->Transform(mat);
    return _res;
}

FacadeOperationResult Facade::RotateScene(float x, float y, float z)
{
    FacadeOperationResult _res;
    TransfromMatrixBuilder builder;
    TransformMatrix mat = builder.create_rotate_matrix(x, y, z);
    _scene->Transform(mat);
    return _res;
}
