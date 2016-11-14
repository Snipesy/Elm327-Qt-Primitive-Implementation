#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include "elm.h"
#include <iostream>
#include <fstream>

class Someclass : public QObject
{
    Q_OBJECT
public:
    explicit Someclass(QObject *parent = 0);
    Elm *sr;
    QDebug *dbg;

signals:

public slots:
private slots:
    void OnDone(Elm::Job j);
    void OnReady();
    void OnFail(Elm::DeviceError error);
};

#endif // SOMECLASS_H
