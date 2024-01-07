
#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_
/*	TIMER0		*/
#define TCCR0_REG		*((volatile u8*)0x53)
#define TCNT0_REG		*((volatile u8*)0x52)
#define OCR0_REG		*((volatile u8*)0x5C)


/*	TIMER1	*/
#define		TCCR1A_REG		*((volatile u8*)0x4F)
#define 	TCCR1B_REG		*((volatile u8*)0x4E)
#define 	TCNT1_REG		*((volatile u16*)0x4C)
#define 	OCR1A_REG		*((volatile u16*)0x4A)
#define 	OCR1B_REG		*((volatile u16*)0x48)
#define 	ICR1_REG		*((volatile u16*)0x46)


#define TIMSK_REG		*((volatile u8*)0x59)
#define TIFR_REG		*((volatile u8*)0x58)



#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
