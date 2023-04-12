
#include <stdint.h>
#include <ili9341_8_bits.h>
// Pines usados
//#define LCD_RST PD_0
//#define LCD_CS PD_1
//#define LCD_RS PD_2
//#define LCD_WR PD_3
//#define LCD_RD PA_6
// hay que modificar los pines en la librería
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};

#include "bitmaps.h"

void setup() {
  lcdSetDataPins(DPINS);
  Serial.begin(9600);
  Serial.println("Iniciando pantalla...");
  lcdInit();
  Serial.println("Pintando negro");
  lcdClear(CYAN);

  LCD_Bitmap(50,50, 100, 29, mario);
  LCD_Sprite(50,100, 25, 29, mario, 4, 0, 0, 1);
  LCD_Sprite(50,150, 25, 29, mario, 4, 1, 0, 1);
  LCD_Sprite(100,100, 25, 29, mario, 4, 2, 0, 1);
  LCD_Sprite(100,150, 25, 29, mario, 4, 3, 0, 1);
}
void loop() {
  while (1);
}
