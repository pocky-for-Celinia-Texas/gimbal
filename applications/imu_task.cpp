#include "cmsis_os.h"
#include "data_interfaces/imu/imu.hpp"

// BMI088 采样 + Mahony 姿态解算
// 本任务是 bmi088 和 imu 的唯一写者, 其他任务只读它们的数据
extern "C" void imu_task()
{
	// BMI088 未接好/自检不通过时会一直重试, 放在本任务里不会阻塞控制任务
	bmi088.init();

	while (true) {
		bmi088.update();
		imu.update(bmi088.acc, bmi088.gyro);

		// 1kHz, 对应 configTICK_RATE_HZ = 1000
		osDelay(1);
	}
}
