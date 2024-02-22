#include "sorter.hpp"

Sorter::Sorter(QVector<int>& _p, QObject *parent)
    : array{_p}
    , QObject{parent}
{
}


Selection::Selection(QVector<int>& _p, QObject *parent)
    : Sorter{_p, parent}
{
}

QVector<int>& Selection::sort()
{
    for (int i = 0; i < array.size() - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < array.size(); ++j)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        std::swap(array[i], array[min]);
    }
    return array;
}

//-------------------------------------------

Bubble::Bubble(QVector<int>& _p, QObject *parent)
    : Sorter{_p, parent}
{
}

QVector<int>& Bubble::sort()
{
    for(int i = 0; i < array.size() - 1; ++i)
    {
        for(int j = 0; j < array.size() - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }

    }
    return array;
}


//-------------------------------------------

Insertion::Insertion(QVector<int>& _p, QObject *parent)
    : Sorter{_p, parent}
{
}

QVector<int>& Insertion::sort()
{
    for (int i = 1; i < array.size(); ++i)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }

    return array;
}





