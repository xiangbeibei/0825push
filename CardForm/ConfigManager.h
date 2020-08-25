#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileInfo>
#include <QDebug>


class ConfigManager
{
public:
    ConfigManager();
    ~ConfigManager();
    static int readerName;
    static int currentreader;
    static int threshold;
    static int isPlaySound;
    static int cleanTime;
    static float CameraExposure;
    static QString imagePath;

    void InitConfigValues();
    bool SaveReaderName(int readerName);
    bool SaveCurrentReader(int currentreader);
    bool SaveThreshold(int threshold);
    bool SaveIsPlaySound(int isPlaySound);
    bool SaveCleanTime(int cleanTime);
    bool SaveImagePath(QString imagePath);
    bool SaveCameraExposure(float CameraExposure);

    void IsConfigExist();


};

#endif // CONFIGMANAGER_H
