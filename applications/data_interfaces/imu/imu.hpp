#ifndef IMU_HPP
#define IMU_HPP

#include "io/bmi088/bmi088.hpp"
#include "tools/mahony/mahony.hpp"

// bmi088系统{b}在云台系{a}下的旋转矩阵, 需按实际安装方向修改, 详见 io/bmi088/readme.md
// 当前值: C板横装, CAN一侧朝前
inline constexpr float IMU_R_AB[3][3] = {
	{0.0f, -1.0f, 0.0f},
	{1.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f}};

// C板: SPI1, 加速度计片选CS1_ACC=PA4, 陀螺仪片选CS1_GYRO=PB0
// 达妙板改用: &hspi2, GPIOC, GPIO_PIN_0, GPIOC, GPIO_PIN_3
inline sp::BMI088 bmi088(&hspi1, GPIOA, GPIO_PIN_4, GPIOB, GPIO_PIN_0, IMU_R_AB);

// dt = 1e-3f, 对应 imu_task 中 1ms 的采样周期
inline sp::Mahony imu(1e-3f);

#endif  // IMU_HPP
