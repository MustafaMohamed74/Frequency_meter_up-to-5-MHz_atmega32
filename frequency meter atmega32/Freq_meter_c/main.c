/*
 * main.c
 *
 *  Created on: DEC 29, 2023
 *      Author: Mustafa Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "TIMER_interface.h"
#include "GLOBAL_INTERRUPT_interface.h"

#include "util/delay.h"

#define F_CPU 11059200

void time0(void);
void time1(void);
void display(u32 freq);
void MHz(u32 freq);
void KHz(u32 freq);
void Hz(u32 freq);

u32 Ovf1 =0 ;
u32 Ovf0 =0 ;
u32 Counter1 = 0 ;
u32 temp = 0 ;
u32 freq = 0 ;

void main(void){
	LCD_Init();
	LCD_Write_Command(lcd_Clear);

	TIMER0_Init();
	TIMER1_Init();

	TIMER0_OVF_Set_Callback_Address(time0);
	TIMER1_OVF_Set_Callback_Address(time1);      //p1/t1 pin is the input pin for timer1 in counter mode

	TIMER0_OVF_Interrupt_Enable();
	TIMER1_OVF_Interrupt_Enable();

	GLOBAL_INTERRUPT_Enable();
	DIO_SetPinDirection(PORT_D,PIN_0,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_0,PIN_HIGH); //Input pull_up

	LCD_Write_String("Start <3",9);
	_delay_ms(100);
	while(1){
		Ovf1 = 0 ;
		Ovf0 = 0 ;
		TIMER0_Set_TCNT0_Register(0);
		TIMER1_Set_TCNT1_Register(0);

		while(Ovf0 <= 59){
			asm("NOP");
		}
		_delay_us(3600);
		LCD_Write_Command(lcd_Clear);

		TIMER0_OVF_Interrupt_Disable();
		TIMER1_OVF_Interrupt_Disable();

		temp = Ovf1 * 65536 ;
		freq = temp + TIMER1_Get_TCNT1_Register();

		if( freq >= 1000000) {
			MHz(freq);
		}
		else if ( freq >= 1000){
			KHz(freq);
		}
		else if (freq < 1000){
			Hz(freq);
		}
		if(DIO_GetPinValue(PORT_D,PIN_0)== 0 ){
			display(freq);
		}
		TIMER0_OVF_Interrupt_Enable();
		TIMER1_OVF_Interrupt_Enable();
	}

}

void time0(void){
	Ovf0 ++ ;
}

void time1(void){
	Ovf1 ++ ;
}
void display(u32 freq){
	LCD_Go_To(1,1);
	LCD_Write_Data(((freq%100000000)/10000000) + '0' );
	LCD_Write_Data(((freq%10000000)/1000000) + '0' );
	LCD_Write_Data(((freq%1000000)/100000) + '0' );
	LCD_Write_Data(((freq%100000)/10000) + '0' );
	LCD_Write_Data(((freq%10000)/1000) + '0' );
	LCD_Write_Data(((freq%1000)/100) +   '0' );
	LCD_Write_Data(((freq%100)/10) +     '0' );
	LCD_Write_Data(((freq%10)/1) +        '0' );
	LCD_Write_String("Hz", 2 );
}
void MHz(u32 freq){
	LCD_Write_String("Freq =", 6 );
	LCD_Write_Data(((freq%100000000)/10000000) + '0' );
	LCD_Write_Data(((freq%10000000)/1000000) + '0' );
	LCD_Write_Data('.');
	LCD_Write_Data(((freq%1000000)/100000) + '0' );
	LCD_Write_Data(((freq%100000)/10000) + '0' );
	LCD_Write_Data(((freq%10000)/1000) + '0' );
	LCD_Write_String("MHz", 3 );

}
void KHz(u32 freq){
	LCD_Write_String("Freq =", 6 );
	LCD_Write_Data(((freq%1000000)/100000) + '0' );
	LCD_Write_Data(((freq%100000)/10000) + '0' );
	LCD_Write_Data(((freq%10000)/1000) + '0' );
	LCD_Write_Data('.');
	LCD_Write_Data(((freq%1000)/100) +   '0' );
	LCD_Write_Data(((freq%100)/10) +     '0' );
	LCD_Write_Data(((freq%10)/1) +        '0' );
	LCD_Write_String("KHz", 3 );

}
void Hz(u32 freq){
	LCD_Write_String("Freq =", 6 );
	LCD_Write_Data(((freq%1000)/100) +   '0' );
	LCD_Write_Data(((freq%100)/10) +     '0' );
	LCD_Write_Data(((freq%10)/1) +        '0' );
	LCD_Write_String("Hz", 2 );
}
