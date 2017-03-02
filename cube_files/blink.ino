#include <Rainbowduino.h>
#include <util/delay.h>

/**
* In this sketch a 4x4x4 Cube of LEDs blinks with intervals of 2 seconds
*/

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

int z,x,y;	
int green = 0x00FF00;

void loop()
{
	for(z=0; z<4; z++)
	{ 
		for(x=0; x<4; x++)
		{
			for(y=0; y<4; y++)
			{
				Rb.setPixelZXY(z, x, y, green); // Set the LED to green 
			}
		}
	}

	_delay_ms(2000); 	// Introduce a delay of 2 seconds
	Rb.blankDisplay(); 	// Switch off the LEDs
	_delay_ms(2000); 	// Introduce a delay of 2 seconds
}