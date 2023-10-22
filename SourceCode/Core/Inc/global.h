/*
 * global.h
 *
 *  Created on: Oct 22, 2023
 *      Author: OS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include"input_reading.h"
#include"software_timer.h"
#include"displayLed.h"

#define INIT 0

#define normalRed1  1
#define normalYellow1  2
#define normalGreen1  3

#define normalRed2  4
#define normalYellow2  5
#define normalGreen2  6


extern int timeRed;
extern int timeYellow;
extern int timeGreen;
extern int status1;
extern int status2;

#endif /* INC_GLOBAL_H_ */
