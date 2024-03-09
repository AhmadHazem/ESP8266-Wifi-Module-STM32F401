#ifndef _WIFI_INTERFACE_H_
#define _WIFI_INTERFACE_H_

#if WIFI_CONFIG_METHOD == WIFI_PRE_BUILD
/*****************************************************************/
/*                     Pre build public API                      */
/*****************************************************************/
void WIFI_vidInit (void);
Std_ReturnType WIFI_udtConnectToWIFI (void);
Std_ReturnType WIFI_udtConnectToServer (void);
Std_ReturnType WIFI_udtGetData (uint8* pu8ReceivedData);
#endif

#endif
