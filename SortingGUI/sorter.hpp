#ifndef SORTER_HPP
#define SORTER_HPP

#include <QObject>
#include <QVector>
#include <qDebug>

class Sorter : public QObject
{
    Q_OBJECT
public:
    explicit Sorter(QVector<int>&, QObject *parent = nullptr);
    virtual ~Sorter() = default;

public:
    virtual QVector<int>& sort() = 0;

protected:
    QVector<int>& array;
};


//--------------------------------------------------------------------------//-----------------------------------------------------//---------------------------------/
class Selection : public Sorter
{
    Q_OBJECT
public:
    explicit Selection(QVector<int>&, QObject *parent = nullptr);
    virtual ~Selection() = default;

public:
    virtual QVector<int>& sort() override;
};



//--------------------------------------------------------------------------//-----------------------------------------------------//---------------------------------/

class Bubble : public Sorter
{
    Q_OBJECT
public:
    explicit Bubble(QVector<int>&, QObject *parent = nullptr);
    virtual ~Bubble() = default;

public:
    virtual QVector<int>& sort() override;
};

//--------------------------------------------------------------------------//-----------------------------------------------------//---------------------------------/

class Insertion : public Sorter
{
    Q_OBJECT
public:
    explicit Insertion(QVector<int>&, QObject *parent = nullptr);
    virtual ~Insertion() = default;

public:
    virtual QVector<int>& sort() override;
};



#endif // SORTER_HPP

