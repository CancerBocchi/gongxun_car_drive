#include "M_Car.h"

m_car M_Car_ob;

void M_Car_Init(m_car* M_Car_Typedef){
    Motor_ob_Init();
    M_Car_Typedef->M_motor1 = &Motor_1;
    M_Car_Typedef->M_motor2 = &Motor_2;
    M_Car_Typedef->M_motor3 = &Motor_3;
    M_Car_Typedef->M_motor4 = &Motor_4;

    M_Car_Typedef->speed_forward = 0;
    M_Car_Typedef->speed_omega   = 0;
    M_Car_Typedef->speed_sideway = 0;

}


float maxLinearSpeed = 1000;
void M_Car_Run(m_car* M_Car_Typedef)
{
    float speed1 = M_Car_Typedef->speed_forward - M_Car_Typedef->speed_sideway - M_Car_Typedef->speed_omega; 
    float speed2 = M_Car_Typedef->speed_forward + M_Car_Typedef->speed_sideway + M_Car_Typedef->speed_omega;
    float speed3 = M_Car_Typedef->speed_forward - M_Car_Typedef->speed_sideway + M_Car_Typedef->speed_omega;
    float speed4 = M_Car_Typedef->speed_forward + M_Car_Typedef->speed_sideway - M_Car_Typedef->speed_omega;

    float max = speed1;
    if (max < speed2)   max = speed2;
    if (max < speed3)   max = speed3;
    if (max < speed4)   max = speed4;
		
    if (max > maxLinearSpeed)
    {
        speed1 = speed1 / max * maxLinearSpeed;
        speed2 = speed2 / max * maxLinearSpeed;
        speed3 = speed3 / max * maxLinearSpeed;
        speed4 = speed4 / max * maxLinearSpeed;
    }
    // 1 4 为同侧轮子
    // 2 3 为同侧轮子
	__Motor_Chang_Speed(M_Car_Typedef->M_motor1,speed1);
    __Motor_Chang_Speed(M_Car_Typedef->M_motor2,-speed4);
    __Motor_Chang_Speed(M_Car_Typedef->M_motor3,-speed2);
    __Motor_Chang_Speed(M_Car_Typedef->M_motor4,speed3);

    Motor_Run(M_Car_Typedef->M_motor1);
    Motor_Run(M_Car_Typedef->M_motor2);
    Motor_Run(M_Car_Typedef->M_motor3);
    Motor_Run(M_Car_Typedef->M_motor4);
}
