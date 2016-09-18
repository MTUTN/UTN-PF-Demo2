#ifndef OPENBRMANAGER_H
#define OPENBRMANAGER_H

#include <QObject>
#include <QSharedPointer>

#include <openbr/openbr_plugin.h>

class OpenBRManager : public QObject
{
    Q_OBJECT

public:
    OpenBRManager(int argc, char *argv[]);
    ~OpenBRManager();

private:
    QString actualImagePath;
    QSharedPointer<br::Transform> transform;

signals:
    void imageProcessed(int age, QString gender);

public slots:
    void saveImagePath(QString str);
    void processImage();

};

#endif // OPENBRMANAGER_H
