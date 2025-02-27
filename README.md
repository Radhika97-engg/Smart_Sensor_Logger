# Smart Sensor Logger

A **C-based sensor data logging system** that records temperature and humidity data, stores it in a log file, and allows users to read, search, and sort the logged sensor data.

## Features
-  Logs **temperature** and **humidity** readings with timestamps.
-  Stores sensor data in a **binary file** for efficient retrieval.
-  Provides **menu-based interaction** for users.
-  Allows **searching by date range** and **sorting data**.
-  Built using **C programming** with structured modular code.

## Installation & Compilation

### Clone the Repository
```sh
git clone https://github.com/Radhika97-engg/Smart_Sensor_Logger.git
cd Smart_Sensor_Logger

Use GCC to compile the project:
gcc main.c sensor.c file_io.c data_processing.c menu.c -o sensor_logger
Run the Executable
./sensor_logger
Usage
1️⃣ Run the program.
2️⃣ Choose an option from the menu:
1: Log new sensor data
2: Read all logged data
3: Search sensor data by date range
4: Sort sensor data
5: Exit
3️⃣ Follow the prompts to interact with the system.

Project Structure

📂 Smart_Sensor_Logger/
│── 📄 main.c *(Entry point of the program)*
│── 📄 sensor.c *(Handles sensor data logging & reading)*
│── 📄 file_io.c *(Handles file operations like read/write)*
│── 📄 data_processing.c *(Handles sorting & searching operations)*
│── 📄 menu.c *(Manages user interface & menu system)*
│── 📄 sensor.h, file_io.h, data_processing.h, menu.h *(Header files for modularity)*

Example Run
Welcome to Smart Sensor Data Logger

1. Log Sensor Data
2. Read Sensor Data
3. Search Data by Date
4. Sort Sensor Data
5. Exit
Enter your choice: 1
Temperature (40 to 70): 45.2
Humidity (20 to 80): 55.0
Data successfully saved to sensor_data.log

Contribution
Feel free to contribute! Open an issue or submit a pull request if you find any bugs or improvements.

License
This project is open-source under the MIT License.
