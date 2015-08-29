void door_check_secure()
{
  if (pdo())
  {
    Serial.println("Passage Door Open");
    master.print("*E1");
    buzz(1);
  }

  if (pdl() == 0)
  {
    Serial.println("Passage Door Lock Opened");
    master.print("*E2");
    buzz(3);
  }
  if (ldo())
  {
    Serial.println("Living Room Door Open");
    master.print("*E3");
    buzz(2);
  }
  if (ldl() == 0 )
  {
    Serial.println("Living Room Door Lock Opened");
    master.print("*E4");
    buzz(4);
  }
  if (gdo())
  {
    Serial.println("Gallery Door Open");
    master.print("*E5");
    buzz(5);
  }

}


void buzz (int type)
{
  switch(type)
  {
  case 1:
    for (int i=0;i<6;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(75);
      digitalWrite(buzzer,LOW);
      delay(100);
    }
    break;

  case 2:
    for (int i=0;i<5;i++)
    {
      tone(buzzer,6000);
      delay(50);
      noTone(buzzer);
      delay(50);
      tone(buzzer,2000);
      delay(50);
      noTone(buzzer);
      delay(50);
    }
    break;
  case 3:


    tone (buzzer,600);
    delay(500);
    noTone(buzzer);
    delay(500);

    tone (buzzer,600);
    delay(500);
    noTone(buzzer);
    delay(500);

    tone (buzzer,600);
    delay(500);
    noTone(buzzer);
    delay(500);




    break;
  case 4:

    for (int i=0;i<3;i++)
    {
      tone(buzzer,4000);
      delay(100);
      noTone(buzzer);
      delay(250);
      tone(buzzer,1500);
      delay(500);
      noTone(buzzer);
      delay(100);
    }
    break;
  case 5:
    for (int i=0;i<15;i++)
    {
      tone(buzzer,4000);
      delay(1);
      noTone(buzzer);
      delay(2);
      tone(buzzer,1500);
      delay(5);
      noTone(buzzer);
      delay(1);
      tone(buzzer,500);
      delay(50);
      noTone(buzzer);
      delay(1);
    }

    break;
  case 6:
    tone(buzzer,8000);
    delay(100);
    noTone(buzzer);
    break;
  case 7:

    break;
  case 8:

    break;
  case 9:

    break;
  case 10:

    break;

  }

}


void get_info()
{
  if (master.available())
  {
    int k=0;
    for (int i=0;i<100;i++)
    {
      while (master.available())
      {
        commands[k] = master.read();
        k++;
      }
    }    
    print_info();

    Serial.flush();

    //    Serial.println();

  }
}





void mosquito_repel()
{

  if (millis() > (y+15000) || y==0)
  {
    y=millis();    
  }  

  if ( (millis()<( y+5000)) && commands[3] == 49)
  {
    digitalWrite(table_plug_2,HIGH); 

  }  

  if (millis() > (y+5000) && (millis() < (y + 15000)) )
  {
    digitalWrite(table_plug_2,LOW); 
  }  

}


void mosquito_repel_2(int s)
{
  switch(s)
  {
  case 1:
    digitalWrite(table_plug_2,HIGH);
    break;
  case 0:
    digitalWrite(table_plug_2,LOW);
    break;

  }

}


