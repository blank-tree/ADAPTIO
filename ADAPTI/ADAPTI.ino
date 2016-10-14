/**
 * ADAPTI
 * Input artefact for the physical computing module 2016 during the third semester «Interaction Design» studies at the Zurich University of the Arts
 * @author: Fernando Obieta - https://blanktree.ch
 * @date: 161011
 * @version: 0.3
 * DO WHAT THE FUCK YOU WANT TO - PUBLIC LICENSE
 */


// Variables
int inputValue;

void setup() {
	
	// Begin serial for debugging
	Serial.begin(9600);

	// Initialize variables
	inputValue = 0;

	// Setup sending to switchr.io
	sendSetup();

	flexSetup();

}

void loop() {

	inputValue = flexLoop()

	sendLoop(inputValue);
}