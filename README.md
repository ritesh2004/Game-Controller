# NodeMCU and MPU6050 Game Controller

This project demonstrates how to build a motion-based game controller using **NodeMCU** and the **MPU6050 sensor**. The sensor captures motion data, which is processed by the NodeMCU and sent to a Python script via the serial port. The Python script then controls the keyboard using the **PyAutoGUI** library to simulate keyboard inputs based on motion.

## Features
- **Motion-based control**: The MPU6050 sensor captures motion data and controls the game accordingly.
- **Python integration**: Python processes the sensor data and maps it to keyboard controls using PyAutoGUI.
- **Serial communication**: The NodeMCU communicates with Python via the serial port.

## Project Components
- **NodeMCU**: Microcontroller that interfaces with the MPU6050.
- **MPU6050**: 3-axis gyroscope and accelerometer for motion data.
- **Python Script**: Uses the PyAutoGUI library to control the keyboard based on motion data received.
- **PyAutoGUI**: Python library for simulating keyboard inputs.
  
## How It Works
1. The MPU6050 sensor provides accelerometer and gyroscope data to the NodeMCU.
2. The NodeMCU sends the data through a serial connection to the Python script running on the computer.
3. The Python script processes the data and uses the PyAutoGUI library to simulate keyboard presses.
4. The keyboard inputs control the game or application based on user movements.

## Installation and Setup

### Hardware Setup
1. Connect the MPU6050 to the NodeMCU:
   - **VCC** to **3.3V** (NodeMCU)
   - **GND** to **GND** (NodeMCU)
   - **SCL** to **D1** (NodeMCU)
   - **SDA** to **D2** (NodeMCU)

2. Ensure NodeMCU is properly connected to the computer via USB.

### Software Setup
1. Clone this repository.
   ```
   git clone https://github.com/ritesh2004/Game-Controller.git
   cd Game-Controller
   ```

2. Install necessary Python libraries:
   ```
   pip install -r requirements.txt
   ```

3. Upload the Arduino code to the NodeMCU:
   - Open the provided **NodeMCU.ino** file in the Arduino IDE.
   - Select the correct board (NodeMCU 1.0) and port.
   - Upload the code to the NodeMCU.

4. Run the Python script:
   ```
   python main.py
   ```

## Usage
Once everything is set up, run the Python script and move the MPU6050 sensor. The script will detect the motion and simulate keyboard presses to control the game or application.

## Limitations
- **Performance**: The system is functional but not highly optimized for speed. There is some latency between motion and the corresponding keyboard input.
- **Keyboard Mapping**: Currently, the keyboard inputs are basic. More advanced controls can be added as needed.

## Future Improvements
- Improve the speed of serial communication for faster response time.
- Enhance keyboard mapping for more complex game controls.
- Add customization options for different game genres.

## License
This project is open-source and licensed under the MIT License.
