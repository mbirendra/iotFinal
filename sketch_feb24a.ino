#define BLYNK_PRINT Serial//blynk library
#include <ESP8266WiFi.h>//nodemcu
#include <BlynkSimpleEsp8266.h>

int buzzer = D8;
int LED = D7;
int flame_sensor = D1;
int flame_detected;

const char auth[] = "WiRTHM1O2tVJgHlHH76N0EtQ4R5EPRi3";//gmail token
const char ssid[]= "ONEPLUS";
const char pass[]="hello123";
BlynkTimer timer;
void setup()
{
  Serial.begin(115200);//serial monitor baud rate
  Blynk.begin(auth,ssid,pass);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
  timer.setInterval(1000L,detectFlame);
}


void detectFlame()
{
    Serial.println("Hello World");
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 0)
  {
    Blynk.notify("Flame detected...! take action immediately.");
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
  else
  {
    Serial.println("No flame detected. stay cool");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
  delay(1000);
}

void loop()
{
  Blynk.run();
  timer.run();
}
