#include <Servo.h>

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

#define TRIG_PIN A5
#define ECHO_PIN A4

Servo myServo;
#define SERVO_PIN 3

long duration;
int distance;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(90); // Center position

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  Serial.begin(9600);
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) {  // Obstacle detected closer than 20 cm
    stopCar();
    delay(200);

    // Turn servo to scan left or right
    myServo.write(30);  // Turn servo left
    delay(500);
    int leftDist = getDistance();

    myServo.write(200); // Turn servo right
    delay(500);
    int rightDist = getDistance();

    myServo.write(150);  // Back to center

    if (leftDist > rightDist) {
      turnRight();
      delay(500);
    } else if(leftDist == rightDist){
      forward();
      delay(100);
    } else {
      turnLeft();
      delay(500);
    }
  } else { // This 'else' now correctly pairs with the 'if (distance < 20)'
    backward();
  }
}
// Ultrasonic distance measurement function
int getDistance() {
  // Clear the trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set the trigger HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pin
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  int distance = duration * 0.034 / 2;

  return distance;
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}