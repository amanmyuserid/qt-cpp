#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (const QCameraInfo & infor : QCameraInfo::availableCameras())
    {
        qDebug() << infor.description();
    }
//    M_Camera.reset(new QCamera);
//    QCameraViewfinder *viewfinder = new QCameraViewfinder;
//    M_Camera->setViewfinder(viewfinder);
//    viewfinder->show();
//    viewfinder->setParent(this);
    M_Camera.reset(new QCamera(QCameraInfo::defaultCamera()));

    M_Camera->setViewfinder(ui->widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_camera_clicked()
{
    M_Camera->start();


}


void MainWindow::on_stop_camera_clicked()
{
    M_Camera->stop();
}

