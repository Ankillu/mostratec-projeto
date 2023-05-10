#include <LiquidCrystal.h>

// Pino de conexão do sensor de temperatura ao Arduino
const int pinSensorTemperatura = A0;

// Pinos de conexão do display LCD ao Arduino
const int pinRS = 12;
const int pinE = 11;
const int pinD4 = 5;
const int pinD5 = 4;
const int pinD6 = 3;
const int pinD7 = 2;

// Inicializa o objeto do display LCD
LiquidCrystal lcd(pinRS, pinE, pinD4, pinD5, pinD6, pinD7);

void setup() {
  // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);
  lcd.print("Temperatura:");
}

void loop() {
  // Lê o valor analógico do sensor de temperatura
  int valorSensor = analogRead(pinSensorTemperatura);

  // Converte o valor analógico para temperatura em graus Celsius
  float temperatura = (valorSensor * 5.0 / 1023.0) * 100.0;

  // Exibe a temperatura no display LCD
  lcd.setCursor(0, 1);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.print(" C");

  delay(1000);  // Aguarda 1 segundo antes de atualizar a temperatura novamente
}
