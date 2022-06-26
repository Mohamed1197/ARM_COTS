/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :          LED             ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/



/*************************************************************************/
/*                        Include LIB Layer                              */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*#######################################################################*/

/*************************************************************************/
/*                        Include MCAL Layer                             */
/*************************************************************************/
#include "GPIO_interface.h"
/*#######################################################################*/

/*************************************************************************/
/*                      Include Driver Files                             */
/*************************************************************************/
/* Include Driver Files */
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
/*#######################################################################*/




/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*************************************************************************/
/*                        Turn On LED Function                           */
/*************************************************************************/
void HLED_voidTurnOnLED(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
    /* calls the GPIO Function and Turns on the LED at Specific PIN */
    MGPIO_voidSetPinValue(Copy_u8PortID , Copy_u8PinID , GPIO_u8_HIGH);
}
/*#######################################################################*/

/*************************************************************************/
/*                       Turn Off LED Function                           */
/*************************************************************************/
void HLED_voidTurnOffLED(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
    /* calls the GPIO Function and Turns off the LED at Specific PIN */
    MGPIO_voidSetPinValue(Copy_u8PortID , Copy_u8PinID , GPIO_u8_LOW);
}
/*#######################################################################*/

/*************************************************************************/
/*                         Toggle LED Function                           */
/*************************************************************************/
void HLED_voidToggleLED(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
   static u8 Local_u8PinValue ;
   /* Get the Value of the Selected LED Pin */
   Local_u8PinValue = MGPIO_u8GetPinValue( Copy_u8PortID , Copy_u8PinID );
   
   if (Local_u8PinValue == GPIO_u8_HIGH)
   {
     /* Checks if the Value of the Selected LED Pin is HIGH it will turn the LED Off */        
        HLED_voidTurnOffLED(Copy_u8PortID , Copy_u8PinID);
   }   
   else if (Local_u8PinValue == GPIO_u8_LOW)
   {
     /* Checks if the Value of the Selected LED Pin is LOW it will turn the LED On */
        HLED_voidTurnOnLED(Copy_u8PortID , Copy_u8PinID);
   }
   
}
/*#######################################################################*/
