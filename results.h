#ifndef RESULTS_H
#define RESULTS_H

#include <QDialog>

namespace Ui {
class results;
}

class results : public QDialog
{
    Q_OBJECT

public:
    explicit results(QWidget *parent = nullptr);
    ~results();

private slots:
    void on_pushButton_clicked();

private:
    Ui::results *ui;
};

#endif // RESULTS_H
