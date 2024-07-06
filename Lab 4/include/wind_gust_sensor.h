/***************************************************************
 * Author: Mansi Joshi
 * Student Number: 041091664
 * Course Name: C Language
 * Course Section: CST8234_302
 * Assignment Name: LAB 4
 * Purpose: Define the structure for Wind Gust Sensor data.
 * Date Submitted: October 6, 2023
 * Due Date: November 17, 2023
 * Professor: Natalie
 * List of Sources: N/A
 **************************************************************/

#ifndef WIND_GUST_SENSOR_H
#define WIND_GUST_SENSOR_H

/* Structure to represent Wind Gust Sensor Data */
typedef struct {
    time_t timestamp;   /* Timestamp of the sensor data */
    int type;           /* Type of sensor (assumed to be 3 for Wind Gust) */
    double prev;        /* Previous wind gust value */
    double current;     /* Current wind gust value */
} WindGustSensorData;

#endif 
