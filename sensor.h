#ifndef SENSOR_H
#define SENSOR_H

#include <time.h>

// Sensor data structure
struct SensorData {
    float temperature;
    float humidity;
    time_t timestamp;
};

// Function declaration
void logging_sensor_data();

#endif 
