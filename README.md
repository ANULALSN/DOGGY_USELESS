EMOTIONAL DOGGIE 🎯
Basic Details
Team Name: InCo
Team Members
Team Lead: NIVEDITHA.T - ST.JOSEPH'S COLLEGE DEVAGIRI
Member 2: ANULAL.P - ST.JOSEPH'S COLLEGE DEVAGIRI
Member 3: SIMRA RIYAZ - ST.JOSEPH'S COLLEGE DEVAGIRI
Project Description
This project is a mood-responsive robotic dog that reacts to objects detected within a certain range using an ultrasonic sensor. It displays three emotions—happy, sad, and angry—through specific servo movements and buzzer sounds, creating realistic behaviors that mimic a dog’s reactions.

The Problem (that doesn't exist)
Ever wondered if machines have feelings? Here’s a groundbreaking way to "prove" it: with a robotic dog that shows its "emotions" through motions and sounds. By interpreting distance-based sensor inputs, this robotic dog becomes happy, sad, or angry depending on its surroundings. Finally, we can confirm that even motors and sensors have moods—because who says only humans get emotional?

The Solution (that nobody asked for)
Introducing the "Mood Swing-o-Meter" dog: a completely unnecessary, yet oddly delightful, robotic friend that reacts to the world with its own unique "emotional" flair! Using an ultrasonic sensor to detect objects, this robo-dog spins, beeps, and twitches to express happiness, sadness, or anger. Each mood triggers a specific servo motion and buzzer tune—proving, once and for all, that machines, too, can have attitude. Because if robots can feel, maybe our appliances are secretly sulking in the background!

Languages used: C++ (Arduino IDE)
Frameworks used: Arduino Platform
Libraries used:
Servo.h - To control the servo motor, giving it the ability to rotate and create “emotional” gestures.
Tools used: Arduino IDE for coding and uploading the sketch to the Arduino board.
For Hardware:

Arduino Uno - The brain of the robo-dog, processing sensor input and controlling the motor and buzzer.
HC-SR04 Ultrasonic Sensor - Detects objects within a specific distance range to trigger different "emotions."
SG90 9g Micro Servo Motor - Provides movement to display emotional responses like rotating for happiness or twitching for anger.
Buzzer - Produces sound patterns to complement each mood, varying pitch and rhythm to match each "emotion."
Breadboard and Wires - For easy and organized connections.

Implementation
For Software:
1.Setup and Initialization:

The code initializes communication with the Arduino IDE's Serial Monitor for debugging purposes.
The Servo object is attached to a designated pin on the Arduino, allowing control over the motor movements.
Pins for the ultrasonic sensor (trig and echo) and buzzer are defined and set as inputs or outputs as needed.
The system starts in a neutral state with the servo in a neutral position and the buzzer off.
2.Loop Functionality:

The main loop continuously checks for an object within a specified distance using the ultrasonic sensor.
The distance from the object determines the "mood" of the robot dog:
Happy: Close distance (less than 10 cm) triggers a happy response.
Sad: Medium distance (10-20 cm) triggers a sad response.
Angry: Farther distance (20-30 cm) triggers an angry response.
If no object is detected within 30 cm, the system remains in a "neutral" state with the buzzer silent and servo in a resting position.
3.Mood-Based Actions:

For each mood, the code updates the servo and buzzer output:
Happy:
The servo rotates between 0° and 180° to simulate a joyful wagging motion.
The buzzer plays a rhythmic, friendly tone pattern.
Sad:
The servo holds a neutral position to represent low energy.
The buzzer plays a slower, softer tone.
Angry:
The servo quickly twitches between 0° and 180° to simulate frustration.
The buzzer emits an annoying, high-pitched beeping sound.
4.State Management:

The current mood only changes if a different mood condition is met and a minimum interval has passed since the last change.
This prevents rapid switching and ensures that each mood is sustained for a short time before changing.
5.Sensor and Actuator Interaction:

Ultrasonic sensor readings control the moods, while the servo and buzzer reflect those moods through movement and sound.

Installation
1.Set Up Arduino IDE:

Download and install the Arduino IDE for your operating system.
2.Connect the Components:

Wire the ultrasonic sensor, servo motor, and buzzer to the Arduino as per the connection diagram.
3.Install Required Libraries:

Ensure the Servo library is included. It typically comes pre-installed with the Arduino IDE. To check, go to Sketch > Include Library > Servo.
4.Upload Code to Arduino:

Connect the Arduino to your computer via USB.
Open the code in the Arduino IDE.
5.Select the correct board and port:
scss
Copy code
Tools > Board > Arduino Uno (or your model)
Tools > Port > [Select the connected port]
Click Upload (the right arrow button in the IDE).
6.Power the Arduino:

Once the code is uploaded, disconnect the USB (if preferred) and power the Arduino through an external source (like a battery pack or power adapter) if it’s a standalone project.

Run
1.Power On Arduino:

Connect the Arduino to power through USB or an external battery pack.
Monitor Serial Output (optional for debugging):

2.If connected via USB, open the Serial Monitor in the Arduino IDE:
arduino
Copy code
Tools > Serial Monitor
Set the baud rate to 9600 to view debug messages and check mood updates as the distance varies.
Place an Object in Front of the Sensor:

3.To test the emotions:
Move an object closer or farther from the ultrasonic sensor to trigger happy, sad, or angry moods.
Observe the actions of the servo motor and the buzzer's sound pattern corresponding to each mood.
Adjust as Needed:

Adjust the object's position or the delay in the code to modify responsiveness if needed.

Project Documentation
4.For Software:



Diagrams


For Hardware:

Schematic & Circuit
![DOGGY](https://github.com/user-attachments/assets/a819502a-26f6-4f7c-ada8-8f4e06da0614)
1. Ultrasonic Sensor (HC-SR04)
Purpose: Measures distance between the sensor and an object.

Pins:

VCC: Connects to 5V on the Arduino to power the sensor.
GND: Connects to GND on the Arduino.
Trig: Connects to Pin 7 on the Arduino. This pin sends ultrasonic pulses when triggered.
Echo: Connects to Pin 6 on the Arduino. This pin receives the echo of the pulse and calculates distance.
Operation:

The Arduino sends a high signal to the Trig pin, triggering a pulse.
This pulse bounces back when it hits an object, and the Echo pin receives the returned signal.
The Arduino calculates distance based on the time taken for the echo to return, triggering various moods based on distance thresholds.
2. Servo Motor (SG90)
Purpose: Mimics the dog’s movement based on its mood.

Pins:

Signal: Connects to Pin 3 on the Arduino. This pin controls the motor’s position based on mood.
VCC: Connects to 5V on the Arduino for power.
GND: Connects to GND on the Arduino.
Operation:

The servo motor receives signals from Pin 3 to adjust its angle.
In the code, different angles represent different moods:
Happy: Repeated rotation.
Sad: Fixed angle.
Angry: Quick, aggressive back-and-forth movement.
3. Buzzer
Purpose: Produces sound patterns based on the mood of the robotic dog.

Pins:

Signal: Connects to Pin 5 on the Arduino. Controls the tone and rhythm of the sound for each mood.
VCC: Can be connected to 5V directly on the Arduino.
GND: Connects to GND on the Arduino.
Operation:

The Arduino sends various frequencies to the buzzer through Pin 5.
Different moods trigger different sound patterns:
Happy: Rhythmic, cheerful sound.
Sad: Slow, somber tone.
Angry: Rapid, loud sound pattern.
Powering the Circuit
The entire circuit is powered by the Arduino's 5V and GND pins.
If using a larger servo motor or multiple motors, an external power source might be necessary as Arduino’s 5V might not provide enough current for all components


Build Photos
![Components]![WhatsApp Image 2024-11-02 at 4 58 13 AM](https://github.com/user-attachments/assets/02245de2-8eda-4c96-b5e2-76f0ce1c7763)


![WhatsApp Image 2024-11-02 at 1 12 40 AM](https://github.com/user-attachments/assets/6afc1f11-851a-4edf-9128-e2884b0fc92e)



![Final]![WhatsApp Image 2024-11-02 at 7 04 35 AM](https://github.com/user-attachments/assets/4f856346-578d-4ca7-8360-d7cd20c9a0d2)
 The final build is a robotic dog model that showcases three distinct "emotions"—happy, sad, and angry—using an ultrasonic sensor, a servo motor, and a buzzer. The components are integrated with an Arduino, creating a responsive, emotive dog character that changes its behavior based on the distance of objects in front of it.

Project Demo
Video


https://github.com/user-attachments/assets/edcc06b1-8277-4dd4-a550-93010fb84b74

The video demonstrates different emotions of the doggy depending upon the distance from the person
the buzzer sound also varies according to the emotion

Additional Demos

Audio depicting various change in emotions.
https://github.com/user-attachments/assets/084c217b-92e0-4de4-9f67-9c88f080acf2



Team Contributions
ANULAL.P: HARDWARE 
[NIVEDITHA.T]: SOFTWARE
[SIMRA RIYAZ]: DESIGNING & ARTWORK
