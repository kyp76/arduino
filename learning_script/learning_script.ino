/*
Learning script to understand how works arduino. 
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // define the Pin branch==> the PIN number where you want to do something. 
  // LED_BUILTIN is the led on the Arduino and/or the PIN 13. you coul change it with the PIN NUMBER. 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2,INPUT); 
}

void blink_led() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
}


void read_push_button() {
  
  int buttonState = digitalRead(2);
  // print out the state of the button:
  // find the way to have more visible information on Serial Monitor
  Serial.println((String)"Valor Sensor D2: "+ buttonState);
  delay(1);
  
}
void read_potentio() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  delay(1000);
  Serial.println((String)"Valor Sensor A0: "+ sensorValue);
}
// the loop routine runs over and over again forever:
void loop() {
  blink_led();
  //read_potentio();
  //read_push_button();
}
