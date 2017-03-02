#include <Rainbowduino.h>
#include <util/delay.h>

/**
* Use the functions defined in the MovingPlane sketch to
* create some 3-dimensional flags in the Cube.
* 
*			R R R R 
* Spain		Y Y Y Y
*			Y Y Y Y
*			R R R R
*
*			R W W R 
* Canada	R W W R
*			R W W R
*			R W W R

*			Y Y Y Y 
* Colombia	Y Y Y Y
*			B B B B
*			R R R R
*
*			W W R R 
* Malta		W W R R
*			W W R R
*			W W R R
*
* Where R=Red, Y=Yellow, W=White, B=Blue.
*
* Display sequentially each flag described above and change
* them every 4 seconds. 
*/

long red = 0xFF0000;
long yellow = 0xFFFF00;
long white = 0xFFFFFF;
long blue = 0x0000FF;

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

void loop()
{
	// Spain
	setCompleteZPlane(3, red);
	setCompleteZPlane(2, yellow);
	setCompleteZPlane(1, yellow);
	setCompleteZPlane(0, red);
	_delay_ms(4000); // Introduce a delay of 4 seconds
		
	// Canada
	setCompleteYPlane(3, red);
	setCompleteYPlane(2, white);
	setCompleteYPlane(1, white);
	setCompleteYPlane(0, red);
	_delay_ms(4000); // Introduce a delay of 4 seconds
	
	// Colombia
	setCompleteZPlane(3, yellow);
	setCompleteZPlane(2, yellow);
	setCompleteZPlane(1, blue);
	setCompleteZPlane(0, red);
	_delay_ms(4000); // Introduce a delay of 4 seconds
		
	// Malta
	setCompleteYPlane(3, white);
	setCompleteYPlane(2, white);
	setCompleteYPlane(1, red);
	setCompleteYPlane(0, red);
	_delay_ms(4000); // Introduce a delay of 4 seconds
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