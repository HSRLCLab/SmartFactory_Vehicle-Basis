/**
 * @file Hoist.cpp
 * @brief Implementation of the Hoist-Class
 * 
 * The hoist module consists of a lifting mechanism powered by a servo motor.
 * 
 * @author Luca Mazzoleni (luca.mazzoleni@hsr.ch)
 * @author Glenn Huber (glenn.patrick.huber@hsr.ch)
 * @author Robert Paly (robert.paly@hsr.ch)
 * 
 * @version 1.0 - Refactored to match FSM Funccall  - Luca Mazzoleni (luca.mazzoleni@hsr.ch)  - 2019-04-23
 * @version 0.0 - BA FTS FS 2018
 * 
 * @date 2019-03-20
 * @copyright Copyright (c) 2019
 * 
 */

#include "Hoist.h"

//=====PUBLIC====================================================================================
Hoist::Hoist(int hoistServoPin, int hoistServoDelay, int posMax, int posMin) : servoPin(hoistServoPin),
                                                                               position(posMin),
                                                                               positionMin(posMin),
                                                                               positionMax(posMax),
                                                                               servoDelay(hoistServoDelay) {
    DBFUNCCALLln("Hoist::Hoist(int hoistServoPin, int hoistServoDelay, int posMax, int posMin)");
    Hoist::init();
}

/*
 * hoistServo.read() only reads the current angle of the servo (the value passed to the LAST call to write()).
 */
void Hoist::init() {
    Hoist::attach();
    position -= 5;  //lift the hoist some degree so that the lower-function works correctly
    while (!lower()) {
    }
    Hoist::detach();
}

bool Hoist::raise() {
    DBFUNCCALLln("Hoist::raise()");
    currentMillis = millis();
    if ((currentMillis - previousMillis) > servoDelay) {
        previousMillis = currentMillis;
        if (position > positionMax) {
            position--;
            hoistServo.write(position);  //< Update Servo-position
        }
    }
    if (position == positionMax) {
        DBSTATUSln("Hoist raised!");
        return true;
    }
    return false;
}

bool Hoist::lower() {
    DBFUNCCALLln("Hoist::lower()");
    currentMillis = millis();
    if ((currentMillis - previousMillis) > servoDelay) {
        previousMillis = currentMillis;
        if (position < positionMin) {
            position++;
            hoistServo.write(position);
        }
    }
    if (position == positionMin) {
        DBSTATUSln("Hoist lowered!");
        return true;
    }
    return false;
}

//=====PRIVATE====================================================================================