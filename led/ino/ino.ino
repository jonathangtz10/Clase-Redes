const int LED_PIN = 3;
bool blink = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      blink = true;
      Serial.println("OK:LED_ON");
    } else if (cmd == "LED_OFF") {
      blink = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("OK:LED_OFF");
    } else {
      Serial.println("ERR:CMD");
    }
  }

  if (blink) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
}
