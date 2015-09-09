// Passage Door Lock

int pdl()
{
  digitalWrite(passage_door_lock_led, LOW);
  analogWrite(passage_door_lock_ldr, 0);
  delay(5);
  if (analogRead(passage_door_lock_ldr) > 0)
  {
    digitalWrite(passage_door_lock_led, HIGH);
    analogWrite(passage_door_lock_ldr, 1023);
    return (0);
  }
  else
  {
    digitalWrite(passage_door_lock_led, HIGH);
    analogWrite(passage_door_lock_ldr, 1023);
    return (1);
  }
}

// Passage Door Open

int pdo() 
{
  digitalWrite(passage_door_open_led, LOW);
  analogWrite(passage_door_open_ldr, 0);
  delay(5);
  if (analogRead(passage_door_open_ldr) > 0)
  {
    digitalWrite(passage_door_open_led, HIGH);
    analogWrite(passage_door_open_ldr, 1023);
    return (0);
  }
  else
  {
    digitalWrite(passage_door_open_led, HIGH);
    analogWrite(passage_door_open_ldr, 1023);
    return (1);
  }
}




// Living Room Door Lock

int ldl() 
{
  digitalWrite(living_room_door_lock_led, LOW);
  analogWrite(living_room_door_lock_ldr, 0);
  delay(5);
  if (analogRead(living_room_door_lock_ldr) > 0)
  {
    digitalWrite(living_room_door_lock_led, HIGH);
    analogWrite(living_room_door_lock_ldr, 1023);
    return (0);
  }
  else
  {
    digitalWrite(living_room_door_lock_led, HIGH);
    analogWrite(living_room_door_lock_ldr, 1023);
    return (1);
  }
}


int ldo() //Living Room Door Open
{
  digitalWrite(living_room_door_open_led, LOW);
  analogWrite(living_room_door_open_ldr, 0);
  delay(5);
  if (analogRead(living_room_door_open_ldr) > 0)
  {
    digitalWrite(living_room_door_open_led, HIGH);
    analogWrite(living_room_door_open_ldr, 1023);
    return (0);
  }
  else
  {
    digitalWrite(living_room_door_open_led, HIGH);
    analogWrite(living_room_door_open_ldr, 1023);
    return (1);
  }
}


// Gallery Door Open

int gdo() 
{
  digitalWrite(gallery_door_open_led, LOW);
  analogWrite(gallery_door_open_ldr, 0);
  delay(5);
  if (analogRead(gallery_door_open_ldr) > 0)
  {
    digitalWrite(gallery_door_open_led, HIGH);
    analogWrite(gallery_door_open_ldr, 1023);
    return (0);
  }
  else
  {
    digitalWrite(gallery_door_open_led, HIGH);
    analogWrite(gallery_door_open_ldr, 1023);
    return (1);
  }
}

int  pir(int no)
{
  int value = -1 ;
  switch (no)
  {
    case 1:
      Serial.print("PIR 1: ");
      value = analogRead(pir_1);
      break;
    case 2:
      Serial.print("PIR 2: ");
      value = analogRead(pir_2);
      break;
    case 3:
      Serial.print("PIR 3: ");
      value = analogRead(pir_3);
      break;
  }

  while (value != 0)
  {
    switch (no)
    {
      case 1:
        value = analogRead(pir_1);
        break;
      case 2:
        value = analogRead(pir_2);
        break;
      case 3:
        value = analogRead(pir_3);
        break;
    }

  };

  /*
  switch(no)
   {
   case 1:
   value = analogRead(pir_1);
   break;
   case 2:
   value = analogRead(pir_2);
   break;
   case 3:
   value = analogRead(pir_3);
   break;
   }
   */

  unsigned long time = millis();

  int adder = 0;

  switch (no)
  {
    case 1:
      adder = 2500;
      break;
    case 2:
      adder = 700;
      break;
    case 3:
      adder = 200;
      break;
  }



  while (millis() < (time + adder))
  {
    switch (no)
    {
      case 1:
        value = analogRead(pir_1);
        break;
      case 2:
        value = analogRead(pir_2);
        break;
      case 3:
        value = analogRead(pir_3);
        break;
    }

    if (value > 1)
    {
      Serial.print("Value = ");
      Serial.println(value);
      Serial.println("Motion Detected");
      return (1);
    }


  }
  Serial.println(" **NO Motion Detected **");

  return (0);

}


int  pir_pure()
{
  if ( analogRead(pir_1) > 0 || analogRead(pir_2) > 0 || analogRead(pir_3) > 0)
  {
    return (1);
  }

  return (0);


}


int motion()
{
  delay(300);
  int val_1 = 0;
  int val_2 = 0;
  int val_3 = 0;


  val_1 = analogRead(pir_1);
  val_2 = analogRead(pir_2);
  val_3 = analogRead(pir_3);
  /*
    if ( val_1 > 1 || val_3 > 1 )
    {
      Serial.println("Motion Detected PIR 1    PIR 2    PIR 3");
      Serial.print("                  ");
      Serial.print(val_1);
      Serial.print("        ");
      Serial.print(val_2 );
      Serial.print("         ");
      Serial.println(val_3);
      return (1);
    }
  */
  unsigned long timer = 0;
  timer = millis();


  unsigned long adder;

  timer = millis();
  adder = 3000;
  int pdo_flag = 0;

  if (pdo() == 1)
  {
    pdo_flag = 5;
  }

  if (pdo() == 1 || pdo_flag > 0)
  {
    delay(1000);
    while (millis() < (timer + adder) )
    {
      val_1 = analogRead(pir_1);
      val_2 = analogRead(pir_2);
      val_3 = analogRead(pir_3);

      if ( val_1 > 1 || val_3 > 3)
      {
        Serial.println("Motion Detected PIR 1    PIR 2    PIR 3");
        Serial.print("                  ");
        Serial.print(val_1);
        Serial.print("        ");
        Serial.print(val_2 );
        Serial.print("         ");
        Serial.println(val_3);
        pdo_flag = pdo_flag - 1;
        return (1);
      }
      bell_detect();
    }
    Serial.println("NO Motion Detected");
    return (0);


  }

  adder = 3600000;




  if (gmode == 5) // Demo Mode
  {
    adder = 0;
  }

  timer = millis();
  while (millis() < (timer + adder) )
  {
    if (pdo() == 1)
    {
      pdo_flag = 5;
      return (1);
    }
    val_1 = analogRead(pir_1);
    val_2 = analogRead(pir_2);
    val_3 = analogRead(pir_3);

    if ( val_1 > 1 || val_3 > 3)
    {
      Serial.println("Motion Detected PIR 1    PIR 2    PIR 3");
      Serial.print("                  ");
      Serial.print(val_1);
      Serial.print("        ");
      Serial.print(val_2 );
      Serial.print("         ");
      Serial.println(val_3);
      return (1);

    }
    bell_detect();
  }
  Serial.println("NO Motion Detected");
  return (0);
}

void bell_detect ()
{
  // For debugging reasons
  get_info();

  //  if (commands[3] == 49)
  {
    analogWrite(passage_door_bell_switch, 0);
    delay(5);
    //  Serial.println(analogRead(passage_door_bell_switch));
    if (analogRead(passage_door_bell_switch) > 500)
    {
      digitalWrite(table_plug_1, HIGH);

      digitalWrite(buzzer, HIGH);
      digitalWrite(passage_door_bell_led, LOW);
      delay(25);
      digitalWrite(buzzer, LOW);
      digitalWrite(passage_door_bell_led, HIGH);
      delay(75);
      digitalWrite(buzzer, HIGH);
      digitalWrite(passage_door_bell_led, LOW);
      delay(25);
      digitalWrite(buzzer, LOW);
      digitalWrite(passage_door_bell_led, HIGH);
      delay(75);
      digitalWrite(buzzer, HIGH);
      digitalWrite(passage_door_bell_led, LOW);
      delay(25);
      digitalWrite(buzzer, LOW);
      digitalWrite(passage_door_bell_led, HIGH);
      delay(150);
      digitalWrite(buzzer, HIGH);
      digitalWrite(passage_door_bell_led, LOW);
      delay(25);
      digitalWrite(buzzer, LOW);
      digitalWrite(passage_door_bell_led, HIGH);
      bell_t++;
      if (bell_t  == 15)
      {
        digitalWrite(bell, HIGH);
        delay(25);
        digitalWrite(bell, LOW);

      }
    }
    else
    {
      bell_t = 0;

    }
    analogWrite(passage_door_bell_switch, 1023);
    if (pdo())
    {
      digitalWrite(table_plug_1, HIGH);
      delay(1000);
    }
    if (pdo() == 0)
    {
      digitalWrite(table_plug_1, LOW);
      //      delay(1000);
    }


  }
}











