/*
 * Annaboard.h
 *
 *  Created on: Dec 23, 2018
 *      Author: robin
 */

#ifndef SRC_ANNABOARD_H_
#define SRC_ANNABOARD_H_

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class Annaboard {
public:
	struct Project {
		bool exists_ = false;
		const char* name_ = nullptr;
		void (*Setup)() = nullptr;
		void (*Loop)() = nullptr;
	};

	Annaboard();
	virtual ~Annaboard();

	void Setup();
	void Loop();

	uint8_t ProjectNumber() { return project_number_; }

	void RegisterProject(uint8_t n, const char* name, void (*setup)(), void (*loop)());

	Adafruit_SSD1306* Gfx() { return gfx_; }

private:

	uint8_t project_number_;
	Adafruit_SSD1306* gfx_;

	Project projects_[256];
	Project* project_;
};


extern Annaboard* annaboard;

#endif /* SRC_ANNABOARD_H_ */
