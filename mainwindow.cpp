#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_PlusMinus, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Percent, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Sin, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Cos, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Tan, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Ctg, SIGNAL(released()), this, SLOT(unary_operator_pressed()));
    connect(ui->pushButton_Multiply, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Divide, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Add, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Substract, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    ui->pushButton_Divide->setCheckable(true);
    ui->pushButton_Add->setCheckable(true);
    ui->pushButton_Multiply->setCheckable(true);
    ui->pushButton_Substract->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelnumber;
    QString newlabel;

    if ((ui->pushButton_Add->isChecked()||ui->pushButton_Substract->isChecked()||
            ui->pushButton_Multiply->isChecked()||ui->pushButton_Divide->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelnumber = button->text().toDouble();
        userIsTypingSecondNumber=true;
        newlabel = QString::number(labelnumber,'g', 15);
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newlabel = ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
            newlabel = QString::number(labelnumber,'g', 15);
        }
    }
    ui->label->setText(newlabel);
}

void MainWindow::on_pushButton_Decimal_released()
{
    QPushButton * button = (QPushButton*)sender();
    if(button->text() == ".")
    {

    }
    else
        ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operator_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelnumber;
    QString newlabel;
    if(button->text() =="+/-")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = labelnumber * -1;
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
    if(button->text() =="%")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = labelnumber * 100;
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
    if(button->text() =="sin")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = sin(labelnumber);
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
    if(button->text() =="cos")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = cos(labelnumber);
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
    if(button->text() =="tan")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = sin(labelnumber)/cos(labelnumber);
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
    if(button->text() =="ctg")
    {
        labelnumber = ui->label->text().toDouble();
        labelnumber = cos(labelnumber)/sin(labelnumber);
        newlabel = QString::number(labelnumber, 'g', 15);
        ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_Clear_released()
{
    ui->pushButton_Add->setChecked(false);
    ui->pushButton_Substract->setChecked(false);
    ui->pushButton_Multiply->setChecked(false);
    ui->pushButton_Divide->setChecked(false);
    userIsTypingSecondNumber = false;
    ui->label->setText("0");
}

void MainWindow::on_pushButton_Equals_released()
{
    double labelNumber, secondNum;
    QString newlabel;
    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_Add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newlabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_Add->setChecked(false);
    }
    else if(ui->pushButton_Substract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newlabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_Substract->setChecked(false);
    }
    else if(ui->pushButton_Multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newlabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_Multiply->setChecked(false);
    }
    else if(ui->pushButton_Divide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newlabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_Divide->setChecked(false);
    }
    userIsTypingSecondNumber = false;
}
void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
}
