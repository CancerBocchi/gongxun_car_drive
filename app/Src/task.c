#include "task.h"
#include "M_Car.h"

float speed;
int last_count;
int cur_count;

inline void task_do(){

    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_10);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,30,0);
    HAL_Delay(500);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,0,0);
    HAL_Delay(1000);
    __M_CAR_CHANG_SPEED((&M_Car_ob),30,0,0);
    HAL_Delay(500);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,0,0);
    HAL_Delay(1000);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,-30,0);
    HAL_Delay(500);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,0,0);
    HAL_Delay(1000);
    __M_CAR_CHANG_SPEED((&M_Car_ob),-30,0,0);
    HAL_Delay(500);
    __M_CAR_CHANG_SPEED((&M_Car_ob),0,0,0);
    HAL_Delay(1000);

}

char data[100];

void task_init(){
    HAL_TIM_Base_Start_IT(&htim5);
    M_Car_Init(&M_Car_ob);
    //HAL_UARTEx_ReceiveToIdle_IT(&huart6,data,3);
    // HAL_UART_Receive_IT(&huart6,data,1);
    
}

/**
 * @brief 电机环路运行中断 
 * 
 * @param htim 
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    static int count = 0;
    count ++;
    if(count == 100){
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
        M_Car_Run(&M_Car_ob);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
        count = 0;
    } 
    
}

// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
//     if(data[0] != '\0')
//         SEGGER_RTT_printf(0,"%d\n",data[0]);
//     HAL_UART_Receive_IT(&huart6,data,1);
// }

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
    
     
    HAL_UARTEx_ReceiveToIdle_IT(&huart6,data,3);
        
}