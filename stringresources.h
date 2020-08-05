#ifndef STRINGRESOURCES_H
#define STRINGRESOURCES_H

#include <QString>
#include <QVariant>

class StringResources
{
private:
    StringResources();
    void initialize();

    static StringResources* instance;
    QMap<QString, QVariant> resourceMap;
public:
    static StringResources* getInstance();
    QVariant getValue(const QString &key) const;
    void setValue(const QString &key, const QVariant &value);
    bool exists(const QString &key);
};

#endif // STRINGRESOURCES_H
