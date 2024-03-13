#include "person.hpp"

Person::Person() {}

Person::Person(const QString& n, size_t a, const QString& b)
    : name{n}
    , age{a}
    , birtday{b}
{
}

void Person::set_name(const QString& n)
{
    name = n;
}
void Person::set_age(size_t a)
{
    age = a;
}
void Person::set_birtday(const QString& b)
{
    birtday =  b;
}


QString Person::get_name() const
{
    return name;
}
size_t Person::get_age() const
{
    return age;
}
QString Person::get_birtday() const
{
    return birtday;
}


QString Person::serialize()
{
    return name + ':' +  QString::number(age) + ':' + birtday;
}

void Person::deserialize(const QString& data)
{
    QStringList parts = data.split(':');

    if (parts.size() != 3)
    {
        throw std::logic_error("cannot parse data");
    }

    name = parts[0];
    age = parts[1].toInt();
    birtday = parts[2];
}

