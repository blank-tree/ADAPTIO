/**
 * ADAPTI - flex
 * Reads the flexing
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161011
 * @version: 0.3
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

//Constants
const int PINS_FLEX[4] = {0, 1, 2, 3};
const int ARRAY_SIZE = 4;

// Variables
int inputValue;
int flexValues[4];

void flexSetup() {
	
	inputValue = 0;

	for(int i=0; i<4; i++){
	    flexValues[i] = 0;
	}

}

int flexLoop() {

	int highestValue = 0;

	for(int i=0; i<ARRAY_SIZE; i++){
	    int currentReadout = analogRead(PINS_FLEX[i]);

	    if (highestValue < currentReadout) {
	    	highestValue = currentReadout;
	    }
	}

	inputValue = inputValue * 0.8 + highestValue * 0.2;

	if (inputValue > 1000) {
		inputValue = 1000;
	}

	if (inputValue < 0) {
		inputValue = 0;
	}

	return inputValue;	
}