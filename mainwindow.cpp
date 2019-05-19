#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    world = new World();
    //connect(world,SIGNAL(renderComplete()),this,SLOT(renderComplete()));
    connect(world,&World::renderComolete,this,&MainWindow::renderComplete);
    connect(world,&World::updateProgeress,[this]{
        ui->renderCanvas->setPixmap(QPixmap::fromImage(*world->image));
        ui->progressBar->setValue(static_cast<int>(world->renderProgress));
    });
    world->build();
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
    ui->renderCanvas->clear();
    world->render_scene();
}
