#include "openbrmanager.h"

OpenBRManager::OpenBRManager()
{

}

OpenBRManager::~OpenBRManager()
{

}

void OpenBRManager::saveImagePath(QImage* img, QString str){
    this->actualImagePath = str;
}

void OpenBRManager::processImage(){

    if(this->actualImagePath.isEmpty()){
        //avisar que no se cargo ninguna imagen
        return;
    }

    //Procesar la imagen
    //Emitir senial de imagen procesada
}
