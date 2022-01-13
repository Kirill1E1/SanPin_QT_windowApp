#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Secktor_clicked(bool checked);

    void on_pushButton_typeRLS_clicked();

    void on_AboutQT_triggered();

    void on_AboutMe_triggered();

    void on_Metodika_triggered();

    void on_Dannie_triggered();

    void on_Secktor_clicked();

    void on_Krug_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
