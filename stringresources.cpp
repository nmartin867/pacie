#include "stringresources.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonParseError>
#include <QDebug>

StringResources::StringResources()
{

}

QMap<QString, QVariant> *StringResources::initialize() const
{
    QFile file(S_RESOURCE_FILE_PATH);
    QJsonParseError jsonError;

    if(file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
        if(jsonError.error == QJsonParseError::NoError) {
             if(jsonError.error == QJsonParseError::NoError) {
                 QJsonObject localObject = jsonDoc.object();
             }
        }
    }
}




StringResources *StringResources::getInstance()
{
    if(!instance)
        instance = new StringResources();
    return instance;
}

QString *StringResources::getString(const QString &key) const
{

}

bool StringResources::setString(const QString &key, const QString &value)
{

}

bool StringResources::exists(const QString &key)
{

}
