#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_choose_file_clicked();
    void on_btn_load_data_clicked();
    void move_scene();
    void scale_scene();
    void rotate_scene();

private:
    QPicture* picture;
    Ui::MainWindow *ui;
    Facade* facade;
};
#endif // MAINWINDOW_H
