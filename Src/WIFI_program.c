#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"

#include "WIFI_interface.h"
#include "WIFI_config.h"
#include "WIFI_private.h"


static uint8 validate (uint32 u32TimeOut);

void WIFI_vidInit (void)
{
	uint8 u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"AT\r\n");
	    u8LocalVar = validate(10000u);
	}
	
	u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"AT+CWMODE=1\r\n");
		u8LocalVar = validate(10000u);
	}
	
}

Std_ReturnType WIFI_udtConnectToWIFI (void)
{
	uint8 u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"AT+CWJAP_CUR =\"HUAWEI Y9 Prime 2019\",\"2872001z\"");
	    u8LocalVar = validate(10000u);
	}

	return E_OK;
}

Std_ReturnType WIFI_udtConnectToServer (void)
{
	uint8 u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"AT+CIPSTART=\"TCP\",\"23.179.32.37\",80");
	    u8LocalVar = validate(10000);
	}
	return E_OK;
}

Std_ReturnType WIFI_udtGetData (uint8* pu8ReceivedData)
{
	uint8 u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"AT+CIPSEND=49");
	    u8LocalVar = validate(10000);
	}
	
	u8LocalVar = 130u;
	while(u8LocalVar == 130u)
	{
		UART_udtTransmit((uint8 *)"GET http://iotwifi.freevar.com/Applications.txt");
	    u8LocalVar = validate(10000);
	}
	
	*pu8ReceivedData = u8LocalVar;
	return E_OK;
}

static uint8 validate (uint32 u32TimeOut)
{
	uint8 u8LocalCounter = 0u;
	uint8 u8Response[100u];
	
	uint8 u8ReceivedData = 0u;
	
	while(u8ReceivedData != 130)
	{
		UART_udtReceive(&u8Response[u8LocalCounter++], u32TimeOut);
		u8ReceivedData++;
	}	
	
	for(u8LocalCounter = 0; u8LocalCounter < 100; u8LocalCounter++)
	{
		if(u8Response[u8LocalCounter] == 'o' && u8Response[u8LocalCounter+1] == 'k')
		{
			return 0;
		}
		else if(u8Response[u8LocalCounter] == 'I' && u8Response[u8LocalCounter+1] == 'P' && u8Response[u8LocalCounter+2] == 'D') 
		{
			return u8Response[u8LocalCounter + 6];
		}
        else
		{
			return 130;
		}			
	}

}


