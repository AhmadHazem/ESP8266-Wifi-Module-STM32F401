#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_lcfg.h"

GPIO_pinState  GPIO_udtArrayOfPins [GPIO_NUMBER_OF_USED_PIN] = 
{
    [0] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN8,
			 .udtMode       = GPIO_OUTPUT,
			 .udtType       = GPIO_PUSH_PULL,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = NOT_USED
	      },
    [1] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN9,
			 .udtMode       = GPIO_AF,
			 .udtType       = GPIO_PUSH_PULL,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = GPIO_AF7
		   },
	[2] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN10,
			 .udtMode       = GPIO_AF,
			 .udtType       = GPIO_PUSH_PULL,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = GPIO_AF7
	      }
		  
};


