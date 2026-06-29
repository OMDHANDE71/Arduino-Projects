const int tempPin = A0;      
const int fanPwmPin = 9;    
float tempC = 0.0;
int pwmValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(fanPwmPin, OUTPUT);
  analogWrite(fanPwmPin, 0);
}
void loop() {
  int analogVal = analogRead(tempPin);        
  float voltage = analogVal * (5.0 / 1023.0); 
  tempC = voltage * 100.0;                    
  float constrainedTemp = constrain(tempC, 27.0, 40.0);
  pwmValue = (int)((constrainedTemp - 27.0) * (255.0 / (40.0 - 27.0)));

  if (tempC < 27.0) {
    pwmValue = 0;
  }

  analogWrite(fanPwmPin, pwmValue);

  Serial.print("Temp: ");
  Serial.print(tempC, 1);   
  Serial.print("C, PWM: ");
  Serial.println(pwmValue);

  delay(500);
}