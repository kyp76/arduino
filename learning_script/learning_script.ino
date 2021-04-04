/*
Learning script to understand how works arduino. 
*/
// Memora_Arduino 
// digitalRead ==> will read the value of the ouput 0 or 1 
// analogRead ==> will read the real value of the output
int led = 9;
int brightness = 0; 
int steps = 5;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // define the Pin branch==> the PIN number where you want to do something. 
  // LED_BUILTIN is the led on the Arduino and/or the PIN 13. you coul change it with the PIN NUMBER. 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led,INPUT); 
}

void blink_led() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(10); 
}

void increase_decrease() {
    analogWrite(led, brightness);
    brightness = brightness + steps;
      if (brightness <= 0 || brightness >= 255) {
    steps = -steps;
  }
  delay(30);
  int sensorValue = analogRead(led);
  Serial.println((String)"Valor Sensor D"+led+ ": "+ sensorValue);
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
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println((String)"Voltage Sensor A0: "+ voltage);
  
}
// the loop routine runs over and over again forever:
void loop() {
  
  read_potentio();
  //read_push_button();
  //blink_led();
  //increase_decrease();
}
