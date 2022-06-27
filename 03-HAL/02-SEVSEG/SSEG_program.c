/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :         SSEG             ********************/
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
#include "SSEG_interface.h"
#include "SSEG_private.h"
#include "SSEG_config.h"
/*#######################################################################*/




/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*************************************************************************/
/*              Displays Number on Seven Segment Function                */
/*************************************************************************/
void HSSEG_voidSetSSEG (u8 Copy_u8DisplayNumber)
{
    /* Display the Number Written By the User on the Seven Segment */
    switch (Copy_u8DisplayNumber)
    {
    case 0:
        { SSEG_A_ON; SSEG_B_ON; SSEG_C_ON; SSEG_D_ON; SSEG_E_ON; SSEG_F_ON; }
        break;
    case 1:
        { SSEG_B_ON; SSEG_C_ON; }
        break;
    case 2:
        { SSEG_A_ON; SSEG_B_ON; SSEG_D_ON; SSEG_E_ON; SSEG_G_ON; }
        break;
    case 3:
        { SSEG_A_ON; SSEG_B_ON; SSEG_C_ON; SSEG_D_ON; SSEG_G_ON; }
        break;
    case 4:
        { SSEG_B_ON; SSEG_C_ON; SSEG_F_ON;  SSEG_G_ON; }
        break;                
    case 5:
        { SSEG_A_ON; SSEG_C_ON; SSEG_D_ON; SSEG_F_ON; SSEG_G_ON; }
        break;
    case 6:
        { SSEG_A_ON; SSEG_C_ON; SSEG_D_ON; SSEG_E_ON; SSEG_F_ON; SSEG_G_ON; }
        break;
    case 7:
        { SSEG_A_ON; SSEG_B_ON; SSEG_C_ON; }
        break;
    case 8:
        { SSEG_A_ON; SSEG_B_ON; SSEG_C_ON; SSEG_D_ON; SSEG_E_ON; SSEG_F_ON; SSEG_G_ON; }
        break;
    case 9:
        { SSEG_A_ON; SSEG_B_ON; SSEG_C_ON; SSEG_D_ON; SSEG_F_ON; SSEG_G_ON; }
        break;        
    default:
        break;
    }
}
/*#######################################################################*/

/*************************************************************************/
/*              Enables the Seven Segment Dot Display Function           */
/*************************************************************************/
void HSSEG_voidDotSSEG (void)
{
    SSEG_DOT_ON;
}
/*#######################################################################*/

/*************************************************************************/
/*              Clear the Seven Segment Display Function                 */
/*************************************************************************/
void HSSEG_voidClearSSEG (void)
{
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_A_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_B_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_C_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_D_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_E_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_F_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_G_PIN    , SSEG_OFF);
    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_DOT_PIN  , SSEG_OFF);
}
/*#######################################################################*/


