void disp()
{
  /*

   0000000000111111
   ....0123456789012345
   0         DAY                   
   1         MODE   ACK                                     
   
   
   
   0000000000111111
   ....0123456789012345
   0         NIGHT                  
   1         MODE   ACK                                     
   
   
   0000000000111111
   ....0123456789012345
   0        SECURED                   
   1         MODE   ACK        
   
   0000000000111111
   ....0123456789012345
   0   HOME  AUTOMATION               
   1   A KTB INITIATIVE        
   
   
   0000000000111111
   ....0123456789012345
   0        EVENING                   
   1         MODE   ACK        
   
   
   0000000000111111
   ....0123456789012345
   0         DEMO                     
   1   FAN   MODE   ACK        
   */

  digitalWrite(buttons_activator,HIGH);
  if (printed != 4 || printed != 5)
  {
    ack();
  }
  if (analogRead(button_1)>600 && analogRead(button_2)<600 && analogRead(button_3)<600 && printed != 1)
  {
    print2=0;
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("DAY");
    lcd.setCursor(6,1);
    lcd.print("MODE");
    ack();
    printed=1;
  } 

  if (analogRead(button_1)<600 && analogRead(button_2)>600 && analogRead(button_3)<600 && printed != 2)
  {
    print2=0;
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("NIGHT");
    lcd.setCursor(6,1);
    lcd.print("MODE");
    ack();
    printed=2;
  } 

/*
  if (analogRead(button_2)<600 && analogRead(button_3)>600 )
  {
    print2=0;

    if (analogRead(button_1)>600 )
    {
      fmode=1;
    } 
    else
    {
      fmode=0;     
    }
    if (printed != 3)
    {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("SECURED");
    lcd.setCursor(6,1);
    lcd.print("MODE");
    fan_disp();
    ack();
    }
    fan_disp();
    ack();
    printed=3;
  } 
*/



  if (analogRead(button_1)>600 && analogRead(button_2)<600 && analogRead(button_3)>600 && printed != 7)
  {
    print2=0;
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("SECURED");
    lcd.setCursor(0,1);
    lcd.print("FAN   MODE");
    ack();
    printed=7;
  } 

  if (analogRead(button_1)<600 && analogRead(button_2)<600 && analogRead(button_3)>600 && printed != 8)
  {
    print2=0;
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("SECURED");
    lcd.setCursor(0,1);
    lcd.print("      MODE");
    ack();
    printed=8;
  } 
























  if (analogRead(button_1)>600 && analogRead(button_2)>600 && analogRead(button_3)<600 && printed != 4)
  {
    print2=0;
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("EVENING");
    lcd.setCursor(6,1);
    lcd.print("MODE");
    ack();
    printed=4;
  } 
  if (analogRead(button_1)>600 && analogRead(button_2)>600 && analogRead(button_3)>600 && analogRead(button_4)>600 && printed != 5)
  {
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("DEMO");
    lcd.setCursor(6,1);
    lcd.print("MODE");
    printed=5;
   
  } 











  if (analogRead(button_1)<600 && analogRead(button_2)<600 && analogRead(button_3)<600 && printed != 6 )
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HOME AUTOMATION");
    lcd.setCursor(0,1);
    lcd.print("A KTB INITIATIVE");
    printed=6;
  } 


  digitalWrite(buttons_activator,LOW);

}


void ack ()
{

  if (analogRead(button_4)>600 )

  {
    if (print2 != 1)
    {
      lcd.setCursor(13,1);
      lcd.print("RPL");

      print2=1;
    }
  } 
  else
  {

    if (print2 != 2)
    {
      lcd.setCursor(13,1);
      lcd.print("   ");   

      print2=2;
    }
  }

}


void fan_disp ()
{
  if (fmode && print3 != 1)
  {
    lcd.setCursor(0,1);
    lcd.print("FAN");
    print3=1;    

  }
  if (fmode == 0 && print3 != 2)
  {
    lcd.setCursor(0,1);
    lcd.print("   ");   
    print3=2;    

  }

}



