/*
 Read pulse length from Spektrum 2.4 Ghz Reciever AUX Channel for accessory control
 3 LEDs are hooked up as outputs to give a visual indication of the position of the AUX
 signal as read from the Rx.

Eventually, I will build a cool RC Truck Accessory such as a winch, lights, camera gimbal, etc.

Also note that this can easily be powered by the 5v in from the reciever if the accessory does not
draw alot of current, but I assume it may start to malfunction when the voltage drops.
*/
  
int greenPin = 6;
int yellowLight = 7;
int redLight = 8;
int receiverPin = 9;

unsigned long duration;

void setup()
{
  pinMode(receiverPin, INPUT);
  for (int x = 6; x <9; x++){
  pinMode(x, OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  
  duration = pulseIn(receiverPin, HIGH);
  Serial.println(duration);
  
  if (duration < 1200){
  Serial.println("Setting A");
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, LOW);

  }
  
  if (1400 < duration && duration < 1800){
  Serial.println("Setting B");
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowLight, HIGH);
  digitalWrite(redLight, LOW);

  }  
  
  if (duration > 1800){
  Serial.println("Setting C");
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, HIGH);

  } 
  
}
