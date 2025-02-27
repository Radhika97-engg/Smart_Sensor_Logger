#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>     
#include "sensor.h"   

// Function to log sensor data
void logging_sensor_data() {
    struct SensorData sensor;

    while (1) {
        printf("Temperature (40 to 70) : ");
        if (scanf("%f", &sensor.temperature) != 1) {
            printf("Invalid Input, enter a numeric value in the range of 40 to 70\n");
            while (getchar() != '\n') {} // Clear input buffer
            continue;
        }
        if (sensor.temperature < 40.00 || sensor.temperature > 70.00) {
            printf("Invalid Input value, please enter a value in range 40 F to 70 F \n");
            continue;
        }
        break;
    }
    printf("Valid temperature entered : %.2f degrees Fahrenheit\n", sensor.temperature);

    // Prompt for humidity input and validate
    while (1) {
        printf("Humidity (20 to 80) : ");
        if (scanf("%f", &sensor.humidity) != 1) {
            printf("Invalid Input, enter a numeric value in the range of 20 to 80\n");
            while (getchar() != '\n') {} // Clear input buffer
            continue;
        }
        if (sensor.humidity < 20 || sensor.humidity > 80) {
            printf("Invalid Input value, please enter a value in range 20 F to 80 F\n");
            continue;
        }
        break;
    }
    printf("Valid humidity entered : %f\n", sensor.humidity);

    // Store timestamp
    sensor.timestamp = time(NULL);
    printf("Timestamp : %s\n", ctime(&sensor.timestamp));

    // Open file to append sensor data
    FILE *fp = fopen("sensor_data.log", "ab");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    // Write sensor data to file
    if (fwrite(&sensor, sizeof(struct SensorData), 1, fp) != 1) {
        printf("Error writing data to file\n");
    } else {
        printf("Data successfully written to file\n");
    }

    fclose(fp); 
}

// Function to search sensor data by date range
void search_sensor_data_by_date() {
    struct SensorData record;
    struct tm start_tm = {0}, end_tm = {0};
    time_t start_timestamp, end_timestamp;
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;
    int found = 0;

    // Prompt user for start and end dates
    printf("Enter start date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &start_day, &start_month, &start_year);
    getchar(); // Consume newline
    printf("Enter end date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &end_day, &end_month, &end_year);

    // Convert input dates to timestamp format
    start_tm.tm_mday = start_day;
    start_tm.tm_mon = start_month - 1;
    start_tm.tm_year = start_year - 1900;
    start_tm.tm_hour = 0;
    start_tm.tm_min = 0;
    start_tm.tm_sec = 0;

    end_tm.tm_mday = end_day;
    end_tm.tm_mon = end_month - 1;
    end_tm.tm_year = end_year - 1900;
    end_tm.tm_hour = 23;
    end_tm.tm_min = 59;
    end_tm.tm_sec = 59;

    start_timestamp = mktime(&start_tm);
    end_timestamp = mktime(&end_tm);

    if (start_timestamp == -1 || end_timestamp == -1) {
        printf("Error converting date to timestamp.\n");
        return;
    }

    // Open file to read sensor data
    FILE *fp = fopen("sensor_data.log", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return;
    }

    // Read and filter sensor data based on date range
    while (fread(&record, sizeof(struct SensorData), 1, fp) == 1) {
        if (record.timestamp >= start_timestamp && record.timestamp <= end_timestamp) {
            printf("Temperature: %.2f degrees Fahrenheit\nHumidity: %.2f%%\n", record.temperature, record.humidity);
            printf("Timestamp: %.24s\n", ctime(&record.timestamp));
            printf("----------------------------\n");
            found = 1;
        }
    }

    // Notify if no records were found in the date range
    if (!found) {
        printf("No records found in the selected time range.\n");
    }

    fclose(fp); 
}
