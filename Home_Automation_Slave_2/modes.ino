
void day_mode()
{
  digitalWrite(night_lamp,LOW);
  delay(100);
  digitalWrite(cfl,LOW);
  delay(100);
  digitalWrite(tubes,LOW);

  if ( md > 0)
  {
    
    digitalWrite(master_plug,HIGH);
    delay(100);
    fan_on(1);
    delay(100);
    mosquito_repel();
  }
  else
  {
    md=0;
    digitalWrite(master_plug,LOW);
    delay(100);
    fan_on(0);
    delay(100);
    digitalWrite(table_plug_2,LOW); 
  }

}

void eve_mode()
{
  delay(100);
  digitalWrite(night_lamp,LOW);

  if ( me>100 )
  {
    digitalWrite(cfl,HIGH);
    delay(100);
    digitalWrite(tubes,HIGH);
    delay(100);
    digitalWrite(master_plug,HIGH);
    delay(100);
    fan_on(1);
    delay(100);
    mosquito_repel();

  }
  else
  {
    delay(100);
    digitalWrite(cfl,LOW);
    delay(100);
    digitalWrite(tubes,LOW);
    delay(100);
    digitalWrite(master_plug,LOW);
    delay(100);
    fan_on(0);
    delay(100);
    digitalWrite(table_plug_2,LOW); 

  }

}

void night_mode()
{
  delay(100);
  digitalWrite(cfl,LOW);
  delay(100);
  digitalWrite(tubes,LOW);
  delay(100);
  if(pdl())
  {
    buzz(3); 
  }
  fan_on(1);


  if ( mn>100 )
  {
    digitalWrite(night_lamp,HIGH);
    delay(100);
    digitalWrite(master_plug,HIGH);
    delay(100);

  }
  else
  {
    digitalWrite(night_lamp,LOW);
    delay(100);
    digitalWrite(master_plug,LOW);
    delay(100);
  }


  delay(100);
  mosquito_repel();


}


void secured_mode()
{
  digitalWrite(cfl,LOW);
  delay(100);
  digitalWrite(tubes,LOW);

  door_check_secure();

  if (fmode)
  {
    fan_on(1);
  }
  else
  {
    fan_on(0);
  }
  delay(500);

  if ( ms >100 )
  {
    mosquito_repel();
    delay(100);
    digitalWrite(night_lamp,HIGH);
    delay(100);
    digitalWrite(master_plug,HIGH);

  }
  else
  {
    delay(100);
    digitalWrite(table_plug_2,LOW); 
    delay(100);
    digitalWrite(night_lamp,LOW);
    delay(100);
    digitalWrite(master_plug,LOW);
    delay(100);

  }
}


void demo_mode()
{
  day_mode();
}

void mode_declare ()
{

  if ((commands[0] == 49) && (commands[1] == 48) && (commands[2] == 48) )
  {
    gmode=1; // Day Mode
  }

  if ((commands[0] == 48) && (commands[1] == 49) && (commands[2] == 48) )
  {
    gmode=2; // Night Mode
  }
  if ( (commands[1] == 48) && (commands[2] == 49) )
  {

    if ( (commands[0] == 49)  )
    {
      fmode=1; // Day Mode
    }
    if ( (commands[0] == 48)  )
    {
      fmode=0; // Day Mode
    }


    gmode=3; // Secured Mode
  }
  if ((commands[0] == 49) && (commands[1] == 49) && (commands[2] == 48) )
  {
    gmode=4; // Evening Mode
  }
  if ((commands[0] == 49) && (commands[1] == 49) && (commands[2] == 49) && (commands[3] == 49) )
  {
    gmode=5; // Demo Mode
  }

}

void mode()
{
  mode_declare();
  switch(gmode)
  {
  case 0:
    if (  millis() > (str + 5000) )
    {
      buzz(6);
      str = millis();
    }
    break;

  case 1:
    day_mode();
    break;
  case 2:
    night_mode();
    break;
  case 3:
    secured_mode();
    break;
  case 4:
    eve_mode();
    break;
  case 5:
    demo_mode();
    break;

  } 
}







void fan_on(int state)
{
  switch (state)
  {
  case 1:
    if (millis() > (x+15000) || x==0)
    {
      x=millis();    
    }  

    //    if ( millis()<( x+5000))
    //    {
    digitalWrite(fan,HIGH); 

    //    }  

    if (millis() > (x+5000) && (millis() < x + 8000) )
    {
      //      digitalWrite(fan,LOW); 
    }  
    break;

  case 0:
    digitalWrite(fan,LOW); 
    break;
  }
}






