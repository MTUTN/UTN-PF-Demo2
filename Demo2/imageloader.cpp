#include "imageloader.h"

ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::loadImage(){
    //Permite seleccionar una imagen al usuario desde el disco
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("Image Files (*.png *.jpg *.bmp)");
    dialog.setViewMode(QFileDialog::List);
    if(dialog.exec()) {
        //emit imageLoaded(QImage, QString);//Emite senial al window para que muestre la imagen y al openbr para que guarde el path
        qDebug("Image path: %s\n", dialog.selectedFiles().first().toLatin1().constData());
        QImage image(dialog.selectedFiles().first().toLatin1().constData());
        if(!image.isNull()){
            qDebug("Image correctly loaded");
        }
    }
    else{
        //Mostrar mensaje de error y retornar
    }
}


