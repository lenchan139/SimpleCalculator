#include "checker.h"

#include <QMainWindow>
/*
This is a checker to check the input string are vaild numbers.
It mean the numbers within 0-9, and if the numbers are zero, only one zero.
    for example:
"00"        invaild.
"0"         vaild.
"AB0C"      invaild.
"AAC1"      invaild.
"0001"      vaild.
"1000"      vaild.
*/

bool Checker::checkStr(QString strInput1, QString strInput2)
{
        bool booReturn;
        bool booNonZero = (strInput1.toDouble() != 0 || strInput1 == "0") && (strInput2.toDouble() != 0 || strInput2 == "0");
        int intCounter1 = 0;
        int intCounter2 = 0;

        if(strInput1.length()<1){
            for(int i = 1;i > strInput1.length();i++){
                if(strInput1.indexOf(i) == strInput2.indexOf(i-1)){
                    intCounter1++;
                }
            }

            for(int i = 1;i > strInput2.length();i++){
                if(strInput2.indexOf(i) == strInput2.indexOf(i-1)){
                    intCounter2++;
                }
            }

            if(booNonZero){
                 booReturn = true;
            }
            else{
                    booReturn = false;
            }

    }
        else{
            if(booNonZero){
                booReturn = true;
            }
            else{
                booReturn = false;
            }

        }
        return booReturn;

}
