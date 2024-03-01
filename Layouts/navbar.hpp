#ifndef NAVBAR_HPP
#define NAVBAR_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class Navbar : public QWidget
{
    Q_OBJECT
public:
    explicit Navbar(QWidget *parent = nullptr);
    ~Navbar();

public:
    void setPlaylist();
    QVBoxLayout* getLayout() const;

signals:
    void pageSwapSignal(int);

public slots:
    void onClick();

private:
    void setNavbar();

private:
    QVBoxLayout* layout;
};

#endif // NAVBAR_HPP
