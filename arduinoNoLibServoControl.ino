const int servo_pin = 9;
const long delayTime = 5;

int my_angle = 0;
int pulseWidth = 0;

void servoPulse(int servopin, int myangle){
  pulseWidth = (myangle *10.55f)+500; //servo 0 dan 180 e 
  digitalWrite(servopin,HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servopin,LOW);
  delay(delayTime);
}

void setup() {
  Serial.begin(9600);
  Serial.print("START");

  pinMode(servo_pin, OUTPUT);
}

void loop() {

  for (my_angle = 0; my_angle <= 180; my_angle+= 6) {
    servoPulse(servo_pin, my_angle);
  }
  delay(500);

  for (my_angle = 180; my_angle >= 90; my_angle-= 6) {
    servoPulse(servo_pin, my_angle);
  }
  delay(500);

  for (my_angle = 90; my_angle >= 0; my_angle-= 6) {
    servoPulse(servo_pin, my_angle);
  }
  delay(500);

}