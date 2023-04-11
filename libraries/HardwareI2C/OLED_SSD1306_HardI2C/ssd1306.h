// Copyright 2021 IOsetting <iosetting(at)outlook.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __SSD1306_H__
#define __SSD1306_H__

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * This SSD1306 LCD uses I2C for communication
 *
 * Library features functions for drawing lines, rectangles and circles.
 *
 * It also allows you to draw texts and characters using appropriate functions provided in library.
 *
 * Default pinout
 *
SSD1306    |W806         |DESCRIPTION

VCC        |3.3V         |
GND        |GND          |
SCL        |PA1          |Serial clock line
SDA        |PA4          |Serial data line
 */

#include "ascii_fonts.h"
#include "Arduino.h"
#include "HardwareI2C.h"


/* I2C address */
#define SSD1306_I2C_ADDR         0x3C

/* SSD1306 settings */
/* SSD1306 width in pixels */
#define SSD1306_WIDTH            128
/* SSD1306 LCD height in pixels */
#define SSD1306_HEIGHT           64

#define SSD1306_TIMEOUT					20000

#define SSD1306_COLOR_BLACK 0x00
#define SSD1306_COLOR_WHITE 0x01

uint8_t SSD1306_Init(void);
void SSD1306_UpdateScreen(void);
void SSD1306_ToggleInvert(void);
void SSD1306_Fill(uint8_t Color);
void SSD1306_DrawPixel(uint16_t x, uint16_t y, uint8_t color);
void SSD1306_GotoXY(uint16_t x, uint16_t y);
char SSD1306_Putc(char ch, FontDef_t* Font, uint8_t color);
char SSD1306_Puts(char* str, FontDef_t* Font, uint8_t color);
void SSD1306_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t c);
void SSD1306_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint8_t c);
void SSD1306_Image(uint8_t *img, uint8_t frame, uint8_t x, uint8_t y);

/**
 * @brief  Writes single byte command to slave
 * @param  command: command to be written
 * @retval None
 */
void SSD1306_WriteCommand(uint8_t command);

/**
 * @brief  Writes single byte data to slave
 * @param  data: data to be written
 * @retval None
 */
void SSD1306_WriteData(uint8_t data);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
