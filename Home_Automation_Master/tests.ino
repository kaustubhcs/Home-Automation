void buttons_test()
{

  /*
     0000000000111111
   0123456789012345
   0       BUTTONS                 
   1   OFF OFF  OFF OFF                                  
   
   */
  digitalWrite(buttons_activator,HIGH);

  if (initialiser)
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("BUTTONS");
    initialiser=0;
  }
  if (analogRead(button_1)>600)
  {
    lcd.setCursor(0,1);
    lcd.print("ON "); 
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("OFF"); 
  }

  if (analogRead(button_2)>600)
  {
    lcd.setCursor(4,1);
    lcd.print("ON "); 
  }
  else
  {
    lcd.setCursor(4,1);
    lcd.print("OFF"); 
  }
  if (analogRead(button_3)>600)
  {
    lcd.setCursor(9,1);
    lcd.print("ON "); 
  }
  else
  {
    lcd.setCursor(9,1);
    lcd.print("OFF"); 
  }
  if (analogRead(button_4)>600)
  {
    lcd.setCursor(13,1);
    lcd.print("ON "); 
  }
  else
  {
    lcd.setCursor(13,1);
    lcd.print("OFF"); 
  }

  Serial.print("Button 1: ");
  Serial.println(analogRead(button_1));
  Serial.print("Button 2: ");
  Serial.println(analogRead(button_2));
  Serial.print("Button 3: ");
  Serial.println(analogRead(button_3));
  Serial.print("Button 4: ");
  Serial.println(analogRead(button_4));
  Serial.println("\n\n");
  digitalWrite(buttons_activator,LOW);
  delay(500);

}

void comm_test()
{
  /*
       0000000000111111
   ....0123456789012345
   0      COMM CHECK                 
   1   RX-0000  TX-0000                                  
   */

  if (initialiser)
  {

    Serial.println("C1");  //              ****CHECKPOINT****


    lcd.setCursor(3,0);
    lcd.print("COMM CHECK");
    lcd.setCursor(0,1);
    lcd.print("RX-      TX-");
    initialiser=0;
  }

  if (slave.available()>0)
  {


    Serial.println("C2");  //              ****CHECKPOINT****

    //    char a = mySerial.read();
    //    Serial.print(a);
    lcd.setCursor(3,1);
    lcd.print(slave.read());
    //    lcd.print(a);

  } 
  if (Serial.available()>0)
  {


    Serial.println("C3");  //              ****CHECKPOINT****



    lcd.setCursor(12,1);
    lcd.print(Serial.read());
  }

  slave_print();


}




void slave_print()
{


  Serial.println("C3");  //              ****CHECKPOINT****


  slave.print(millis()/1000);
  lcd.setCursor(12,1);
  lcd.print(millis()/1000);
  delay(1000);
}



