//declarations
const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() 
{
  //setup serial communications
  Serial.begin(9600);
  
  pinMode(greenLEDPin, OUTPUT); //
  pinMode(redLEDPin, OUTPUT); //// setup pins in declaration order
  pinMode(blueLEDPin, OUTPUT); ///
}

void loop() 
{
  //read photoresistor values to analog pins. 5ms delay
  redSensorValue = analogRead(redSensorPin);
  delay(3);
  greenSensorValue = analogRead(greenSensorPin);
  delay(3);
  blueSensorValue = analogRead(blueSensorPin);

  //print the raw sensor values. AKA raw values
  Serial.print("Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\n Sensor Values \t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\n Sensor Values \t Blue: ");
  Serial.print(blueSensorValue);

  //set values in 0-255 range. AKA processed values
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  //display processed values on serial
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);

  //write the light intensity to the incoming light after it has been processed
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
