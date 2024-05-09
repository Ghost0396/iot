# Import libraries
import Adafruit_DHT
import RPi.GPIO as GPIO
from time import sleep


DHT_PIN = 15
DHT_SENSOR = Adafruit_DHT.DHT11
BUTTON_PIN = 0
LED_PIN = 2


GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)


class LEDController:
    def __init__(self, pin):
        self.pin = pin
        self.is_on = False
        self.turn_off()

    def turn_on(self):
        GPIO.output(self.pin, GPIO.HIGH)
        self.is_on = True

    def turn_off(self):
        GPIO.output(self.pin, GPIO.LOW)
        self.is_on = False

    def toggle(self):
        if self.is_on:
            self.turn_off()
        else:
            self.turn_on()


led = LEDController(LED_PIN)


try:
    while True:
        button_pressed = GPIO.input(BUTTON_PIN) == GPIO.LOW
        print(button_pressed)

        if button_pressed:
            led.toggle()
            sleep(0.3)

        humidity, temperature = Adafruit_DHT.read_retry(DHT_SENSOR, DHT_PIN)

        if humidity is None or temperature is None:
            print("Failed to read from DHT sensor!")
        else:
            print(f"Humidity: {humidity:.1f}%, Temperature: {temperature:.1f}°C")
        sleep(0.2)

except KeyboardInterrupt:
    GPIO.cleanup()
