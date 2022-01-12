#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "results.h"
#include <QMessageBox>
#include <cmath>


int Norma = 0;

extern QString R0_result;
extern QString Norma_result;
extern QString Long_Max_result;
extern QString Long_result;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
if((ui->lineEdit->text().isEmpty())||(ui->lineEdit_2->text().isEmpty())||(ui->lineEdit_3->text().isEmpty())||(ui->lineEdit_4->text().isEmpty())||(ui->lineEdit_5->text().isEmpty())||(ui->lineEdit_6->text().isEmpty())){

    QMessageBox::warning(this, "Ошибка ввода данных", "Пожалуйста введите исходные данные!");//Проверка на наличие ввода исходных данных

}else{
    double Oslablenie = (ui->lineEdit->text()).toDouble();
    double Moshnost = (ui->lineEdit_2->text()).toDouble();
    double dlinna_volni = (ui->lineEdit_3->text()).toDouble();
    double appertura_vert = (ui->lineEdit_4->text()).toDouble();
    double appertura_goriz = (ui->lineEdit_5->text()).toDouble();
    double shirina_dn = (ui->lineEdit_6->text()).toDouble();

    double R0,Gk,Long_Max, Long;

    R0 = (2*(appertura_vert*appertura_vert))/dlinna_volni;
    Gk = (37.68*appertura_vert*appertura_goriz*0.525)/(dlinna_volni*dlinna_volni);
    Long_Max = sqrt((8*Moshnost*Gk)/Norma);
    Long = (Long_Max/2)*(pow(10,((-1*Oslablenie)/20)));

    R0_result = QString::number(R0,'g',8);
    Norma_result = QString::number(Norma);
    Long_Max_result = QString::number(Long_Max,'g',8);
    Long_result = QString::number(Long,'g',8);


    if(Norma == 0){ //Проверка на то, что выбран тип РЛС
        QMessageBox::warning(this, "Ошибка ввода данных", "Пожалуйста введите тип РЛС!");
    }else{

        results *r = new results;
        r.setWindowTitle("Результаты расчета");
        r->show();

    }
}
}

void MainWindow::on_pushButton_typeRLS_clicked()
{
    if (ui->Secktor->isChecked()){
        Norma = 10;
        ui->statusbar->showMessage("Рассчет производиться для РЛС секторного обзора");
    }else if (ui->Krug->isChecked()){
        Norma = 25;
        ui->statusbar->showMessage("Рассчет производиться для РЛС кругового обзора");
    }else {
        QMessageBox::warning(this, "Ошибка ввода данных", "Пожалуйста введите тип РЛС!");
    }
}

void MainWindow::on_AboutQT_triggered()
{
    QMessageBox::aboutQt(this, "О программе QT");
}

void MainWindow::on_AboutMe_triggered()
{
    QMessageBox::about(this, "О создателе", "Приложение создано Емельяновым Кириллом Викторовичем в личных целях.");
}

void MainWindow::on_Metodika_triggered()
{
    QMessageBox::about(this, "Методика расчета", " Расчеты произведены в соответствии с: Методические указания по определению и гигиенической регламентации электромагнитных полей,  создаваемых береговыми и судовыми радиолокационными станциями. Утвержденными заместителем Главного государственного врача СССР А.И.Заиченко 2 марта 1987 года № 4258-87");
}

