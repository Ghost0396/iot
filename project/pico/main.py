from machine import Pin
import dht
import time

sensor = dht.DHT11(Pin(14))

led = Pin("LED", Pin.OUT)

button = Pin(15, Pin.IN, Pin.PULL_UP)


def toggle_led():
    led.value(not led.value())


def read_sensor():
    try:
        sensor.measure()
        temp = sensor.temperature()
        hum = sensor.humidity()
        print("Temperature: {}°C, Humidity: {}%".format(temp, hum))
    except OSError as e:
        print("Failed to read from DHT sensor: {}".format(e))


def check_button():
    if not button.value():
        print("Button pressed")
        toggle_led()
        time.sleep(0.1)


while True:
    check_button()
    read_sensor()
    time.sleep(0.1)
