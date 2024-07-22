// Ultrasonic sensor pins
#define echoPin 9 // Ultrasonic sensor echo pin connected to Arduino pin 9
#define trigPin 10 // Ultrasonic sensor trig pin connected to Arduino pin 10

// Motor A pins
#define MotorPinA 12 // Direction pin for Motor A (enA)
#define MotorSpeedPinA 3 // PWM speed control pin for Motor A  


// Motor B pins
#define MotorPinB 13 // Direction pin for Motor B (enB)  
#define MotorSpeedPinB 11 // PWM speed control pin for Motor B 


long duration, distance; // Variables for duration and distance measurement

void setup() {
  // Ultrasonic sensor pins setup
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // Motor pins setup
  pinMode(MotorPinA, OUTPUT);
  pinMode(MotorSpeedPinA, OUTPUT);
 
  
  pinMode(MotorPinB, OUTPUT);
  pinMode(MotorSpeedPinB, OUTPUT);
 

  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  // Ultrasonic sensor measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 29.1) / 2;

  Serial.println(distance);

  if (distance < 15) { // If distance is less than 15 cm
    moveBackward();
    delay(150);
    turnRight();
    delay(250);
  } else {
    moveForward(); // Move forward if distance is greater than or equal to 15 cm
  }
}

void turnRight() {
  digitalWrite(MotorPinA, HIGH);
  digitalWrite(MotorPinB, HIGH);
  analogWrite(MotorSpeedPinA, 155);
  analogWrite(MotorSpeedPinB, 70);
  delay(150);
}

void turnLeft() {
  digitalWrite(MotorPinA, HIGH);
  digitalWrite(MotorPinB, HIGH);
  analogWrite(MotorSpeedPinA, 70);
  analogWrite(MotorSpeedPinB, 155);
  delay(150);
}

void moveForward() {
  // Move both motors forward
  digitalWrite(MotorPinA, HIGH);
  analogWrite(MotorSpeedPinA, 250);
  digitalWrite(MotorPinB, HIGH);
  analogWrite(MotorSpeedPinB, 250);
 
}

void moveBackward() {
  // Move both motors backward
  digitalWrite(MotorPinA, LOW);
  analogWrite(MotorSpeedPinA, 150);
  digitalWrite(MotorPinB, LOW);
  analogWrite(MotorSpeedPinB, 150);
  
}

void moveFullSpeedAhead() {
  digitalWrite(MotorPinA, HIGH);
  digitalWrite(MotorPinB, HIGH);
  analogWrite(MotorSpeedPinA, 250);
  analogWrite(MotorSpeedPinB, 250);
}

void moveLightSpeedForward() {
  digitalWrite(MotorPinA, HIGH);
  digitalWrite(MotorPinB, HIGH);
  analogWrite(MotorSpeedPinA, 105);
  analogWrite(MotorSpeedPinB, 105);
}

 void moveFullSpeedBackwards() {
  digitalWrite(MotorPinA, LOW);
  digitalWrite(MotorPinB, LOW);
  analogWrite(MotorSpeedPinA, 250);
  analogWrite(MotorSpeedPinB, 250);
}

void Stop() {
  digitalWrite(MotorPinA, LOW);
  digitalWrite(MotorPinB, LOW);
  analogWrite(MotorSpeedPinA, 0);
  analogWrite(MotorSpeedPinB, 0);
}

void accelerateSlightly() {
  for (int speed = 0; speed <= 105; speed += 5) {
    analogWrite(MotorSpeedPinA, speed);
    analogWrite(MotorSpeedPinB, speed);
    delay(30);
  }
}

void accelerate() {
  for (int speed = 0; speed <= 250; speedd += 5) {
    analogWrite(MotorSpeedPinA, speed);
    analogWrite(MotorSpeedPinB, speed);
    delay(30);
  }
}

void slowDown() {
  for (int speed = 250; speed >= 0; speed-= 5) {
    analogWrite(MotorSpeedPinA, speed);
    analogWrite(MotorSpeedPinB, speed);
    delay(30);
  }
}


