# 🌱 Automatic Plant Watering System

An IoT-based automated hardware and software solution designed to monitor soil moisture and manage water resources efficiently for optimal plant care.

---
## 📝 Project Description

The **Automatic Plant Watering System** is an intelligent embedded system that uses a soil moisture sensor to detect the dryness of the soil and a water level sensor to monitor the water tank level. 
When the soil moisture drops below a predefined threshold, the microcontroller evaluates the water availability. If sufficient water is present, the system activates the watering mechanism until the desired moisture is reached. If the tank is empty, it halts the process and alerts the user via a **16x2 LCD display**.

---
## ⚡ Key Features
* **Soil Condition Monitoring:** Dynamically categorizes soil status into WET, NORMAL, or DRY based on real-time analog sensor readings.
* **Resource Management:** Prevents pump damage by verifying the water tank level before initiating any watering cycle.
* **Intelligent Actuation Logic:** Watering occurs strictly when the soil is dry *and* sufficient water is available.
* **Live Display Interface:** Keeps users informed with a parallel interface LCD showing the current soil condition or displaying a "Water Tank Empty" warning.
---
## 🛠️ Hardware Components
* **Microcontroller:** Arduino Uno.
* **Sensors:** 
  * Soil moisture sensor (simulated via Potentiometer on Analog Pin A0).
  * Water level sensor (simulated via Potentiometer on Analog Pin A1).
* **Display:** 16x2 LCD Display (parallel interface).
* **Actuators:** LED with a 220Ω resistor (simulating the water pump connected to Digital Pin 13).
* **Power:** 5V power supply and connecting wires.
---
## 📐 System Logic & Simulation Flow
The firmware manages the automated watering process by polling analog values from two independent sensors and processing them through conditional logic blocks.
1. **Data Acquisition:** 
   * The Arduino reads the soil moisture analog value (`A0`).
   * The Arduino reads the water tank analog value (`A1`).
   
2. **Soil Evaluation:**
   * Value `< 400`: Soil is classified as **WET**.
   * Value between `400` and `700`: Soil is classified as **NORMAL**.
   * Value `> 700`: Soil is classified as **DRY**.
3. **Water Level & Actuation Sequence:**
   * If the water sensor reads `> 200` (Sufficient Water) **AND** the soil is **DRY**, the microcontroller triggers the LED (`HIGH`) to start watering.
   * If the soil is wet/normal, the LED remains `OFF`.
   * If the water sensor reads `< 200` (Empty Tank), the watering is aborted (LED `OFF`), and the LCD strictly overrides normal display to show "Water Tank Empty".
---

---
## 🔄 System States & Logic Verification
To verify the control firmware, the system was thoroughly simulated using Proteus ISIS. The matrix below demonstrates the exact truth table of the system inputs, the resulting LCD feedback, and the actuator (LED) status:
<br>
| Scenario | Analog Inputs <br> `(SOIL  / TANK )` | LCD Display Status | Pump Status (LED 13) | Simulation Preview |
| :--- | :--- | :--- | :--- | :--- |
| **1. Soil Wet** <br> *(Water tank has water)* | `< 400` / `> 200` | "Soil: WET"<br>"STOP WATRING..." | OFF | <img src="https://github.com/user-attachments/assets/aea4960b-c6d1-4f42-9922-ec1ce80075cf" width="200"> |
| **2. Soil Normal** <br> *(Water tank has water)* | `400 - 700` / `> 200` | "Soil: NORMAL"<BR>"STOP WATRING..." | OFF | <img src="https://github.com/user-attachments/assets/384bb7fc-3b47-4582-877d-c10b024823ae" width="200"> |
| **3. Active Watering** <br> *(Soil is dry & water available)* | `> 700` / `> 200` | "Soil: DRY"<BR>"WATRING.." | ON (Watering) | <img src="https://github.com/user-attachments/assets/29060522-b622-4044-b460-10a8ed172264" width="200"> |
| **4. Error / Tank Empty** <br> *(Regardless of soil condition)* | `Any` / `< 200` | "Water Tank Empty" | OFF (Safe Mode) | <img src="https://github.com/user-attachments/assets/2330a90d-0025-4f5f-a23e-9bf1e8d2458f" width="200"><br><img src="https://github.com/user-attachments/assets/c4192769-adb4-43aa-bef1-849b5eced6c0" width="200">|

---
---
## 💻 Code Structure
The repository includes:
* `Smart_Watering.ino` - The core firmware containing analog sensor polling logic, nested conditions for system safety, and the LiquidCrystal display driver commands.
---
## 🚀 How to Run the Project
1. Clone the repository to your local machine.
2. Open `Smart_Watering.ino` in the Arduino IDE.
3. Ensure the built-in `LiquidCrystal.h` library is included.
4. Upload the code to your Arduino Uno board and connect the hardware according to the specified pinout tables.
5. Alternatively, load the generated `.hex` file into your Proteus ISIS simulation.
<br><br>
