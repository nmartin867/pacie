#include "stringresources.h"
#include "constants.h"
#include <QFile>
#include <QFileInfo>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDebug>

StringResources* StringResources::instance = 0;

StringResources::StringResources()
{
    initialize();
}

void StringResources::initialize()
{
    QFile file(S_RESOURCE_FILE_PATH);
    QJsonParseError jsonError;

    if(file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
        if(jsonError.error == QJsonParseError::NoError) {
            if(jsonError.error == QJsonParseError::NoError) {
                auto data = jsonDoc.object();
                resourceMap = data.toVariantMap();
            }
        }
    }
}

StringResources* StringResources::getInstance()
{
    if(instance == 0)
        instance = new StringResources();
    return instance;
}

QVariant StringResources::getValue(const QString &key) const
{
   return resourceMap[key];
}

void StringResources::setValue(const QString &key, const QVariant &value)
{
    resourceMap[key] = value;
}

bool StringResources::exists(const QString &key)
{
    return resourceMap.contains(key);
}
