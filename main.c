#include <stdio.h>
#include "sensor.h"
#include "file_io.h"
#include "data_processing.h"
#include "menu.h"

int main() {
    int choice;
    printf("Welcome to Smart Sensor Data Logger\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: logging_sensor_data(); 
            break;
            case 2: read_sensor_data(); 
            break;
            case 3: sort_sensor_data(); 
            break;
            case 4: search_sensor_data_by_date(); 
            break;
            case 5: printf("Exiting\n"); 
            return 0;
            default: printf("Invalid choice\n");
        }
    }
}
