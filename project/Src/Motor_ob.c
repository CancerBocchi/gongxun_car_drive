/**
 * @file Motor_ob.c
 * @author Cancer (you@domain.com)
 * @brief   电机实例化，实例化了四个电机，用于验证电机库
 * 
 * @note    注意 由于电路连线上的失误，导致电机1，3的转向于定义的转向一致，电机2，4的转向与定义的转向相反，注意区分
 *          基于的电机操作库 速度为正，转向为 RIGHT，速度为负 转向为 LEFT；异常电机 2，4则相反
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Motor_ob.h"

//实例化电机对象
motor Motor_1;
motor Motor_2;
motor Motor_3;
motor Motor_4;

//电机对象的初始化
void Motor_ob_Init(){

//Motor1 Init
/////////////////////////////////////////////////////////////////
    Motor_1.set_DirLeft = Motor1_set_DirLeft;
    Motor_1.set_DirRight = Motor1_set_DirRight;
    Motor_1.pwm_tim = &htim5;
    Motor_1.encoder_tim = &htim2;
    Motor_1.pwm_channel = TIM_CHANNEL_3;
    Motor_1.TurnDir = M_TURN_RIGHT;

    Pos_PID_Init(&(Motor_1.Motor_PID),0.3f,0.05f,0);
    Motor_1.Motor_PID.Output_Max = 1.00f;
    Motor_1.Motor_PID.Output_Min = 0.00f;
    Motor_1.Motor_PID.Value_I_Max = 100.0f;

    Motor_Init(&Motor_1);
/////////////////////////////////////////////////////////////////

//Motor2 Init
/////////////////////////////////////////////////////////////////
    Motor_2.set_DirLeft = Motor2_set_DirLeft;
    Motor_2.set_DirRight = Motor2_set_DirRight;
    Motor_2.pwm_tim = &htim5;
    Motor_2.encoder_tim = &htim4;
    Motor_2.pwm_channel = TIM_CHANNEL_2;
    Motor_2.TurnDir = M_TURN_RIGHT;

    Pos_PID_Init(&(Motor_2.Motor_PID),0.3f,0.05f,0);
    Motor_2.Motor_PID.Output_Max = 1.00f;
    Motor_2.Motor_PID.Output_Min = 0.00f;
    Motor_2.Motor_PID.Value_I_Max = 100.0f;

    Motor_Init(&Motor_2);
/////////////////////////////////////////////////////////////////

//Motor3 Init
/////////////////////////////////////////////////////////////////
    Motor_3.set_DirLeft = Motor3_set_DirLeft;
    Motor_3.set_DirRight = Motor3_set_DirRight;
    Motor_3.pwm_tim = &htim5;
    Motor_3.encoder_tim = &htim1;
    Motor_3.pwm_channel = TIM_CHANNEL_1;
    Motor_3.TurnDir = M_TURN_RIGHT;

    Pos_PID_Init(&(Motor_3.Motor_PID),0.3f,0.05f,0);
    Motor_3.Motor_PID.Output_Max = 1.00f;
    Motor_3.Motor_PID.Output_Min = 0.00f;
    Motor_3.Motor_PID.Value_I_Max = 100.0f;

    Motor_Init(&Motor_3);
/////////////////////////////////////////////////////////////////

//Motor4 Init
/////////////////////////////////////////////////////////////////
    Motor_4.set_DirLeft = Motor4_set_DirLeft;
    Motor_4.set_DirRight = Motor4_set_DirRight;
    Motor_4.pwm_tim = &htim5;
    Motor_4.encoder_tim = &htim3;
    Motor_4.pwm_channel = TIM_CHANNEL_4;
    Motor_4.TurnDir = M_TURN_RIGHT;

    Pos_PID_Init(&(Motor_4.Motor_PID),0.3f,0.05f,0);
    Motor_4.Motor_PID.Output_Max = 1.00f;
    Motor_4.Motor_PID.Output_Min = 0.00f;
    Motor_4.Motor_PID.Value_I_Max = 100.0f;

    Motor_Init(&Motor_4);
/////////////////////////////////////////////////////////////////
}

/**
 * @brief 电机换向函数的实现
 * 
 */
//motor 1
void Motor1_set_DirLeft(){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
}

void Motor1_set_DirRight(){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
}


//motor2
void Motor2_set_DirLeft(){
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,0);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,1);
}

void Motor2_set_DirRight(){
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,1);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,0);
}


//motor3
void Motor3_set_DirLeft(){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,0);
}

void Motor3_set_DirRight(){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,1);
}


//motor4
void Motor4_set_DirLeft(){
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,0);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
}

void Motor4_set_DirRight(){
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,1);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
}