#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include "window.h"
#include "rocket.h"
#include "engine.h"
#include "second_window.h"

int main(int argc, char *argv[]) {
    printf("------Constant Acceleration------\n");
    auto e = Engine(4);
    auto r = Rocket(10000, &e, 10000);
    auto t = r.sameAccSimulation();
    printf("Time of best flight: %d s\n", t);
    printf("Fuel left: %d\n", r.getFuel());
    printf("Fuel percent left: %d%%\n", r.getFuelPercent());
    printf("------Constant Burn------\n");
    t = r.sameBurnSimulation();
    printf("Time of best flight: %d s\n", t);
    printf("Fuel left: %d\n", r.getFuel());
    printf("Fuel percent left: %d%%\n", r.getFuelPercent());
    printf("------Constant Speed------\n");
    t = r.sameSpeedSimulation();
    printf("Time of best flight: %d s\n", t);
    printf("Fuel left: %d\n", r.getFuel());
    printf("Fuel percent left: %d%%\n", r.getFuelPercent());
    // tests over

    QApplication app(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();
    SecondWindow swindow;
    swindow.hide();
    auto *window = new MainWindow(&swindow);
    window->show();        //working window object from custom window class
//    QWidget window;
//    window.setFixedSize(400, 200);

//    auto *progressBar = new QProgressBar(&window);
//    progressBar->setRange(0,100);
//    progressBar->setValue(10);
//    progressBar->setGeometry(10, 50, 100, 40);
//
//    auto *slider = new QSlider(&window);
//    slider->setOrientation(Qt::Horizontal);
//    slider->setRange(0,100);
//    slider->setValue(10);
//    slider->setGeometry(10, 90, 100, 40);
//    window.show();
//
//
//    QObject::connect(slider, SIGNAL(valueChanged(int)),
//                     progressBar, SLOT(setValue(int)));
    return QApplication::exec();
}
