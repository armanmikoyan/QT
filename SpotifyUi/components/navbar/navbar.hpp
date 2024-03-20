#ifndef NAVBAR_HPP
#define NAVBAR_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>

class Navbar : public QWidget
{
    Q_OBJECT
public:
    explicit Navbar(QWidget *parent = nullptr);

private:
    void setCards();
    void setProfile();
    QWidget* cardFactory();

private:

    QVBoxLayout* mainLayout;
    QWidget* mainWidget;

    QLabel* username;
    QLabel* logo;
};

#endif // NAVBAR_HPP
