#include "file_io.h"
#include <stdio.h>

// Function to read stored sensor data
void read_sensor_data() {
    struct SensorData sensor;
    FILE *fp = fopen("sensor_data.log", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("\nStored Sensor Data\n");
    printf("----------------------------\n");

    while (fread(&sensor, sizeof(struct SensorData), 1, fp) == 1) {
        printf("Temperature : %.2f deg F\n", sensor.temperature);
        printf("Humidity : %.2f%%\n", sensor.humidity);
        printf("Timestamp : %s\n", ctime(&sensor.timestamp));
    }

    fclose(fp);
}
