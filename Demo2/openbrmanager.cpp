#include "openbrmanager.h"

OpenBRManager::OpenBRManager()
{

}

OpenBRManager::~OpenBRManager()
{

}

void OpenBRManager::saveImagePath(QString str){
    qDebug("OBR: Image path is: %s", str.toLatin1().constData());
    this->actualImagePath = str;
}

void OpenBRManager::processImage(){

    if(this->actualImagePath.isEmpty()){
        //avisar que no se cargo ninguna imagen
        return;
    }

    /*
     * STEPS:
     * 1- Procesar la imagen
     * 2- Emitir senial de imagen procesada
     * /
}
