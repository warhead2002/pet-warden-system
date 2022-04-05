int motor1 = 2; //motor pin 1
int motor2 = 3; //motor pin 2
int sensorpwr = 7;  //sensor +ve pin
int sensorsig = A0; //sensor data pin
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(sensorpwr, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);                      // wait 10 seconds
  digitalWrite(sensorpwr, HIGH);  // turn the sensor ON
  value = analogRead(sensorsig); // read the analog value from sensor
  delay(1000);
  digitalWrite(sensorpwr, LOW);   // turn the sensor OFF
 
  Serial.print("Sensor value: ");
  Serial.println(value);
  motor(value);
}
void motor(int flag)
{
  if(value<200){
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    delay(2000);
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    delay(2000);
  }
  else if(value>0){
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);

  }
}
