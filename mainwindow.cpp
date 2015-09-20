#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->digitButton_0, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_1, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_2, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_3, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_4, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_5, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_6, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_7, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_8, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->digitButton_9, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->dotButton, SIGNAL(clicked()), this, SLOT(buttonClick()));

    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->starButton, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->slashButton, SIGNAL(clicked()), this, SLOT(buttonClick()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void MainWindow::on_equalsButton_clicked()
{
    const std::string expresion = ui->lineEdit->text().toStdString();
    try
    {
        const double result = calculator::calculate(expresion);
        ui->lineEdit->setText(QString::number(result));
    }
    catch(std::exception e)
    {
        ui->lineEdit->setText(e.what());
    }
}


