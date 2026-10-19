#include "cmsis_os.h"
#include "control_task.hpp"
#include "data_interfaces/imu/imu.hpp"
#include "io/plotter/plotter.hpp"

sp::Plotter plotter(&huart1);

// clang-format off
extern "C" void plot_task()
{
	while (1) {

    plotter.plot(
      // 电机: 角度(rad) / 速度(rad/s) / 力矩(Nm)
      rm_motor_x.angle,
      //rm_motor_x.speed,
      //rm_motor_x.torque,
      // 陀螺仪三轴(rad/s), 已按 IMU_R_AB 转到云台系
      //bmi088.gyro[0],
      //bmi088.gyro[1],
      //bmi088.gyro[2],
      imu.yaw,
      imu.pitch,
      imu.roll //初始大概是0.52,重心位置-1.16
	);

		osDelay(5);
	}
}
// clang-format on
