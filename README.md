**README.md**

## Coal Weight Measurement in coal wagon

This repository contains two Arduino sketches:

1. **Load Cell Calibration** - This code is designed to calibrate a load cell. A load cell is a transducer that converts force into an electrical signal. Calibration is essential to ensure accurate measurements. Each load cell will have different calibration factor which varies during manufacturing. This sketch provides a platform to calibrate the load cell by establishing the relationship between the force applied and the electrical signal generated.

2. **Coal Wagon Weight Measurement** - This code facilitates the measurement of the weight of a coal wagon. It utilizes a load cell for weight sensing, an LCD for displaying measurements, LEDs for indicating various conditions, and a buzzer for audible alerts. The system offers a comprehensive solution for monitoring the weight of the coal wagon, ensuring efficiency and accuracy in coal transportation processes.

### Load Cell Calibration

The load cell calibration process involves determining the relationship between the force applied to the load cell and the corresponding electrical output. This is achieved by applying known loads to the load cell and recording the corresponding readings. The calibration sketch provides a user-friendly interface to streamline this process, allowing users to input known loads and record the corresponding readings for calibration purposes.

### Coal Weight Measurement in coal wagon

The coal wagon weight measurement system combines various components to facilitate accurate and efficient weight measurement of coal wagons. The load cell serves as the primary sensor for weight detection, while the LCD provides a clear display of the measured weight. Additionally, LEDs are employed to indicate different conditions, such as weight thresholds or system status, while a buzzer offers audible alerts when necessary.

### Usage

1. **Load Cell Calibration**: 
   - Upload the `calibrating_load_cell.ino` sketch to your Arduino board.
   - Follow the instructions provided in the sketch to input known loads and record corresponding readings for calibration.

2. **Coal Wagon Weight Measurement**:
   - Upload the `measuring_weight.ino` sketch to your Arduino board.
   - Ensure all components (load cell, LCD, LEDs, and buzzer) are correctly connected to the Arduino board.
   - Follow the prompts on the LCD display to initiate weight measurement and interpret the visual and audible indicators as necessary.

### Dependencies

- This project requires the Arduino IDE for uploading sketches to the Arduino board.
- Ensure all necessary libraries are installed for the proper functioning of components such as the LCD, load cell, LEDs, and buzzer.

### Contributors

- [Bharath KUMAR V](https://github.com/bharathkumar0246) - Add your contributions here if you have contributed to the project.
