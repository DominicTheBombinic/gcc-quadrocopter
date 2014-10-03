/************************************************/
/* Written by:  Aaron Derstine                  */
/* Date:        1/11/14                         */
/* Name:        main.cpp                        */
/* Description: This is the main routine which  */
/*    basically is the automatically generated  */
/*    Arduino routine but with the quadrotor    */
/*    class                                     */
/************************************************/

#include <Arduino.h>
#include "Quadrotor.h"

int main(void)
{
   // Arduino init function
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	Bluetooth TestBluetooth;
	TestBluetooth.initialize();
	TestBluetooth.writeLine("Hello World! I'm starting up! :D\n");
	
	for (int i = 0; i < 255; i++) 
	{
		analogWrite(2,i);
		analogWrite(3,i);
		analogWrite(5,i);
		analogWrite(6,i);
		delay(100);
		TestBluetooth.writeLine("The duty cycle is: ");
		TestBluetooth.writeInt(i);
		TestBluetooth.writeLine("\n");
		if (serialEventRun) serialEventRun();
	}

		analogWrite(2,0);
		analogWrite(3,0);
		analogWrite(5,0);
		analogWrite(6,0);

	while(1) {}
	return 0;
}

