/*
 * TIMER_program.c
 *
 *  Created on: Oct 6, 2023
 *      Author: 20128
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (* TIMER0_OVF_CALLBACK_PTR) (void)=NULL;

void TIMER0_Init(void){
	//Select mode
	Clr_Bit(TCCR0_register,WGM00);
	Clr_Bit(TCCR0_register,WGM01);

	//set output mode
	Clr_Bit(TCCR0_register,COM00);
	Clr_Bit(TCCR0_register,COM01);

	//select prescalar
	Set_Bit(TCCR0_register,CS00);
	Clr_Bit(TCCR0_register,CS01);
	Set_Bit(TCCR0_register,CS02);

}

void TIMER0_OVF_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TOIE0);
}
void TIMER0_OVF_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TOIE0);
}
void TIMER0_Set_TCNT0_Register(u8 Value){

	TCNT0_register=Value;

}
void TIMER0_OVF_Set_Callback_Address(void (*PTR) (void)){
	TIMER0_OVF_CALLBACK_PTR=PTR;
}
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_11 (void){
	TIMER0_OVF_CALLBACK_PTR();
}

//TIMER1
void (* TIMER1_CTC_A_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_CTC_B_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_OVF_CALLBACK_PTR) (void)=NULL;
void (* TIMER1_ICI_CALLBACK_PTR) (void)=NULL;

void TIMER1_Init(void){
	//selsect mode
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1A_register,WGM10);
	Clr_Bit(TCCR1A_register,WGM11);

	Clr_Bit(TCCR1A_register,COM1A0);
	Clr_Bit(TCCR1A_register,COM1A1);
	Clr_Bit(TCCR1A_register,COM1B0);
	Clr_Bit(TCCR1A_register,COM1A1);

	Set_Bit(TCCR1B_register,CS11);
	Set_Bit(TCCR1B_register,CS10);
	Set_Bit(TCCR1B_register,CS12);


	//out mode


}

void TIMER1_OVF_Interrupt_Enable(void){
	Set_Bit(TIMSK_register,TOIE1);
}
void TIMER1_OVF_Interrupt_Disable(void){
	Clr_Bit(TIMSK_register,TOIE1);

}

void TIMER1_OVF_Set_Callback_Address(void (*PTR) (void)){
	TIMER1_OVF_CALLBACK_PTR=PTR;
}


void TIMER1_Set_TCNT1_Register(u16 Value){
	TCNT1_register=Value;
}
u16 TIMER1_Get_TCNT1_Register(void){
	return TCNT1_register;
}

void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_9 (void){
	TIMER1_OVF_CALLBACK_PTR();
}



