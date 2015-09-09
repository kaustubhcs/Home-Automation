void relay_test()
{
  //  off();
  for (int i=0;i<11;i++)
  {
    digitalWrite(relay[i],HIGH);
    delay(1500);
    pir3_buzz();
    digitalWrite(relay[i],LOW);
    delay(1500);
  }
}

// All switch off test !
void off()
{
  for (int i=0;i<11;i++)
  {
    digitalWrite(relay[i],LOW);
  }
}

void sensor_test ()
{

  /* 
   digitalWrite(passage_door_open_led,LOW);
   digitalWrite(living_room_door_open_led,LOW);
   digitalWrite(living_room_door_lock_led,LOW);
   digitalWrite(gallery_door_open_led,LOW);
   digitalWrite(buzzer,HIGH);
   */
  Serial.println("\n\n\n\n\n\n\n\n\n\n");


  digitalWrite(passage_door_bell_led,LOW);

  digitalWrite(passage_door_lock_led,LOW);
  analogWrite(passage_door_lock_ldr,0);
  digitalWrite(buzzer,HIGH);
  delay(5);
  Serial.print("Passage Door LOCK LDR: ");
  Serial.println(analogRead(passage_door_lock_ldr)); 
  digitalWrite(buzzer,LOW);
  digitalWrite(passage_door_lock_led,HIGH);
  analogWrite(passage_door_lock_ldr,1023);
  digitalWrite(passage_door_bell_led,HIGH);

  delay(50);
  digitalWrite(passage_door_bell_led,LOW);


  digitalWrite(passage_door_open_led,LOW);
  analogWrite(passage_door_open_ldr,0);
  digitalWrite(buzzer,HIGH);
  delay(5);
  Serial.print("Passage Door OPEN LDR: ");
  Serial.println(analogRead(passage_door_open_ldr)); 
  digitalWrite(buzzer,LOW);
  digitalWrite(passage_door_open_led,HIGH);
  analogWrite(passage_door_open_ldr,1023);
  digitalWrite(passage_door_bell_led,HIGH);

  delay(50);
  digitalWrite(passage_door_bell_led,LOW);



  digitalWrite(living_room_door_lock_led,LOW);
  analogWrite(living_room_door_lock_ldr,0);
  digitalWrite(buzzer,HIGH);
  delay(5);
  Serial.print("Living Room Door LOCK LDR: ");
  Serial.println(analogRead(living_room_door_lock_ldr)); 
  digitalWrite(buzzer,LOW);
  digitalWrite(living_room_door_lock_led,HIGH);
  analogWrite(living_room_door_lock_ldr,1023);
  digitalWrite(passage_door_bell_led,HIGH);

  delay(50);
  digitalWrite(passage_door_bell_led,LOW);



  digitalWrite(living_room_door_open_led,LOW);
  analogWrite(living_room_door_open_ldr,0);
  digitalWrite(buzzer,HIGH);
  delay(5);
  Serial.print("Living Room Door OPEN LDR: ");
  Serial.println(analogRead(living_room_door_open_ldr)); 
  digitalWrite(buzzer,LOW);
  digitalWrite(living_room_door_open_led,HIGH);
  analogWrite(living_room_door_open_ldr,1023);
  digitalWrite(passage_door_bell_led,HIGH);

  delay(50);
  digitalWrite(passage_door_bell_led,LOW);


  digitalWrite(gallery_door_open_led,LOW);
  analogWrite(gallery_door_open_ldr,0);
  digitalWrite(buzzer,HIGH);
  delay(5);
  Serial.print("Gallery Door OPEN LDR: ");
  Serial.println(analogRead(gallery_door_open_ldr)); 
  digitalWrite(buzzer,LOW);
  digitalWrite(gallery_door_open_led,HIGH);
  analogWrite(gallery_door_open_ldr,1023);

  digitalWrite(passage_door_bell_led,HIGH);

  delay(1000);



}


void sensor_test_2()
{
  digitalWrite(passage_door_open_led,LOW);
  analogWrite(passage_door_open_ldr,0);
  if (analogRead(passage_door_open_ldr)>70)
  {
    digitalWrite(buzzer,LOW);
  }
  else
  {
    digitalWrite(buzzer,HIGH);   
  }
}


void comm_test()
{
  int i=10;
  while(1)
  {
    Serial.println(i);
    master.write(i);
    delay(1000);
    i++;
  }
}

void pir_test()
{
  Serial.println("PIR Test Running");
  Serial.print("PIR 1: " );
  if (analogRead(pir_1)>0)
  {
    Serial.print("ON");
  } 
  else
  {
    Serial.print("OFF");
  } 


  Serial.print("    PIR 2: " );
  if (analogRead(pir_2)>0)
  {
    Serial.print("ON");
  } 
  else
  {
    Serial.print("OFF");
  } 




  Serial.print("    PIR 3: " );
  if (analogRead(pir_3)>0)
  {
    Serial.print("ON");
  } 
  else
  {
    Serial.print("OFF");
  } 

  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  delay(750);
}



void pir_test_2()
{
  Serial.println("** PIR Test Running **");
  Serial.print("PIR 1: " );
  Serial.println(analogRead(pir_1));


  Serial.print("PIR 2: " );
  Serial.println(analogRead(pir_2));


  Serial.print("PIR 3: " );
  Serial.println(analogRead(pir_3));



  //  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  delay(750);
}

void pir_test_3()
{
  Serial.println("PIR 3 Time Test Initiated !");
  Serial.println("Waiting 1 Second");  
  delay(1000);
  unsigned long timer=0;
  Serial.print("Waiting for PIR 0");
  while(analogRead(pir_3) == 0);
  Serial.println("    FOUND");
  Serial.print("Waiting for PIR 1");
  while(analogRead(pir_3) != 0);
  Serial.println("    FOUND");
  timer=millis();
  Serial.println("Detecting Motion...");
  while(analogRead(pir_3) == 0);
  Serial.println("Calculating Time");
  Serial.print("Time: ");
  Serial.println(millis()-timer);
  Serial.println("\n\n\n\n\n\n\n");

}


void c(int num)
{
  Serial.print("Check Pt ");
  Serial.println(num);
  //  Serial.println("\n\n"); 
}


void analog_pir()
{
  Serial.print("PIR Reading: ");
  Serial.println(analogRead(pir_2));

  if (analogRead(pir_2)>1)
  {
    digitalWrite(buzzer,HIGH);
    delay(10);
    digitalWrite(buzzer,LOW);

  }
  delay(500);

}

void print_info()
{

  for (int i=0;i<4;i++)
  {
    Serial.print(commands[i]); 
    Serial.print("  ");
    //    Serial.println("\n\n")
  }
  Serial.println();
}


void pir3_buzz()
{
 int t;
 t=analogRead(pir_3);
 Serial.println(t);
 if (t>0)
 {
  digitalWrite(buzzer,HIGH); 
 }
 else
 {
  digitalWrite(buzzer,LOW); 
 }
}
