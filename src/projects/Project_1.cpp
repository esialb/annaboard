/*
 * Project_0.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: robin
 */

#include "../Annaboard.h"

class Project_1 {
public:
	Project_1() {
		annaboard->RegisterProject(1, "Project #1", &Setup, &Loop);
	}

	static void Setup() {
		annaboard->Gfx()->setCursor(0, 24);
		annaboard->Gfx()->print("You did it!");
		annaboard->Gfx()->display();
	}

	static void Loop() {

	}

};

Project_1 project_1;


