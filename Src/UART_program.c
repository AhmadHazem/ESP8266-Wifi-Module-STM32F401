#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_vidInit (void)
{
	/* !Commnet: BAUDRATE configuration of 115200 */
	UART -> BRR = 0xD9;
	
	/* !Comment: CR1 Configurations */
	//UART -> CR1.B.UE = 1U;
	//UART -> CR1.B.TE = 1U;
	//UART -> CR1.B.RE = 1U;
	SET_BIT(UART -> CR1, 3U);
	SET_BIT(UART -> CR1, 2U);
	SET_BIT(UART -> CR1, 13U);
}

Std_ReturnType UART_udtTransmit (uint8* pu8Data) 
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	uint8 u8LocalCounter = 0u;
	
	while(pu8Data[u8LocalCounter] != '\0')
	{
		UART -> DR = pu8Data[u8LocalCounter++];
		
		while(GET_BIT(UART -> SR, 7U) == 0U); 
	}
	
	return udtRetVal;
}

Std_ReturnType UART_udtTransmitNum (uint8 u8Data)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	UART -> DR = u8Data;
		
    while(GET_BIT(UART -> SR, 7U) == 0U); 
	
	return udtRetVal;
}

Std_ReturnType UART_udtReceive (uint8* pu8ReceivedData, uint32 u32TimeOutVal)
{
	uint32 u32LocalCounter = 0u;
	
	*pu8ReceivedData = 0u;
	
	Std_ReturnType udtRetVal = E_NOT_OK;
		
    while(GET_BIT(UART -> SR, 5U) == 0U)
	{
		u32LocalCounter++;
		if(u32LocalCounter == u32TimeOutVal)
		{
			*pu8ReceivedData = 130;	
			break;
		}
	}
	
	if(*pu8ReceivedData == 0u)
	{
		*pu8ReceivedData = UART -> DR;
	}
	
	CLR_BIT(UART -> SR, 5U);
	
	return udtRetVal;
}