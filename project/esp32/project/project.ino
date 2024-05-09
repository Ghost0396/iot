// Libraries
#include <DHT.h>

// Constants
#define DHTPIN 15    
#define DHTTYPE DHT11
#define BUTTONPIN 0
#define LEDPIN 2

DHT dht(DHTPIN, DHTTYPE);

// LEDController class definition
class LEDController {
  private:
    int pin;
    bool isOn;

  public:
    // Constructor
    LEDController(int pinNumber) {
      pin = pinNumber;
      isOn = false;
      pinMode(pin, OUTPUT);
      turnOff();
    }

    void turnOn() {
      digitalWrite(pin, HIGH);
      isOn = true;
    }

    void turnOff() {
      digitalWrite(pin, LOW);
      isOn = false;
    }

    void toggle() {
      if (isOn) {
        turnOff();
      } else {
        turnOn();
      }
    }
};

LEDController led(LEDPIN);

void setup() {

  Serial.begin(115200);
  dht.begin();
  pinMode(BUTTONPIN, INPUT_PULLUP);
  
}

void loop() {

  bool buttonPressed = digitalRead(BUTTONPIN) == LOW;
  Serial.println(buttonPressed);
  if (buttonPressed) {
    led.toggle();
    delay(300);
  }

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();


  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
  }
  delay(200);
}
