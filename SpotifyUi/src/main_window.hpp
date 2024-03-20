#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window;
}
QT_END_NAMESPACE

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();
private:
    QGridLayout* mainLayout;
    QWidget* mainWidget;


};
#endif // MAIN_WINDOW_HPP
