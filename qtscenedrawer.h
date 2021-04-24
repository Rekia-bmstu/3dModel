#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H
#include "scenedrawerbase.h"

class QtSceneDrawer : public SceneDrawerBase
{
private:
    QPicture* _picture;
    const int coef = 15;
public:
    QtSceneDrawer(QPicture* picture);
    void DrawScene(Scene *scene);
    ~QtSceneDrawer();
};

#endif // QTSCENEDRAWER_H
