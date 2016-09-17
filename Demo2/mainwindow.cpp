#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectBR(OpenBRManager *obr){
    connect(ui->processPushButton, SIGNAL(clicked()), obr, SLOT(processImage(QString)));
}


void MainWindow::connectImageLoader(ImageLoader *imgLoader){
    connect(ui->loadImagePushButton, SIGNAL(clicked()), imgLoader, SLOT(loadImage()));
}

void MainWindow::showImage(QImage *img, QString str){
    //Show image in Graphic View. Do Nothing with str.
}
