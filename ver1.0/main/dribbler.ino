#define KICKER_R 26
#define KICKER_L 27

void esc_setup(){
     escF.attach(28);
     escB.attach(29);

     escF.write(2000);
     escB.write(2000);
     delay(1300);
     escF.write(1000);
     escB.write(1000);
     delay(1300);
     Serial.println("esc setup succeded!!");

}

void kicker_setup(){
     pinMode(KICKER_R,OUTPUT);
     pinMode(KICKER_L,OUTPUT);
}

void kick(){
     if(isBLUE_GOAl){
          if(fBlueDir < 10 && fBlueDir > -10){
               digitalWrite(KICKER_R,HIGH);
               digitalWrite(KICKER_L,HIGH);
               delay(100);
               digitalWrite(KICKER_R,LOW);
               digitalWrite(KICKER_L,LOW);
               delay(500);
          }else if(fBlueDir < -10){
               digitalWrite(KICKER_R,HIGH);
               delay(100);
               digitalWrite(KICKER_R,LOW);
               delay(500);
          }else if(fBlueDir > 10){
               digitalWrite(KICKER_L,HIGH);
               delay(100);
               digitalWrite(KICKER_L,LOW);
               delay(500);
          }
     }else if(isYELLOW_GOAL){
          if(fYellowDir < 10 && fYellowDir > -10){
               digitalWrite(KICKER_R,HIGH);
               digitalWrite(KICKER_L,HIGH);
               delay(100);
               digitalWrite(KICKER_R,LOW);
               digitalWrite(KICKER_L,LOW);
               delay(500);
          }else if(fYellowDir < -10){
               digitalWrite(KICKER_R,HIGH);
               delay(100);
               digitalWrite(KICKER_R,LOW);
               delay(500);
          }else if(fYellowDir > 10){
               digitalWrite(KICKER_L,HIGH);
               delay(100);
               digitalWrite(KICKER_L,LOW);
               delay(500);
          }
     }
     
}

void japan(){
     if(isBLUE_GOAl){
          if(fBlueDir < 0){
               right_round();
          }else if(fBlueDir > 0){
               right_round();
          }
     }else if(isYELLOW_GOAL){
          if(fYellowDir < 0){
               //migikaitenn
          }else if(fYellowDir > 0){
               //hidarikaitenn
          }
     }
}