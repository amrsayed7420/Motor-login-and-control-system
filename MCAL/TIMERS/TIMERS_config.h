/*
 * TIMERS_config.h
 *
 *  Created on: Aug 15, 2023
 *      Author: First
 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_

#define COMPARE_MATCH_VALUE		200

#define TIMERS_SW_COUNTER_CTC		5000
#define TIMERS_SW_COUNTER_OVF		3907

#define T1_SW_COUNTER_CTC_CHANNEL_A		20

#define F_T1			1000000
#define	T1_CMPR_MATCH_CHA_VALUE		50000

/*options:
 * 1. CTC MODE
 * 2.FAST PWM --> TOP ICR
 * */
#define TIMERS_T1_MODE			FAST_PWM

#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */
