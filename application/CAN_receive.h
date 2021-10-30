/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       can_receive.c/h
  * @brief      there is CAN interrupt function  to receive motor data,
  *             and CAN send function to send motor current to control motor.
  *             ������CAN�жϽ��պ��������յ������,CAN���ͺ������͵���������Ƶ��.
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Dec-26-2018     RM              1. done
  *  V1.1.0     Nov-11-2019     RM              1. support hal lib
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#ifndef CAN_RECEIVE_H
#define CAN_RECEIVE_H

#include "struct_typedef.h"

//�˴���ʱΪ�˵��ԣ���CAN��˳�������һ��
#define GIMBAL_CAN hcan2
#define SHOOT_CAN hcan2
#define CHASSIS_CAN hcan1
#define SUPER_CAP_CAN hcan2

//��̨����������
enum gimbal_motor_id_e
{
  YAW_MOTOR = 0,
  PITCH_MOTOR,
};

//�������������
enum shoot_motor_id_e
{
  LEFT_FRIC_MOTOR = 0,
  RIGHT_FRIC_MOTOR,
  TRIGGER_MOTOR,
  MAGAZINE_MOTOR,
};

//���̶���������
enum motive_chassis_motor_id_e
{
  //���̶����������
  MOTIVE_FR_MOTOR = 0,
  MOTIVE_FL_MOTOR,
  MOTIVE_BL_MOTOR,
  MOTIVE_BR_MOTOR,

};

//���̶��������
enum rudde_chassisr_motor_id_e
{
  //���̶�����
  RUDDER_FL_MOTOR = 0,
  RUDDER_FR_MOTOR,
  RUDDER_BL_MOTOR,
  RUDDER_BR_MOTOR,
};

/* CAN send and receive ID */
typedef enum
{

  //��������������ID CAN1
  CAN_LEFT_FRIC_MOTOR_ID = 0x201,
  CAN_RIGHT_FRIC_MOTOR_ID = 0x202,
  CAN_TRIGGER_MOTOR_ID = 0x203,
  CAN_MAGAZINE_MOTOR_ID = 0X204,
  CAN_SHOOT_ALL_ID = 0x200,

  //��̨�������ID CAN1
  CAN_YAW_MOTOR_ID = 0x205,
  CAN_PITCH_MOTOR_ID = 0x206,
  CAN_GIMBAL_ALL_ID = 0x1FF,

  //���̶����������ID  CAN2
  CAN_MOTIVE_FR_MOTOR_ID = 0x201,
  CAN_MOTIVE_FL_MOTOR_ID = 0x202,
  CAN_MOTIVE_BL_MOTOR_ID = 0x203,
  CAN_MOTIVE_BR_MOTOR_ID = 0x204,
  CAN_CHASSIS_MOTIVE_ALL_ID = 0x200,

  //���̶�����ID CAN2
  CAN_RUDDER_FL_MOTOR_ID = 0x205,
  CAN_RUDDER_FR_MOTOR_ID = 0x206,
  CAN_RUDDER_BL_MOTOR_ID = 0x207, 
  CAN_RUDDER_BR_MOTOR_ID = 0X208,
  CAN_CHASSIS_RUDDER_ALL_ID = 0x1FF,

  //�������ݽ���ID CAN2
  CAN_SUPER_CAP_ID = 0x211,
  CAN_SUPER_CAP_ALL_ID = 0x210,
} can_msg_id_e;

//rm motor data
typedef struct
{
    uint16_t ecd;
    int16_t speed_rpm;
    int16_t given_current;
    uint8_t temperate;
    int16_t last_ecd;
} motor_measure_t;



/**
  * @brief          ���͵�����Ƶ���(0x209,0x20A,0x20B,0x20C)
  * @param[in]      yaw: (0x209) 6020������Ƶ���, ��Χ [-30000,30000]
  * @param[in]      pitch: (0x20A) 6020������Ƶ���, ��Χ [-30000,30000]
  * @param[in]      rev1: (0x20B)  ������������Ƶ���
  * @param[in]      rev2: (0x20C) ������������Ƶ���
  * @retval         none
  */
extern void CAN_cmd_gimbal(int16_t yaw, int16_t pitch, int16_t rev1, int16_t rev2);


/**
  * @brief          ����IDΪ0x700��CAN��,��������3508��������������ID
  * @param[in]      none
  * @retval         none
  */
extern void CAN_cmd_chassis_reset_ID(void);


/**
  * @brief          ���Ͷ���������Ƶ���(0x201,0x202,0x203,0x204)
  * @param[in]      motor1: (0x201) 3508������Ƶ���, ��Χ [-16384,16384]
  * @param[in]      motor2: (0x202) 3508������Ƶ���, ��Χ [-16384,16384]
  * @param[in]      motor3: (0x203) 3508������Ƶ���, ��Χ [-16384,16384]
  * @param[in]      motor4: (0x204) 3508������Ƶ���, ��Χ [-16384,16384]
  * @retval         none
  */
extern void CAN_cmd_chassis_motive(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);


/**
  * @brief          ���Ͷ��������Ƶ���(0x205,0x206,0x207,0x208)
  * @param[in]      motor1: (0x205) 6020������Ƶ���, ��Χ [-30000,30000]
  * @param[in]      motor2: (0x206) 6020������Ƶ���, ��Χ [-30000,30000]
  * @param[in]      motor3: (0x207) 6020������Ƶ���, ��Χ [-30000,30000]
  * @param[in]      motor4: (0x208) 6020������Ƶ���, ��Χ [-30000,30000]
  * @retval         none
  */
extern void CAN_cmd_chassis_rudder(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);


/**
  * @brief          ���͵�����Ƶ���(0x205,0x206,0x207,0x208)
  * @param[in]      left_fric: (0x205) 3508������Ƶ���, ��Χ [-16384,16384]
  * @param[in]      right_fric: (0x206) 3508������Ƶ���, ��Χ [-16384,16384]
  * @param[in]      trigger: (0x207) 2006������Ƶ���, ��Χ [-10000,10000]
  * @param[in]      ����: (0x208) ������������Ƶ���
  * @retval         none
  */
extern void CAN_cmd_shoot(int16_t left_fric, int16_t right_fric, int16_t trigger, int16_t magazine);

/**
  * @brief          �������ݷ��͹������
  * @param[in]      0x211 �������ݹ���
  * @retval         none
  */
extern void CAN_cmd_super_cap(int16_t temPower);

/**
  * @brief          ���ط��������� 3508�������ָ��
  * @param[in]       i: ������,��Χ[0,3]
  * @retval         �������ָ��
  */
extern const motor_measure_t *get_shoot_motor_measure_point(uint8_t i);

/**
  * @brief          ������̨�����������ָ��
  * @param[in]       i: ������,��Χ[0,1]
  * @retval         �������ָ��
  */
extern const motor_measure_t *get_gimbal_motor_measure_point(uint8_t i);

/**
  * @brief          ���ص��̶������ 3508�������ָ��
  * @param[in]      i: ������,��Χ[0,3]
  * @retval         �������ָ��
  */
extern const motor_measure_t *get_chassis_motive_motor_measure_point(uint8_t i);

/**
  * @brief          ���ص��̶����� 3508�������ָ��
  * @param[in]      i: ������,��Χ[0,3]
  * @retval         �������ָ��
  */
extern const motor_measure_t *get_chassis_rudder_motor_measure_point(uint8_t i);

#endif
