/*
 Read pulse length from Spektrum 2.4 Ghz Reciever AUX Channel for accessory control
*/
  
int greenPin = 6;
int yellowPin = 7;
int redPin = 8;
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
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);

  }
  
  if (1400 < duration && duration < 1800){
  Serial.println("Setting B");
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, LOW);

  }  
  
  if (duration > 1800){
  Serial.println("Setting C");
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);

  } 
  
}
