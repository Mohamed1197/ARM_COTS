/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        29/06/2022        ********************/
/**************** SWC     :          GPIO            ********************/
/**************** Version :           1.5            ********************/
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
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/*#######################################################################*/



/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXX       vvvv     FUNCTIONS IMPLEMENTATIONS      vvvv        XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

/*************************************************************************/
/*                      Set Pin Direction Function                       */
/*************************************************************************/
void MGPIO_voidSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode)
{
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinID <= GPIO_u8_PIN15))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinID <= GPIO_u8_PIN7)
				 {
					 /* BIT Masking For 4 Bits for the used Pin */
					 GPIOA_CRL &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOA_CRL |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 } 
				 /* Check if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinID <= GPIO_u8_PIN15) 
				 {
					 Copy_u8PinID = Copy_u8PinID - 8 ;
					 /* BIT Masking For 4 Bits for the used Pin */
					 GPIOA_CRH &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOA_CRH |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 }
			     break;
			case GPIO_u8_PORTB:
					 /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinID <= GPIO_u8_PIN7)
				 {
					 /* BIT Masking For 4 Bits for the used Pin */
					 GPIOB_CRL &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOB_CRL |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 } 
				 /* Check if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinID <= GPIO_u8_PIN15) 
				 {
					 Copy_u8PinID = Copy_u8PinID - 8 ;
					 /* BIT Masking For 4 Bits */
					 GPIOB_CRH &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOB_CRH |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 }
			     break;
			case GPIO_u8_PORTC:
				 /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinID <= GPIO_u8_PIN7)
				 {
					 /* BIT Masking For 4 Bits */
					 GPIOC_CRL &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOC_CRL |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 } 
				 /* Check if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinID <= GPIO_u8_PIN15) 
				 {
					 Copy_u8PinID = Copy_u8PinID - 8 ;
					 /* BIT Masking For 4 Bits */
					 GPIOC_CRH &= ~ ((0b1111) << (Copy_u8PinID * 4));
					 GPIOC_CRH |=   ((Copy_u8Mode) << (Copy_u8PinID * 4));
				 }
			     break;
		}
	}
	else
	{
		/*  Do Nothing  */
	}
}
/*#######################################################################*/


/*************************************************************************/
/*                      Set Pin Value Function                           */
/*************************************************************************/
void MGPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinID <= GPIO_u8_PIN15))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
	    	if(Copy_u8Value == GPIO_u8_HIGH)
	    	{	// Using ODR or BSRR Register (BSRR is Faster)
				#if (USE_OUTPUT_REG_ONSET == ODR ) 
	    		SET_BIT(GPIOA_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    		GPIOA_BSRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong SET Register Macro Selection"
				#endif	
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{	// Using ODR or BRR Register (BRR is Faster)
				#if (USE_OUTPUT_REG_ONCLR == ODR )
	    		CLR_BIT(GPIOA_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    		GPIOA_BRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong CLR Register Macro Selection"
				#endif
	    	}
	    	else
	    	{
	    		/* Do Nothing */
	    	}
			break;
			case GPIO_u8_PORTB:
	    	if(Copy_u8Value == GPIO_u8_HIGH)
	    	{	// Using ODR or BSRR Register (BSRR is Faster)
				#if (USE_OUTPUT_REG_ONSET == ODR )
	    		SET_BIT(GPIOB_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    		GPIOB_BSRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong SET Register Macro Selection"
				#endif	
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{	// Using ODR or BRR Register (BRR is Faster)
				#if (USE_OUTPUT_REG_ONCLR == ODR )
	    		CLR_BIT(GPIOB_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    		GPIOB_BRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong CLR Register Macro Selection"
				#endif
	    	}
	    	else
	    	{
	    		/* Do Nothing */
	    	}
			break;
			case GPIO_u8_PORTC:
	    	if(Copy_u8Value == GPIO_u8_HIGH)
	    	{	// Using ODR or BSRR Register (BSRR is Faster)
				#if (USE_OUTPUT_REG_ONSET == ODR )
	    		SET_BIT(GPIOC_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    		GPIOC_BSRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong SET Register Macro Selection"
				#endif
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{	// Using ODR or BRR Register (BRR is Faster)
				#if (USE_OUTPUT_REG_ONCLR == ODR )
	    		CLR_BIT(GPIOC_ODR , Copy_u8PinID);
				#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    		GPIOC_BRR = (1 << Copy_u8PinID);
				#else
					#error "Wrong CLR Register Macro Selection"
				#endif
	    	}
	    	else
	    	{
	    		/* Do Nothing */
	    	}
			break;
		}
	}
	else
	{
		/*  Do Nothing  */
	}
}
/*#######################################################################*/


/*************************************************************************/
/*                      Get Pin Value Function                           */
/*************************************************************************/
u8   MGPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID )
{
	u8 Local_u8PINValue = 0xFF;
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinID <= GPIO_u8_PIN15))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
			Local_u8PINValue = GET_BIT(GPIOA_IDR , Copy_u8PinID ); break;
			case GPIO_u8_PORTB:
			Local_u8PINValue = GET_BIT(GPIOB_IDR , Copy_u8PinID ); break;
			case GPIO_u8_PORTC:
			Local_u8PINValue = GET_BIT(GPIOC_IDR , Copy_u8PinID ); break;
		}
	}
	else
	{
		/*  Do Nothing  */
	}
	
	return Local_u8PINValue;
}
/*#######################################################################*/


/*************************************************************************/
/*                      Set Port Direction Function                      */
/*************************************************************************/
void MGPIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PinType ,u8 Copy_u8Mode )
{
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinType <= GPIO_u8_HIGH_PINS))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
			      /* Reset PortA From Pin0 to Pin7 */
			       GPIOA_CRL &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOA_CRL|= (Copy_u8Mode << (4 * i));
			       }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortA From Pin8 to Pin15 */
			       GPIOA_CRH &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOA_CRH|= (Copy_u8Mode << (4 * i));
			       }
				 }
		    break;
		    case GPIO_u8_PORTB:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
			      /* Reset PortA From Pin0 to Pin7 */
			       GPIOB_CRL &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOB_CRL|= (Copy_u8Mode << (4 * i));
			       }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortA From Pin8 to Pin15 */
			       GPIOB_CRH &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOB_CRH|= (Copy_u8Mode << (4 * i));
			       }
				 }
			 break;
		     case GPIO_u8_PORTC:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
			      /* Reset PortA From Pin0 to Pin7 */
			       GPIOC_CRL &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOC_CRL|= (Copy_u8Mode << (4 * i));
			       }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortA From Pin8 to Pin15 */
			       GPIOC_CRH &= 0x00000000;
			       for(u8 i =0 ; i<8 ; i++)
			       {
			       GPIOC_CRH|= (Copy_u8Mode << (4 * i));
			       }
				 }
		      break;
		}
	}

}
/*#######################################################################*/


/*************************************************************************/
/*                      Set Port Value Function                          */
/*************************************************************************/
void MGPIO_voidSetPortValue(u8 Copy_u8PortID , u8 Copy_u8PinType ,u8 Copy_u8value )
{
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinType <= GPIO_u8_HIGH_PINS))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH: 	// Using ODR or BSRR Register (BSRR is Faster)
					 		#if (USE_OUTPUT_REG_ONSET == ODR )
							GPIOA_ODR |= 0x000000FF;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOA_BSRR = 0x000000FF;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif	
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					 		#if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOA_ODR &= ~(0x000000FF);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOA_BRR = 0x000000FF;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:		// Using ODR or BSRR Register (BSRR is Faster)
							#if (USE_OUTPUT_REG_ONSET == ODR )
	    					GPIOA_ODR |= 0x0000FF00;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOA_BSRR = 0x0000FF00;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					        #if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOA_ODR &= ~(0x0000FF00);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOA_BRR = 0x0000FF00;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif		
						 break;
					 }
			     }
		    break;
		    case GPIO_u8_PORTB:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:		// Using ODR or BSRR Register (BSRR is Faster)
					 		#if (USE_OUTPUT_REG_ONSET == ODR )
	    					GPIOB_ODR |= 0x000000FF;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOB_BSRR = 0x000000FF;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					 		#if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOB_ODR &= ~(0x000000FF);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOB_BRR = 0x000000FF;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif	
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:		// Using ODR or BSRR Register (BSRR is Faster)
					 		#if (USE_OUTPUT_REG_ONSET == ODR )
	    					GPIOB_ODR |= 0x0000FF00;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOB_BSRR = 0x0000FF00;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					 		#if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOB_ODR &= ~(0x0000FF00);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOB_BRR = 0x0000FF00;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif
						 break;
					 }
			     }
			 break;
		     case GPIO_u8_PORTC:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:		// Using ODR or BSRR Register (BSRR is Faster)
					 		#if (USE_OUTPUT_REG_ONSET == ODR )
	    					GPIOC_ODR |= 0x000000FF;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOC_BSRR = 0x000000FF;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					 		#if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOC_ODR &= ~(0x000000FF);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOC_BRR = 0x000000FF;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:		// Using ODR or BSRR Register (BSRR is Faster)
					 		#if (USE_OUTPUT_REG_ONSET == ODR )
	    					GPIOC_ODR |= 0x0000FF00;
							#elif (USE_OUTPUT_REG_ONSET == BSRR )
	    					GPIOC_BSRR = 0x0000FF00;
							#else
								#error "Wrong SET Register Macro Selection"
							#endif
						 break;
					 case GPIO_u8_LOW:		// Using ODR or BRR Register (BRR is Faster)
					 		#if (USE_OUTPUT_REG_ONCLR == ODR )
	    					GPIOC_ODR &= ~(0x0000FF00);
							#elif (USE_OUTPUT_REG_ONCLR == BRR )
	    					GPIOC_BRR = 0x0000FF00;
							#else
								#error "Wrong CLR Register Macro Selection"
							#endif
						 break;
					 }
			     }
		      break;
		}
	}

}
/*#######################################################################*/


/*************************************************************************/
/*                 Set Port Register Direction Function                  */
/*************************************************************************/
void MGPIO_voidSetPortDirectionRegister(u8 Copy_u8PortID , u8 Copy_u8PinType ,u32 Copy_u32Mode )
{
	/*       Range Check PortID and PinID        */
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinType <= GPIO_u8_HIGH_PINS))
	{
		switch(Copy_u8PortID)
		{
			case GPIO_u8_PORTA:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
				      /* Reset PortA From Pin0 to Pin7 */
				     GPIOA_CRL &= 0x00000000;
					 GPIOA_CRL |= Copy_u32Mode;
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortA From Pin8 to Pin15 */
			       GPIOA_CRH &= 0x00000000;
			       GPIOA_CRH|= Copy_u32Mode;
			       }

		    break;
		    case GPIO_u8_PORTB:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
			      /* Reset PortB From Pin0 to Pin7 */
			       GPIOB_CRL &= 0x00000000;
			       GPIOB_CRL|= Copy_u32Mode;
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortB From Pin8 to Pin15 */
			       GPIOB_CRH &= 0x00000000;
			       GPIOB_CRH|= Copy_u32Mode;
				 }
			 break;
		     case GPIO_u8_PORTC:
			     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
				 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
				 {
			      /* Reset PortC From Pin0 to Pin7 */
			       GPIOC_CRL &= 0x00000000;
			       GPIOC_CRL|= Copy_u32Mode;
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
			      /* Reset PortC From Pin8 to Pin15 */
			       GPIOC_CRH &= 0x00000000;
			       GPIOC_CRH|= Copy_u32Mode;
				 }
		      break;
		}
	}

}
/*#######################################################################*/


/*************************************************************************/
/*              Set Half Port Register Value Function                    */
/*************************************************************************/
void MGPIO_voidSetHalfPortValueRegister(u8 Copy_u8PortID , u8 Copy_u8PinType ,u8 Copy_u8value )
{
	/*       Range Check PortID and PinID        */
	if(Copy_u8PortID <= GPIO_u8_PORTC)
	{
		switch(Copy_u8PortID)
		{
		case GPIO_u8_PORTA:
		     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
			 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
			 {
			      /* Reset PortA From Pin0 to Pin7 */
				  	#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOA_ODR &= ~(0b0000000011111111);             
		            GPIOA_ODR |=  (Copy_u8value << 0); 
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOA_BRR  = 0x000000FF;
					GPIOA_BSRR = (Copy_u8value << 0);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif		 
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortA From Pin8 to Pin15 */
			  		#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOA_ODR &= ~(0b1111111100000000);
				    GPIOA_ODR |=  (Copy_u8value << 8);
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOA_BRR  = 0x0000FF00;
					GPIOA_BSRR = (Copy_u8value << 8);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif	
		     }
		    break;
		case GPIO_u8_PORTB:
		     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
			 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
			 {
			      /* Reset PortB From Pin0 to Pin7 */
				 	#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOB_ODR &= ~(0b0000000011111111) ;
		        	GPIOB_ODR |=  (Copy_u8value << 0);
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOB_BRR  = 0x000000FF;
					GPIOB_BSRR = (Copy_u8value << 0);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif	
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortB From Pin8 to Pin15 */
			  		#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOB_ODR &= ~(0b1111111100000000) ;
					GPIOB_ODR |=  (Copy_u8value << 8);
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOB_BRR  = 0x0000FF00;
					GPIOB_BSRR = (Copy_u8value << 8);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif	 
		     }
		    break;
		case GPIO_u8_PORTC:
		     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
			 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
			 {
			      /* Reset PortC From Pin0 to Pin7 */
				  	#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOC_ODR &= ~(0b0000000011111111) ;
		       	 	GPIOC_ODR |=  (Copy_u8value << 0);
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOC_BRR  = 0x000000FF;
					GPIOC_BSRR = (Copy_u8value << 0);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif	
				 
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortC From Pin8 to Pin15 */
			  		#if (USE_OUTPUT_REG_ONSET == ODR )
	    			GPIOC_ODR &= ~(0b1111111100000000) ;
				 	GPIOC_ODR |=  (Copy_u8value << 8);
					#elif (USE_OUTPUT_REG_ONSET == BSRR )
   					GPIOC_BRR  = 0x0000FF00;
					GPIOC_BSRR = (Copy_u8value << 8);
					#else
						#error "Wrong SET Register Macro Selection"
					#endif
		     }
		    break;
		}
	}

}
/*#######################################################################*/


/*************************************************************************/
/*              Set FULL Port Register Value Function                    */
/*************************************************************************/
void MGPIO_voidSetFullPortValueRegister(u8 Copy_u8PortID , u16 Copy_u16value )
{
	/*       Range Check PortID and PinID        */
	if(Copy_u8PortID <= GPIO_u8_PORTC)
	{
		switch(Copy_u8PortID)
		{
		case GPIO_u8_PORTA:
			      /* Write on whole PortA From Pin0 to Pin15 */
		         GPIOA_ODR =  Copy_u16value ;
		    break;
			
		case GPIO_u8_PORTB:
			      /* Write on whole PortB From Pin0 to Pin15 */
		         GPIOB_ODR =  Copy_u16value ;
		    break;
			
		case GPIO_u8_PORTC:
			      /* Write on whole PortC From Pin0 to Pin15 */
		         GPIOC_ODR =  Copy_u16value ;
		    break;
		}
	}

}
/*#######################################################################*/


/*************************************************************************/
/*              Select Input PullUp or PullDown Function                 */
/*************************************************************************/
void MGPIO_voidSetInputPullUpPullDn(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8InputType)
{
	if((Copy_u8PortID <= GPIO_u8_PORTC) && (Copy_u8PinID <= GPIO_u8_PIN15))
	{
		switch (Copy_u8InputType)
		{
		case GPIO_u8_PULL_UP:
			MGPIO_voidSetPinValue (Copy_u8PortID , Copy_u8PinID , GPIO_u8_HIGH);
			break;

		case GPIO_u8_PULL_DOWN:
			MGPIO_voidSetPinValue (Copy_u8PortID , Copy_u8PinID ,GPIO_u8_LOW);
			break;
		default:
			break;
		}
	}
}
/*#######################################################################*/


/*************************************************************************/
/*              Select Input PullUp or PullDown Function                 */
/*************************************************************************/
void MGPIO_voidLockPortConfig(u8 Copy_u8PortID , u16 Copy_u16value )
{
	switch (Copy_u8PortID)
	{
	case GPIO_u8_PORTA:
		/* Choosing pins to be locked in PORTA */
		GPIOA_LCKR = Copy_u16value;
		/* Applying the Lock Sequence to PORTA */
		SET_BIT(GPIOA_LCKR , 16);  // Write 1
		CLR_BIT(GPIOA_LCKR , 16);  // Write 0
		SET_BIT(GPIOA_LCKR , 16);  // Write 1
		GET_BIT(GPIOA_LCKR , 16);  // Read  0
		GET_BIT(GPIOA_LCKR , 16);  // Read  1
		break;

	case GPIO_u8_PORTB:
		/* Choosing pins to be locked in PORTA */
		GPIOB_LCKR = Copy_u16value;
		/* Applying the Lock Sequence to PORTA */
		SET_BIT(GPIOB_LCKR , 16);  // Write 1
		CLR_BIT(GPIOB_LCKR , 16);  // Write 0
		SET_BIT(GPIOB_LCKR , 16);  // Write 1
		GET_BIT(GPIOB_LCKR , 16);  // Read  0
		GET_BIT(GPIOB_LCKR , 16);  // Read  1
		break;

	case GPIO_u8_PORTC:
		/* Choosing pins to be locked in PORTA */
		GPIOC_LCKR = Copy_u16value;
		/* Applying the Lock Sequence to PORTA */
		SET_BIT(GPIOC_LCKR , 16);  // Write 1
		CLR_BIT(GPIOC_LCKR , 16);  // Write 0
		SET_BIT(GPIOC_LCKR , 16);  // Write 1
		GET_BIT(GPIOC_LCKR , 16);  // Read  0
		GET_BIT(GPIOC_LCKR , 16);  // Read  1
		break;		
	
	default:
		break;
	}
}
/*#######################################################################*/


/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXX             END OF FUNCTIONS IMPLEMENTATION                XXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/



