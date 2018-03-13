#ifndef RESSOURCETYPE_H
#define RESSOURCETYPE_H

#include <QString>

class ResourceType
{
public:
    ResourceType(int id, QString name);
    int getId();
    QString getName();

private:
    int id;
    QString name;
};

#endif // RESSOURCETYPE_H
