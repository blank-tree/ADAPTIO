/**
 * ADAPTIO
 * Output artefact for the physical computing module 2016 during the third semester «Interaction Design» studies at the Zurich University of the Arts
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161010
 * @version: 0.2
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

// Include libraries
#include <Servo.h>

// Constants
const int ARRAY_SIZE = 4;
const int PINS_SERVO[ARRAY_SIZE] = {A1, A2, A3, A4};

// Variables
Servo servos[ARRAY_SIZE];
float servoPositions[ARRAY_SIZE];
// int currentInput;

// Testing variable
const int SENSOR_PIN = A5;

void setup() {

	// receiveSetup();
	morphSetup();

	for(int i=0; i<ARRAY_SIZE; i++){
		// Attach servo pins to the servo variables
	    servos[i].attach(PINS_SERVO[i]);

	    // initialize servo positions
	    servoPositions[i] = 0;
	}

	Serial.begin(9600);
}

void loop() {

	// receiveLoop();
	// morphLoop(getInput());

	// Testing
	float sensorValue = analogRead(SENSOR_PIN); // Readout on variable
	// Serial.println(sensorValue);
	sensorValue = map(sensorValue, 0, 1023, 0, 1000);
	morphLoop(sensorValue);


	

	// position servos
	for(int i=0; i<ARRAY_SIZE; i++){
	    servos[i].write(servoPositions[i]);
	}	
}
