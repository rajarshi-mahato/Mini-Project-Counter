#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


int count = 0;
char ssid[] = "";
char pass[] = "";

// Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// PCA9685 setup
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // Default I2C address 0x40

// Servo min/max pulse (adjust if needed)
#define SERVO_MIN  102  // Minimum pulse length out of 4096 (0°)
#define SERVO_MAX  512  // Maximum pulse length out of 4096 (180°)

void setServoAngle(uint8_t channel, uint8_t angle)
{
  if (angle > 180) angle = 180;
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(channel, 0, pulse);
}

// 0 - upper
// 2 - middle
// 4 - lower
// 6 - upper right
// 8 - lower right
// 10- upper left
// 12- lower left

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  Wire.begin(); // Initialize I2C
  pwm.begin();  // Initialize PCA9685
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz
  delay(10);
}

// Convert angle (0–180) to pulse (min–max)
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}


BLYNK_WRITE(V0) 
{
  int zero = param.asInt(); // Read incoming value
  if (zero == 1) 
    Zero();  
}

BLYNK_WRITE(V1) 
{
  int one = param.asInt(); // Read incoming value
  if (one == 1) 
    One();
   
}

BLYNK_WRITE(V2) 
{
  int two = param.asInt(); // Read incoming value
  if (two == 1) 
    Two();
   
}

BLYNK_WRITE(V3) 
{
  int three = param.asInt(); // Read incoming value
  if (three == 1) 
    Three();
   
}
BLYNK_WRITE(V4) 
{
  int four = param.asInt(); // Read incoming value
  if (four == 1) 
    Four();
   
}

BLYNK_WRITE(V5) 
{
  int five = param.asInt(); // Read incoming value
  if (five == 1) 
    Five();
   
}

BLYNK_WRITE(V6) 
{
  int six = param.asInt(); // Read incoming value
  if (six == 1) 
    Six();
   
}

BLYNK_WRITE(V7) 
{
  int seven = param.asInt(); // Read incoming value
  if (seven == 1) 
    Seven();
   
}

BLYNK_WRITE(V8) 
{
  int eight = param.asInt(); // Read incoming value
  if (eight == 1) 
    Eight();
   
}

BLYNK_WRITE(V9) 
{
  int nine = param.asInt(); // Read incoming value
  if (nine == 1)
   Nine();
   
   
}


BLYNK_WRITE(V10) 
{
  count = 0;
  int all = param.asInt(); // Read incoming value
  while (all == 1 && count == 0) 
  {
   All();
   count++;
  }
}

BLYNK_WRITE(V11) 
{
  count = 0;
  int all = param.asInt(); // Read incoming value
  while (all == 1 && count == 0) 
  {
   Even();
   count++;
  }
}

BLYNK_WRITE(V12) 
{
  count = 0;
  int all = param.asInt(); // Read incoming value
  while (all == 1 && count == 0) 
  {
   Odd();
   count++;
  }
}

BLYNK_WRITE(V13) 
{
  count = 0;
  int all = param.asInt(); // Read incoming value
  while (all == 1 && count == 0) 
  {
   Reverse();
   count++;
  }
}
  

void All()
{
  Zero();
  delay(1000);
  One();
  delay(1000);
  Two();
  delay(1000);
  Three();
  delay(1000);
  Four();
  delay(1000);
  Five();
  delay(1000);
  Six();
  delay(1000);
  Seven();
  delay(1000);
  Eight();
  delay(1000);
  Nine();
  delay(1000);
}

void Odd()
{
  One();
  delay(1000);
  Three();
  delay(1000);
  Five();
  delay(1000);
  Seven();
  delay(1000);
  Nine();
  delay(1000);
}

void Even()
{
  Zero();
  delay(1000); 
  Two();
  delay(1000);
  Four();
  delay(1000); 
  Six();
  delay(1000); 
  Eight();
  delay(1000);

}

void Reverse()
{
  Nine();
  delay(1000);
  Eight();
  delay(1000);
  Seven();
  delay(1000);
  Six();
  delay(1000);
  Five();
  delay(1000);
  Four();
  delay(1000);
  Three();
  delay(1000);
  Two();
  delay(1000);
  One();
  delay(1000);
  Zero();
  delay(1000);
}

void Nine()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,90);
}

void Eight()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,0);
}

void Seven()
{
  setServoAngle(0,0);
  setServoAngle(2,90);
  setServoAngle(4,90);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,90);
}

void Six()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,90);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,0);
}

void Five()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,90);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,90);
}

void Four()
{
  setServoAngle(0,90);
  setServoAngle(2,0);
  setServoAngle(4,90);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,90);
}

void Three()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,90);
  setServoAngle(12,90);
}

void Two()
{
  setServoAngle(0,0);
  setServoAngle(2,0);
  setServoAngle(4,0);
  setServoAngle(6,0);
  setServoAngle(8,90);
  setServoAngle(10,90);
  setServoAngle(12,0);
}

void One()
{
  setServoAngle(0,90);
  setServoAngle(2,90);
  setServoAngle(4,90);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,90);
  setServoAngle(12,90);
}

void Zero()
{
  setServoAngle(0,0);
  setServoAngle(2,90);
  setServoAngle(4,0);
  setServoAngle(6,0);
  setServoAngle(8,0);
  setServoAngle(10,0);
  setServoAngle(12,0);
}



void loop() 
{
  Blynk.run();  
}
