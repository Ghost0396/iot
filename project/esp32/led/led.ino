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

const int ledPin = 2;
LEDController led2(ledPin);

void setup() {

}

void loop() {
  led2.turnOn();
  delay(1000);
  led2.turnOff();
  delay(1000);
}
