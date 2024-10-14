#ifndef __M_CAR_H__
#define __M_CAR_H__

#include "headfile.h"

typedef struct M_CAR{

    // 电机对象
    motor *M_motor1;
    motor *M_motor2;
    motor *M_motor3;
    motor *M_motor4;

    // 速度参数
    int speed_forward;
    int speed_sideway;
    int speed_omega;

}m_car;

extern m_car M_Car_ob;

#define __M_CAR_CHANG_SPEED(__M_CAR__,__FORWARD__,__SIDEWAYS__,__OMEGA__) {__M_CAR__->speed_forward = __FORWARD__;__M_CAR__->speed_sideway = __SIDEWAYS__;__M_CAR__->speed_omega = __OMEGA__;}
                            

void M_Car_Run(m_car* M_Car_Typedef);
void M_Car_Init(m_car* M_Car_Typedef);

#endif // !__M_CAR_H__
