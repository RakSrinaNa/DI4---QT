#ifndef RESSOURCETYPE_H
#define RESSOURCETYPE_H

class RessourceType
{
public:
    RessourceType(int id, QString name);
    int getId();
    QString getName();

private:
    int id;
    QString name;
};

#endif // RESSOURCETYPE_H
