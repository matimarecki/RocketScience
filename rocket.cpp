//
// Created by maiszek on 29.05.23.
//

#include <cstdio>
#include "rocket.h"


int min(float a, float b) {
    if (a < b) {
        return (int)a;
    }
    return (int)b;
}

int Rocket::sameAccSimulation() {
    // Keep a constant acceleration throughout the whole flight (or until fuel runs out)
    this->mass = this->s_mass;
    this->fuel = this->engines->getFuelCapacity();
    this->height = 0;
    this->speed = 0;
    int s_accel;
    int burn, accel;
    burn = this->engines->getMaxBurn();
    accel = burn*1000/mass - 10;         // arbitrary *1000, could be any number
    s_accel = accel;
    int b_fuel, b_accel, b_time;
    b_fuel = 0;
    b_accel = -1;
    b_time = -1;
    int time;
    while (true) {
        // different simulation loop
        if (accel < 0) {
            break;
        }
        time = 0;
        while (true) {
            if (height >= t_height) {
                if (b_fuel < fuel) {
                    b_accel = s_accel;
                    b_time = time;
                }
                break;
            }
            if (speed < 0) {
//                printf("Simulation unsuccesfuk \n");
                break;
            }
            // done with ending ifs, now to simulate the flight
            height += speed + accel/2;
            speed += accel;
            mass -= burn;
            fuel -= burn;
            burn = min(((float)accel+10)*(float)mass/1000, (float)fuel);
            accel = burn*1000/mass - 10;
            time += 1;
        }
        this->mass = this->s_mass;
        this->fuel = this->engines->getFuelCapacity();
        this->height = 0;
        this->speed = 0;
        s_accel -= 1;
        accel = s_accel;
        burn = ((accel+10)*mass)/1000;
    }
    accel = b_accel;
    burn = ((accel+10)*mass)/1000;
//    Best simulation, to then have correct height, speed and fuel to display
    while (true) {
        if (height >= t_height) {
            break;
        }
        if (speed < 0) {
            break;
        }
        height += speed + accel/2;
        speed += accel;
        mass -= burn;
        fuel -= burn;
        burn = min(((float)accel+10)*(float)mass/1000, (float)fuel);
        accel = burn*1000/mass - 10;
        time += 1;
    }
    return b_time;
}

int Rocket::sameBurnSimulation() {
    // Keep the same Burn throughout the whole flight (or until fuel runs out)
    this->mass = this->s_mass;
    this->fuel = this->engines->getFuelCapacity();
    this->height = 0;
    this->speed = 0;
    int s_burn;
    int burn, accel;
    burn = this->engines->getMaxBurn();
    accel = burn*1000/mass - 10;         // arbitrary *1000, could be any number
    s_burn = burn;
    int b_fuel, b_burn, b_time;
    b_fuel = 0;
    b_burn = 0;
    b_time = -1;
    int time;
    while (true) {
        if (accel < 0) {
            break;
        }
        time = 0;
        while (true) {
            if (height >= t_height) {
                if (b_fuel < fuel) {
                    b_burn = s_burn;
                    b_time = time;
                }
                break;
            }
            if (speed < 0) {
//                printf("Simulation unsuccesfuk \n");
                break;
            }
            // done with ending ifs, now to simulate the flight
            height += speed + accel/2;
            speed += accel;
            mass -= burn;
            fuel -= burn;
            burn = min((float) burn, (float)fuel);
            accel = burn*1000/mass - 10;
            time += 1;
        }
        this->mass = this->s_mass;
        this->fuel = this->engines->getFuelCapacity();
        this->height = 0;
        this->speed = 0;
        s_burn -= 1;
        burn = s_burn;
        accel = burn*1000/mass - 10;
    }
    burn = b_burn;
    accel = burn*1000/mass - 10;
    while (true) {
        if (height >= t_height) {
            break;
        }
        if (speed < 0) {
            break;
        }
        // done with ending ifs, now to simulate the flight
        height += speed + accel/2;
        speed += accel;
        mass -= burn;
        fuel -= burn;
        burn = min((float) burn, (float)fuel);
        accel = burn*1000/mass - 10;
        time += 1;
    }
    return b_time;
}

int Rocket::sameSpeedSimulation() {
    // reach target Speed, then keep it until end of flight (or until fuel runs out at any point)
    this->mass = this->s_mass;
    this->fuel = this->engines->getFuelCapacity();
    this->height = 0;
    this->speed = 0;
    int s_velocity;
    int burn, accel;
    burn = this->engines->getMaxBurn();
    accel = burn*1000/mass - 10;         // arbitrary *1000, could be any number
    s_velocity = accel*20;
    int b_fuel, b_velocity, b_time;
    b_fuel = 0;
    b_velocity = -1;
    b_time = -1;
    int time;
    while (true) {
        if (accel < 0) {
            break;
        }
        time = 0;
        while (true) {
            if (height >= t_height) {
                if (b_fuel < fuel) {
                    b_velocity = s_velocity;
                    b_time = time;
                }
                break;
            }
            if (speed < 0) {
//                printf("Simulation unsuccesfuk \n");
                break;
            }
            // done with ending ifs, now to simulate the flight
            if (speed < s_velocity) {
                height += speed + accel/2;
                speed += accel;
                mass -= burn;
                fuel -= burn;
                burn = min((float) burn, (float)fuel);
                accel = burn*1000/mass - 10;
                time += 1;
            }
            else {
                height += speed + accel/2;
                speed += accel;
                mass -= burn;
                fuel -= burn;
                accel = 0;
                burn = mass/100;
                time += 1;
            }
        }
        s_velocity -= 5;
        this->mass = this->s_mass;
        this->fuel = this->engines->getFuelCapacity();
        this->height = 0;
        this->speed = 0;
        accel = burn*1000/mass - 10;
    }
    s_velocity = b_velocity;
    burn = this->engines->getMaxBurn();
    accel = burn*1000/mass - 10;
    while (true) {
        if (height >= t_height) {
            break;
        }
        if (speed < 0) {
//                printf("Simulation unsuccesfuk \n");
            break;
        }
        // done with ending ifs, now to simulate the flight
        if (speed < s_velocity) {
            height += speed + accel/2;
            speed += accel;
            mass -= burn;
            fuel -= burn;
            burn = min((float) burn, (float)fuel);
            accel = burn*1000/mass - 10;
            time += 1;
        }
        else {
            height += speed + accel/2;
            speed += accel;
            mass -= burn;
            fuel -= burn;
            accel = 0;
            burn = mass/100;
            time += 1;
        }
    }
    return b_time;
}