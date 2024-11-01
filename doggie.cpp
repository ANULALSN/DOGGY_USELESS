#include <Servo.h>

Servo myServo;

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 3;
const int buzzerPin = 5; // Pin for the buzzer

String currentMood = "neutral"; // Start in neutral mood
unsigned long lastMoodChangeTime = 0; // Time since last mood change
const unsigned long moodChangeInterval = 2000; // Minimum interval between mood updates in milliseconds

void setup() {
  Serial.begin(9600); // For debugging on Serial Monitor
  myServo.attach(servoPin); // Attach the servo motor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  myServo.write(90); // Start servo in neutral position
  noTone(buzzerPin); // Ensure the buzzer is off initially
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Calculate distance in cm

  // Check if an object is detected
  if (distance < 30) { // Only react when an object is detected within 30 cm
    String newMood = currentMood; // Start with current mood

    // Define moods based on distances
    if (distance < 10) {
      newMood = "happy";
    } else if (distance < 20) {
      newMood = "sad";
    } else {
      newMood = "angry"; // If distance is between 20 and 30 cm
    }

    // Only update mood if it has changed and enough time has passed
    unsigned long currentTime = millis();
    if ((newMood != currentMood) && (currentTime - lastMoodChangeTime > moodChangeInterval)) {
      currentMood = newMood; // Update current mood
      lastMoodChangeTime = currentTime; // Reset the mood change timer
      Serial.println(currentMood); // Print new mood for debugging

      // Update servo position and buzzer sound based on mood
      if (currentMood == "happy") {
        // Play a rhythmic pattern for happy mood
        for (int i = 0; i < 3; i++) {
          tone(buzzerPin, 1000); // Play sound (1000 Hz)
          delay(200);             // Play for 200 ms
          noTone(buzzerPin);      // Stop sound
          delay(100);             // Wait for 100 ms
        }
        // Simulate continuous rotation by moving quickly between 0° and 180°
        for (int i = 0; i < 10; i++) {
          myServo.write(0);
          delay(100); // Delay to control speed
          myServo.write(180);
          delay(100);
        }
      } else if (currentMood == "sad") {
        // Play a slower, rhythmic pattern for sad mood
        for (int i = 0; i < 2; i++) {
          tone(buzzerPin, 500); // Play sound (500 Hz)
          delay(400);            // Play for 400 ms
          noTone(buzzerPin);     // Stop sound
          delay(200);            // Wait for 200 ms
        }
        myServo.write(90); // Example position for sad mood
      } else if (currentMood == "angry") {
        // Annoying fast beeping pattern for angry mood
        for (int i = 0; i < 10; i++) {
          tone(buzzerPin, 2000); // Play sound (2000 Hz)
          delay(100);             // Play for 100 ms
          noTone(buzzerPin);      // Stop sound
          delay(100);             // Wait for 100 ms
        }
        // Aggressive movement for angry mood
        for (int i = 0; i < 5; i++) {
          myServo.write(0);
          delay(100);
          myServo.write(180);
          delay(100);
        }
      }
    }
  } else {
    // If no object is detected, ensure the buzzer is off and the servo is neutral
    noTone(buzzerPin); // Stop sound if no mood change
    myServo.write(90); // Set servo to a neutral position
    currentMood = "neutral"; // Keep mood as neutral when no object is detected
  }

  delay(500); // Delay to avoid overly frequent sensor readings
}
