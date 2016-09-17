#include "mainwindow.h"
#include "openbrmanager.h"
#include "imageloader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create objects
    MainWindow w;
    OpenBRManager openbrmanager;
    ImageLoader imgLoader;

    //Connect objects
    w.connectBR(&openbrmanager); //miembro ui de clase MainWindow es privado, por eso conectamos a traves de un metodo publico.
    w.connectImageLoader(&imgLoader); //miembro ui de clase MainWindow es privado, por eso conectamos a traves de un metodo publico.
    QObject::connect(&imgLoader, SIGNAL(imageLoaded(QImage*, QString)), &w, SLOT(showImage(QImage*, QString)));
    QObject::connect(&imgLoader, SIGNAL(imageLoaded(QImage*, QString)), &openbrmanager, SLOT(saveImagePath(QImage*,QString)));

    w.show();

    return a.exec();
}
