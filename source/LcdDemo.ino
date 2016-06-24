#include <LiquidCrystal.h>
#include "MemoryFree.h"

// constants won't change. Used here to set a pin number :
// the number of the LED pin
const int ledPin = 13;      

// Variables will change :
// ledState used to set the LED
int ledState = LOW;             

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
// will store last time LED was updated
unsigned long previousMillis = 0;        

// constants won't change :
// interval at which to blink (milliseconds)
const long interval = 1000;           

unsigned short counter = 0;
unsigned short state = 0;

const unsigned short DisplayWidth = 24;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 0, 1, 2, 3, 4, 5, 6, 7);
//LiquidCrystal lcd(8, 9, 10, 4, 5, 6, 7);
void setup() {
	// set the digital pin as output:
	pinMode(ledPin, OUTPUT);

	// set up the LCD's number of columns and rows:
	lcd.begin(DisplayWidth, 2);
	delay(50);

	// Print a message to the LCD.
	DisplayMessage(1, "Kurde, udalo sie!");
	DisplayFreeMemory(2);

	delay(2000);
	lcd.clear();
}



void loop() {
	
	// here is where you'd put code that needs to be running all the time.

	// 
	unsigned long startProcessingTime = millis();

	// Max number of states used to display messages in line 1
	const int MaxMessagingState = 4;

	switch (state)
	{
	case 0:
		DisplayMessage(1, "LCD Demo Application");
		break;
	case 1:
		DisplayMessage(1, "Version: 1.0, 24/06/2016");
		break;
	case 2: 
		DisplayFreeMemory(1);
		break;
	case 3:
		DisplayProcessingTime(1, startProcessingTime);
		break;

	default:
		DisplayMessage(1, "Fajnie dziala...   :-)");
		break;
	}

	DisplayWorkingTime(2);

	BlinkLed(MaxMessagingState);
}


// check to see if it's time to blink the LED; that is, if the
// difference between the current time and last time you blinked
// the LED is bigger than the interval at which you want to
// blink the LED.
void BlinkLed(int maxMessagingState)
{
	unsigned long currentMillis = millis();

	if (currentMillis - previousMillis >= interval) {
		// save the last time you blinked the LED
		previousMillis = currentMillis;

		// if the LED is off turn it on and vice-versa:
		if (ledState == LOW) 
		{
			ledState = HIGH;
		}
		else 
		{
			ledState = LOW;
		}

		// set the LED with the ledState of the variable:
		digitalWrite(ledPin, ledState);

		RefreshDisplayMode(maxMessagingState);
	}
}


// Display a message with time since reset.
// lineNumber can be 1 or 2
void DisplayWorkingTime(int lineNumber)
{
	String labelText = String("Czas od startu: ");
	String unitText = String("sek");
	String valueText = String();

	// print the number of seconds since reset:
	unsigned int seconds = millis() / 1000;
	if (seconds < 60)
	{
		valueText = labelText + seconds + unitText;
	}
	else
	{
		unsigned int mins = seconds / 60;
		unsigned int sek = seconds - mins * 60;

		if (sek < 10)
		{
			valueText = labelText + mins + ".0" + sek + "min";
		}
		else
		{
			valueText = labelText + mins + "." + sek + "min";
		}
	}

	DisplayMessage(lineNumber, valueText);
}


// Display Core Processing Time
void DisplayProcessingTime(int lineNumber, unsigned long startTime)
{
	String labelText = String("Czas wykonania: ");
	String unitText = String("ms");
	String valueText = String();

	unsigned long endTime = millis();
	unsigned long value = endTime - startTime;

	valueText = labelText + value + unitText;

	DisplayMessage(lineNumber, valueText);

	// Add a short delay to see fast changing value
	delay(100);
}


// Display Free Memory message
void DisplayFreeMemory(int lineNumber)
{
	String labelText = String("Wolna pamiec: ");
	String unitText = String(" bytes");
	String valueText = String();

	valueText = labelText + freeMemory() + unitText;

	DisplayMessage(lineNumber, valueText);
}



void RefreshDisplayMode(int maxMessagingState)
{
	if (++counter > 5)
	{
		counter = 0;
		if (++state > maxMessagingState)
		{
			state = 0;
		}
	}
}


// Display text message
void DisplayMessage(int lineNumber, String message)
{
	lcd.setCursor(0, lineNumber == 1 ? 0 : 1);

	lcd.print(message);
	for (int i = message.length(); i < DisplayWidth; i++)
	{
		lcd.print(" ");
	}
}