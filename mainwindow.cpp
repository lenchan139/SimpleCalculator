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
//This is a sub-program when you are click a "btnCalculate" button on "MainWindow" form.
void MainWindow::on_btnCalculate_clicked()
{
    //Create some varible
    //You need use QString or double to create varible like: QString <varible name>
    QString strOperator,strAns,strInput1,strInput2;
    double dblInput1,dblInput2,dblAns;
    strInput1 = ui->lineInput1->text();
    strInput2 = ui->lineInput2->text();

    //vaild check, if QString is not a vaild number, QString.toDouble will return 0.
    if( (strInput1.toDouble() != 0 || strInput1 == "0") && (strInput2.toDouble() != 0 || strInput2 == "0") ){
        dblInput1 = ui->lineInput1->text().toDouble();
        dblInput2 = ui->lineInput2->text().toDouble();
        //You need use ui->... to call the GUI element.
        //the format is ui::[formname]->[object name]->[value name]
        //Moreover, " ui->comboChoices->currentText()" is a QString,
        //so that you can use this as a QString.
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

        //Output, use setText(varible) to put the varible to the Output box.
        ui->lineAnswer->setText(strAns);
    }
    else{
        strAns = "Error!";
        ui->lineAnswer->setText(strAns);
    }
}
