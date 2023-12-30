/*
 * LCD_program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: aminz
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"

void LCD_Init(void){

	DIO_SetPortDirection(DATA_PORT,PORT_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,RS_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,RW_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,E_PIN,PIN_OUTPUT);
	_delay_ms(30);

	LCD_Write_Command(0X02);
	LCD_Write_Command(0X28);
	_delay_ms(3);

	LCD_Write_Command(lcd_DisplayOn);

	_delay_ms(3);

	LCD_Write_Command(lcd_Clear);

	_delay_ms(3);

	LCD_Write_Command(lcd_EntryMode);

	_delay_ms(3);

	LCD_Write_Command(lcd_Home);

	_delay_ms(3);


}

void LCD_Write_Command(u8 Command){

	DIO_SetPinValue(CONTROL_PORT,RS_PIN,PIN_LOW);
	DIO_SetPinValue(CONTROL_PORT,RW_PIN,PIN_LOW);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);


	DIO_SetPinValue(DATA_PORT,PIN_7,Get_Bit(Command,7));
	DIO_SetPinValue(DATA_PORT,PIN_6,Get_Bit(Command,6));
	DIO_SetPinValue(DATA_PORT,PIN_5,Get_Bit(Command,5));
	DIO_SetPinValue(DATA_PORT,PIN_4,Get_Bit(Command,4));
	//	DIO_SetPortValue(DATA_PORT,Command);

	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
	_delay_ms(3);
	DIO_SetPinValue(DATA_PORT,PIN_7,Get_Bit(Command,3));
	DIO_SetPinValue(DATA_PORT,PIN_6,Get_Bit(Command,2));
	DIO_SetPinValue(DATA_PORT,PIN_5,Get_Bit(Command,1));
	DIO_SetPinValue(DATA_PORT,PIN_4,Get_Bit(Command,0));
	//	DIO_SetPortValue(DATA_PORT,Command<<4);

	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
	_delay_ms(3);
}

void LCD_Write_Data(u8 Data){

	DIO_SetPinValue(CONTROL_PORT,RS_PIN,PIN_HIGH);
	DIO_SetPinValue(CONTROL_PORT,RW_PIN,PIN_LOW);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);

	DIO_SetPinValue(DATA_PORT,PIN_7,Get_Bit(Data,7));
	DIO_SetPinValue(DATA_PORT,PIN_6,Get_Bit(Data,6));
	DIO_SetPinValue(DATA_PORT,PIN_5,Get_Bit(Data,5));
	DIO_SetPinValue(DATA_PORT,PIN_4,Get_Bit(Data,4));
	//	DIO_SetPortValue(DATA_PORT,Data);


	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
	_delay_ms(3);
	DIO_SetPinValue(DATA_PORT,PIN_7,Get_Bit(Data,3));
	DIO_SetPinValue(DATA_PORT,PIN_6,Get_Bit(Data,2));
	DIO_SetPinValue(DATA_PORT,PIN_5,Get_Bit(Data,1));
	DIO_SetPinValue(DATA_PORT,PIN_4,Get_Bit(Data,0));
	//	DIO_SetPortValue(DATA_PORT,Data<<4);


	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
	_delay_ms(3);
}

void LCD_Write_String(u8 * Str, u8 Length){
	u8 i=0;
	for(i=0;i<Length;i++){
		LCD_Write_Data(Str[i]);
	}
}

void LCD_Go_To(u8 y,u8 x){
	LCD_Write_Command((128+(y*0x40)+x));
}
