/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       18/06/2022         ********************/
/**************** SWC     :          RCC             ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*************************************************************************/
/*                       Register Base Address                           */
/*************************************************************************/
#define RCC_BASE_ADDRESS              0x40021000
/*#######################################################################*/


/*************************************************************************/
/*                       Register Definitions                            */
/*************************************************************************/
#define RCC_CR                 *((volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR               *((volatile u32*)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CIR                *((volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR           *((volatile u32*)(RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR           *((volatile u32*)(RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR             *((volatile u32*)(RCC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR            *((volatile u32*)(RCC_BASE_ADDRESS + 0x18))
#define RCC_APB1ENR            *((volatile u32*)(RCC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR               *((volatile u32*)(RCC_BASE_ADDRESS + 0x20))
#define RCC_CSR                *((volatile u32*)(RCC_BASE_ADDRESS + 0x24))
/*#######################################################################*/


/*************************************************************************/
/*                         Macros For RCC                                */
/*************************************************************************/
#define    HSI             0
#define    HSE             1
#define    PLL             2
#define    CRYSTAL         3
#define    RC              4
#define    CSS_ENABLE      5
#define    CSS_DISABLE     6
#define    HSI_DIV_2       7
#define    HSE_DIV_2       8
#define    PLL_MUL_2       9
#define    PLL_MUL_3       10
#define    PLL_MUL_4       11
#define    PLL_MUL_5       12
#define    PLL_MUL_6       13
#define    PLL_MUL_7       14
#define    PLL_MUL_8       15
#define    PLL_MUL_9       16
#define    PLL_MUL_10      17
#define    PLL_MUL_11      18
#define    PLL_MUL_12      19
#define    PLL_MUL_13      20
#define    PLL_MUL_14      21
#define    PLL_MUL_15      22
#define    PLL_MUL_16      23

#define     SYSCLK              0
#define	    SYSCLK_DIV_2        1
#define		SYSCLK_DIV_4        2
#define     SYSCLK_DIV_8        3
#define     SYSCLK_DIV_16	    4
#define     SYSCLK_DIV_64       5
#define     SYSCLK_DIV_128      6
#define     SYSCLK_DIV_256      7
#define     SYSCLK_DIV_512      8

#define     HCLK                0
#define     HCLK_DIV_2          1
#define     HCLK_DIV_4          2
#define     HCLK_DIV_8          3
#define     HCLK_DIV_16         4
/*#######################################################################*/


#endif