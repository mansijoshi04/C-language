/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 4
* Purpose: Read data from file and organize it based on sensor type.
* Date Submitted: October 6, 2023
* Due Date: November 17, 2023
* Professor: Natalie Gluzman
* List of Sources: N/A
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wind_sensor.h"
#include "wind_gust_sensor.h"
#include "temp_sensor.h"

typedef struct {
    time_t timestamp;
    int type;
    double field1;
    double field2;
    double field3;
} SensorData;

int main() {
    int i;
    FILE *file = stdin; 

    /* Define arrays to store sensor data */
    TempSensorData temp_data[256];
    WindSensorData wind_data[256];
    WindGustSensorData wind_gust_data[256];

    /* Initialize counters for each sensor type */
    int temp_count = 0;
    int wind_count = 0;
    int wind_gust_count = 0;

    /* Read data from the file */
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        /* Parse the line into timestamp, type, and sensor-specific fields */
        time_t timestamp;
        int type;
        double field1, field2, field3;

        if (sscanf(line, "%ld,%d,%lf,%lf,%lf", &timestamp, &type, &field1, &field2, &field3) >= 3) {
            /* Organize data into arrays based on sensor type */
            if (type == 1 && temp_count < sizeof(temp_data)) {
                temp_data[temp_count].timestamp = timestamp;
                temp_data[temp_count].type = type;
                temp_data[temp_count].celsius = field1;
                temp_count++;
            } else if (type == 2 && wind_count < sizeof(wind_data)) {
                wind_data[wind_count].timestamp = timestamp;
                wind_data[wind_count].type = type;
                wind_data[wind_count].km_per_h = field1;
                wind_data[wind_count].degrees = (int)field2;
                wind_count++;
            } else if (type == 3 && wind_gust_count < sizeof(wind_gust_data)) {
                wind_gust_data[wind_gust_count].timestamp = timestamp;
                wind_gust_data[wind_gust_count].type = type;
                wind_gust_data[wind_gust_count].prev = field1;
                wind_gust_data[wind_gust_count].current = field2;
                wind_gust_count++;
            }
        }
    }

    /* Print temperature data */
    printf("Date\tTime\tCelsius\n");
    for (i = 0; i < temp_count; i++) {
        struct tm *tm_info = localtime(&temp_data[i].timestamp);
        char time_str[20];
        strftime(time_str, 20, "%Y/%m/%d %H:%M:%S", tm_info);
        printf("%s %.2f\n", time_str, temp_data[i].celsius);
    }

    /* Print wind data */
    printf("\nDate\tTime\tSpeed Direction\n");
    for (i = 0; i < wind_count; i++) {
        struct tm *tm_info = localtime(&wind_data[i].timestamp);
        char time_str[20];
        strftime(time_str, 20, "%Y/%m/%d %H:%M:%S", tm_info);
        printf("%s %.2f %d\n", time_str, wind_data[i].km_per_h, wind_data[i].degrees);
    }

    /* Print wind gust data */
    printf("\nDate\tTime\tWind Change\n");
    for (i = 0; i < wind_gust_count; i++) {
        struct tm *tm_info = localtime(&wind_gust_data[i].timestamp);
        char time_str[20];
        strftime(time_str, 20, "%Y/%m/%d %H:%M:%S", tm_info);
        printf("%s %s\n", time_str, wind_gust_data[i].current < wind_gust_data[i].prev ? "Decreasing" : "Increasing");
    }

    return 0;
}
