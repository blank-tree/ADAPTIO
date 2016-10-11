/**
 * ADAPTIO
 * Morphing function
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161011
 * @version: 0.2
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

// Constants
const int servoRange[4][2] = {
	{0,180}, // Servo 0
	{0,180}, // Servo 1
	{0,180}, // Servo 2
	{0,180}  // Servo 3
};
const int ARRAY_SIZE = 4;
const int DURATION = 250; // 0.25sec

// Variables
int duration;
int[] servoPositioning;
int lastInput;
unsigned long lastActivation;

void morphSetup() {

	// Initialize all variables
	for(int i=0; i<ARRAY_SIZE; i++){
	    servoPositioning[i] = 0;
	}
	duration = 0;
	lastInput = 0;
	lastActivation = 0;
}

int[] morphLoop(int morphInput) {

	// save the current time into a new variable
	long currentTime = millis();

	// only morph when the duration is past
	if (currentTime - lastActivation > DURATION) {

		// select a servo at random
		int selectedServo = random(0, 4);
	
		// to prevent from running all the time, when no input is passed, only activate when the input alters
		// or the morph is still fading down
		if(morphInput != lastInput || 
			(morphInput == 0 && servoPositioning[selectedServo] != 0)) {
			    
			// define factor to multiply the servo positioning
			double factor = 1;

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
				factor = 0.8;
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
			servoPositioning[selectedServo] = 2 + servoPositioning[selectedServo] * factor;

			// check that the positioning for the selected servo doesn't go below the defined range
			if (servoPositioning[selectedServo] < servoRange[selectedServo][0]) {
				servoPositioning[selectedServo] = servoRange[selectedServo][0];
			}

			// check that the positioning for the selected servo doesn't go above the defined range
			if (servoPositioning[selectedServo] > servoRange[selectedServo][1]) {
				servoPositioning[selectedServo] = servoRange[selectedServo][1];
			}

			// update the last activation variable so the functions waits for the defined duration
			lastActivation = currentTime;
		}
	}

	// update the last input variable so the functions waits if the same input is passed
	lastInput = morphInput;

	// return the new positioning array
	return servoPositioning;
}