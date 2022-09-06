#include <stdio.h>
#include "i2c_conf.h"
#include "lis3dh.h"

#define IMU_AXIS_SAMPLED    3
#define CONVERT_G_TO_MS2    9.80665f

LIS3DH lis3dh;
static float imu_data[IMU_AXIS_SAMPLED];

extern "C" void app_main()
{
    i2c_bus = i2c_bus_create(I2C_MASTER_NUM, &conf);

    lis3dh.begin(i2c_bus, LIS3DH_ADDRESS_UPDATED);

    if(lis3dh.isConnection() == false) {
        printf("ERR: failed to connect to LIS3DH sensor!\n");
        return;
    }

    vTaskDelay(100 / portTICK_RATE_MS);
    lis3dh.setFullScaleRange(LIS3DH_RANGE_2G);
    lis3dh.setOutputDataRate(LIS3DH_DATARATE_100HZ);

    while (true)
    {
        lis3dh.getAcceleration(&imu_data[0], &imu_data[1], &imu_data[2]);
        imu_data[0] *= CONVERT_G_TO_MS2;
        imu_data[1] *= CONVERT_G_TO_MS2;
        imu_data[2] *= CONVERT_G_TO_MS2;

        printf("accX: %f\t accY: %f\t accZ: %f\n", imu_data[0], imu_data[1], imu_data[2]);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
