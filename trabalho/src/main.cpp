#include <Arduino.h>

constexpr int red_led_pin = 2;
constexpr int yellow_led_pin = 3;
constexpr int green_led_pin = 4;

constexpr int red_led_interval = 3000;
constexpr int yellow_led_interval = 1000;
constexpr int green_led_interval = 3000;

void configureLeds();
void turnLedOn(int ledPin);
void turnLedOff(int ledPin);
void doLedInterval();

void setup()
{
    configureLeds();
}

void loop()
{
    doLedInterval(green_led_pin, green_led_interval);
    doLedInterval(yellow_led_pin, yellow_led_interval);
    doLedInterval(red_led_pin, red_led_interval);
}

void configureLeds()
{
    pinMode(red_led_pin, OUTPUT);
    pinMode(yellow_led_pin, OUTPUT);
    pinMode(green_led_pin, OUTPUT);
}

void turnLedOn(int ledPin)
{
    digitalWrite(ledPin, HIGH);
}

void turnLedOff(int ledPin)
{
    digitalWrite(ledPin, LOW);
}

void doLedInterval(int ledPin, int interval)
{
    turnLedOn(ledPin);
    delay(interval);
    turnLedOff(ledPin);
}
