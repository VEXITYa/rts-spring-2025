int pins[] = {3, 5, 6, 9, 10};
unsigned long periods[] = {10000, 1000, 500, 100, 50};
unsigned long prevMicros[5];
bool states[] = {LOW, LOW, LOW, LOW, LOW};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
    prevMicros[i] = micros();
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    unsigned long curMicros = micros()
    if (curMicros - prevMicros[i] >= periods[i]) {
      states[i] = !states[i];
      digitalWrite(pins[i], states[i]);
      prevMicros[i] = curMicros;
    }
  }
}