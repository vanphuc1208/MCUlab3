/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2023
 *      Author: OS
 */


#include "main.h"
#include "input_reading.h"
#include "displayLed.h"
#include "software_timer.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;
void fsm_for_input_processing(void){
	switch(buttonState){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			buttonState = BUTTON_PRESSED;
			//INCREASE VALUE OF PORT A BY ONE UNIT
			displayLed();
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(0)){
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				setTimer1(50);
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		}
		if(timer1_flag==1) {
			displayLed();
			setTimer1(50);
		}
		break;
	}
}
