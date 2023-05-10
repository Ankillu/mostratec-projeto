#include <LiquidCrystal.h>

// Inicialização do display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pino do sensor de temperatura
const int pinSensorTemperatura = A0;

void setup() {
  // Inicialização do display LCD
  lcd.begin(16, 2);
  lcd.print("Temperatura:");

  // Inicialização da comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura da tensão do sensor de temperatura
  int valorSensor = analogRead(pinSensorTemperatura);

  // Cálculo da temperatura em Celsius
  float tensao = valorSensor * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100;

  // Exibição da temperatura no display LCD
  lcd.setCursor(0, 1);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.print(" C");

  // Exibição da temperatura no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  delay(1000); // Aguarda 1 segundo antes de ler a temperatura novamente
}
