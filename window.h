//
// Created by maiszek on 29.05.23.
//

#ifndef UNTITLED1_WINDOW_H
#define UNTITLED1_WINDOW_H


#include <QWidget>
#include "second_window.h"
class QPushButton;
class QLineEdit;
class QSlider;
class QLabel;
//class Window : public QWidget     class #1
//{
//public:
//    explicit Window(QWidget *parent = 0);
//private:
//    QPushButton *m_button;
//};

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow (SecondWindow *child, QWidget *parent = nullptr);
    signals:
private slots:
    void launchRocket();
//    void counterReached();
    void sliderValueChanged(int newVal);
//    void slotButtonClicked(bool checked);
//    void showThySelf();
private:
    QPushButton *close_button, *launch_button;
    QLineEdit *payload_line, *target_line;
    QSlider *engine_count;
    QLabel *engine_label_d, *payload_label_d, *target_label_d, *engine_label_c;
    SecondWindow *child_w;

};

#endif //UNTITLED1_WINDOW_H
