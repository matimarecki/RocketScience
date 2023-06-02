//
// Created by maiszek on 30.05.23.
//

#include <QTableWidget>
#include <QPushButton>
#include <QStringList>
#include <QString>
#include <QApplication>
#include "second_window.h"
#include "window.h"
#include "rocket.h"

SecondWindow::SecondWindow(QWidget *parent) {
    setFixedSize(450,300);
    setWindowTitle("Astronaut!");

    parent_window = parent;
//    this->setVisible(false);

    result_table = new QTableWidget(3, 3, this);
    QStringList cols = {"Constant Acc.", "Constant Burn", "Constant Speed"};
    QStringList rows = {"Time of Flight", "Fuel Burned", "Fuel % remaining"};
    result_table->setHorizontalHeaderLabels(cols);
    result_table->setVerticalHeaderLabels(rows);
    result_table->setGeometry(10, 10, 411, 180);
    for (int row = 0; row < 3; row ++) {
        for (int col = 0; col < 3; col++) {
            auto *yakutsk = new QTableWidgetItem();
            result_table->setItem(row, col, yakutsk);
        }
    }
    result_table->itemAt(0,0)->setText("Bruh");

    button_close = new QPushButton("Close",this);
    button_close->setGeometry(380, 260, 60, 30);

    button_return = new QPushButton("Return", this);
    button_return->setGeometry(310, 260, 60, 30);

    connect(button_close, SIGNAL(pressed()),
            QApplication::instance(), SLOT(quit()));
    connect(button_return, SIGNAL(pressed()),
            this, SLOT(returnToParent()));
}


void SecondWindow::updateValues(Rocket *r) {
    auto t = r->sameAccSimulation();
//    printf("I'm done");
    if (t == -1) {
        result_table->item(0, 0)->setText("NOT REACHED");
        result_table->item(1, 0)->setText("");
        result_table->item(2, 0)->setText("");
    }
    else {
        result_table->item(0, 0)->setText(QString("%1 s").arg(t));
        result_table->item(1, 0)->setText(QString::number(r->getFuelBurned()));
        result_table->item(2, 0)->setText(QString("%1 %").arg(r->getFuelPercent()));
    }

    t = r->sameBurnSimulation();
    if (t == -1) {
        result_table->item(0, 1)->setText("NOT REACHED");
        result_table->item(1, 1)->setText("");
        result_table->item(2, 1)->setText("");
    }
    else {
        result_table->item(0, 1)->setText(QString("%1 s").arg(t));
        result_table->item(1, 1)->setText(QString::number(r->getFuelBurned()));
        result_table->item(2, 1)->setText(QString("%1 %").arg(r->getFuelPercent()));
    }

    t = r->sameSpeedSimulation();
    if (t == -1) {
        result_table->item(0, 2)->setText("NOT REACHED");
        result_table->item(1, 2)->setText("");
        result_table->item(2, 2)->setText("");
    }
    else {
        result_table->item(0, 2)->setText(QString("%1 s").arg(t));
        result_table->item(1, 2)->setText(QString::number(r->getFuelBurned()));
        result_table->item(2, 2)->setText(QString("%1 %").arg(r->getFuelPercent()));
    }
//    result_table->item(0, 2)->setText(QString::number(t));
//    result_table->item(1, 2)->setText(QString::number(r->getFuelBurned()));
//    result_table->item(2, 2)->setText(QString("%1 %").arg(r->getFuelPercent()));
}

void SecondWindow::showWindow(QWidget *newparent) {
    this->show();
    parent_window = newparent;
}
void SecondWindow::returnToParent() {
    this->hide();
    parent_window->show();
}