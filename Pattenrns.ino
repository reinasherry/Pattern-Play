const int ledPins[3] = {2, 3, 4};
const int btnPins[3] = {5, 6, 7};
const int buzzerPin = 9;
  int tones[3] = {262, 330, 392};  
int sequence[50];   // store up to 50 steps
int level = 0;

void setup() {
  Serial.begin(9600);
  for (int i=0; i<3; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(btnPins[i], INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);

// C4, E4, G4, B4 (you can change these)


  }
  randomSeed(analogRead(0));
  newRound();
}

void loop() {
  showSequence();

  if (!getPlayerInput()) {
    Serial.println("Game Over!");
    level = 0;
    delay(3000);   // 3 sec pause before restart
    newRound();
  } else {
    Serial.println("Level Complete!");
    delay(1500);   // short pause before new round
    newRound();
  }
}


void newRound() {
  sequence[level] = random(0, 3);
  level++;
  Serial.print("Level: ");
  Serial.println(level);
}

void showSequence() {
  for (int i = 0; i < level; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    tone(buzzerPin, tones[led], 400); // play tone for 400ms
    delay(500);
    digitalWrite(ledPins[led], LOW);
    delay(300);
  }
}


bool getPlayerInput() {
  for (int i=0; i<level; i++) {
    int pressed = waitForButton();
    if (pressed != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForButton() {
  while (true) {
    for (int i = 0; i < 3; i++) {
      if (digitalRead(btnPins[i]) == LOW) {
        digitalWrite(ledPins[i], HIGH);
        tone(buzzerPin, tones[i], 300); // beep for button press
        delay(300);
        digitalWrite(ledPins[i], LOW);
        noTone(buzzerPin); // stop sound
        return i;
      }
    }
  }
}

