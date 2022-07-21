/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        21/07/2022        ********************/
/**************** SWC     :          GPIO            ********************/
/**************** Version :           1.2            ********************/
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

u8 MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u8GroupandSub);
/*================================================================================================*/
/**	Function Name	: MNVIC_voidSetPriority.						    	                     **/
/**	Return Type		: Error State.					   		   		                             **/
/**	Arguments		: Interrupt ID , Group Priority , Sub Priority and (Group and Sub Mode)      **/
/**	Functionality	: Set the Priority of the selected Interrupt ID at run time.                 **/
/*================================================================================================*/


/*#######################################################################*/
/*                                 MACROS                                */
/*#######################################################################*/
/*                Vector Table ISR Interrupt ID    >PAGE(204)<           */
#define NVIC_VEC_TBL_WWDG                  0
#define NVIC_VEC_TBL_PVD                   1
#define NVIC_VEC_TBL_TAMPER                2
#define NVIC_VEC_TBL_RTC                   3
#define NVIC_VEC_TBL_FLASH                 4
#define NVIC_VEC_TBL_RCC                   5
#define NVIC_VEC_TBL_EXTI0                 6
#define NVIC_VEC_TBL_EXTI1                 7
#define NVIC_VEC_TBL_EXTI2                 8
#define NVIC_VEC_TBL_EXTI3                 9
#define NVIC_VEC_TBL_EXTI4                10
#define NVIC_VEC_TBL_DMA1_CHANNEL1        11
#define NVIC_VEC_TBL_DMA1_CHANNEL2        12
#define NVIC_VEC_TBL_DMA1_CHANNEL3        13
#define NVIC_VEC_TBL_DMA1_CHANNEL4        14
#define NVIC_VEC_TBL_DMA1_CHANNEL5        15
#define NVIC_VEC_TBL_DMA1_CHANNEL6        16
#define NVIC_VEC_TBL_DMA1_CHANNEL7        17
#define NVIC_VEC_TBL_ADC1_2               18
#define NVIC_VEC_TBL_USB_HP_CAN_TX        19
#define NVIC_VEC_TBL_USB_LP_CAN_RX0       20
#define NVIC_VEC_TBL_CAN_RX1              21
#define NVIC_VEC_TBL_CAN_SCE              22
#define NVIC_VEC_TBL_EXTI9_5              23
#define NVIC_VEC_TBL_TIM1_BRK             24
#define NVIC_VEC_TBL_TIM1_UP              25
#define NVIC_VEC_TBL_TIM1_TRG_COM         26
#define NVIC_VEC_TBL_TIM1_CC              27
#define NVIC_VEC_TBL_TIM2                 28
#define NVIC_VEC_TBL_TIM3                 29
#define NVIC_VEC_TBL_TIM4                 30
#define NVIC_VEC_TBL_I2C1_EV              31
#define NVIC_VEC_TBL_I2C1_ER              32
#define NVIC_VEC_TBL_I2C2_EV              33
#define NVIC_VEC_TBL_I2C2_ER              34
#define NVIC_VEC_TBL_SPI1                 35
#define NVIC_VEC_TBL_SPI2                 36
#define NVIC_VEC_TBL_USART1               37
#define NVIC_VEC_TBL_USART2               38
#define NVIC_VEC_TBL_USART3               39
#define NVIC_VEC_TBL_EXTI15_10            40
#define NVIC_VEC_TBL_RTC_ALARM            41
#define NVIC_VEC_TBL_USB_WAKEUP           42
#define NVIC_VEC_TBL_TIM8_BRK             43
#define NVIC_VEC_TBL_TIM8_UP              44
#define NVIC_VEC_TBL_TIM8_TRG_COM         45
#define NVIC_VEC_TBL_TIM8_CC              46
#define NVIC_VEC_TBL_ADC3                 47
#define NVIC_VEC_TBL_FSMC                 48
#define NVIC_VEC_TBL_SDIO                 49
#define NVIC_VEC_TBL_TIM5                 50
#define NVIC_VEC_TBL_SPI3                 51
#define NVIC_VEC_TBL_UART4                52
#define NVIC_VEC_TBL_UART5                53
#define NVIC_VEC_TBL_TIM6                 54
#define NVIC_VEC_TBL_TIM7                 55
#define NVIC_VEC_TBL_DMA2_CHANNEL1        56
#define NVIC_VEC_TBL_DMA2_CHANNEL2        57
#define NVIC_VEC_TBL_DMA2_CHANNEL3        58
#define NVIC_VEC_TBL_DMA2_CHANNEL4_5      59
/*    Interrupt Software Priority Groups and Sub groups using SCB        */
#define  SCB_GROUP_BITS4_SUB_BITS0           0X05FA0300 /* 4 Bit for Group and 0 Bit for Sub (IPR) => 16 Groups */
#define  SCB_GROUP_BITS3_SUB_BITS1           0X05FA0400 /* 3 Bit for Group and 1 Bit for Sub (IPR) => 8 Groups + 2 Sub*/
#define  SCB_GROUP_BITS2_SUB_BITS2           0X05FA0500 /* 2 Bit for Group and 2 Bit for Sub (IPR) => 4 Groups + 4 Sub*/
#define  SCB_GROUP_BITS1_SUB_BITS3           0X05FA0600 /* 1 Bit for Group and 3 Bit for Sub (IPR) => 2 Groups + 8 Sub*/
#define  SCB_GROUP_BITS0_SUB_BITS4           0X05FA0700 /* 0 Bit for Group and 4 Bit for Sub (IPR) => 16 Sub */
/*########################################################################*/


#endif 