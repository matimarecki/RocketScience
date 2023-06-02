//
// Created by maiszek on 30.05.23.
//

#ifndef UNTITLED1_SECOND_WINDOW_H
#define UNTITLED1_SECOND_WINDOW_H
#include <QWidget>
#include "rocket.h"

class QPushButton;
class QLabel;
class QTableWidget;

class SecondWindow : public QWidget {
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    void updateValues(Rocket *r);
    void showWindow(QWidget *newparent);
private slots:
    void returnToParent();
private:
    QTableWidget *result_table;
    QPushButton *button_return, *button_close;
    QWidget *parent_window;
};


#endif //UNTITLED1_SECOND_WINDOW_H
