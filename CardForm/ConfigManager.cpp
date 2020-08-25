#include "ConfigManager.h"
int ConfigManager::readerName = 1;
int ConfigManager::currentreader = 1;
int ConfigManager::threshold = 74;
int ConfigManager::isPlaySound = 1;
int ConfigManager::cleanTime = 5;
float ConfigManager::CameraExposure = 0.0;
QString ConfigManager::imagePath = "./data";
ConfigManager::ConfigManager()
{
    IsConfigExist();
}

ConfigManager::~ConfigManager()
{

}

void ConfigManager::IsConfigExist()
{
    QFileInfo config("./data/config.json");
    if(!config.isFile())
    {
        QFile file("./data/config.json");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QJsonObject json;
        json.insert("readerName","1");
        json.insert("currentreader","1");
        json.insert("isPlaySound","1");
        json.insert("cleanTime","5");
        json.insert("threshold","73");
        json.insert("imagePath","./data/");
        json.insert("CameraExposure","0.0");
        QJsonDocument document;
        document.setObject(json);
        QByteArray byteArray = document.toJson(QJsonDocument::Compact);
        file.write(byteArray,byteArray.length());
        file.flush();
        file.close();
    }
    InitConfigValues();
}

void ConfigManager::InitConfigValues()
{
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) return ;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            QJsonObject object = document.object();  // 转化为对象
            if (object.contains("readerName")) {  // 包含指定的 key
                QJsonValue value = object.value("readerName");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    readerName = strName.toInt();
                }
            }
            if (object.contains("currentreader")) {  // 包含指定的 key
                QJsonValue value = object.value("currentreader");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    currentreader = strName.toInt();
                }
            }
            if (object.contains("isPlaySound")) {  // 包含指定的 key
                QJsonValue value = object.value("isPlaySound");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    isPlaySound = strName.toInt();
                }
            }
            if (object.contains("cleanTime")) {  // 包含指定的 key
                QJsonValue value = object.value("cleanTime");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    cleanTime = strName.toInt();
                }
            }
            if (object.contains("threshold")) {  // 包含指定的 key
                QJsonValue value = object.value("threshold");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    threshold = strName.toInt();
                }
            }
            if (object.contains("imagePath")){
                QJsonValue value = object.value("imagePath");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    imagePath = strName;
                }
            }
            if (object.contains("CameraExposure")){
                QJsonValue value = object.value("CameraExposure");  // 获取指定 key 对应的 value
                if (value.isString()) {  // 判断 value 是否为字符串
                    QString strName = value.toString();  // 将 value 转化为字符串
                    CameraExposure = strName.toFloat();
                }
            }
        }

    }
}
bool ConfigManager::SaveReaderName(int readerName)
{
    this->readerName = readerName;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);    // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) {                                              // JSON 文档为对象
            object = document.object();                                         // 转化为对象
            if (object.contains("readerName")) {                                // 包含指定的 key
                QString str;
                str = QString::number(readerName,10);
                object.insert("readerName",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();

    return true;
}
bool ConfigManager::SaveCurrentReader(int currentreader)
{
    this->currentreader = currentreader;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);    // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) {                                              // JSON 文档为对象
            object = document.object();                                         // 转化为对象
            if (object.contains("currentreader")) {                                // 包含指定的 key
                QString str;
                str = QString::number(currentreader,10);
                object.insert("currentreader",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();

    return true;
}

bool ConfigManager::SaveIsPlaySound(int isPlaySound)
{
    this->isPlaySound = isPlaySound;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            object = document.object();  // 转化为对象
            if (object.contains("isPlaySound")) {  // 包含指定的 key
                QString str;
                str = QString::number(isPlaySound,10);
                object.insert("isPlaySound",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();
    return true;
}

bool ConfigManager::SaveCleanTime(int cleanTime)
{
    this->cleanTime = cleanTime;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            object = document.object();  // 转化为对象
            if (object.contains("cleanTime")) {  // 包含指定的 key
                QString str;
                str = QString::number(cleanTime,10);
                object.insert("cleanTime",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();
    return true;
}

bool ConfigManager::SaveThreshold(int threshold)
{
    this->threshold = threshold;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            object = document.object();  // 转化为对象
            if (object.contains("threshold")) {  // 包含指定的 key
                QString str;
                str = QString::number(threshold,10);
                object.insert("threshold",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();
    return true;
}
bool ConfigManager::SaveCameraExposure(float CameraExposure)
{
    this->CameraExposure = CameraExposure;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) { // JSON 文档为对象
            object = document.object();  // 转化为对象
            if (object.contains("CameraExposure")) {  // 包含指定的 key
                QString str;
                str = QString("%1").arg(CameraExposure);
                object.insert("CameraExposure",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();
    return true;
}
bool ConfigManager::SaveImagePath(QString imagePath)
{
    this->imagePath = imagePath;
    QFile file("./data/config.json");
    if(!file.open(QIODevice::ReadWrite)) return false;
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonObject object;
    QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);    // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) {                                              // JSON 文档为对象
            object = document.object();                                         // 转化为对象
            if (object.contains("imagePath")) {                                // 包含指定的 key
                QString str;
                str = imagePath;
                object.insert("imagePath",str);
                }
             }
           }
    document.setObject(object);
    byteArray = document.toJson(QJsonDocument::Compact);
    QFile outfile("./data/config.json");
    if(!outfile.open(QIODevice::ReadWrite|QIODevice::Truncate)) return false;
    outfile.write(byteArray,byteArray.length());
    outfile.flush();
    outfile.close();

    return true;
}
