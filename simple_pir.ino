const int MOTION_PIN = 3; // Pin connected to motion detector
const int LED_PIN = 7; // LED pin - active-high

void setup() 
{
  Serial.begin(9600);
  // The PIR sensor's output signal is an open-collector, 
  // so a pull-up resistor is required:
  pinMode(MOTION_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  int proximity = digitalRead(MOTION_PIN);
  if (proximity == HIGH) // If the sensor's output goes low, motion is detected
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  }
  else
  {
    Serial.println("No Motion");
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
