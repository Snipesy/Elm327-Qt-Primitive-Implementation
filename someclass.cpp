#include "someclass.h"

Someclass::Someclass(QObject *parent) : QObject(parent)
{
    sr = new Elm();
    connect(sr, SIGNAL(OnDeviceReady()), this, SLOT(OnReady()));
    connect(sr, SIGNAL(OnDeviceFail(Elm::DeviceError)), this, SLOT(OnFail(Elm::DeviceError)));
    sr->ConnectToDevice();

}

void Someclass::OnReady()
{
    qInfo() << "Ready";
    qInfo() << "Justin Hoogestraat (C) 2016";
    connect(sr, SIGNAL(OnJobFinished(Elm::Job)), this, SLOT(OnDone(Elm::Job)));

    sr->AddJob("ATI");




}

void Someclass::OnDone(Elm::Job job)
{
    static int i = 0;
    //qInfo() << job.command << " : " << job.response << " : " << job.execution_time;
    QString buffer;
    //QTextStream s(stdin);

    //std::cout << ">";
    //buffer = "ATI";
    sr->AddJob(buffer.toLocal8Bit());
    i++;
    if (i == 100000)
    {
        qInfo() << "Debug";
        sr->Disconnect();
        sr->disconnect();
    }
}

void Someclass::OnFail(Elm::DeviceError error)
{
    qWarning() << "Device failed." << error;
    if (error == 14)
    {
        sr->SetBaudRate(500000);
        sr->ConnectToDevice();
    }

}
