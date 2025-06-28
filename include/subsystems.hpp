#pragma once

#include "EZ-Template/api.hpp"
#include "EZ-Template/piston.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');


// Pneumatics
inline ez::Piston extender('A');
inline ez::Piston scraper('B');
inline pros::Motor intake_S1(10);
inline pros::Motor intake_S2(11);