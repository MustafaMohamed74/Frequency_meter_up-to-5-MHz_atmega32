/*
 * LCD_interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: aminz
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

void LCD_Init(void);
void LCD_Write_Command(u8 Command);
void LCD_Write_Data(u8 Data);
void LCD_Write_String(u8 * Str, u8 Length);
void LCD_Go_To(u8 y,u8 x);

#endif /* LCD_INTERFACE_H_ */
