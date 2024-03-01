#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

public:
    QVBoxLayout* getLayout() const;
    QWidget* getWidget() const;

private:
    void setHome();

private:
    QWidget* widget;
    QVBoxLayout* layout;
    QLabel* pageName;
};

#endif // HOMEPAGE_H
