/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :          LED             ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/


#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/*************************************************************************/
/*                      Prototypes of the LED driver                     */
/*************************************************************************/

void HLED_voidTurnOnLED(u8 Copy_u8PortID , u8 Copy_u8PinID);
/*================================================================================================*/
/**	Function Name	: HLED_voidTurnOnLED.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: PORT Number , PIN Number.                                                  **/
/**	Functionality	: Turns On Specific LED at run time.         	                             **/
/*================================================================================================*/

void HLED_voidTurnOffLED(u8 Copy_u8PortID , u8 Copy_u8PinID);
/*================================================================================================*/
/**	Function Name	: HLED_voidTurnOffLED.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: PORT Number , PIN Number.                                                  **/
/**	Functionality	: Turns Off Specific LED at run time.         	                             **/
/*================================================================================================*/

void HLED_voidToggleLED(u8 Copy_u8PortID , u8 Copy_u8PinID);
/*================================================================================================*/
/**	Function Name	: HLED_voidToggleLED.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: PORT Number , PIN Number.                                                  **/
/**	Functionality	: Toggle Specific LED at run time.           	                             **/
/*================================================================================================*/


#endif