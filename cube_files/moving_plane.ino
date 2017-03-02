#include <Rainbowduino.h>
#include <util/delay.h>

/**
* Define a function to switch on all the LEDs in a given Z plane 
* with a desired colour, where Z € (0,3).
*
*		setCompleteZPlane(z, colour);
*
* Define a similar function to switch on the LEDs in a given
* Y plane.
*
* Using both functions, develop a sketch where a blue Z plane 
* go through the whole Cube sequentially, that is, first Z=0, then
* Z=1, Z=2 and finally Z=3. Only one plane can be set at a given
* moment. Afterwards, following the same rules, define a red 
* Y plane going from Y=0 to Y=3.
*
* Introduce a delay of 2 seconds every time the plane changes.
*/

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

long blue = 0x0000FF;
long red = 0xFF0000;

void loop()
{
	// Blue plane
	setCompleteZPlane(0, blue); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
	
	setCompleteZPlane(1, blue); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
	
	setCompleteZPlane(2, blue); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();

	setCompleteZPlane(3, blue); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
	
	// Red plane
	setCompleteYPlane(0, red); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
	
	setCompleteYPlane(1, red); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
	
	setCompleteYPlane(2, red); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
    
	setCompleteYPlane(3, red); 
	_delay_ms(2000); // Introduce a delay of 2 seconds
	Rb.blankDisplay();
}

/*
* Function to switch on all the LEDs in a Z plane, with a given colour
*/
void setCompleteZPlane(int z, long colour)
{
	int x,y;
	
	for(x=0; x<4; x++)
	{
		for(y=0; y<4; y++)
		{
			Rb.setPixelZXY(z, x, y, colour); // Set the LED to the given colour
		}
	}
}

/*
* Function to switch on all the LEDs in a Y plane, with a given colour
*/
void setCompleteYPlane(int y, long colour)
{
	int z,x;
	
	for(z=0; z<4; z++)
	{
		for(x=0; x<4; x++)
		{
			Rb.setPixelZXY(z, x, y, colour); // Set the LED to the given colour
		}
	}
}