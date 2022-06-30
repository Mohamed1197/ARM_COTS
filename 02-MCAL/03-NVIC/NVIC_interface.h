/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        30/06/2022        ********************/
/**************** SWC     :          GPIO            ********************/
/**************** Version :           1.0            ********************/
/************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/**************************************************************************************************/
/*                      Prototypes of the NVIC driver                                             */
/**************************************************************************************************/

u8 MNVIC_u8EnableInterrupt (u8 Copy_u8IntNumber);
/*================================================================================================*/
/**	Function Name	: MNVIC_voidEnableInterrupt.						    	                 **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: External Interrupt Number in the Vector Table                              **/
/**	Functionality	: Enables Interrupt of the External Prepherals at run time.	                 **/
/*================================================================================================*/

u8 MNVIC_u8DisableInterrupt (u8 Copy_u8IntNumber);
/*================================================================================================*/
/**	Function Name	: MNVIC_voidDisableInterrupt.						    	                 **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: External Interrupt Number in the Vector Table                              **/
/**	Functionality	: Disables Interrupt of the External Prepherals at run time.	             **/
/*================================================================================================*/

u8 MNVIC_u8SetPendingFlag (u8 Copy_u8IntNumber);
/*================================================================================================*/
/**	Function Name	: MNVIC_u8SetPendingFlag.						    	                     **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: External Interrupt Number in the Vector Table                              **/
/**	Functionality	: Set the Pending Interrupt Flag of the External Prepherals at run time.     **/
/*================================================================================================*/

u8 MNVIC_u8ClearPendingFlag (u8 Copy_u8IntNumber);
/*================================================================================================*/
/**	Function Name	: MNVIC_u8ClearPendingFlag.						    	                     **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: External Interrupt Number in the Vector Table                              **/
/**	Functionality	: Clear the Pending Interrupt Flag of the External Prepherals at run time.   **/
/*================================================================================================*/

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber , u8* Copy_pu8FlagResult);
/*================================================================================================*/
/**	Function Name	: MNVIC_u8GetActiveFlag.						    	                     **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: External Interrupt Number in the Vector Table and a pointer to the Result  **/
/**	Functionality	: Set the Pending Interrupt Flag of the External Prepherals at run time.     **/
/*================================================================================================*/


/*#######################################################################*/
/*                                 MACROS                                */
/*#######################################################################*/


/*########################################################################*/


#endif