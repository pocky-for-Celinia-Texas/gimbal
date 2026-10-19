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
      rm_motor_x.speed,
      rm_motor_x.torque,
      // 陀螺仪三轴(rad/s), 已按 IMU_R_AB 转到云台系
      bmi088.gyro[0],
      bmi088.gyro[1],
      bmi088.gyro[2],
      // 姿态角(rad): yaw绕z轴, pitch绕y轴, roll绕x轴
      // 无磁力计, yaw是相对值且会缓慢漂移; pitch/roll由重力校正, 静态较准
      imu.yaw,
      imu.pitch,
      imu.roll
	);

		osDelay(5);
	}
}
// clang-format on
