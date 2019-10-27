
void esc_setup()
{
     escF.attach(10);
     escB.attach(10);

     escF.write(2000);
     escB.write(2000);
     delay(1600);
     escF.write(1000);
     escB.write(1000);
     delay(1600);

}

/*void dribbler(string pos, int speed)
{

} */
