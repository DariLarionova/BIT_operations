void setup() {
  Serial.begin(9600);

  // Настраиваем A0–A2 как входы
  DDRC = 0b00000000; // все входы

  // Настраиваем PB3–PB5 (D11–D13) как выходы для светодиодов
  DDRB = 0b00111000; 
}

void loop() {
  // Сбрасываем все светодиоды
  PORTB = 0b00000000;

  // Проверяем кнопку A0
  if (PINC & 0b00000001) {
    Serial.println("Нажата кнопка A0");
    PORTB = 0b00100000; // D13 → красный
    Serial.println("Загорелся КРАСНЫЙ → PORTB, бит 5 (D13)");
  }

  // Проверяем кнопку A1
  if (PINC & 0b00000010) {
    Serial.println("Нажата кнопка A1");
    PORTB = 0b00010000; // D12 → жёлтый
    Serial.println("Загорелся ЖЁЛТЫЙ → PORTB, бит 4 (D12)");
  }

  // Проверяем кнопку A2
  if (PINC & 0b00000100) {
    Serial.println("Нажата кнопка A2");
    PORTB = 0b00001000; // D11 → зелёный
    Serial.println("Загорелся ЗЕЛЁНЫЙ → PORTB, бит 3 (D11)");
  }

  // Выводим состояние всех 6 аналоговых входов A0–A5
  Serial.print("Состояние PINC: ");
  for (int i = 5; i >= 0; i--) {
    Serial.print((PINC >> i) & 1);
  }
  Serial.println();

  delay(1000);
}
