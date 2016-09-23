#ifndef OPENBRMANAGER_H
#define OPENBRMANAGER_H

#include <QObject>
#include <QSharedPointer>

#include <openbr/openbr_plugin.h>
#include "age.h"
#include "gender.h"

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
    void imageProcessed(Age::Range age, Gender::Type gender);

public slots:
    void saveImagePath(QString str);
    void processImage();
    void clear();

};

#endif // OPENBRMANAGER_H
