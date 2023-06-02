//
// Created by maiszek on 29.05.23.
//

#include "window.h"
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include "engine.h"
#include "rocket.h"
//Window::Window(QWidget *parent) : QWidget(parent) {       class #1
//    setFixedSize(400, 200);
//    m_button = new QPushButton("Heeellooo babyyyyy", this);
//    m_button->setGeometry(10, 10, 100, 40);
//    connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
//}

MainWindow::MainWindow(SecondWindow *child, QWidget *parent) {
    setFixedSize(400,300);
    setWindowTitle("This isn't science rocket!");
    child_w = child;

    engine_count = new QSlider(this);
    engine_count->setOrientation(Qt::Horizontal);
    engine_count->setTickInterval(1);
    engine_count->setValue(4);
    engine_count->setRange(1,20);
    engine_count->setGeometry(10, 10, 120, 30);

    engine_label_c = new QLabel(this);
    engine_label_c->setText(QString::number(engine_count->value()));
    engine_label_c->setGeometry(140, 10, 60, 30);

    engine_label_d = new QLabel(this);
    engine_label_d->setText("Number of Engines on Rocket");
    engine_label_d->setGeometry(190, 10, 200, 30);

    payload_line = new QLineEdit(this);
    payload_line->setPlaceholderText("Payload Weight");
    payload_line->setFocus();
    payload_line->setValidator(new QIntValidator(0,200000,payload_line));
    payload_line->setGeometry(10, 50, 120, 30);

    payload_label_d = new QLabel(this);
    payload_label_d->setText("Mass of Payload of Rocket");
    payload_label_d->setGeometry(190, 50, 200, 30);

    target_line = new QLineEdit(this);
    target_line->setPlaceholderText("Target Height");
    target_line->setValidator(new QIntValidator(0, 100000, target_line));
    target_line->setGeometry(10, 90, 120, 30);

    target_label_d = new QLabel(this);
    target_label_d->setText("Target Height for Rocket");
    target_label_d->setGeometry(190, 90, 200, 30);

    launch_button = new QPushButton("Launch!", this);
    launch_button->setGeometry(260, 260, 60, 30);

    close_button = new QPushButton("Close", this);
    close_button->setGeometry(330, 260, 60, 30);

//    connect(this, SIGNAL(counterReached()),
//            QApplication::instance(), SLOT(quit()));
    connect(engine_count, SIGNAL(valueChanged(int)),
            this, SLOT(sliderValueChanged(int)));
    connect(close_button, SIGNAL(pressed()),
            QApplication::instance(), SLOT(quit()));
    connect(launch_button, SIGNAL(pressed()),
            this, SLOT(launchRocket()));

}

void MainWindow::sliderValueChanged(int newVal) {
    engine_label_c->setText(QString::number(newVal));
}

void MainWindow::launchRocket() {
    if (payload_line->text().length() == 0 || target_line->text().length() == 0){
        printf("Not enough values! \n");
        return;
    }
    int payload, height, engines;
    payload = payload_line->text().toInt();
    height = target_line->text().toInt();
    engines = engine_count->value();
    auto engine = Engine(engines);
    auto rocket = Rocket(payload, &engine, height);
    child_w->updateValues(&rocket);
    child_w->showWindow(this);
    this->hide();
}

//void MainWindow::slotButtonClicked(bool checked) {
//    if (checked) {
//        m_button->setText("Checked!");
//    }
//    else {
//        m_button->setText("Unchecked!");
//    }
//    m_counter ++;
//    if(m_counter >= 10) {
//        emit counterReached();
//    }
//}
