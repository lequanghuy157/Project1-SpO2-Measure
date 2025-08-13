# STM32 SpO2 with MAX30100

This project is a real-time blood oxygen saturation (SpO2) using an STM32 microcontroller, a MAX30100 sensor, and a standard 16x2 character LCD. The code is developed using the STM32CubeIDE and HAL libraries.


## Features

-   **Real-time SpO2 Calculation:** Measures blood oxygen saturation levels.
-   **LCD Display:** Shows results clearly on a 16x2 character LCD.
-   **Robust Algorithm:** Uses the Root Mean Square (RMS) of the signal's AC component to provide more stable readings against noise.

## Hardware Required

| Component                                         | Quantity | Notes                                            |
| ------------------------------------------------- | :------: | ------------------------------------------------ |
| STM32F103C8T6 ("Blue Pill") Board                 |    1     | Or any other compatible STM32F1 series board.    |
| MAX30100 Pulse Oximeter & Heart-Rate Sensor       |    1     |                                                  |
| Other                                             |          | Wires, resistor, v.v...                          |


## Wiring Diagram


if you need, please contact me, i will give you Altium file


## Software & Tools

-   [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) (Version 1.9.0 or later recommended)
-   STM32CubeMX (included in the IDE)
-   Git

## How to Build and Run

1.  **Clone the Repository:**
    ```bash
    git clone (https://github.com/lequanghuy157/Project1-SpO2-Measure)
    ```

2.  **Open in STM32CubeIDE:**
    -   Launch STM32CubeIDE.
    -   Go to `File` > `Import...`.
    -   Select `General` > `Existing Projects into Workspace` and click `Next`.
    -   For `Select root directory`, browse to the folder you just cloned.
    -   Make sure the project is checked and click `Finish`.

3.  **Generate HAL Drivers (if needed):**
    -   Double-click the `.ioc` file in the Project Explorer.
    -   The STM32CubeMX perspective will open. You don't need to change anything.
    -   A dialog will ask "Do you want to generate Code?". Click **Yes**. This will generate the `Drivers` and `Middlewares` folders, which are not stored in the repository.

4.  **Build the Project:**
    -   Click the "Build" button (the hammer icon) on the toolbar or press `Ctrl+B`.

5.  **Flash the Microcontroller:**
    -   Connect your STM32 board to your computer via an ST-Link programmer (KeilC)
    -   Click the "Run" button (the green play icon) on the toolbar or press `F11`.
    -   The IDE will compile and flash the code to your board. The LCD should light up and start displaying data.

## Algorithm Details

The calculation of SpO2 and heart rate is based on the principles of photoplethysmography (PPG).

1.  **Data Acquisition:** The MAX30100 sensor measures the amount of Red and Infrared (IR) light reflected by the blood flowing through the finger.
2.  **Signal Components:** For both Red and IR signals, we separate the DC component (average light absorption) and the AC component (pulsating absorption due to heartbeats).
3.  **Ratio of Ratios (R):** The core of SpO2 calculation is the "Ratio of Ratios", calculated as:
    ```
    R = (AC_red / DC_red) / (AC_ir / DC_ir)
    ```
    Instead of a simple peak-to-peak method, this project uses the **Root Mean Square (RMS)** of the AC component, which makes the calculation more robust against noise.
4.  **SpO2 Lookup:** An empirical formula is used to convert the `R` value into an SpO2 percentage.
    ```
    // spo2 = A*R^2 + B*R + C;
    float spo2 = 1.5958422f * R * R - 34.6596622f * R + 112.6898759f;
    ```

## License

Huy
