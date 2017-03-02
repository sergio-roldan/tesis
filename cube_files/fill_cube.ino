#include <Rainbowduino.h>
#include <util/delay.h>

/**
* Create a sketch that fills all the LEDs in the Cube one by one,
* with a random colour for each LED. Introduce a delay of 1 second
* every time a new LED is set. 
*/

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

int z,x,y;	
long colour;

void loop()
{
	// Random colour
	colour = random(0,0xFFFFFF);

	for(z=0; z<4; z++)
	{ 
		for(x=0; x<4; x++)
		{
			for(y=0; y<4; y++)
			{
				Rb.setPixelZXY(z, x, y, colour); // Set the LED 
				_delay_ms(1000); 	// Introduce a delay of 1 second
			}
		}
	}
	
	Rb.blankDisplay(); 	// Switch off the LEDs
}