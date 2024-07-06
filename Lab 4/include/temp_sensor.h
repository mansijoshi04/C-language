/***************************************************************
 * Author: Mansi Joshi
 * Student Number: 041091664
 * Course Name: C Language
 * Course Section: CST8234_302
 * Assignment Name: LAB 4
 * Purpose: Define the structure for Temperature Sensor data.
 * Date Submitted: October 6, 2023
 * Due Date: November 17, 2023
 * Professor: Natalie
 * List of Sources: N/A
 **************************************************************/

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

/* Structure to represent Temperature Sensor Data */
typedef struct {
    time_t timestamp;   /* Timestamp of the sensor data */
    int type;           /* Type of sensor (assumed to be 1 for Temperature) */
    double celsius;     /* Temperature in degrees Celsius */
} TempSensorData;

#endif 
