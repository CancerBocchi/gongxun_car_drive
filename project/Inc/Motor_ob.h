
#ifndef __MOTOR_OB_H__
#define __MOTOR_OB_H__

#include "Motor.h"


extern motor Motor_1;
extern motor Motor_2;
extern motor Motor_3;
extern motor Motor_4;

void Motor_ob_Init();

void Motor1_set_DirLeft();
void Motor1_set_DirRight();
void Motor2_set_DirLeft();
void Motor2_set_DirRight();
void Motor3_set_DirLeft();
void Motor3_set_DirRight();
void Motor4_set_DirLeft();
void Motor4_set_DirRight();

#endif // !__MOTOR_OB_H__