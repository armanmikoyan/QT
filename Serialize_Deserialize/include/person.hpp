#ifndef PERSON_HPP
#define PERSON_HPP

#include "./SerializeDeserialize.hpp"
#include <QString>
#include <QStringList>


class Person : public SerializeDeserialize
{
public:
    Person();
    Person(const QString&, size_t, const QString&);

    virtual QString serialize() override;
    virtual void deserialize(const QString&)  override;

public:
    QString get_name()    const;
    size_t  get_age()     const;
    QString get_birtday() const;

    void    set_name(const QString&);
    void             set_age(size_t);
    void set_birtday(const QString&);

private:
    QString    name;
    size_t      age;
    QString birtday;

};

#endif // PERSON_HPP
