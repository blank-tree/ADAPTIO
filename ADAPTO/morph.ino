/**
 * ADAPTIO
 * Morphing function
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161010
 * @version: 0.1
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

// Constants
// const int servoRange[4][2] = {
// 	{0,180}, // Servo 0
// 	{0,180}, // Servo 1
// 	{0,180}, // Servo 2
// 	{0,180}  // Servo 3
// };

// Variables
int duration;
int[] servoPositioning;
int lastInput;
unsigned long lastPeak;

void morphSetup() {

	duration = 0;

	for(int i=0; i<4; i++){
	    servoPositioning[i] = 0;
	}

	lastInput = 0;
	lastPeak = 0;
}

int[] morphLoop(int morphInput) {

	// How are we going to changed this stuff?! Good question I guess...
	
	if(morphInput != lastInput || morphInput == 0) {

		int selectedServo[] = random(0, 4);

		int selectedServoSize = 0; // TODO

		for(int i=0; i<4; i++){
		    
			double factor = 1;

			if (morphInput < 0) {
				morphInput = 0;
			}

			if (morphInput > 1000) {
				morphInput = 1000;
			}

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

			servoPositioning[i] = servoPositioning[i] * factor;

			if (servoPositioning[i] < servoRange[i][0]) {
				servoPositioning[i] = servoRange[i][0];
			}

			if (servoPositioning[i] > servoRange[i][1]) {
				servoPositioning[i] = servoRange[i][1];
			}

		}
	}

	lastInput = morphInput;

	return servoPositioning;
}