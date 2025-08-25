# 🤖 Autonomous Obstacle Avoidance Robot with Servo Scanning

An Arduino-based robotic car that uses an ultrasonic sensor on a servo motor to intelligently detect obstacles and navigate its environment.

-----

## 🎥 Demo Video

The provided demo video shows a black, circular robot moving on a tiled floor and a person interacting with it. The video appears to be a good representation of a project similar to this one.

👉 [Demo video link here](https://youtu.be/FEy6YuiIQD8)

-----

## 📌 Project Description

This **Autonomous Obstacle Avoidance Robot** is an advanced version of a standard obstacle avoidance car. It uses a **servo motor** to pan an **ultrasonic distance sensor** (HC-SR04) left and right. This allows the robot to "look around" when it encounters an obstacle, enabling it to make more intelligent decisions about which direction to turn to find the clearest path.

The car constantly measures the distance to objects in front of it. When an obstacle is detected within a specific threshold, it stops, scans its surroundings, and then turns toward the side with the most open space.

-----

## 🧠 Features

  - 🔄 **Intelligent Obstacle Scanning** using a servo motor
  - 🚫 **Auto-stop** when an obstacle is too close
  - 🧠 **Smart Pathfinding** logic to determine the best direction to turn
  - 🛠️ Fully autonomous movement using **Arduino**
  - 🤖 **Continuous obstacle detection** and navigation

-----

## 🛠️ Hardware Components

| Component | Quantity |
|-----------------------------------|----------|
| Arduino UNO/Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| Motor Driver Module (L298N or similar) | 1 |
| DC Gear Motors | 2 |
| Wheels | 2 |
| Chassis | 1 |
| Battery Pack | 1 |
| Jumper Wires | As needed |

-----

## 🧰 Software Used

  - Arduino IDE
  - C/C++ (Arduino language)

-----

## 🔌 Pin Configuration

| Pin | Purpose |
|-----------------------------|--------------------------------------------|
| `ENA` (Pin 5) & `ENB` (Pin 6) | Motor driver speed control |
| `IN1` (Pin 7) & `IN2` (Pin 8) | Motor A control |
| `IN3` (Pin 9) & `IN4` (Pin 11)| Motor B control |
| `TRIG_PIN` (Pin A5) | Connected to HC-SR04 TRIG |
| `ECHO_PIN` (Pin A4) | Connected to HC-SR04 ECHO |
| `SERVO_PIN` (Pin 3) | Connected to Servo motor |
| Power Pins | 5V/12V for Arduino and motors |

-----

## 📜 How It Works

1.  The `getDistance()` function continuously measures the distance from the ultrasonic sensor.
2.  The car is programmed to move backward by default in the `loop()` function.
3.  If an obstacle is detected within **15 cm**, the car will stop.
4.  The servo motor then pans the ultrasonic sensor to the left (30°) and right (200°) to measure the distance on each side.
5.  The program compares the measured left and right distances:
      - If the left distance is greater than the right, the car **turns right**.
      - If the right distance is greater, it **turns left**.
      - If both distances are equal, the car moves **forward** for a short duration.
6.  The car continues this process, constantly adapting to its environment.

-----

## 🚀 Getting Started

### ✅ Uploading the Code

1.  Open the file named `sketch_jul31a.ino` in the **Arduino IDE**.
2.  Connect your **Arduino** board to your computer via USB.
3.  Select the correct board and **COM port** from the **Tools** menu.
4.  Click the **Upload** button to transfer the code to your Arduino board.

-----

## 👨‍💻 Authors

Developed by:

  - **Anshul Dewangan**
  - **Pratyaksh Lodhi**
  - **Aaron David Don**
  - **Joshua Benchamin**

-----

## 📝 License

This project is open-source and available under the [MIT License](https://www.google.com/search?q=LICENSE).

-----

## 📬 Contributions

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change or improve.
