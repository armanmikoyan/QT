#ifndef BODY_HPP
#define BODY_HPP

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QComboBox>


class Body : public QWidget
{
    Q_OBJECT
public:
    explicit Body(QWidget *parent = nullptr);

private:
    QWidget* cardFactory();
    QWidget* layerFactory();

private:
    QVBoxLayout* mainLayout;
    QWidget* mainWidget;
};

#endif // BODY_HPP
