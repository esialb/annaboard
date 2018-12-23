/*
 * main.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: robin
 */

#include <Arduino.h>

#include "Annaboard.h"

void setup() {
	annaboard->Setup();
}

void loop() {
	annaboard->Loop();
}


