/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :          RCC             ********************/
/**************** Version :          1.1             ********************/
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
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
/*#######################################################################*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*************************************************************************/
/*                  Initialize System Clock Function                     */
/*************************************************************************/
void MRCC_voidInitSysClock(void)
{
    	/* Selecting System Clock Source */
	
#if(RCC_CLOCK_SOURCE == HSI)
{  
    CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	
	/* Turn On HSI */
	SET_BIT(RCC_CR,0);
	
	/* Polling on HSI clock ready flag */
	while(!(GET_BIT(RCC_CR,1)));
}
#elif(RCC_CLOCK_SOURCE == HSE)
{
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	
	/* External Clock HSE Type */
	#if(HSE_CLOCK_TYPE == CRYSTAL)
	{
		CLR_BIT(RCC_CR,18);
	}
	#elif(HSE_CLOCK_TYPE == RC)
	{
		SET_BIT(RCC_CR,18);
	}
    #else
        #error(Wrong External Clock HSE Type Choice)
	#endif
	
	/* Clock Security System  */
	#if(CLOCK_SECURITY_SYSTEM == CSS_ENABLE)
	{
		SET_BIT(RCC_CR,19);
	}
	#elif(CLOCK_SECURITY_SYSTEM == CSS_DISABLE)
	{
		CLR_BIT(RCC_CR,19);
	}
    #else
        #error(Wrong Clock Security System Choice)
	#endif
    
	/* Turn On HSE */
	SET_BIT(RCC_CR,16);
    
	/* Polling on HSE clock ready flag */
	while(!(GET_BIT(RCC_CR,17)));
}
#elif(RCC_CLOCK_SOURCE == PLL)
{
	CLR_BIT(RCC_CFGR,0);
	SET_BIT(RCC_CFGR,1);
	
	/* PLL Input Clock Source Select */
	#if(PLL_INPUT_SOURCE == HSI_DIV_2)
	{
		CLR_BIT(RCC_CFGR,16);
		
		/* Turn On HSI */
		SET_BIT(RCC_CR,0);
	}
	#elif(PLL_INPUT_SOURCE == HSE)
	{
		SET_BIT(RCC_CFGR,16);
		
		/* PLL Input Clock Source HSE Divider */
		#if(PLL_INPUT_HSE_DIVIDER == HSE)
		{
			CLR_BIT(RCC_CFGR,17);
		}
		#elif(PLL_INPUT_HSE_DIVIDER == HSE_DIV_2)
		{
			SET_BIT(RCC_CFGR,17);
		}
        #else
           #error(Wrong PLL Input Clock Source HSE Divider Selection)
	  
		#endif
		
		/* Turn On HSE */
		SET_BIT(RCC_CR,16);
	}
    #else
        #error(Wrong PLL Input Clock Source Selection)

	#endif
	
	/* PLL Ouput Multiplication Factor */
	#if(PLL_OUTPUT_FACTOR == PLL_MUL_2)
	{
		RCC_CFGR |= (0<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_3)
	{
		RCC_CFGR |= (1<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_4)
	{
		RCC_CFGR |= (2<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_5)
	{
		RCC_CFGR |= (3<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_6)
	{
		RCC_CFGR |= (4<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_7)
	{
		RCC_CFGR |= (5<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_8)
	{
		RCC_CFGR |= (6<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_9)
	{
		RCC_CFGR |= (7<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_10)
	{
		RCC_CFGR |= (8<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_11)
	{
		RCC_CFGR |= (9<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_12)
	{
		RCC_CFGR |= (10<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_13)
	{
		RCC_CFGR |= (11<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_14)
	{
		RCC_CFGR |= (12<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_15)
	{
		RCC_CFGR |= (13<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_16)
	{
		RCC_CFGR |= (14<<18);
	}
     #else
        #error(Wrong PLL Ouput Multiplication Factor Selection)

	#endif
	
	/* Turn On PLL */
    SET_BIT(RCC_CR,24);
	
	/* Polling on PLL clock ready flag */	
	while(!(GET_BIT(RCC_CR,25)));
}
#else
    #error("Wrong Clock Source Selection !")	
#endif	

/* AHB Prescaler Set */
#if(AHB_PRESCALER == SYSCLK)
{
	CLR_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_2)
{
	CLR_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_4)
{
	SET_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_8)
{
	CLR_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_64)
{
	CLR_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_128)
{
	SET_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_256)
{
	CLR_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_512)
{
	SET_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
 #else
    #error(Wrong AHB Prescaler Selection)

#endif

/* APB1 Prescaler Set */
#if(APB1_PRESCALER == HCLK)
{
	CLR_BIT(RCC_CFGR,10);
	
}
#elif(APB1_PRESCALER == HCLK_DIV_2)
{                    
	CLR_BIT(RCC_CFGR,8);
    CLR_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);	
}                    
#elif(APB1_PRESCALER == HCLK_DIV_4)
{                      
	SET_BIT(RCC_CFGR,8);
    CLR_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);					   
}                      
#elif(APB1_PRESCALER == HCLK_DIV_8)
{                      
	CLR_BIT(RCC_CFGR,8);
    SET_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);					   
}                      
#elif(APB1_PRESCALER == HCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,8);
    SET_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);
}
 #else
    #error(Wrong APB1 Prescaler Selection)
#endif

/* APB2 Prescaler Set */
#if(APB2_PRESCALER == HCLK)
{
	CLR_BIT(RCC_CFGR,13);
}
#elif(APB2_PRESCALER == HCLK_DIV_2)
{                    
	CLR_BIT(RCC_CFGR,11);
    CLR_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				 
}                    
#elif(APB2_PRESCALER == HCLK_DIV_4)
{                      
	SET_BIT(RCC_CFGR,11);
    CLR_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				   
}                      
#elif(APB2_PRESCALER == HCLK_DIV_8)
{                      
	CLR_BIT(RCC_CFGR,11);
    SET_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				   
}                      
#elif(APB2_PRESCALER == HCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,11);
    SET_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);
}
 #else
    #error(Wrong APB2 Prescaler Selection)
#endif
}
/*#######################################################################*/ 


/*************************************************************************/
/*                  Enable Peripheral Clock Function                     */
/*************************************************************************/
void MRCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
    if (Copy_u8PeripheralId <=31 )
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PeripheralId); break;
            case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PeripheralId); break;
            case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PeripheralId); break;
        }
    }
    else
    {
        /* Return Error */
    }
}
/*#######################################################################*/ 


/*************************************************************************/
/*                  Disable Peripheral Clock Function                    */
/*************************************************************************/
void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
    if (Copy_u8PeripheralId <=31 )
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PeripheralId); break;
            case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PeripheralId); break;
            case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PeripheralId); break;
        }
    }
    else
    {
        /* Return Error */
    }
}
/*#######################################################################*/ 
