/**
 * ADAPTIO
 * Output artefact for the physical computing module 2016 during the third semester «Interaction Design» studies at the Zurich University of the Arts
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161012
 * @version: 0.5
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

// Include libraries
#include <Servo.h>

// Constants
const int ARRAY_SIZE = 4;
const int PINS_SERVO[ARRAY_SIZE] = {A1, A2, A3, A4};
const int UPDATE_DELAY = 25;
const int servoRange[4][2] = {
	{5,170}, // Servo 0
	{5,170}, // Servo 1
	{5,170}, // Servo 2
	{5,170}  // Servo 3
};
const int PIN_EL = 7;

// Variables
Servo servos[ARRAY_SIZE];
float servoPositions[ARRAY_SIZE];
float newServoPositions[ARRAY_SIZE];
unsigned long lastUpdate[ARRAY_SIZE];
// int currentInput;

// Testing variable
const int SENSOR_PIN = A5;

void setup() {

	receiveSetup();
	morphSetup();

	for(int i=0; i<ARRAY_SIZE; i++){
		// Attach servo pins to the servo variables
	    servos[i].attach(PINS_SERVO[i]);

	    // initialize servo positions
	    servoPositions[i] = 0;
	    newServoPositions[i] = 0;
	    lastUpdate[i] = 0;
	}

	pinMode(PIN_EL, OUTPUT);

	Serial.begin(9600);
}

void loop() {

	// Serial.println("A");

	digitalWrite(PIN_EL, 255);

	// save the current time into a new variable
	unsigned long currentTime = millis();

	receiveLoop();
	morphLoop(getInput());

	// Testing
	// float sensorValue = analogRead(SENSOR_PIN); // Readout on variable
	// sensorValue = map(sensorValue, 0, 1023, 0, 1000);
	// morphLoop(sensorValue);
	// Testing end
	

	// position servos
	for(int i=0; i<ARRAY_SIZE; i++){

		// Delay the updates for the servo positions
		if (millis() - lastUpdate[i] > UPDATE_DELAY) {
			if (newServoPositions[i] > servoPositions[i]) {
				servoPositions[i] = servoPositions[i] + 1;
			} else if (newServoPositions[i] < servoPositions[i]) {
				servoPositions[i] = servoPositions[i] - 1;
			}
			lastUpdate[i] = currentTime;
		}

		int newVal = map(servoPositions[i], servoRange[i][0], servoRange[i][1], servoRange[i][1], servoRange[i][0]);

		// send new servo positions
	    servos[i].write(newVal);
	}	
}
