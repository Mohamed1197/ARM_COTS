/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        25/06/2022        ********************/
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
	    	{
	    		SET_BIT(GPIOA_ODR , Copy_u8PinID);
	    		//GPIOA_BSRR = (1 << Copy_u8PinID);
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{
	    		CLR_BIT(GPIOA_ODR , Copy_u8PinID);
	    		//GPIOA_BRR = (1 << Copy_u8PinID);
	    	}
	    	else
	    	{
	    		/* Do Nothing */
	    	}
			break;
			case GPIO_u8_PORTB:
	    	if(Copy_u8Value == GPIO_u8_HIGH)
	    	{
	    		SET_BIT(GPIOB_ODR , Copy_u8PinID);
	    		//GPIOB_BSRR = (1 << Copy_u8PinID);
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{
	    		CLR_BIT(GPIOB_ODR , Copy_u8PinID);
	    		//GPIOB_BRR = (1 << Copy_u8PinID);
	    	}
	    	else
	    	{
	    		/* Do Nothing */
	    	}
			break;
			case GPIO_u8_PORTC:
	    	if(Copy_u8Value == GPIO_u8_HIGH)
	    	{
	    		SET_BIT(GPIOC_ODR , Copy_u8PinID);
	    		//GPIOC_BSRR = (1 << Copy_u8PinID);
	    	}
	    	else if(Copy_u8Value == GPIO_u8_LOW)
	    	{
	    		CLR_BIT(GPIOC_ODR , Copy_u8PinID);
	    		//GPIOC_BSRR = (1 << Copy_u8PinID);
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
					 case GPIO_u8_HIGH:
						 //GPIOA_ODR |= 0x000000FF;
						 GPIOA_BSRR = 0x000000FF;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOA_ODR &= ~(0x000000FF);
						 GPIOA_BRR = 0x000000FF;
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:
						 //GPIOA_ODR |= 0x0000FF00;
						 GPIOA_BSRR = 0x0000FF00;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOA_ODR &= ~(0x0000FF00);
						 GPIOA_BRR = 0x0000FF00;
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
					 case GPIO_u8_HIGH:
						// GPIOB_ODR |= 0x000000FF;
						 GPIOB_BSRR = 0x000000FF;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOB_ODR &= ~(0x000000FF);
						 GPIOB_BRR = 0x000000FF;
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:
						 //GPIOB_ODR |= 0x0000FF00;
						 GPIOB_BSRR = 0x0000FF00;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOB_ODR &= ~(0x0000FF00);
						 GPIOB_BRR = 0x0000FF00;
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
					 case GPIO_u8_HIGH:
						 //GPIOC_ODR |= 0x000000FF;
						 GPIOC_BSRR = 0x000000FF;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOC_ODR &= ~(0x000000FF);
						 GPIOC_BRR = 0x000000FF;
						 break;
					 }
				 }
			     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
				 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
				 {
					 switch(Copy_u8value)
					 {
					 case GPIO_u8_HIGH:
						 //GPIOC_ODR |= 0x0000FF00;
						 GPIOC_BSRR = 0x0000FF00;
						 break;
					 case GPIO_u8_LOW:
						 //GPIOC_ODR &= ~(0x0000FF00);
						 GPIOC_BRR = 0x0000FF00;
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
/*                   Set Port Register Value Function                    */
/*************************************************************************/
void MGPIO_voidSetPortValueRegister(u8 Copy_u8PortID , u8 Copy_u8PinType ,u16 Copy_u16value )
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
				 GPIOA_ODR &= ~(0b0000000011111111) ;
		         GPIOA_ODR |=  (Copy_u16value << 0);
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortA From Pin8 to Pin15 */
				 GPIOA_ODR &= ~(0b1111111100000000) ;
				 GPIOA_ODR |=  (Copy_u16value << 8);
		     }
		    break;
		case GPIO_u8_PORTB:
		     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
			 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
			 {
			      /* Reset PortA From Pin0 to Pin7 */
				 GPIOB_ODR &= ~(0b0000000011111111) ;
		         GPIOB_ODR |=  (Copy_u16value << 0);
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortA From Pin8 to Pin15 */
				 GPIOB_ODR &= ~(0b1111111100000000) ;
				 GPIOB_ODR |=  (Copy_u16value << 8);
		     }
		    break;
		case GPIO_u8_PORTC:
		     /* Check if Pin is from GPIO_u8_PIN0 to GPIO_u8_PIN7 (LOW pins) */
			 if(Copy_u8PinType == GPIO_u8_LOW_PINS)
			 {
			      /* Reset PortA From Pin0 to Pin7 */
				 GPIOC_ODR &= ~(0b0000000011111111) ;
		         GPIOC_ODR |=  (Copy_u16value << 0);
			 }
		     /* else if Pin is from GPIO_u8_PIN8 to GPIO_u8_PIN15 (HIGH pins) */
			 else if(Copy_u8PinType == GPIO_u8_HIGH_PINS)
			 {
		      /* Reset PortA From Pin8 to Pin15 */
				 GPIOC_ODR &= ~(0b1111111100000000) ;
				 GPIOC_ODR |=  (Copy_u16value << 8);
		     }
		    break;
		}
	}

}
/*#######################################################################*/



