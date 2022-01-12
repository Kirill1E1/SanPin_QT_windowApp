#include "results.h"
#include "ui_results.h"
#include "mainwindow.h"

extern QString R0_result;
extern QString Norma_result;
extern QString Long_Max_result;
extern QString Long_result;

results::results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::results)
{
   ui->setupUi(this);

   ui->label_udalenie->setText(R0_result);
   ui->label_PPE->setText(Norma_result);
   ui->label_LongMax->setText(Long_Max_result);
   ui->label_Long->setText(Long_result);

}

results::~results()
{
    delete ui;
}



void results::on_pushButton_clicked()
{
    QWidget::close();
}
