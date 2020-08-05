#ifndef STRINGRESOURCES_H
#define STRINGRESOURCES_H

#include <QString>
#include <QVariant>

const QString S_RESOURCE_FILE_PATH = QString("strings.json");

class StringResources
{
private:
    StringResources();
    static StringResources *instance;
    QMap<QString, QVariant> *resourceMap;
    QMap<QString, QVariant> *initialize() const;
    QMessageLogger *log = new QMessageLogger();

public:
    static StringResources *getInstance();
    QString *getString(const QString &key) const;
    bool setString(const QString &key, const QString &value);
    bool exists(const QString &key);

};

#endif // STRINGRESOURCES_H
