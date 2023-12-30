/*
 * TIMER_interface.h
 *
 *  Created on: Oct 6, 2023
 *      Author: 20128
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//Timer0

void TIMER0_Init(void);

void TIMER0_OVF_Interrupt_Enable(void);
void TIMER0_OVF_Interrupt_Disable(void);
void TIMER0_Set_TCNT0_Register(u8 Value);

void TIMER0_OVF_Set_Callback_Address(void (*PTR) (void));

//TIMER1

void TIMER1_Init(void);

void TIMER1_OVF_Interrupt_Enable(void);
void TIMER1_OVF_Interrupt_Disable(void);

void TIMER1_OVF_Set_Callback_Address(void (*PTR) (void));

void TIMER1_Set_TCNT1_Register(u16 Value);
u16 TIMER1_Get_TCNT1_Register(void);


#endif /* TIMER_INTERFACE_H_ */
