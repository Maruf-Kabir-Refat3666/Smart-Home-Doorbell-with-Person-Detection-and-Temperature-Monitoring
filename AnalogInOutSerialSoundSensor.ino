

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


const float WEIGHT = 0.15;
const float THRESHOLD =200;
const float DEBOUNCE = 1000;

int sensorValue = 0;  // value read from the pot
float average = 0;  
long time = 0;
     
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  //moving average:
  average += WEIGHT*(sensorValue - average);
  

  // print the results to the Serial Monitor:
  
  Serial.print(average);
  Serial.print(",");
  Serial.println(sensorValue);

  if (average>THRESHOLD && millis()>time+DEBOUNCE) {
    Serial.println("CLAP!!!!!");
    time = millis();
  }

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(100);
}
