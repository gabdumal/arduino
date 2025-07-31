#include <Arduino.h>

constexpr int red_led_pin = 2;
constexpr int yellow_led_pin = 3;
constexpr int green_led_pin = 4;

void configureLeds();
void turnLedOn(int ledPin);
void turnLedsOn();

void setup()
{
    configureLeds();
    turnLedsOn();
}

void loop()
{
    // put your main code here, to run repeatedly:
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

void turnLedsOn()
{
    turnLedOn(red_led_pin);
    turnLedOn(yellow_led_pin);
    turnLedOn(green_led_pin);
}
