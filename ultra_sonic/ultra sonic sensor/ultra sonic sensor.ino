/*
 * Created by ArduinoGetStarted, https://arduinogetstarted.com
 *
 * Arduino - Ultrasonic Sensor HC-SR04
 *
 * Wiring: Ultrasonic Sensor -> Arduino:
 * - VCC  -> 5VDC
 * - TRIG -> Pin 2
 * - ECHO -> Pin 3
 * - GND  -> GND
 *
 * Tutorial is available here: https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor
 */

int trigPin = 2;    // TRIG pin
int echoPin = 3;    // ECHO pin
int brightness = 0;

int duration_us, distance_cm;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;
  // brightness = map(distance_cm, 0, 1023, 0, 255);
  brightness = distance_cm;
  // print the value to Serial Monitor
  //Serial.write("distance: ");
  Serial.write(brightness);
  //Serial.write(" cm");

  delay(200);
}