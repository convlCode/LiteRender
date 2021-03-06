#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "World/World.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void renderComplete();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_saveButton_clicked();

signals:
    void startRendering();

private:
    Ui::MainWindow *ui;
    World* world;
};

#endif // MAINWINDOW_H
