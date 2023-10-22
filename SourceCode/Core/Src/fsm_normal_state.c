/*
 * fsm_normal_state.c
 *
 *  Created on: Oct 22, 2023
 *      Author: OS
 */

#include "global.h"
#include "fsm_normal_state.h"

void normalState1(void) {
	switch(status1) {
	case INIT:
		clearAllLed();
		status1=normalRed1;
		setTimer1(timeRed*100);
		break;
	case normalRed1:
		displayRed1();
		if(timer1_flag==1) {
			status1=normalGreen1;
			setTimer1(timeGreen*100);
		}
		break;
	case normalYellow1:
		displayYellow1();
		if(timer1_flag==1) {
			status1=normalRed1;
			setTimer1(timeRed*100);
		}
		break;
	case normalGreen1:
		displayGreen1();
		if(timer1_flag==1) {
			status1=normalYellow1;
			setTimer1(timeYellow*100);
		}
		break;
	default:
		break;
	}
}

void normalState2(void) {
	switch(status2) {
	case INIT:
		clearAllLed();
		status2=normalGreen2;
		setTimer2(timeGreen*100);
		break;
	case normalRed2:
		displayRed2();
		if(timer2_flag==1) {
			status2=normalGreen2;
			setTimer2(timeGreen*100);
		}
		break;
	case normalYellow2:
		displayYellow2();
		if(timer2_flag==1) {
			status2=normalRed2;
			setTimer2(timeRed*100);
		}
		break;
	case normalGreen2:
		displayGreen2();
		if(timer2_flag==1) {
			status2=normalYellow2;
			setTimer2(timeYellow*100);
		}
		break;
	default:
		break;
	}
}
