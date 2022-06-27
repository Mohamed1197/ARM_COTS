/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :         SSEG             ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/

#ifndef SSEG_PRIVATE_H
#define SSEG_PRIVATE_H



/*#######################################################################*/
/*                                 MACROS                                */
/*#######################################################################*/

/*************************************************************************/
/*                 Seven Segment Pins Enable Macros                      */
/*************************************************************************/
#define SSEG_A_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_A_PIN    , SSEG_ON)
#define SSEG_B_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_B_PIN    , SSEG_ON)
#define SSEG_C_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_C_PIN    , SSEG_ON)
#define SSEG_D_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_D_PIN    , SSEG_ON)
#define SSEG_E_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_E_PIN    , SSEG_ON)
#define SSEG_F_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_F_PIN    , SSEG_ON)
#define SSEG_G_ON                      MGPIO_voidSetPinValue(SSEG_PORT , SSEG_G_PIN    , SSEG_ON)
#define SSEG_DOT_ON                    MGPIO_voidSetPinValue(SSEG_PORT , SSEG_DOT_PIN  , SSEG_ON)
/*#######################################################################*/

/*************************************************************************/
/*                 Seven Segment Type Configurations                     */
/*************************************************************************/
#if(SSEG_TYPE == COMMON_CATHODE)
    #define SSEG_OFF                       GPIO_u8_LOW
    #define SSEG_ON                        GPIO_u8_HIGH
#elif(SSEG_TYPE == COMMON_ANODE)
    #define SSEG_ON                        GPIO_u8_LOW
    #define SSEG_OFF                       GPIO_u8_HIGH
#else
    #error
#endif
/*#######################################################################*/


#endif
