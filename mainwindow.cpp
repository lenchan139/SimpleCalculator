#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checker.h"

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

    QString strOperator,strAns,strInputs1,strInputs2;
    double dblInput1,dblInput2,dblAns;
    strInputs1 = ui->lineInput1->text();
    strInputs2 = ui->lineInput2->text();

    /*Check String is or is not all 0 and more than 1.
    if(strInputs1.length() > 1){
        int intCounter1 = 0;
            for(int i = 1;i > strInputs1.length();i++){
                if(strInputs1.indexOf(i) == strInputs1.indexOf(i-1))
                intCounter1++;
             }
        if(intCounter1 == strInputs1.length())
        strInputs1 = strInputs1.indexOf(1);
    }*/

    //vaild check.
    if( Checker::checkStr(strInputs1,strInputs2) ){
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



