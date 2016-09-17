#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QObject>
#include <QFileDialog>

//#include "mainwindow.h"

class ImageLoader : public QObject
{
    Q_OBJECT

public:
    ImageLoader();
    ~ImageLoader();


signals:
    void imageLoaded(QString path);
public slots:
    void loadImage();
};

#endif // IMAGELOADER_H
