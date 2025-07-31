#include <Arduino.h>

// Constants
constexpr int red_led_pin = 2;
constexpr int yellow_led_pin = 3;
constexpr int green_led_pin = 4;
constexpr int button_pin = A1;

constexpr int common_red_led_interval = 3000;
constexpr int common_yellow_led_interval = 1000;
constexpr int common_green_led_interval = 3000;

constexpr int stopped_red_led_interval = 5000;
constexpr int stopped_yellow_led_interval = 1000;

constexpr int analog_constant = 1015;

// Variables
int last_lit_led = red_led_pin;
bool button_is_pressed = false;
bool semaphore_is_in_stopped_mode = false;

void configureLeds();
void turnLedOn(int led_pin);
void turnLedOff(int led_pin);
void doLedInterval(int led_pin, int interval);
void readButtonState();
void doAppropriateLedInterval();

void setup()
{
    Serial.begin(9600);
    configureLeds();
}

void loop()
{
    readButtonState();
    if (button_is_pressed)
    {
        semaphore_is_in_stopped_mode = true;
    }
    doAppropriateLedInterval();
}

void configureLeds()
{
    pinMode(red_led_pin, OUTPUT);
    pinMode(yellow_led_pin, OUTPUT);
    pinMode(green_led_pin, OUTPUT);
    pinMode(button_pin, INPUT);
}

void turnLedOn(int led_pin)
{
    digitalWrite(led_pin, HIGH);
}

void turnLedOff(int led_pin)
{
    digitalWrite(led_pin, LOW);
}

void doLedInterval(int led_pin, int interval)
{
    turnLedOn(led_pin);
    delay(interval);
    turnLedOff(led_pin);
    last_lit_led = led_pin;
}

void readButtonState()
{
    int read_signal = analogRead(button_pin);
    Serial.println(read_signal);
    if (read_signal < analog_constant)
    {
        button_is_pressed = false;
    }
    else
    {
        button_is_pressed = true;
    }
}

void doAppropriateLedInterval()
{
    if (semaphore_is_in_stopped_mode)
    {
        if (last_lit_led == green_led_pin)
        {
            doLedInterval(yellow_led_pin, stopped_yellow_led_interval);
        }
        doLedInterval(red_led_pin, stopped_red_led_interval);
        semaphore_is_in_stopped_mode = false;
    }
    else
    {
        if (last_lit_led == green_led_pin)
        {
            doLedInterval(yellow_led_pin, common_yellow_led_interval);
        }
        else if (last_lit_led == yellow_led_pin)
        {
            doLedInterval(red_led_pin, common_red_led_interval);
        }
        else if (last_lit_led == red_led_pin)
        {
            doLedInterval(green_led_pin, common_green_led_interval);
        }
    }
}
