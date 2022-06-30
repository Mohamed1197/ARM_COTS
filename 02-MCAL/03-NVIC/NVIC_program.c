/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        30/06/2022        ********************/
/**************** SWC     :          GPIO            ********************/
/**************** Version :           1.0            ********************/
/************************************************************************/

/*************************************************************************/
/*                        Include LIB Layer                              */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*#######################################################################*/

/*************************************************************************/
/*                      Include Driver Files                             */
/*************************************************************************/
/* Include Driver Files */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
/*#######################################################################*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*************************************************************************/
/*                Enable External Interrupt Function                     */
/*************************************************************************/
u8 MNVIC_u8EnableInterrupt (u8 Copy_u8IntNumber);
{
    u8 Local_u8_ErrorState = NOK ;

    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ISER0 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ISER0 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else if ((Copy_u8IntNumber >= 32) && (Copy_u8IntNumber <= 63))
    {
        Copy_u8IntNumber -= 32; /* to be able to write in the next Register */
        NVIC_ISER1 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ISER1 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else
    {
        /* Do Nothing */
    }
    return Local_u8_ErrorState ;  /* Returns Error State */
}
/*#######################################################################*/


/*************************************************************************/
/*               Disable External Interrupt Function                     */
/*************************************************************************/
u8 MNVIC_u8DisableInterrupt (u8 Copy_u8IntNumber);
{
    u8 Local_u8_ErrorState = NOK ;

    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ICER0 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else if ((Copy_u8IntNumber >= 32) && (Copy_u8IntNumber <= 63))
    {
        Copy_u8IntNumber -= 32; /* to be able to write in the next Register */
        NVIC_ICER1 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ICER1 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else
    {
        /* Do Nothing */
    }
    return Local_u8_ErrorState ;  /* Returns Error State */
}
/*#######################################################################*/


/*************************************************************************/
/*          Set External Interrupt Pending Flag Function                 */
/*************************************************************************/
u8 MNVIC_u8SetPendingFlag (u8 Copy_u8IntNumber);
{
    u8 Local_u8_ErrorState = NOK ;

    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ISPR0 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else if ((Copy_u8IntNumber >= 32) && (Copy_u8IntNumber <= 63))
    {
        Copy_u8IntNumber -= 32; /* to be able to write in the next Register */
        NVIC_ISPR1 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ISPR1 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else
    {
        /* Do Nothing */
    }
    return Local_u8_ErrorState ;  /* Returns Error State */
}
/*#######################################################################*/


/*************************************************************************/
/*        CLear External Interrupt Pending Flag Function                 */
/*************************************************************************/
u8 MNVIC_u8ClearPendingFlag (u8 Copy_u8IntNumber);
{
    u8 Local_u8_ErrorState = NOK ;

    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ICPR0 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else if ((Copy_u8IntNumber >= 32) && (Copy_u8IntNumber <= 63))
    {
        Copy_u8IntNumber -= 32; /* to be able to write in the next Register */
        NVIC_ICPR1 = (1 << Copy_u8IntNumber); /* Faster than SET_BIT (writing 0 has no effect) */
        //SET_BIT(NVIC_ICPR1 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else
    {
        /* Do Nothing */
    }
    return Local_u8_ErrorState ;  /* Returns Error State */
}
/*#######################################################################*/


/*************************************************************************/
/*              Read Interrupt Active Flag Function                      */
/*************************************************************************/
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber , u8* Copy_pu8FlagResult);
{
    u8 Local_u8_ErrorState = NOK ;

    if(Copy_u8IntNumber <= 31)
    {
        *Copy_pu8FlagResult = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else if ((Copy_u8IntNumber >= 32) && (Copy_u8IntNumber <= 63))
    {
        Copy_u8IntNumber -= 32; /* to be able to write in the next Register */
        *Copy_pu8FlagResult = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
        Local_u8_ErrorState = OK ;
    }
    else
    {
        /* Do Nothing */
    }
    return Local_u8_ErrorState ;  /* Returns Error State */
}
/*#######################################################################*/


/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXX             END OF FUNCTIONS IMPLEMENTATION                XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
