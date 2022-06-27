/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :         SSEG             ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/


#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/*************************************************************************/
/*                 Prototypes of the Seven Segment driver                */
/*************************************************************************/

void HSSEG_voidSetSSEG (u8 Copy_u8DisplayNumber);
/*================================================================================================*/
/**	Function Name	: HSSEG_voidSetSSEG.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: Display Number.                                                            **/
/**	Functionality	: Displays Number on Seven Segment at run time.                              **/
/*================================================================================================*/

void HSSEG_voidDotSSEG (void);
/*================================================================================================*/
/**	Function Name	: HSSEG_voidDotSSEG.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: void.                                                                      **/
/**	Functionality	: Enables the Seven Segment Display Dot at run time.                         **/
/*================================================================================================*/

void HSSEG_voidClearSSEG (void);
/*================================================================================================*/
/**	Function Name	: HSSEG_voidSetSSEG.		         				    	                 **/
/**	Return Type		: void.					   		   		                                     **/
/**	Arguments		: void.                                                                      **/
/**	Functionality	: Clears the Seven Segment Display at run time.                              **/
/*================================================================================================*/











#endif