/**
 * ADAPTIO
 * Morphing function
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161012
 * @version: 0.4
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

// Constants
const int servoRange[4][2] = {
	{5,170}, // Servo 0
	{5,170}, // Servo 1
	{5,170}, // Servo 2
	{5,170}  // Servo 3
};
const int ARRAY_SIZE_MORPH = 4;
const int DURATION = 250; // 0.25sec

// Variables
int duration;
int lastInput;
unsigned long lastActivation;

void morphSetup() {

	// Initialize all variables
	duration = 0;
	lastInput = 0;
	lastActivation = 0;
}

void morphLoop(double morphInput) {

	// save the current time into a new variable
	unsigned long currentTime = millis();

	// only morph when the duration is past
	if (currentTime - lastActivation > DURATION) {

		// select a servo at random
		int selectedServo = random(0, 4);
	
		// to prevent from running all the time, when no input is passed, only activate when the input alters
		// or the morph is still fading down
		// if(morphInput != lastInput || 
		// 	(morphInput <= 100 && servoPositions[selectedServo] != 0)) {
			    
			// define factor to multiply the servo positioning
			float factor = 1;

			// prevent the value from going below zero
			if (morphInput < 0) {
				morphInput = 0;
			}

			// prevent the value from going above 1000
			if (morphInput > 1000) {
				morphInput = 1000;
			}

			// all cases of different input factors
			if (morphInput <= 100) {
				factor = 0.75;
			} else if (morphInput > 100 && morphInput < 199) {
				factor = 1;
			} else if (morphInput > 200 && morphInput < 299 ) {
				factor = 1.05;
			} else if (morphInput > 300 && morphInput < 399 ) {
				factor = 1.1;
			} else if (morphInput > 400 && morphInput < 499 ) {
				factor = 1.15;
			} else if (morphInput > 500 && morphInput < 599 ) {
				factor = 1.2;
			} else if (morphInput > 600 && morphInput < 699 ) {
				factor = 1.25;
			} else if (morphInput > 700 && morphInput < 799 ) {
				factor = 1.3;
			} else if (morphInput > 800 && morphInput < 899 ) {
				factor = 1.35;
			} else {
				factor = 1.4;
			}

			// apply the factor to change the servo positioning
			// the plus 2 only prevents the positioning going below 2, so that the callculation with
			// the factor still works
			newServoPositions[selectedServo] = 2 + newServoPositions[selectedServo] * factor;

			// check that the positioning for the selected servo doesn't go below the defined range
			if (newServoPositions[selectedServo] < servoRange[selectedServo][0]) {
				newServoPositions[selectedServo] = servoRange[selectedServo][0];
			}

			// check that the positioning for the selected servo doesn't go above the defined range
			if (newServoPositions[selectedServo] > servoRange[selectedServo][1]) {
				newServoPositions[selectedServo] = servoRange[selectedServo][1];
			}

			// update the last activation variable so the functions waits for the defined duration
			lastActivation = currentTime;

			Serial.println(newServoPositions[selectedServo]);
		// }
	}

	// update the last input variable so the functions waits if the same input is passed
	lastInput = morphInput;
}