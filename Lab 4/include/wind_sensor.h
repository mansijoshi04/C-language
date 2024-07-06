/***************************************************************
 * Author: Mansi Joshi
 * Student Number: 041091664
 * Course Name: C Language
 * Course Section: CST8234_302
 * Assignment Name: LAB 4
 * Purpose: Define the structure for Wind Sensor data.
 * Date Submitted: October 6, 2023
 * Due Date: November 17, 2023
 * Professor: Natalie
 * List of Sources: N/A
 **************************************************************/

#ifndef WIND_SENSOR_H
#define WIND_SENSOR_H

/* Structure to represent Wind Sensor Data */
typedef struct {
    time_t timestamp;   /* Timestamp of the sensor data */
    int type;           /* Type of sensor (assumed to be 2 for Wind) */
    double km_per_h;    /* Wind speed in kilometers per hour */
    int degrees;        /* Wind direction in degrees */
} WindSensorData;

#endif 
