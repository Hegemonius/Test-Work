#include "mydialog.h"
#include "ui_mydialog.h"
#include <QFile>
#include <QTextStream>
#include <QApplication>


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::CreateFile()
{
    QFile file("output.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Миру мир!" << Qt::endl;
        file.close();
    }
    QApplication::quit();
}
