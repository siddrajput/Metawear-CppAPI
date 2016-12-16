/**
 * @copyright MbientLab License
 * @file sensor_fusion.h
 * @brief Performs sensor fusion using accelerometer, gyro, and magnetometer data
 * @details When using the sensor fusion module, do not use the accelerometer, gyro, and magnetometer functions.  
 * The api will automatically configure the sensors based on the selected fusion mode.
 */
#pragma once

#include "sensor_common.h"

#ifdef	__cplusplus
extern "C" {
#endif

const uint8_t MBL_MW_SENSOR_FUSION_CALIBRATION_ACCURACY_UNRELIABLE = 0,
        MBL_MW_SENSOR_FUSION_CALIBRATION_ACCURACY_LOW = 1,
        MBL_MW_SENSOR_FUSION_CALIBRATION_ACCURACY_MEDIUM = 2,
        MBL_MW_SENSOR_FUSION_CALIBRATION_ACCURACY_HIGH = 3;

/**
 * Fusion modes supported by the algorithm
 */
typedef enum {
    MBL_MW_SENSOR_FUSION_MODE_SLEEP = 0,
    MBL_MW_SENSOR_FUSION_MODE_NDOF,
    MBL_MW_SENSOR_FUSION_MODE_IMU_PLUS,
    MBL_MW_SENSOR_FUSION_MODE_COMPASS,
    MBL_MW_SENSOR_FUSION_MODE_M4G
} MblMwSensorFusionMode;

/**
 * Supported acceleration ranges
 */
typedef enum {
    MBL_MW_SENSOR_FUSION_ACC_RANGE_2G = 0,
    MBL_MW_SENSOR_FUSION_ACC_RANGE_4G,
    MBL_MW_SENSOR_FUSION_ACC_RANGE_8G,
    MBL_MW_SENSOR_FUSION_ACC_RANGE_16G
} MblMwSensorFusionAccRange;

/**
 * Supported rotation ranges
 */
typedef enum {
    MBL_MW_SENSOR_FUSION_GYRO_RANGE_2000DPS = 0,
    MBL_MW_SENSOR_FUSION_GYRO_RANGE_1000DPS,
    MBL_MW_SENSOR_FUSION_GYRO_RANGE_500DPS,
    MBL_MW_SENSOR_FUSION_GYRO_RANGE_250DPS
} MblMwSensorFusionGyroRange;

/**
 * Data computed by the algorithm
 */
typedef enum {
    MBL_MW_SENSOR_FUSION_DATA_CORRECTED_ACC = 0,
    MBL_MW_SENSOR_FUSION_DATA_CORRECTED_GYRO,
    MBL_MW_SENSOR_FUSION_DATA_CORRECTED_MAG,
    MBL_MW_SENSOR_FUSION_DATA_QUATERION,
    MBL_MW_SENSOR_FUSION_DATA_EULER_ANGLE,
    MBL_MW_SENSOR_FUSION_DATA_GRAVITY_VECTOR,
    MBL_MW_SENSOR_FUSION_DATA_LINEAR_ACC
} MblMwSensorFusionData;

/**
 * Get the data signal object representing data from the sensor fusion algorithm
 * @param board         Calling object
 * @param data          Desired sensor fusion data
 * @return Data signal object  
 */
METAWEAR_API MblMwDataSignal* mbl_mw_sensor_fusion_get_data_signal(const MblMwMetaWearBoard* board, MblMwSensorFusionData data);

/**
 * Set the operation mode
 * @param board         Calling object
 * @param mode          New operation mode
 */
METAWEAR_API void mbl_mw_sensor_fusion_set_mode(MblMwMetaWearBoard* board, MblMwSensorFusionMode mode);
/**
 * Set the accelerometer data range
 * @param board         Calling object
 * @param range         New data range of the accelerometer
 */
METAWEAR_API void mbl_mw_sensor_fusion_set_acc_range(MblMwMetaWearBoard* board, MblMwSensorFusionAccRange range);
/**
 * Set the gyroscope data range
 * @param board         Calling object
 * @param range         New data range of the gyroscope
 */
METAWEAR_API void mbl_mw_sensor_fusion_set_gyro_range(MblMwMetaWearBoard* board, MblMwSensorFusionGyroRange range);
/**
 * Write the module configuration to the board
 * @param board         Calling object
 */
METAWEAR_API void mbl_mw_sensor_fusion_write_config(MblMwMetaWearBoard* board);

/**
 * Set a data enable bit
 * @param board         Calling object
 * @param data          Sensor fuson data to enable
 */
METAWEAR_API void mbl_mw_sensor_fusion_enable_data(MblMwMetaWearBoard* board, MblMwSensorFusionData data);
/**
 * Clear all data enable bits
 * @param board         Calling object
 */
METAWEAR_API void mbl_mw_sensor_fusion_clear_enabled_mask(MblMwMetaWearBoard* board);

/**
 * Start sensor fusion
 * @param board         Calling object
 */
METAWEAR_API void mbl_mw_sensor_fusion_start(const MblMwMetaWearBoard* board);
/**
 * Stop sensor fusion
 * @param board         Calling object
 */
METAWEAR_API void mbl_mw_sensor_fusion_stop(const MblMwMetaWearBoard* board);

#ifdef	__cplusplus
}
#endif
