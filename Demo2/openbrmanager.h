#ifndef OPENBRMANAGER_H
#define OPENBRMANAGER_H

#include <QObject>

class OpenBRManager : public QObject
{
    Q_OBJECT

public:
    OpenBRManager();
    ~OpenBRManager();
    void processImage(QString path);

private:
    QString actualImagePath;

signals:
    void imageProcessed();

public slots:
    void saveImagePath(QImage *img, QString str);
    void processImage();

};

#endif // OPENBRMANAGER_H
