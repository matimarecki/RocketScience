//
// Created by maiszek on 29.05.23.
//

#ifndef UNTITLED1_ROCKET_H
#define UNTITLED1_ROCKET_H

#include "engine.h"

class Rocket {
private:
    int s_mass, t_height;
    int mass, fuel, speed, height;
    Engine* engines;
public:
    explicit Rocket(int payload_mass, Engine* engine, int target_height) {
        engines = engine;
        this->s_mass = payload_mass + engine->getMass();
        this->mass = this->s_mass;
        this->fuel = this->engines->getFuelCapacity();
        this->t_height = target_height;
        this->height = 0;
        this->speed = 0;
    }
    int getMass () const {
        return mass;
    }
    int getFuel () const {
        return fuel;
    }
    int getFuelBurned () const {
        return this->engines->getFuelCapacity() - fuel;
    }
    int getFuelPercent() const {
        return (int) (fuel*100/this->engines->getFuelCapacity());
    }
    int getSpeed() const {
        return speed;
    }
    int getHeight() const {
        return height;
    }
    int sameAccSimulation();
    int sameBurnSimulation();
    int sameSpeedSimulation();
};


#endif //UNTITLED1_ROCKET_H
