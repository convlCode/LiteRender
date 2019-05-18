#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    world = new World();
    //connect(world,SIGNAL(renderComplete()),this,SLOT(renderComplete()));
    connect(world,&World::renderComolete,this,&MainWindow::renderComplete);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete world;
}

void MainWindow::renderComplete()
{
    ui->renderCanvas->setPixmap(QPixmap::fromImage(*(world->image)));
}

void MainWindow::on_startButton_clicked()
{
    world->build();
    world->render_scene();
}
