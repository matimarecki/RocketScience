//
// Created by maiszek on 29.05.23.
//

#ifndef UNTITLED1_ENGINE_H
#define UNTITLED1_ENGINE_H


class Engine {
private:
    int mass, max_burn, fuel_capacity;
public:
    explicit Engine(int Engine_Count) {
        this->mass = Engine_Count * 10;     // base mass
        this->max_burn = Engine_Count * 100;
        this->fuel_capacity = Engine_Count * 1000;
        this->mass += this->fuel_capacity;  // fuel mass
    }
    int getFuelCapacity() const {
        return fuel_capacity;
    }
    int getMaxBurn() const {
        return max_burn;
    }
    int getMass() const {
        return this->mass;
    }
};


#endif //UNTITLED1_ENGINE_H
