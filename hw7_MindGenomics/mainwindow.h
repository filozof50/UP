#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QList>
#include <QVector>
#include <QDebug>
#include <algorithm>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeQuestions(int number);
    void uncheckButton (QRadioButton *button);
    void disableButton (QRadioButton *button);
    void findGroup ();
    void makeCoeff(double x, double y, double z);
    void changeVignette();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<QString> listOfQuestions;
    QList<QString> listOfAnswers;
    QVector<double> listOfGroups;
    QList<QString> listOfOffers;
    QMap<QString,QVector<double>> map;
    int number, group, numOfVignettes;
};

#endif // MAINWINDOW_H
