/*

HOME AUTOMATION SLAVE CODE

*/



#include <SoftwareSerial.h>

#define relay_0 2
#define relay_1 3
#define relay_2 11
#define relay_3 6
#define relay_4 4
#define relay_5 45
#define relay_6 47
#define relay_7 52
#define relay_8 51
#define relay_9 53
#define relay_10 49

#define cfl relay_0
#define tubes relay_1
#define fan relay_2
#define night_lamp relay_3
//#define
#define table_plug_2 relay_5
#define table_plug_1 relay_6
#define bell relay_7
#define master_plug relay_8
#define tv relay_9

#define mosquito_light table_plug_1

//#defines

#define buzzer 35
#define passage_door_open_led 23
#define passage_door_lock_led 25
#define passage_door_open_ldr A8
#define passage_door_lock_ldr A7
#define passage_door_bell_led 27
#define passage_door_bell_switch A6
#define pir_1 A5
#define pir_2 A4
#define pir_3 A3
#define living_room_door_open_led 29
#define living_room_door_lock_led 31
#define living_room_door_lock_ldr A2
#define living_room_door_open_ldr A1
#define gallery_door_open_led 33
#define gallery_door_open_ldr A0





SoftwareSerial master(10, 14);

int relay[11] = {
  2, 3, 11, 6, 4, 45, 47, 52, 51, 53, 49
};
int commands[15] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int bell_t = 0;
unsigned long time = 0;
int gmode = 0;
int fmode = 0;
unsigned long y = 0;
unsigned long x = 0;
unsigned long str = millis();

void setup()
{
  initialise_pins();

  Serial.begin(9600);
  master.begin(9600);
  digitalWrite(master_plug, HIGH);


}

void loop()
{
  digitalWrite(master_plug, HIGH);
  mode();
  bell_detect();

  //  delay(1000);


  //pir_test_3();
  //    tests();
}




void tests()
{
  // sensor_test();
  // sensor_test_2();
  //pir_test_3();
  //  comm_test();
  //relay_test();
  //pir_test_2();
  //analog_pir();

  /*
   pir(1);
   pir(2);
   pir(3);
   */
  pir3_buzz();
  if (Serial.available())
  {
    relay_test();
    Serial.read();
  }
}












void initialise_pins()
{

  for (int i = 0; i < 11; i++)
  {
    pinMode(relay[i], OUTPUT);
    digitalWrite(relay[i], LOW);
  }


  pinMode(buzzer, OUTPUT);
  pinMode(passage_door_open_led, OUTPUT);
  pinMode(passage_door_lock_led, OUTPUT);
  pinMode(passage_door_open_ldr, INPUT);
  pinMode(passage_door_lock_ldr, INPUT);
  pinMode(passage_door_bell_led, OUTPUT);
  pinMode(passage_door_bell_switch, INPUT);
  pinMode(pir_1, INPUT);
  pinMode(pir_2, INPUT);
  pinMode(pir_3, INPUT);
  pinMode(living_room_door_open_led, OUTPUT);
  pinMode(living_room_door_lock_led, OUTPUT);
  pinMode(living_room_door_lock_ldr, INPUT);
  pinMode(living_room_door_open_ldr, INPUT);
  pinMode(gallery_door_open_led, OUTPUT);
  pinMode(gallery_door_open_ldr, INPUT);



  digitalWrite(buzzer, LOW);
  digitalWrite(passage_door_open_led, HIGH);
  digitalWrite(passage_door_lock_led, HIGH);
  analogWrite(passage_door_open_ldr, 1023);
  analogWrite(passage_door_lock_ldr, 1023);
  digitalWrite(passage_door_bell_led, HIGH);
  analogWrite(passage_door_bell_switch, 1023);
  analogWrite(pir_1, 1023);
  analogWrite(pir_2, 1023);
  analogWrite(pir_3, 1023);
  digitalWrite(living_room_door_open_led, HIGH);
  digitalWrite(living_room_door_lock_led, HIGH);
  analogWrite(living_room_door_lock_ldr, 1023);
  analogWrite(living_room_door_open_ldr, 1023);
  digitalWrite(gallery_door_open_led, HIGH);
  analogWrite(gallery_door_open_ldr, 1023);

  analogWrite(pir_1, 0);
  analogWrite(pir_2, 0);
  analogWrite(pir_3, 0);


}






























