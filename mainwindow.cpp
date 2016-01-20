#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalculate_clicked()
{
    //Create some varible
    QString strOperator,strAns;
    double dblInput1,dblInput2,dblAns;
    dblInput1 = ui->lineInput1->text().toDouble();
    dblInput2 = ui->lineInput2->text().toDouble();
    strOperator = ui->comboChoices->currentText();

    //do if
    if(strOperator == "+"){
        dblAns = dblInput1 + dblInput2;
        strAns = QString::number(dblAns);
    }
    else if(strOperator == "-"){
        dblAns = dblInput1 - dblInput2;
        strAns = QString::number(dblAns);
    }
    else if(strOperator == "*"){
        dblAns = dblInput1 * dblInput2;
        strAns = QString::number(dblAns);
    }
    else if(strOperator == "/"){
        dblAns = dblInput1 / dblInput2;
        strAns = QString::number(dblAns);
    }
    else{
        strAns = "Error!";
    }
    //QString strTemp = QString::number(dblInput1) + "!!!" + QString::number(dblInput2);
    ui->lineAnswer->setText(strAns);
}
