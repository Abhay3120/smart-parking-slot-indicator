# Smart Parking Slot Indicator

An IoT-based system that detects whether each parking slot is free or occupied using IR sensors and a NodeMCU ESP8266. The status is shown instantly on LED indicators and on a web page over Wi-Fi.

## Project Details

- **Subject:** Digital Electronics
- **Submitted to:** Niraj Pathak
- **University:** K.R. Mangalam University

## Team Members

| Name | Roll No. |
|---|---|
| Harsh Verma | 2601730261 |
| Ritesh | 2601730249 |
| Aditya Choudhary | 2601730238 |
| Abhay Kumar | 2601730232 |

## Components Used

| Component | Quantity | Purpose |
|---|---|---|
| NodeMCU ESP8266 | 1 | Microcontroller with built-in Wi-Fi; reads sensors and hosts the web page |
| IR obstacle sensor module | 3 | Detects a car in each slot (one sensor per slot) |
| LED (red) | 3 | Glows when the matching slot is occupied |
| 220 ohm resistor | 3 | Limits the current through each LED |
| Breadboard | 1 | Holds the circuit without soldering |
| Jumper wires | 1 set | Makes the connections |
| USB cable / 5 V supply | 1 | Powers the NodeMCU and uploads the program |

## How It Works

1. Each IR sensor outputs LOW (logic 0) when a car is in front of it and HIGH (logic 1) when the slot is empty.
2. The NodeMCU reads the three sensor pins as digital inputs.
3. If a pin is LOW, the slot is marked occupied and its LED turns ON; if HIGH, the slot is free and the LED stays OFF.
4. The NodeMCU also hosts a web page over Wi-Fi that shows FREE or OCCUPIED for every slot.

## Folder Guide

| Folder / File | What it contains |
|---|---|
| `report/Smart_Parking_Report.pdf` | Final project report |
| `code/smart_parking.ino` | Arduino source code for the NodeMCU |
| `presentation/Smart_Parking_Slot_Indicator.pptx` | Project slides |
| `images/` | Circuit diagram and project photos |
| `README.md` | This file |

## How to Run

1. Open `code/smart_parking.ino` in the Arduino IDE.
2. Install the ESP8266 board package and select **NodeMCU 1.0 (ESP-12E Module)**.
3. Replace `YOUR_WIFI` and `YOUR_PASSWORD` with your Wi-Fi details.
4. Upload the code, open the Serial Monitor to find the NodeMCU's IP address, and enter it in a phone or laptop browser on the same Wi-Fi.
