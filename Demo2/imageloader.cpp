#include "imageloader.h"

ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::loadImage(){//Permite seleccionar una imagen al usuario desde el disco

    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("Image Files (*.png *.jpg *.bmp)");
    dialog.setViewMode(QFileDialog::List);
    if(dialog.exec()) {
        qDebug("IL: Image path: %s\n", dialog.selectedFiles().first().toLatin1().constData());
        QImage image(dialog.selectedFiles().first().toLatin1().constData());
        if(!image.isNull()){
            qDebug("IL: Image correctly loaded");
            emit imageLoaded(dialog.selectedFiles().first());
        }
        else{
            //TODO: Mostrar mensaje de error el cargar la imagen y retornar
        }
    }
    else{
        //TODO: Mostrar mensaje de error y retornar
    }
}


