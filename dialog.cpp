#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    cout << "Started ground control station" << endl;

    //Populate table
    //set left column (drone number)
    int numDrones = 8;      //READ THIS IN?
    ui->tableWidget->setRowCount(numDrones+1);
    for(int i=0; i<=numDrones; i++){
        QString num = QString::number(i);
        if(i==0){
            num = "";
        }
        QTableWidgetItem *temp = new QTableWidgetItem;
        temp->setText(num);
        ui->tableWidget->setVerticalHeaderItem(i, temp);
    }

    //PUT THESE INTO THE UPDATE LOOP?
    //set drone hostnames
    int col = 0;
    for(int i=1; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem *temp = ui->tableWidget->item(i, col);
        if(!temp){
            temp = new QTableWidgetItem;
            ui->tableWidget->setItem(i, col, temp);
        }
        //set hostname
        ui->tableWidget->item(i, col)->setText("Drone" + QString::number(i) + "_HOSTNAME");
    }
    //set drone statuses
    col = 1;
    for(int i=1; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem *temp = ui->tableWidget->item(i, col);
        if(!temp){
            temp = new QTableWidgetItem;
            ui->tableWidget->setItem(i, col, temp);
        }
        //set status
        //ui->tableWidget->item(i, col)->setText("example");
    }

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_tableWidget_cellClicked(int row, int column)
{
    if(row == 0 && column == 2){
        //send command to update all raspberry pis
        cout << "updating all raspberry pis" << endl;
    }
    else if (column == 2){
        //update the ROWth + 1 drone's raspberry pi

    }
}

