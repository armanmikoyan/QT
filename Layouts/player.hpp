#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QPushButton>

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();

public:
    QVBoxLayout* getLayout() const;

private:
    void setPlayer();

private:
    QWidget* widget;
    QVBoxLayout* vlayout;
    QHBoxLayout* hlayout;
    QSlider* slider;
    QPushButton* next;
    QPushButton* prev;
};

#endif // PLAYER_HPP
