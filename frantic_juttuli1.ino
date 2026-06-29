const int soilPin = A0;
const int ledPin = 13;
const int buzzerPin = 13;  
const int dryValue = 800;   
const int wetValue = 350;  
const int moistureThreshold = 20;  
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}
void loop() {
  int sensorValue = analogRead(soilPin);
  int moisture = map(sensorValue, dryValue, wetValue, 0, 100);
  moisture = constrain(moisture, 0, 100);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("  Moisture: ");
  Serial.print(moisture);
  Serial.println("%");
  if (moisture < moistureThreshold) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);   
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  delay(1000);
}