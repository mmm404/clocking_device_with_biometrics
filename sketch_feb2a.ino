//#include <Adafruit_I2CDevice.h>
//#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;
uint16_t tft_id="";

void setup() {
  tft.reset();
  tft_id = tft.readID();
  tft.begin(tft_id);
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  blink();
  delay(5000);
  tft.fillScreen(TFT_BLACK);
  welcome();
  delay(5000);
  tft.fillScreen(TFT_BLACK);
  
}

void loop() {
 queryPin();
 delay(2000);
  tft.fillScreen(TFT_BLACK);
  tft.fillScreen(TFT_BLACK);
 delay(2000);
  tft.fillScreen(TFT_BLACK);
  masterMenu(); 
 delay(2000);
  tft.fillScreen(TFT_BLACK);
  enterNewPass();
 delay(2000);
  tft.fillScreen(TFT_BLACK);
  confirmNewPass();
 delay(2000);
  tft.fillScreen(TFT_BLACK);
  passReset();
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  
  passNotReset();
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  
}
void welcome(){
  tft.drawRect(70,65,180,100,TFT_WHITE);
  //tft.fillRect(120,120,50,50,TFT_NAVY);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(100, 100);
  tft.println("WELCOME");

}
void blink(){
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(100, 100);
  tft.println("LOADING");

 for(int i = 150 ; i < 180 ; i+=10){
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(i, 130);
    tft.println(".");
    delay(2000);
 }

}    

void queryPin(){

 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(110, 50);
 tft.println("ENTER PIN");
 
 for (int i = 0; i < 140;i++){
   tft.drawFastHLine(80+i, 110, 30, TFT_WHITE);
 }
 //delay();
}
void masterMenu(){
 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(110, 30);
 tft.println("MASTER MENU");
 for (int i = 0; i < 110;i++){
   tft.drawFastHLine(100+i, 55, 30, TFT_WHITE);
 }
 
 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(60, 70);
 tft.println("1. SINGLE ACCESS");
 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(60, 100);
 tft.println("2. MULTIPLE ACCESS");
 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(60, 130);
 tft.println("3. RESET PASSWORD");
 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(60, 160);
 tft.println("4. RETURN TO HOME");
  
}
void enterNewPass(){

 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(50, 40);
 tft.println("ENTER NEW PASSWORD");
 
 for (int i = 0; i < 150;i++){
   tft.drawFastHLine(70+i, 110, 30, TFT_WHITE);
 }
 //delay();
}
void confirmNewPass(){

 tft.setTextSize(2);
 tft.setTextColor(TFT_WHITE);
 tft.setCursor(40, 40);
 tft.println("CONFIRM NEW PASSWORD");
 
 for (int i = 0; i < 150;i++){
   tft.drawFastHLine(70+i, 110, 30, TFT_WHITE);
 }
 //delay();
}
void passReset(){

 tft.setTextSize(3);
 tft.setTextColor(TFT_GREEN);
 tft.setCursor(40, 100);
 tft.println("PASSWORD RESET");
 tft.drawRect(25,90,280,40, TFT_GREEN);
}
void passNotReset(){

 tft.setTextSize(2);
 tft.setTextColor(TFT_RED);
 tft.setCursor(30, 100);
 tft.println("PASSWORDS DID NOT MATCH");
 tft.drawRect(25,85,290,40, TFT_RED);
}

