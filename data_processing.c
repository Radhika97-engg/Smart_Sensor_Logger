#include <stdio.h>
#include "sensor.h" 
#include "data_processing.h"

// Function to swap two sensor data records
void swap(struct SensorData *record1, struct SensorData *record2) {
    struct SensorData temp = *record1;
    *record1 = *record2;
    *record2 = temp;
  }
  
  // Function to partition the sensor data array for quicksort
  int partition(struct SensorData sensor_in_array[], int low, int high) {
    int pivotIndex = low + (high - low) / 2;
    struct SensorData pivot = sensor_in_array[pivotIndex];
    int left = low, right = high;
    while (left <= right) {
        while (sensor_in_array[left].temperature > pivot.temperature) left++;
        while (sensor_in_array[right].temperature < pivot.temperature) right--;
        if (left <= right) {
            swap(&sensor_in_array[left], &sensor_in_array[right]);
            left++;
            right--;
        }
    }
    return left;
  }
  
  // Function to perform quicksort on sensor data
  void quick_sort(struct SensorData sensor_in_array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(sensor_in_array, low, high);
        quick_sort(sensor_in_array, low, pivotIndex - 1);
        quick_sort(sensor_in_array, pivotIndex, high);
    }
  }
  
  // Function to sort and store sensor data in a file
  void sort_sensor_data() {
    int number_of_records = 0;
    struct SensorData sensor_in_array[100];
  
    // Open file to read sensor data
    FILE *fp = fopen("sensor_data.log", "rb");  
    if (fp == NULL) {
        printf("ERROR: file not found or empty\n");
        return;
    }
  
    // Read sensor data into an array
    while (fread(&sensor_in_array[number_of_records], sizeof(struct SensorData), 1, fp) == 1) {
        number_of_records++;
        if (number_of_records >= 100) {
            printf("WARNING: MAXIMUM record limit reached\n");
            break;
        }
    }
    fclose(fp);
  
    if (number_of_records == 0) {
        printf("No data found in the file\n");
        return;
    }
  
    // Sort the sensor data using quicksort
    quick_sort(sensor_in_array, 0, number_of_records - 1);
  
    // Open file to write sorted sensor data
    FILE *fp_w = fopen("sensor_data.log", "wb");
    if (fp_w == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    
    // Write sorted data back to the file
    fwrite(sensor_in_array, sizeof(struct SensorData), number_of_records, fp_w);
    fclose(fp_w);
  
    printf("Sensor data sorted successfully!\n");
  }