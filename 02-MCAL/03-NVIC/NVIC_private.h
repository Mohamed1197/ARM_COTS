/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        30/06/2022        ********************/
/**************** SWC     :          GPIO            ********************/
/**************** Version :           1.0            ********************/
/************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*************************************************************************/
/*                      NVIC Register Base Address                       */
/*************************************************************************/
#define  NVIC_BASE_ADDRESS                     0xE000E100
/*#######################################################################*/


/*************************************************************************/
/*                Register Addresses Definitions For NVIC                */
/*************************************************************************/
/*                 Enable External Interrupt Registers                   */
#define   NVIC_ISER0      *((volatile u32*)(NVIC_BASE_ADDRESS+0x000))  /* Enable External Interrupts from  0 to 31 */
#define   NVIC_ISER1      *((volatile u32*)(NVIC_BASE_ADDRESS+0x004))  /* Enable External Interrupts from 32 to 63 */
#define   NVIC_ISER2      *((volatile u32*)(NVIC_BASE_ADDRESS+0x008))  /* Enable External Interrupts from 64 to 80 */
/*                Disable External Interrupt Registers                   */
#define   NVIC_ICER0      *((volatile u32*)(NVIC_BASE_ADDRESS+0x080))  /* Disable External Interrupts from  0  to 31 */
#define   NVIC_ICER1      *((volatile u32*)(NVIC_BASE_ADDRESS+0x084))  /* Disable External Interrupts from  32 to 63 */
#define   NVIC_ICER2      *((volatile u32*)(NVIC_BASE_ADDRESS+0x088))  /* Disable External Interrupts from  64 to 80 */
/*         Set Pending Flag of External Interrupt Registers              */
#define   NVIC_ISPR0      *((volatile u32*)(NVIC_BASE_ADDRESS+0x100))  /* Set Pending Flag of External Interrupts from  0  to 31 */
#define   NVIC_ISPR1      *((volatile u32*)(NVIC_BASE_ADDRESS+0x104))  /* Set Pending Flag of External Interrupts from  32 to 63 */
#define   NVIC_ISPR2      *((volatile u32*)(NVIC_BASE_ADDRESS+0x108))  /* Set Pending Flag of External Interrupts from  64 to 80 */ 
/*       Clear Pending Flag of External Interrupt Registers              */
#define   NVIC_ICPR0      *((volatile u32*)(NVIC_BASE_ADDRESS+0x180))  /* Clear Pending Flag of External Interrupts from  0  to 31 */
#define   NVIC_ICPR1      *((volatile u32*)(NVIC_BASE_ADDRESS+0x184))  /* Clear Pending Flag of External Interrupts from  32 to 63 */
#define   NVIC_ICPR2      *((volatile u32*)(NVIC_BASE_ADDRESS+0x188))  /* Clear Pending Flag of External Interrupts from  64 to 80 */ 
/*        Read Active Flag of External Interrupt Registers               */
#define   NVIC_IABR0      *((volatile u32*)(NVIC_BASE_ADDRESS+0x200))  /* Read Active Flag of External Interrupts from  0  to 31 */
#define   NVIC_IABR1      *((volatile u32*)(NVIC_BASE_ADDRESS+0x204))  /* Read Active Flag of External Interrupts from  32 to 63 */
#define   NVIC_IABR2      *((volatile u32*)(NVIC_BASE_ADDRESS+0x208))  /* Read Active Flag of External Interrupts from  64 to 80 */ 
/*#######################################################################*/

#endif  