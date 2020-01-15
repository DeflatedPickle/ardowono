struct LED_NUM {
  int dot;
  int top;
  int left_high;
  int right_high;
  int middle;
  int left_low;
  int right_low;
  int bottom;

  LED_NUM (int dot, int top, int left_high, int right_high, int middle, int left_low, int right_low, int bottom) {
    this->dot = dot;
    this->top = top;
    this->left_high = left_high;
    this->right_high = right_high;
    this->middle = middle;
    this->left_low = left_low;
    this->right_low = right_low;
    this->bottom = bottom;
  }

  void setup() {
    pinMode(this->dot, OUTPUT);
    pinMode(this->top, OUTPUT);
    pinMode(this->left_high, OUTPUT);
    pinMode(this->right_high, OUTPUT);
    pinMode(this->middle, OUTPUT);
    pinMode(this->left_low, OUTPUT);
    pinMode(this->right_low, OUTPUT);
    pinMode(this->bottom, OUTPUT);
  }
};

enum Num {
  NONE,
  ZERO,
};

LED_NUM my_led = LED_NUM(0, 3, 2, 1, 4, 5, 7, 6);

void num(LED_NUM led, Num num, bool dot) {
  if (dot) digitalWrite(led.dot, HIGH); else digitalWrite(led.dot, LOW);
  
  switch(num) {
    case Num::NONE:
      // Clear all the LEDs
      digitalWrite(led.dot, LOW);
      digitalWrite(led.top, LOW);
      digitalWrite(led.left_high, LOW);
      digitalWrite(led.right_high, LOW);
      digitalWrite(led.middle, LOW);
      digitalWrite(led.left_low, LOW);
      digitalWrite(led.right_low, LOW);
      digitalWrite(led.bottom, LOW);
      
    case Num::ZERO:
      //  ---
      // |   |
      // |   |
      //  ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.left_low, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;
  }
}

void setup() {
  // Serial.begin(9600);

  my_led.setup();
}

void loop() {
  // num(my_led, Num::NONE, false);
  num(my_led, Num::ZERO, false);
}
