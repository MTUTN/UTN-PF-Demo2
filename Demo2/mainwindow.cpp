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

void MainWindow::showResults(int age, QString gender){
    //mostar edad y genero en la seccion indicada
    qDebug("MW: Signal received!");
    qDebug()<< "MW: Age: " << age;
    qDebug()<< "MW: Gender: "<<gender;
}
