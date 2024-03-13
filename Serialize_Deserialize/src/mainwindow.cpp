#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->serialize_btn, &QPushButton::clicked, this, &MainWindow::write_to_file);
    connect(ui->deserialize_btn, &QPushButton::clicked, this, &MainWindow::render_ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write_to_file()
{
    if (last_person == nullptr)
    {
        last_person = new Person{};
    }

    size_t a = ui->age_field->text().toInt();
    QString n = ui->username_field->text();
    QString b = ui->birtday_field->text();

    ui->age_field->clear();
    ui->username_field->clear();
    ui->birtday_field->clear();

    last_person->set_age(a);
    last_person->set_name(n);
    last_person->set_birtday(b);

    QString data = last_person->serialize();

    QFile file{"/Users/armanmikoyan/Desktop/QT/Serialize_Deserialize/db.txt"};

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "error opening file";
        return;
    }

    QTextStream out(&file);
    out << data;
    file.close();
}


void MainWindow::render_ui()
{
    QFile file("/Users/armanmikoyan/Desktop/QT/Serialize_Deserialize/db.txt");
    if (last_person == nullptr) return;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "error opening file";
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    QStringList parts = line.split(':');
    if (parts.size() != 3) {
        qDebug() << "Invalid data format in file";
        return;
    }

    last_person->set_name(parts[0]);
    last_person->set_age(parts[1].toInt());
    last_person->set_birtday(parts[2]);

    ui->birtday_field->setText(last_person->get_birtday());
    ui->username_field->setText(last_person->get_name());
    ui->age_field->setText( QString::number(last_person->get_age()));
}
