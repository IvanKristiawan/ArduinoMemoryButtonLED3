int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int index = 0;

int pressed_button[64];
int password[] = { 1, 2, 3 };
bool isAuthenticated = true;
char secret_key[] = "passwordnya";

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(13, INPUT);
  pinMode(9, INPUT);

  // Play with blink LED
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);

  while (!Serial) {
    ;
  }

  Serial.println("Program Started!");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(2);
  buttonState2 = digitalRead(4);
  buttonState3 = digitalRead(13);
  buttonState4 = digitalRead(9);

  if (buttonState == HIGH) {
    // Serial.println("HIGH1");
    digitalWrite(7, HIGH);

    pressed_button[index] = 1;
    index++;
    // Serial.println(index);
    delay(500);
  } else {
    digitalWrite(7, LOW);
  }

  if (buttonState2 == HIGH) {
    // Serial.println("HIGH2");
    digitalWrite(8, HIGH);

    pressed_button[index] = 2;
    index++;
    // Serial.println(index);
    delay(500);
  } else {
    digitalWrite(8, LOW);
  }

  if (buttonState3 == HIGH) {
    // Serial.println("HIGH3");
    digitalWrite(12, HIGH);

    pressed_button[index] = 3;
    index++;
    // Serial.println(index);
    delay(500);
  } else {
    digitalWrite(12, LOW);
  }

  if (buttonState4 == HIGH) {
    // Serial.println("HIGH4");

    // Find Array Size
    int arrayLength = sizeof(pressed_button) / sizeof(pressed_button[0]);
    // Serial.println(arrayLength);

    for (int i = 0; i < arrayLength; i++) {
      delay(500);
      // Serial.print(pressed_button[i]);
      // Serial.print(", ");
      if (pressed_button[i] == 1) {
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(12, LOW);
      } else if (pressed_button[i] == 2) {
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(12, LOW);
      } else {
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(12, HIGH);
      }

      // Authenticate
      if (pressed_button[i] != password[i]
          && pressed_button[i] != 0) {
        isAuthenticated = false;
      }

      if (pressed_button[i] == 0) {
        if (isAuthenticated) {
          Serial.print("Secret Key : ");
          Serial.print(secret_key);
        }

        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(12, LOW);
        while (1) {}
      }
    }
  }
}
