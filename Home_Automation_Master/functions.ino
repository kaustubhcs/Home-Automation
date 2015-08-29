void button_stats()
{
  digitalWrite(buttons_activator,HIGH);

  if ( analogRead(button_1) > 600 )
  {
//    Serial.println("Button 1 ON");
    slave.print("1");
  } 
  else
  {
//    Serial.println("Button 1 OFF");
    slave.print("0");
  }
  if ( analogRead(button_2) > 600 )
  {
//    Serial.println("Button 2 ON");
    slave.print("1");
  } 
  else
  {
//    Serial.println("Button 2 OFF");
    slave.print("0");
  }
  if ( analogRead(button_3) > 600 )
  {
 //   Serial.println("Button 3 ON");
    slave.print("1");
  } 
  else
  {
  //  Serial.println("Button 3 OFF");
    slave.print("0");
  }
  if ( analogRead(button_4) > 600 )
  {
//    Serial.println("Button 4 ON");
    slave.print("1");
  } 
  else
  {
//    Serial.println("Button 4 OFF");
    slave.print("0");
  }

  digitalWrite(buttons_activator,LOW);


}



