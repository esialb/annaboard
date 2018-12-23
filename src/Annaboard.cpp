/*
 * Annaboard.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: robin
 */

#include <Annaboard.h>
#include <Wire.h>

Annaboard annaboard_;
Annaboard* annaboard = &annaboard_;

Annaboard::Annaboard() {
	project_number_ = 0;
	gfx_ = new Adafruit_SSD1306(128, 64, &Wire1);
	project_ = nullptr;
}

Annaboard::~Annaboard() {
	delete gfx_;
}

void Annaboard::Setup() {
	project_number_ = 0;
	for (int pin = 53; pin >= 46; --pin) {
		pinMode(pin, INPUT_PULLUP);
		project_number_ <<= 1;
		project_number_ |= (digitalRead(pin) == LOW) ? 1 : 0;
	}
	if (projects_[project_number_].exists_) {
		project_ = &projects_[project_number_];
	}

	gfx_->begin(SSD1306_SWITCHCAPVCC, 0x3C);
	gfx_->clearDisplay();
	gfx_->setTextColor(WHITE, BLACK);
	gfx_->setCursor(0, 56);
	gfx_->print("Project: ");
	for (int8_t bit = 7; bit >= 0; --bit) {
		gfx_->print((project_number_ & (1<<bit)) ? "1" : "0");
	}
	gfx_->print("=");
	gfx_->print(project_number_);

	gfx_->setCursor(0, 0);
	gfx_->setTextSize(2);
	if (project_) {
		gfx_->print(project_->name_);
	} else {
		gfx_->print("No Project");
	}
	gfx_->display();

	gfx_->setTextSize(0);
	gfx_->setCursor(0, 0);

	if (project_) project_->Setup();
}

void Annaboard::Loop() {
	if (project_) project_->Loop();
}

void Annaboard::RegisterProject(uint8_t n, const char* name, void (*setup)(), void (*loop)()) {
	Project* p = &projects_[n];
	p->exists_ = true;
	p->name_ = name;
	p->Setup = setup;
	p->Loop = loop;
}
