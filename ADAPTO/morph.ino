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
const int DURATION = 250; // 0.25sec

// Variables
int duration;
int[] servoPositioning;
int lastInput;
unsigned long lastActivation;

void morphSetup() {

	duration = 0;

	for(int i=0; i<4; i++){
	    servoPositioning[i] = 0;
	}

	lastInput = 0;
	lastActivation = 0;
}

int[] morphLoop(int morphInput) {

	long currentTime = millis();

	if (currentTime - lastActivation > DURATION) {
	
		if(morphInput != lastInput || 
			(morphInput == 0 && servoPositioning[selectedServo] != 0)) {

			int selectedServo = random(0, 4);
			    
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

			servoPositioning[selectedServo] = servoPositioning[selectedServo] * factor;

			if (servoPositioning[selectedServo] < servoRange[selectedServo][0]) {
				servoPositioning[selectedServo] = servoRange[selectedServo][0];
			}

			if (servoPositioning[selectedServo] > servoRange[selectedServo][1]) {
				servoPositioning[selectedServo] = servoRange[selectedServo][1];
			}

			lastActivation = currentTime;
		}
	}

	lastInput = morphInput;

	return servoPositioning;
}