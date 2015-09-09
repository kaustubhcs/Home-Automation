
void day_mode()
{
  door_check_secure2();
  digitalWrite(night_lamp, LOW);
  digitalWrite(cfl, LOW);
  digitalWrite(tubes, LOW);

  if ( motion() )
  {
    //    digitalWrite(master_plug, HIGH);
    fan_on(1);
    mosquito_repel();
  }
  else
  {
    //    digitalWrite(master_plug, LOW);
    fan_on(0);
    digitalWrite(table_plug_2, LOW);
  }

}

void eve_mode()
{
  door_check_secure2();
  digitalWrite(night_lamp, LOW);


  if ( motion() )
  {
    digitalWrite(cfl, HIGH);
    digitalWrite(tubes, HIGH);
    //    digitalWrite(master_plug, HIGH);
    fan_on(1);
    mosquito_repel();

  }
  else
  {
    digitalWrite(cfl, LOW);
    digitalWrite(tubes, LOW);
    //    digitalWrite(master_plug, LOW);
    fan_on(0);
    digitalWrite(table_plug_2, LOW);

  }

}

void night_mode()
{
  door_check_secure3();
  digitalWrite(cfl, LOW);
  digitalWrite(tubes, LOW);

  fan_on(1);


  if ( motion() )
  {
    digitalWrite(night_lamp, HIGH);
    digitalWrite(master_plug, HIGH);

  }
  else
  {
    digitalWrite(night_lamp, LOW);
    //    digitalWrite(master_plug, LOW);
  }


  mosquito_repel();


}


void secured_mode()
{
  digitalWrite(cfl, LOW);
  digitalWrite(tubes, LOW);

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

  if (motion())
  {
    mosquito_repel();
    digitalWrite(night_lamp, HIGH);
    digitalWrite(master_plug, HIGH);

  }
  else
  {
    digitalWrite(table_plug_2, LOW);
    digitalWrite(night_lamp, LOW);
    //    digitalWrite(master_plug, LOW);

  }
}

// For rapid changes in relays

void demo_mode()
{
  day_mode();
}

void mode_declare ()
{

  if ((commands[0] == 49) && (commands[1] == 48) && (commands[2] == 48) )
  {
    gmode = 1; // Day Mode
  }

  if ((commands[0] == 48) && (commands[1] == 49) && (commands[2] == 48) )
  {
    gmode = 2; // Night Mode
  }
  if ( (commands[1] == 48) && (commands[2] == 49) )
  {

    if ( (commands[0] == 49)  )
    {
      fmode = 1; // Day Mode
    }
    if ( (commands[0] == 48)  )
    {
      fmode = 0; // Day Mode
    }


    gmode = 3; // Secured Mode
  }
  if ((commands[0] == 49) && (commands[1] == 49) && (commands[2] == 48) )
  {
    gmode = 4; // Evening Mode
  }
  if ((commands[0] == 49) && (commands[1] == 49) && (commands[2] == 49) && (commands[3] == 49) )
  {
    gmode = 5; // Demo Mode
  }

}

// Global Mode Declare

void mode()
{
  mode_declare();
  switch (gmode)
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





// Fan controller for Arduino Microcontroller

void fan_on(int state)
{
  switch (state)
  {
    case 1:
      if (millis() > (x + 15000) || x == 0)
      {
        x = millis();
      }

      //    if ( millis()<( x+5000))
      //    {
      digitalWrite(fan, HIGH);

      //    }

      if (millis() > (x + 5000) && (millis() < x + 8000) )
      {
        //      digitalWrite(fan,LOW);
      }
      break;

    case 0:
      digitalWrite(fan, LOW);
      break;
  }
}





