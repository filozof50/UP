#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listOfAnswers = {"No, I don't have employees.", "No, I clean by myself.",
                     "Yes, I have part time employees who only clean.",
                     "Yes, my employees clean besides their primary job.",
                     "I don't have enough time for cleaning.", "So I can do some other stuff when I am home.",
                     "For cleaning bigger space.", "To help my employees and make them more productive."};

    listOfQuestions = {"Do you have an employee who's part of work is cleaning?", "What is your reason to buy SRHC?"};

    listOfOffers = {"Special offer!\n\nFeel tired?\nWant to have some fun and rest?\n\nVisit \"Vila Mijic\" on Zlatibor.\n"
                    "We guarantee a good rest and fun.\n\nCall us on +381 31 594 869 or +381 64 795 965 3.\n\nSee you! :)",
                    "Special offer!\n\nWork all the time? Don't have time for yourself?\n\nTake a break!\n\nWe offer you"
                    " the best list of good restaurants all over the world.\n\nDifferent cuisines, music, special evenings.\n\n"
                    "Visit us at www.bestworldrestaurnats.com",
                    "Special offer!\n\n* Buy one SRHC you get second by 50% discount!\n\n"
                    "* Buy two SRHC you get third by 75% discount!\n\n"
                    "* Buy three SRHC you get fourth totally free!"
                    };

    map.insert("Not going to work, cleaning a lot.", {0.925, 0, 0.075});
    map.insert("1 or 2 days pre week on work, cleaning pretty much.", {0.84, 0.025, 0.135});
    map.insert("5 days on work, not so much cleaning.", {0.015, 0.8, 0.185});
    map.insert("6-7 days on work, not much time for cleaning.", {0, 0.925, 0.075});
    map.insert("No, I don't have employees.", {0.73, 0.27, 0});
    map.insert("No, I clean by myself.", {0.77, 0.23, 0});
    map.insert("Yes, I have part time employees who only clean.", {0.05, 0.23, 0.72});
    map.insert("Yes, my employees clean besides their primary job.", {0, 0.01, 0.99});
    map.insert("I don't have enough time for cleaning.", {0.046, 0.954, 0});
    map.insert("So I can do some other stuff when I am home.", {0.175, 0.812, 0.013});
    map.insert("For cleaning bigger space.", {0.062, 0.034, 0.904});
    map.insert("To help my employees and make them more productive.", {0.016, 0.076, 0.908});


    listOfGroups={0,0,0};

    number = 1;
    numOfVignettes = 3;
    ui->lineEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s;
    QVector<double> pom;
    if (ui->radioButton->isChecked()) {
        s = ui->radioButton->text();
        pom = map[s];
        makeCoeff(pom[0], pom[1], pom[2]);
        changeVignette();
    }
    else if (ui->radioButton_2->isChecked()) {
        s = ui->radioButton_2->text();
        pom = map[s];
        makeCoeff(pom[0], pom[1], pom[2]);
        changeVignette();
    }
    else if (ui->radioButton_3->isChecked()) {
        s = ui->radioButton_3->text();
        pom = map[s];
        makeCoeff(pom[0], pom[1], pom[2]);
        changeVignette();
    }
    else if (ui->radioButton_4->isChecked()) {
        s = ui->radioButton_4->text();
        pom = map[s];
        makeCoeff(pom[0], pom[1], pom[2]);
        changeVignette();
    }
    else {
        QMessageBox::information(this,"Notification", "You have to choose one of the answers!");
    }
}

void MainWindow::changeQuestions(int number)
{
    number == 2 ? ui->radioButton->setText(listOfAnswers.at(0)) : ui->radioButton->setText(listOfAnswers.at(4));

    number == 2 ? ui->radioButton_2->setText(listOfAnswers.at(1)) : ui->radioButton_2->setText(listOfAnswers.at(5));

    number == 2 ? ui->radioButton_3->setText(listOfAnswers.at(2)) : ui->radioButton_3->setText(listOfAnswers.at(6));

    number == 2 ? ui->radioButton_4->setText(listOfAnswers.at(3)) : ui->radioButton_4->setText(listOfAnswers.at(7));

    number == 2 ? ui->lineEdit->setText(listOfQuestions.at(0)) : ui->lineEdit->setText(listOfQuestions.at(1));

    uncheckButton(ui->radioButton);

    uncheckButton(ui->radioButton_2);

    uncheckButton(ui->radioButton_3);

    uncheckButton(ui->radioButton_4);

    if (number == 4) {
        disableButton(ui->radioButton);
        disableButton(ui->radioButton_2);
        disableButton(ui->radioButton_3);
        uncheckButton(ui->radioButton_4);
        ui->pushButton->setDisabled(true);
        findGroup();
        QMessageBox::information(this,"Offer", listOfOffers.at(group));
    }
}

void MainWindow::uncheckButton (QRadioButton *button)
{
    button->setAutoExclusive(false);
    button->setChecked(false);
    button->setAutoExclusive(true);
}

void MainWindow::disableButton (QRadioButton *button) {
    button->setCheckable(false);
}

void MainWindow::findGroup ()
{
    double probability1, probability2, probability3;

    probability1 = listOfGroups[0] / numOfVignettes;

    probability2 = listOfGroups[1] / numOfVignettes;

    probability3 = listOfGroups[2] / numOfVignettes;

    double max = *std::max_element(listOfGroups.begin(), listOfGroups.end());
    max /= 3;

    if (probability1 == max)
        group = 0;
    else if (probability3 == max)
        group = 2;
    else
        group = 1;
}

void MainWindow::makeCoeff(double x, double y, double z)
{
    listOfGroups[0] += x;
    listOfGroups[1] += y;
    listOfGroups[2] += z;
}

void MainWindow::changeVignette()
{
    number+=1;
    changeQuestions(number);
}
