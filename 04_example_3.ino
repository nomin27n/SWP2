#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); // Initialize serial port
  while (!Serial) {
    ; // wait for serial port to connect (for Leonardo, Micro etc.)
  }
  Serial.println("Hello World!");
  count = 0;
  toggle = 0;
  digitalWrite(PIN_LED, toggle); // turn off LED initially
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle); // toggle LED value
  digitalWrite(PIN_LED, toggle); // update LED status
  delay(1000); // wait for 1,000 milliseconds (1 second)
}

int toggle_state(int t) {
  return !t; // 반전시켜야 LED가 켜졌다 꺼짐
}
