struct LED_NUM {
  int dot;
  int top;
  int left_high;
  int right_high;
  int middle;
  int left_low;
  int right_low;
  int bottom;

  /*
   * Right = The side with the dot
   */
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
  ZERO,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  NONE,
};

LED_NUM my_led = LED_NUM(
  4, // Dot
  9, // Top
  2, // Left High
  8, // Right High
  3, // Middle
  7, // Left Low
  5, // Right Low
  6  // Bottom
);

void num(LED_NUM led, Num num, bool dot) {
  if (dot) digitalWrite(led.dot, HIGH); else digitalWrite(led.dot, LOW);
  
  switch(num) {
    case Num::NONE:
      // Clear all the LEDs
      digitalWrite(led.top, LOW);
      digitalWrite(led.left_high, LOW);
      digitalWrite(led.right_high, LOW);
      digitalWrite(led.middle, LOW);
      digitalWrite(led.left_low, LOW);
      digitalWrite(led.right_low, LOW);
      digitalWrite(led.bottom, LOW);
      break;
      
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

    case Num::ONE:
      //
      //     |
      //     |
      //
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.right_low, HIGH);
      break;

    case Num::TWO:
      //   ---
      //   ___|
      //  |   
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.left_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;

    case Num::THREE:
      //   ---
      //   ___|
      //      |
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;

    case Num::FOUR:
      //
      //  |___|
      //      |
      //
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      break;

    case Num::FIVE:
      //   ---
      //  |___
      //      |   
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;

    case Num::SIX:
      //   ---
      //  |___
      //  |   |   
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.left_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;

    case Num::SEVEN:
      //   ---
      //      |
      //      |   
      //
      digitalWrite(led.top, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.right_low, HIGH);
      break;

    case Num::EIGHT:
      //   ---
      //  |___|
      //  |   |   
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.left_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;

    case Num::NINE:
      //   ---
      //  |___|
      //      |   
      //   ---
      digitalWrite(led.top, HIGH);
      digitalWrite(led.right_high, HIGH);
      digitalWrite(led.left_high, HIGH);
      digitalWrite(led.middle, HIGH);
      digitalWrite(led.right_low, HIGH);
      digitalWrite(led.bottom, HIGH);
      break;
  }
}

void setup() {
  Serial.begin(9600);

  my_led.setup();
}

int my_num = 0;

void loop() {
  // num(my_led, Num::NONE, false);

  if (my_num <= 9) {
    Serial.println(my_num);
    
    my_num++;
    num(my_led, Num::NONE, false);
    num(my_led, Num(my_num), false);

    delay(2000);
  }
  else {
    my_num = 0;
  }
}
