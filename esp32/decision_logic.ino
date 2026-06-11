int dustLevel = 0;
int threshold = 50;

void setup() {
  Serial.begin(115200);
}

void loop() {
  dustLevel = analogRead(34); // sensor input

  if (dustLevel > threshold) {
    Serial.println("Cleaning Required");
    startCleaning();
  } else {
    Serial.println("No Cleaning Needed");
  }

  delay(60000); // check every minute
}

void startCleaning() {
  // motor ON
  digitalWrite(5, HIGH);

  // pump ON
  digitalWrite(18, HIGH);

  delay(10000);

  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
}