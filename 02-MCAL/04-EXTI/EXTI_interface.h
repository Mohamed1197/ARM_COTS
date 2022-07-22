/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        21/07/2022        ********************/
/**************** SWC     :          EXTI            ********************/
/**************** Version :           1.0            ********************/
/************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* line & Mode */
void MEXTI_voidInit();

void MEXTI_voidEnableEXTI(u8 copy_u8Line);

void MEXTI_voidDisableEXTI(u8 copy_u8Line);

void MEXTI_voidSWTrigger(u8 copy_u8Line);


#endif