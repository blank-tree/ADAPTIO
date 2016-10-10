/**
 * ADAPTIO
 * Morphing function
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161010
 * @version: 0.1
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 */

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

	return servoPositioning;

}