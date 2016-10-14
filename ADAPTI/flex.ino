/**
 * ADAPTI - flex
 * Reads the flexing
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161013
 * @version: 0.6
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */

//Constants
const int PINS_FLEX[4] = {A1, A2, A3, A4};
const int ARRAY_SIZE = 4;
const int FLEX_RANGE[4][2] = {
	{600,650}, // Flex 1
	{600,715}, // Flex 2
	{630,700}, // Flex 3
	{450,580}  // Flex 4
};

// Variables
// int inputValue;
int flexValues[ARRAY_SIZE];

void flexSetup() {
	
	// inputValue = 0;

	for(int i=0; i<4; i++){
	    flexValues[i] = 0;
	}

}

int flexLoop() {

	int highestValue = 0;

	for(int i=0; i<ARRAY_SIZE; i++){
	    int currentReadout = analogRead(PINS_FLEX[i]);

	    if (currentReadout < FLEX_RANGE[i][0]) {
	    	currentReadout = FLEX_RANGE[i][0];
	    }

	    if (currentReadout > FLEX_RANGE[i][1]) {
	    	currentReadout = FLEX_RANGE[i][1];
	    }

	    currentReadout = map (currentReadout, FLEX_RANGE[i][0], FLEX_RANGE[i][1], 0, 1000);

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