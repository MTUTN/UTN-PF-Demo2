#include "mainwindow.h"
#include "openbrmanager.h"
#include "imageloader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create objects
    MainWindow w;
    OpenBRManager openbrmanager(argc, argv);
    ImageLoader imgLoader;

    //Connect objects
    w.connectBR(&openbrmanager); //miembro ui de clase MainWindow es privado, por eso conectamos a traves de un metodo publico.
    w.connectImageLoader(&imgLoader); //miembro ui de clase MainWindow es privado, por eso conectamos a traves de un metodo publico.
    QObject::connect(&imgLoader, SIGNAL(imageLoaded(QString)), &w, SLOT(showImage(QString)));
    QObject::connect(&imgLoader, SIGNAL(imageLoaded(QString)), &openbrmanager, SLOT(saveImagePath(QString)));
    QObject::connect(&openbrmanager, SIGNAL(imageProcessed(int,QString)), &w, SLOT(showResults(int,QString)));
    QObject::connect(&w, SIGNAL(brClear()), &openbrmanager, SLOT(clear()));


    w.show();

    return a.exec();
}
