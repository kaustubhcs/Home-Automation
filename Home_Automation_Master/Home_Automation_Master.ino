#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial slave(9, 10); // RX, TX
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


#define button_1 A1
#define button_2 A2
#define button_3 A3
#define button_4 A4
#define lcd_contrast A0
#define lcd_backlight 6
#define buttons_activator 7

// GLOBAL VALUES
int initialiser = 1;
int printed=0;
int print2=0;
int print3=0;
int fmode=0;;

void setup() 
{
  pinMode(buttons_activator,OUTPUT);
  pinMode(lcd_backlight,OUTPUT);
  pinMode(lcd_contrast,OUTPUT);
  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
  pinMode(button_3,INPUT);
  pinMode(button_4,INPUT);

  slave.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  digitalWrite(buttons_activator,LOW);
  digitalWrite(lcd_backlight,HIGH);
  analogWrite(lcd_contrast,0);
}

void loop() 
{
  button_stats();
  disp();
  delay(5000);
  // delay(1500);
  //tests();
  //led_dim();
}

void tests()
{
  button_stats();
  //secure_mode();
  buttons_test();
  //comm_test();




}




