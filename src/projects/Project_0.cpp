/*
 * Project_0.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: robin
 */

#include "../Annaboard.h"

class Project_0 {
public:
	Project_0() {
		annaboard->RegisterProject(0, "Welcome!", &Setup, &Loop);
	}

	static void Setup() {
		annaboard->Gfx()->setCursor(0, 24);
		annaboard->Gfx()->print("Try project 1.\n");
		annaboard->Gfx()->print("You can do it!");
		annaboard->Gfx()->display();
	}

	static void Loop() {

	}

};

Project_0 project_0;


