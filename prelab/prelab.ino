
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

void setup() {
  lcdSetDataPins(DPINS);
  lcdInit();
  lcdClear(CYAN);


  for (int x = 0; x < 5; x++) {
      FillRect(80 + x * 20, 90 - x * 10, 160 - 40 * x, 10, RED); //techo
  }
  
  FillRect(100, 100, 120, 140, ORANGE); //base casa

  FillRect(110, 120, 40, 40, DARKCYAN); //ventana 1
  FillRect(170, 120, 40, 40, DARKCYAN); //ventana 2
  FillRect(140, 180, 40, 60, MAROON); //puerta}
}
void loop() {
  while (1);
}
