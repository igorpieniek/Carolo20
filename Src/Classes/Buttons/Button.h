/*
 * Button.h
 *
 *  Created on: 03.01.2020
 *      Author: Igor
 */

#ifndef CLASSES_BUTTON_H_
#define CLASSES_BUTTON_H_

#include "main.h"

class Button {
private:
	uint8_t status;
	uint8_t everActivated;

	GPIO_TypeDef* gpio_port;
	uint16_t gpio_pin;
public:
	uint8_t check();
	uint8_t isEverActivated();
	void reset();
	uint8_t getStatus();
	Button(GPIO_TypeDef* gpio_port, uint16_t gpio_pin);
	virtual ~Button();
};

#endif /* CLASSES_BUTTON_H_ */
