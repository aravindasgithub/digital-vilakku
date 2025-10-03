int ledPins[] = {9,10,11,12,13};  // 5 LEDs

void setup() {
  Serial.begin(9600);  // Bluetooth HC-05 communicates on hardware Serial

  // Set LED pins as output
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.println("Bluetooth LED Control Ready");
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    Serial.print("Received: ");
    Serial.println(data);

    switch (data) {
      case '1': digitalWrite(ledPins[0], HIGH); Serial.println("LED1 ON"); break;
      case '2': digitalWrite(ledPins[1], HIGH); Serial.println("LED2 ON"); break;
      case '3': digitalWrite(ledPins[2], HIGH); Serial.println("LED3 ON"); break;
      case '4': digitalWrite(ledPins[3], HIGH); Serial.println("LED4 ON"); break;
      case '5': digitalWrite(ledPins[4], HIGH); Serial.println("LED5 ON"); break;

      case 'A': digitalWrite(ledPins[0], LOW); Serial.println("LED1 OFF"); break;
      case 'B': digitalWrite(ledPins[1], LOW); Serial.println("LED2 OFF"); break;
      case 'C': digitalWrite(ledPins[2], LOW); Serial.println("LED3 OFF"); break;
      case 'D': digitalWrite(ledPins[3], LOW); Serial.println("LED4 OFF"); break;
      case 'E': digitalWrite(ledPins[4], LOW); Serial.println("LED5 OFF"); break;

      case 'X': 
        for (int i = 0; i < 5; i++) digitalWrite(ledPins[i], HIGH);
        Serial.println("ALL LEDs ON");
        break;

      case 'Y': 
        for (int i = 0; i < 5; i++) digitalWrite(ledPins[i], LOW);
        Serial.println("ALL LEDs OFF");
        break;
    }
  }
}
