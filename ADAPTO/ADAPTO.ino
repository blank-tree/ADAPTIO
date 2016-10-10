/**
 * ADAPTIO
 * Output artefact for the physical computing module 2016 during the third semester «Interaction Design» studies at the Zurich University of the Arts
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161010
 * @version: 0.2
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 */

// Include libraries
#include <Servo.h>

// Constants
const int[] PINS_SERVO = {1, 2, 3, 4};

// Variables
Servo[] servos;
int[] servoPositions;
int currentInput;


void setup() {

	receiveSetup();
	morphSetup();

	for(int i=0; i<4; i++){
		// Attach servo pins to the servo variables
	    Servo[i].attach(PINS_SERVO[i]);

	    // initialize servo positions
	    servoPositions[i] = 0;
	}	
}

void loop() {

	receiveLoop();
	servoPositions = morphLoop(getInput());

	// position servos
	for(int i=0; i<4; i++){
	    servos[i].write(servoPositions[i]);
	}

	
}
