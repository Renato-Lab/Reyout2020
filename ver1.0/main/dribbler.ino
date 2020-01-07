
void esc_setup()
{
     escF.attach(28);
     escB.attach(29);

     escF.write(2000);
     escB.write(2000);
     delay(1500);
     escF.write(1000);
     escB.write(1000);
     delay(1500);
     Serial.println("esc setup succeded!!");

}
