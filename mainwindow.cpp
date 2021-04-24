#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "qtscenedrawer.h"
#include "facadeoperationresult.h"

QString filename;
bool picture_was_set = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    double width = ui->label->width();
    double height = ui->label->height();
    picture = new QPicture;
    picture->setBoundingRect(QRect(QPoint(0, 0), QPoint(width, height)));

    FileReader* fl = new FileReader;
    QtSceneDrawer* drawer = new QtSceneDrawer(picture);
    facade = new Facade(fl, drawer);

    connect(ui->move_up, SIGNAL(clicked()), this, SLOT(move_scene()));
    connect(ui->move_down, SIGNAL(clicked()), this, SLOT(move_scene()));
    connect(ui->move_left, SIGNAL(clicked()), this, SLOT(move_scene()));
    connect(ui->move_right, SIGNAL(clicked()), this, SLOT(move_scene()));

    connect(ui->rotate_right, SIGNAL(clicked()), this, SLOT(rotate_scene()));
    connect(ui->rotate_left, SIGNAL(clicked()), this, SLOT(rotate_scene()));
    connect(ui->rotate_up, SIGNAL(clicked()), this, SLOT(rotate_scene()));
    connect(ui->rotate_down, SIGNAL(clicked()), this, SLOT(rotate_scene()));

    connect(ui->scale_inc, SIGNAL(clicked()), this, SLOT(scale_scene()));
    connect(ui->scale_dec, SIGNAL(clicked()), this, SLOT(scale_scene()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_choose_file_clicked()
{
     filename = QFileDialog::getOpenFileName(this, "Choose CSV file", "");
}


void MainWindow::on_btn_load_data_clicked()
{
    FacadeOperationResult res;
    NormalizationParameters params(0, 0, 0, 50);
    res = facade->LoadScene(filename.toStdString(), params);
    if (res.isSuccess())
    {
        ui->statusbar->showMessage(QString::fromStdString(res.getErrorMessage()));
        return;
    }
    facade->DrawScene();
    ui->label->setPicture(*picture);
}

void MainWindow::move_scene()
{
    QPushButton* button = (QPushButton*)sender();
    float x_move = 0;
    float y_move = 0;
    QString command = button->text();
    if (command == "up")
    {
        y_move = -3;
    }
    else if (command == "down")
    {
        y_move = 3;
    }
    else if (command == "left")
    {
        x_move = -3;
    }
    else if (command == "right")
    {
        x_move = 3;
    }
    facade->MoveScene(x_move, y_move, 0);
    facade->DrawScene();
    ui->label->setPicture(*picture);
}

void MainWindow::scale_scene()
{
    QPushButton* button = (QPushButton*)sender();
    float scale = 1;
    QString command = button->text();
    if (command == "+")
    {
        scale += 0.1;
    }
    else if (command == "-")
    {
        scale -= 0.1;
    }
    facade->ScaleScene(scale, scale, scale);
    facade->DrawScene();
    ui->label->setPicture(*picture);
}

void MainWindow::rotate_scene()
{
    QPushButton* button = (QPushButton*)sender();
    double x_rotate = 0;
    double y_rotate = 0;
    QString command = button->text();
    if (command == "up")
    {
        x_rotate = 3;
    }
    else if (command == "down")
    {
        x_rotate = -3;
    }
    else if (command == "left")
    {
        y_rotate = -3;
    }
    else if (command == "right")
    {
        y_rotate = 3;
    }
    facade->RotateScene(x_rotate, y_rotate, 0);
    facade->DrawScene();
    ui->label->setPicture(*picture);
}
