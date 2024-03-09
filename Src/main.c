#include <stdlib.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "WIFI_interface.h"



int main(void)
{
	//Enable RCC
	RCC_udtInitSystemClock();
	RCC_udtEnablePeripheralClock(AHB, 0);
	RCC_udtEnablePeripheralClock(APB2, 4);

	//Init GPIO
	for (int i=0 ; i < 3; i++)
	{
		GPIO_Init();
	}

	//Init Uart
	UART_vidInit();

	//Wifi Init
	WIFI_vidInit();

	//Connect to Wifi
	WIFI_udtConnectToWIFI();

	//Connect to Server
	WIFI_udtConnectToServer();

	uint8* data = (uint8 *)malloc(sizeof(uint8));
	while(1)
	{
		WIFI_udtGetData(data);

		if (*data == 1)
		{
			GPIO_udtAtomicSetPinValue(GPIO_PORTA, GPIO_PIN8, GPIO_HIGH);
		}
		else
		{
			GPIO_udtAtomicSetPinValue(GPIO_PORTA, GPIO_PIN8, GPIO_LOW);
		}
	}
}
