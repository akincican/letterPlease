#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QRandomGenerator>
#include <QTimer>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->box_10->hide();
    ui->box_9->hide();
    ui->box_8->hide();
    ui->box_7->hide();
    ui->box_6->hide();
    ui->box_5->hide();


      ui->label->hide();
      ui->label_2->hide();
      ui->label_3->hide();
      ui->label_4->hide();
      ui->label_5->hide();
      ui->label_6->hide();
      ui->label_7->hide();
      ui->label_8->hide();
      ui->label_9->hide();
      ui->label_10->hide();
      timer = new QTimer(this);
      connect(timer, SIGNAL(timeout()),this,
              SLOT(timerfunction()));
      timer->start(1000);
;}

MainWindow::~MainWindow()
{
    delete ui;

}

quint32 *MainWindow::randomTypeSetter(int range) //Returns pointer of 10 element array which include all numbers 0 to given range but in random mixed order
{
    static quint32 randomArray[10];
    quint32 h  = QRandomGenerator::global()->bounded(range);
    int i = 1;
    randomArray[0]=h;

    while (i<range) {
        h = QRandomGenerator::global()->bounded(range);
        bool isUnique=true;
        bool check;
        int var=0;
        while ((var < i) && isUnique) {
            if(h != randomArray[var])
            {
                check=true;

            }
            else{
                isUnique = false;
            }
            isUnique = isUnique && check;
            var++;
        }
        if(isUnique){
            randomArray[i]=h;
            i++;
        }
    }
    return randomArray;
}


void MainWindow::timerfunction()
{

    if(dakika+saniye == 0){
        timer->stop();
        ui->timerLabel->setText("0 : 00lkjbkjhkjh");
    }
    else{
        saniye --;
    }
    if (saniye == 0 && dakika!=0)
    {
        saniye =59;
        dakika --;
    }
    ui->timerLabel->setText(QString::number(dakika)+" : "+QString::number(saniye));

}


int numberofOpenBox = 10;
QString EnteredAnswer[10];
QString correctAnswer;




void MainWindow::questionBankImporter(QString filePath){
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    for (int var = 0; var < 14; ++var) {
        questionBank[var].Question = file.readLine().trimmed();
        questionBank[var].Answer =file.readLine().trimmed();
    }
}
void MainWindow::on_startButton_clicked()
{

    QString filePath = "C:/Users/akinc/Desktop/wordDatabase.txt";
    questionBankImporter(filePath);
    ui->questionBrowser->setText(questionBank[0].Question);
    correctAnswer = questionBank[0].Answer;

}



void MainWindow::on_box_1_textChanged(const QString &arg1)
{

    EnteredAnswer[0]= arg1 ;
    if(arg1==""){}
    else{
    ui->box_2->setFocus();
    }
}

void MainWindow::on_box_2_textChanged(const QString &arg1)
{
    EnteredAnswer[1]= arg1 ;
    if(arg1==""){
        ui->box_1->setFocus();
    }
    else{
    ui->box_3->setFocus();
    }
}

void MainWindow::on_box_3_textChanged(const QString &arg1)
{
    EnteredAnswer[2]= arg1 ;
    if(arg1==""){
        ui->box_2->setFocus();
    }
    else{
    ui->box_4->setFocus();
    }
}

void MainWindow::on_box_4_textChanged(const QString &arg1)
{
        EnteredAnswer[3]= arg1 ;
        if(arg1==""){
            ui->box_3->setFocus();
        }
        else if(numberofOpenBox>4){
        ui->box_5->setFocus();
        }
}

void MainWindow::on_box_5_textChanged(const QString &arg1)
{
        EnteredAnswer[4]= arg1 ;
        if(arg1==""){
            ui->box_4->setFocus();
        }
        else if(numberofOpenBox>5){
        ui->box_6->setFocus();
        }
}

void MainWindow::on_box_6_textChanged(const QString &arg1)
{
        EnteredAnswer[5]= arg1 ;
        if(arg1==""){
            ui->box_5->setFocus();
        }
        else if(numberofOpenBox>6){
        ui->box_7->setFocus();
        }
}

void MainWindow::on_box_7_textChanged(const QString &arg1)
{
        EnteredAnswer[6]= arg1 ;
        if(arg1==""){
            ui->box_6->setFocus();
        }
        else if(numberofOpenBox>7){
        ui->box_8->setFocus();
        }
}

void MainWindow::on_box_8_textChanged(const QString &arg1)
{
        EnteredAnswer[7]= arg1 ;
        if(arg1==""){
            ui->box_7->setFocus();
        }
        else if(numberofOpenBox>8){
        ui->box_9->setFocus();
        }
}

void MainWindow::on_box_9_textChanged(const QString &arg1)
{
    EnteredAnswer[8]= arg1 ;
    if(arg1==""){
        ui->box_8->setFocus();
    }
    else if(numberofOpenBox>9){
    ui->box_10->setFocus();
    }

}

void MainWindow::on_box_10_textChanged(const QString &arg1)
{
    EnteredAnswer[9]= arg1 ;
    if(arg1==""){
        ui->box_9->setFocus();
    }
}







void MainWindow::on_pauseButton_clicked()
{
    timer->stop();
//   timer2->start(30000);




qDebug()<<"clicked";
}


void MainWindow::on_confirmButton_clicked()
{
    QString finalAnswer;
    QString temp;
    for(int i=0;i<4;i++){
        temp = EnteredAnswer[i];
        finalAnswer = finalAnswer+temp;
    }
        finalAnswer = finalAnswer.trimmed();

    if(finalAnswer == correctAnswer){

        qDebug()<< "yeeeeeeeeey";


    }
}

