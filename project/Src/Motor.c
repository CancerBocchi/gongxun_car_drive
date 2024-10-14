#include "headfile.h"

/**
 * @brief 电机外设初始化
 * 
 * @param Motor_TypeDef 
 */
void Motor_Init(motor *Motor_TypeDef){
    //开启外设
    HAL_TIM_Encoder_Start(Motor_TypeDef->encoder_tim,TIM_CHANNEL_ALL);
    HAL_TIM_PWM_Start(Motor_TypeDef->pwm_tim,Motor_TypeDef->pwm_channel);
    //初始化方向
    Motor_TypeDef->set_DirRight();
    Motor_TypeDef->TurnDir = M_TURN_RIGHT;
}

/**
 * @brief 获取速度
 * 
 * @param Motor_TypeDef 
 */
void Motor_Get_Speed(motor *Motor_TypeDef){
    //保存上次数据
    Motor_TypeDef->last_speed = Motor_TypeDef->cur_speed;

    //读取计数器的值
    Motor_TypeDef->cur_count = Motor_TypeDef->encoder_tim->Instance->CNT;
    // 计算速度
    // 向右转
    if(Motor_TypeDef->TurnDir == M_TURN_LEFT){
        if(Motor_TypeDef->last_count < Motor_TypeDef->cur_count)
            Motor_TypeDef->cur_speed = 65535 - Motor_TypeDef->cur_count + Motor_TypeDef->last_count;
        else 
            Motor_TypeDef->cur_speed = - Motor_TypeDef->cur_count + Motor_TypeDef->last_count;
    }
    //向左转
    else{
        if(Motor_TypeDef->last_count > Motor_TypeDef->cur_count)
            Motor_TypeDef->cur_speed = 65535 + Motor_TypeDef->cur_count - Motor_TypeDef->last_count;
        else 
            Motor_TypeDef->cur_speed = Motor_TypeDef->cur_count - Motor_TypeDef->last_count;
    }

    Motor_TypeDef->last_count = Motor_TypeDef->cur_count;

    //Motor_TypeDef->cur_speed = (1.0f-0.5f)*speed + 0.5f*Motor_TypeDef->cur_speed;

    //修正数据
    Motor_TypeDef->cur_speed = Motor_TypeDef->cur_speed > 60000 ? Motor_TypeDef->last_speed : Motor_TypeDef->cur_speed;

}

/**
 * @brief 电机运行函数
 *        电机运行函数 根据电机输入的速度值对电机的转向进行了更改
 *        但是实际运行的环路的值始终为正值
 * 
 * @param Motor_TypeDef 电机对象
 */
void Motor_Run(motor *Motor_TypeDef){
    float duty;
    //改变转向
    if(Motor_TypeDef->tar_speed < 0){
        Motor_TypeDef->set_DirLeft();
        Motor_TypeDef->TurnDir = M_TURN_LEFT;
    }
    else{
        Motor_TypeDef->set_DirRight();
        Motor_TypeDef->TurnDir = M_TURN_RIGHT;
    }

    //传入目标转速的绝对值
    Motor_TypeDef->Motor_PID.Ref = fabs(Motor_TypeDef->tar_speed);

    //读取速度
    Motor_Get_Speed(Motor_TypeDef);
    duty = Pos_PID_Controller(&(Motor_TypeDef->Motor_PID),Motor_TypeDef->cur_speed);
    Motor_Change_Duty(Motor_TypeDef,duty);

    //SEGGER_RTT_printf(0,"%d,%d,%d\n",Motor_TypeDef->cur_speed,(int)(duty*1000),(int)(Motor_TypeDef->Motor_PID.Value_I*1000));

}

/**
 * @brief 电机改变占空比函数
 * 
 * @param Motor_TypeDef 电机对象
 * @param duty 占空比
 */
void Motor_Change_Duty(motor *Motor_TypeDef,float duty){

    int ccr = (int)(__HAL_TIM_GET_AUTORELOAD(Motor_TypeDef->pwm_tim) * duty);

    __HAL_TIM_SET_COMPARE(Motor_TypeDef->pwm_tim,
                          Motor_TypeDef->pwm_channel, ccr);

}

