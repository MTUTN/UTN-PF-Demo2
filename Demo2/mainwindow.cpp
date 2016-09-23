#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->resetPushButton, SIGNAL(clicked(bool)), this, SLOT(reset()));
    connect(ui->clearPushButton, SIGNAL(clicked(bool)), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::connectBR(OpenBRManager *obr){
    connect(ui->processPushButton, SIGNAL(clicked()), obr, SLOT(processImage()));
}


void MainWindow::connectImageLoader(ImageLoader *imgLoader){
    connect(ui->loadImagePushButton, SIGNAL(clicked()), imgLoader, SLOT(loadImage()));
}

void MainWindow::showImage(QString str){
    //TODO: habria que encontrar las clases adecuadas para que al mostrar la imagen, se autoajuste al tamanio del contenedor
    QGraphicsScene *scene = new QGraphicsScene();
    ui->mainImageGraphicsView->setScene(scene);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(str.toLatin1().constData()));
    scene->addItem(item);
    ui->mainImageGraphicsView->show();
}

void MainWindow::showResults(Age::Range range, Gender::Type gender){

    QString displayResults = "Edad: " + Age::getStringFromEnum(range) + ".\n" + "Genero: " + Gender::getStringFromEnum(gender) + ".\n";

    ui->resultsTextEdit->append(displayResults);
}

void MainWindow::reset(){
    ui->resultsTextEdit->clear();
    ui->mainImageGraphicsView->scene()->clear();
    emit brClear();

}

void MainWindow::clear(){
    ui->resultsTextEdit->clear();
}
