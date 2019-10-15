void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  myBlink(25);
}
