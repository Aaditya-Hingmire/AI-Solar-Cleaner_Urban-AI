#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal_I2C.h>

HardwareSerial PMSerial(2);

Adafruit_INA219 ina219;
LiquidCrystal_I2C lcd(0x27,16,2);

#define IN1 18
#define IN2 19

#define PUMP_PIN 23
#define VALVE_PIN 5
#define RELAY_PIN 4

#define LIMIT_LEFT 25
#define LIMIT_RIGHT 26

#define STATUS_LED 2

#define PM_RX 16
#define PM_TX 17

int pm25Value = 0;
int dustThreshold = 150;

void setup()
{
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(PUMP_PIN, OUTPUT);
  pinMode(VALVE_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  pinMode(LIMIT_LEFT, INPUT_PULLUP);
  pinMode(LIMIT_RIGHT, INPUT_PULLUP);

  pinMode(STATUS_LED, OUTPUT);

  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(VALVE_PIN, LOW);
  digitalWrite(RELAY_PIN, LOW);

  Wire.begin(SDA_PIN,SCL_PIN);

  ina219.begin();

  lcd.init();
  lcd.backlight();

  PMSerial.begin(9600,SERIAL_8N1,PM_RX,PM_TX);

  lcd.clear();
  lcd.print("Solar Cleaner");
  delay(2000);
}

void loop()
{
  readPM25();

  float voltage = ina219.getBusVoltage_V();
  float current = ina219.getCurrent_mA();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PM:");
  lcd.print(pm25Value);

  lcd.setCursor(0,1);
  lcd.print(voltage,1);
  lcd.print("V");

  Serial.print("PM2.5 = ");
  Serial.println(pm25Value);

  Serial.print("Voltage = ");
  Serial.println(voltage);

  Serial.print("Current = ");
  Serial.println(current);

  if(pm25Value > dustThreshold)
  {
    startCleaning();
  }

  delay(3000);
}

void readPM25()
{
  if(PMSerial.available() >= 32)
  {
    uint8_t buffer[32];

    for(int i=0;i<32;i++)
    {
      buffer[i] = PMSerial.read();
    }

    if(buffer[0]==0x42 && buffer[1]==0x4D)
    {
      pm25Value = (buffer[12]<<8) | buffer[13];
    }
  }
}

void startCleaning()
{
  lcd.clear();
  lcd.print("Cleaning...");

  digitalWrite(STATUS_LED,HIGH);

  digitalWrite(PUMP_PIN,HIGH);
  digitalWrite(VALVE_PIN,HIGH);

  delay(2000);

  moveRight();

  while(digitalRead(LIMIT_RIGHT)==HIGH)
  {
    delay(5);
  }

  stopMotor();

  delay(1000);

  moveLeft();

  while(digitalRead(LIMIT_LEFT)==HIGH)
  {
    delay(5);
  }

  stopMotor();

  digitalWrite(PUMP_PIN,LOW);
  digitalWrite(VALVE_PIN,LOW);

  digitalWrite(STATUS_LED,LOW);

  lcd.clear();
  lcd.print("Done");

  delay(3000);
}

void moveRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void moveLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void stopMotor()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}