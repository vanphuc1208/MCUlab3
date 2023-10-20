/*
 * displayLed.c
 *
 *  Created on: Oct 20, 2023
 *      Author: OS
 */
#include "main.h"
#include "displayLed.h"

uint16_t ledPin[]= {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4,
		GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7
};
int idx=0;
void clearLed() {
	for(int i=0;i<8;i++) {
		HAL_GPIO_WritePin(GPIOA, ledPin[i], SET);
	}
}
void displayLed(void) {
	clearLed();
	for(int i=0;i<8;i++) {
		if(i==idx) {
			HAL_GPIO_WritePin(GPIOA, ledPin[i], RESET);
		}
		else {
			HAL_GPIO_WritePin(GPIOA, ledPin[i], SET);
		}
	}
	if(idx>=7) idx=0;
	else idx++;
}

