#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "headfile.h"

#define M_TURN_RIGHT 1
#define M_TURN_LEFT  0

typedef struct MOTOR{
    Pos_PID_t Motor_PID;
    //转速
    int tar_speed;
    int cur_speed;
    int last_speed;
    //计算速度
    int last_count;
    int cur_count;
    //当前转向
    int TurnDir;
    //外设操作句柄
    TIM_HandleTypeDef*  encoder_tim;
    TIM_HandleTypeDef*  pwm_tim;
    uint32_t            pwm_channel;
    //自定义换向函数
    void               (*set_DirLeft)();
    void               (*set_DirRight)();

}motor;


#define __Motor_Chang_Speed(__MOTOR__,__SPEED__) {__MOTOR__->tar_speed = __SPEED__;}


void                Motor_Init                  (motor *Motor_TypeDef);
void                Motor_Get_Speed             (motor *Motor_TypeDef);
void                Motor_Change_Duty           (motor *Motor_TypeDef,float duty);
void                Motor_Run                   (motor *Motor_TypeDef);

#endif // !__MOTOR_H__