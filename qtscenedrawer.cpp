#include "qtscenedrawer.h"
#include <QPainter>


QtSceneDrawer::QtSceneDrawer(QPicture* picture) : SceneDrawerBase(), _picture(picture)
{

}

void QtSceneDrawer::DrawScene(Scene *scene)
{
    QPainter painter;
    painter.begin(_picture);
    for (int i = 0; i < scene->get_figure()->get_edges()->size(); i++)
    {
        painter.drawLine(scene->get_figure()->get_edges()->at(i).get_begin()->get_position()->X * coef,
                         scene->get_figure()->get_edges()->at(i).get_begin()->get_position()->Y * coef,
                         scene->get_figure()->get_edges()->at(i).get_end()->get_position()->X * coef,
                         scene->get_figure()->get_edges()->at(i).get_end()->get_position()->Y * coef);
    }
    painter.end();
}

QtSceneDrawer::~QtSceneDrawer()
{
    delete  _picture;
}
