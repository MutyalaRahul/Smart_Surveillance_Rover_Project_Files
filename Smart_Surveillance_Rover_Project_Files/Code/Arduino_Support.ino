// Arduino UNO Secondary Controller
// Receives data from MSP430 and logs or reacts

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // LED indicator
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    Serial.println("Distance from MSP430: " + data + " cm");

    int dist = data.toInt();
    if (dist < 15) {
      digitalWrite(13, HIGH); // Alert LED ON
    } else {
      digitalWrite(13, LOW);  // LED OFF
    }
  }
}
