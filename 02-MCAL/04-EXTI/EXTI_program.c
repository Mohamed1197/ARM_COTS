/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        21/07/2022        ********************/
/**************** SWC     :          EXTI            ********************/
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
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/*#######################################################################*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

void MEXTI_voidInit()
{
    #if   EXTI_MODE  ==  RISING
    SET_BIT(EXTI -> RTSR , EXTI_LINE);
    #elif EXTI_MODE  ==  FALLING
    SET_BIT(EXTI -> FTSR , EXTI_LINE);
    #elif EXTI_MODE  ==  ON_CHANGE
    SET_BIT(EXTI -> RTSR , EXTI_LINE);
    SET_BIT(EXTI -> FTSR , EXTI_LINE);
    #else
        #error  "Wrong Mode / Line Choice !"
    #endif
    /* Disable Interrupt */
    CLR_BIT(EXTI -> IMR , copy_u8Line);
}

void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
    SET_BIT(EXTI -> IMR , copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
    CLR_BIT(EXTI -> IMR , copy_u8Line);
}

void MEXTI_voidSWTrigger(u8 copy_u8Line)
{
    SET_BIT(EXTI -> SWIER , copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 copy_u8Line , u8 copy_u8Mode)
{
    switch (copy_u8Mode)
    {
    case RISING:
        SET_BIT(EXTI -> RTSR , copy_u8Line);
        break;
    case FALLING:
        SET_BIT(EXTI -> FTSR , copy_u8Line);
        break;
    case ON_CHANGE:
        SET_BIT(EXTI -> RTSR , copy_u8Line);
        SET_BIT(EXTI -> FTSR , copy_u8Line);
        break;        
    
    default:
        break;
    }
}