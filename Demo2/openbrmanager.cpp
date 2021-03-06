#include "openbrmanager.h"

using namespace br;

OpenBRManager::OpenBRManager(int argc, char *argv[])
{
    Context::initialize(argc, argv, "", true);
    transform= br::Transform::fromAlgorithm("GenderEstimation+AgeEstimation");
    Globals->enrollAll = true;
}

OpenBRManager::~OpenBRManager()
{
    Context::finalize();
}

void OpenBRManager::saveImagePath(QString str){
    qDebug("OBR: Image path is: %s", str.toLatin1().constData());
    this->actualImagePath = str;
}

void OpenBRManager::processImage(){

    if(this->actualImagePath.isEmpty()){
        //avisar que no se cargo ninguna imagen
        qDebug("actualImagePath is empty");
        return;
    }

    // 1- Process image
    br::Template brTemplate(actualImagePath);
    brTemplate >>  *transform;

    // 2- Get image attributes
    int age = int(brTemplate.file.get<float>("Age"));
    QString gender = brTemplate.file.get<QString>("Gender");

    // 3- Emit signal of image processed
    emit(imageProcessed(age, gender));
}

void OpenBRManager::clear(){
    this->actualImagePath = "";
}
