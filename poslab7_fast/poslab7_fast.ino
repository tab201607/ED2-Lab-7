
#include <stdint.h>
#include <ili9341_8_bits_fast.h>
// Pines usados
//#define LCD_RST PD_0
//#define LCD_CS PD_1
//#define LCD_RS PD_2
//#define LCD_WR PD_3
//#define LCD_RD PA_6
// hay que modificar los pines en la librería
// DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};

#include "bitmaps.h"

bool leftbutton = 1, rightbutton = 1;
int xpos = 50;

void setup() {
  Serial.begin(9600);
  lcdInit();
  lcdClear(CYAN);

pinMode(31, INPUT_PULLUP);//pin PB1 como input y interrupt
pinMode(17, INPUT_PULLUP);//pin PB2 como input y interrupt


//Colocar fondo 
  LCD_Bitmap(270,20, 30, 30, sun); //colocar sol
  LCD_Bitmap(50,30, 50, 16, cloud1); //colocar nubes
  LCD_Bitmap (160, 40, 34, 16, cloud2);
for (int x = 0; x<20; x++) {
  LCD_Bitmap(x * 16, 229, 16, 16, block); //colocar piso
}
  
}

bool lastpress = 0; //para revisar en que direccion esta apuntado mario y dejarlo en esa direccion cuando no esta moviendo (0 = derecha, 1 = izquierda)

void loop() {

leftbutton = digitalRead(31);
rightbutton = digitalRead(17);

//Mover mario a la izquierda o derecha, realizando la animacion correcta (a una velocidad de 1 frame por cada 5 pixeles)
  if (leftbutton == 0) { 
   xpos--;

   LCD_Sprite(xpos,200, 25, 29, mario, 4, (xpos/5)%4, 1, 1); 
   V_line(xpos + 26, 195, 29, CYAN);
   lastpress = 1;
   delay(10);
   }

  if (rightbutton == 0) {
   xpos++;
   
   LCD_Sprite(xpos,200, 25, 29, mario, 4, (xpos/5)%4, 0, 0);
   V_line(xpos - 1, 199, 29, CYAN);
   lastpress = 0;
   delay(10);
  }

  if ((rightbutton == 1) && (leftbutton = 1)) { //sirve para dejar mario parado en la direccion correcta cuando no esta moviendo
   LCD_Sprite(xpos,200, 25, 29, mario, 4, 0, lastpress, 0); 
  }
  

}
