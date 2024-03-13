#ifndef SERIALIZEDESERIALIZE_HPP
#define SERIALIZEDESERIALIZE_HPP

#endif // SERIALIZEDESERIALIZE_HPP

#include <QString>


class SerializeDeserialize
{
public:
    virtual QString serialize()              = 0;
    virtual void deserialize(const QString&) = 0;
};
