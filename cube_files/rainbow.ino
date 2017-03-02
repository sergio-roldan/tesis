#include <Rainbowduino.h>
#include <util/delay.h>

/**
* A rainbow is a meteorological phenomenon that is caused by reflection, 
* refraction and dispersion of light. It produces seven colours that can
* be distinguish in the sky: red, orange, yellow, green, blue, indigo and
* purple.
*
* Define an array with these colours as RGB and use it to do the following:
*
* Initially the core of the Cube (all inner LEDs) is set to red and the 
* exterior (all external LEDs) is set to purple. Every 2 seconds the colour
* in the core is transferred to the exterior and the following colour in 
* the array sequence fills the core.
*
* To carry out this task, define two functions: one to set the LEDs in the 
* core to a desired colour and a second one to do the same with the exterior.
*
*			setCubeCore(colour);
*			setCubeExt(colour);
*/

long red = 0xFF0000;
long orange = 0xFFA500;
long yellow = 0xFFFF00;
long green = 0x00FF00;
long blue = 0x0000FF;
long indigo = 0x4B0082;
long purple = 0xEE82EE;
long sequence[7] = {red, orange, yellow, green, blue, indigo, purple};

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

void loop()
{
	int lastColour = 7;
	for(int i=0; i<7; i++)
	{ 
		setCubeCore(sequence[i]);
		setCubeExt(sequence[lastColour]);
		_delay_ms(2000); // Introduce a delay of 2 seconds
		
		lastColour = i;
	}
}

/*
* Function to switch the LEDs in the Cube's core, with a given colour
*/
void setCubeCore(long colour)
{
	int z,x,y;
	
	for(z=1; z<3; z++)
	{ 
		for(x=1; x<3; x++)
		{
			for(y=1; y<3; y++)
			{
				Rb.setPixelZXY(z, x, y, colour); // Set the cube to the given colour
			}
		}
	}
}

/*
* Function to switch the LEDs in the Cube's exterior, with a given colour
*/
void setCubeExt(long colour)
{
	int z,x,y;
	
	for(z=0; z<4; z++)
	{ 
		for(x=0; x<4; x++)
		{
			for(y=0; y<4; y++)
			{
				if (z==0 || z==4 || x==0 || x==3 || y==0 || y==3 )
				{
					Rb.setPixelZXY(z, x, y, colour); // Set the cube to the given colour
				}
			}
		}
	}
}