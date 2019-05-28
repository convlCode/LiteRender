#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LiteRender");
    world = new World();
    //connect(world,SIGNAL(renderComplete()),this,SLOT(renderComplete()));
    connect(this,&MainWindow::startRendering,world,&World::render_scene);
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
    if(world){
        delete world;
    }
}

void MainWindow::renderComplete()
{
    ui->renderCanvas->setPixmap(QPixmap::fromImage(*(world->image)));
}

void MainWindow::on_startButton_clicked()
{
    world->stopRender=false;
    ui->renderCanvas->clear();
    emit startRendering();
    //world->render_scene();
}

void MainWindow::on_stopButton_clicked()
{
    world->stopRender=true;
}

void MainWindow::on_saveButton_clicked()
{
    if(world->image){
        world->image->save(QFileDialog::getSaveFileName(this,
              tr(u8"保存当前渲染场景"),".",tr(u8"图片文件 (*.png *.jpg *.bmp)")));
    }
}
