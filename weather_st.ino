#include "SPI.h"
#include "TFT_eSPI.h"

#include <TouchScreen.h>
#define MINPRESSURE 10
#define MAXPRESSURE 40000
TFT_eSPI tft = TFT_eSPI();       
const int XP = 27, XM = 15, YP = 4, YM = 14; //ID=0x9341

const int TS_LEFT = 380, TS_RT = -2700, TS_TOP = -2500, TS_BOT = 520;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
int pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool Touch_getXY(void)
{
     TSPoint p = ts.getPoint();
}

void setup()
{
  Serial.begin(9600);
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLUE);
 
  tft.setTextSize(2);
  tft.setCursor(40,20);
  tft.setTextColor(TFT_WHITE);
  //tft.print("Teach Me Something");
  //Serial.println("Teach Me Something");


  //Header
   tft.fillRect(0 , 0 , 320 , 40, TFT_WHITE);
   //Thermometer
   tft.fillCircle(16, 33 , 5, TFT_BLACK);
   tft.fillCircle(16, 11 , 3, TFT_BLACK);   
   tft.fillCircle(16, 33 , 3, TFT_RED); 
   tft.fillRect( 13, 13, 7, 20, TFT_BLACK);
   tft.fillRect( 15, 13, 3, 20, TFT_RED);
   tft.setTextSize(2);
   tft.setCursor(25,20);
   tft.setTextColor(TFT_BLACK);
   tft.print(random(0,32));
   ///water
   tft.fillCircle(60, 28 , 11, TFT_BLACK);
    tft.fillTriangle(49, 28, 60, 6, 70, 24, TFT_BLACK);
    tft.fillCircle(60, 28 , 9, TFT_BLUE);
    tft.fillTriangle(50, 28, 60, 9, 68, 24, TFT_BLUE);
    
    tft.setCursor(80,20);
   tft.setTextColor(TFT_BLACK);
   tft.print(random(0,32));







  tft.setTextSize(2); 




}

void loop()
{
    
    
        tft.setTextColor(TFT_GREEN);
        tft.fillRect(40,120,300,30,TFT_BLUE);
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(40,120);
        tft. print ("X = ");
        tft.print(pixel_x);
        tft.setCursor(160,120);
        tft. print ("Y = ");
        tft.print(pixel_y);
        delay(10);
        bool down = Touch_getXY();
        
}