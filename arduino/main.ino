#include <LiquidCrystal.h>
#include <Servo.h>

// Inicialização do display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pino do sensor de temperatura
const int pinSensorTemperatura = A0;

// Pino do motor servo
const int pinServo = 9;

// Limiares de temperatura
const float temperaturaLimite = 30.0; // Defina o limite de temperatura desejado

// Inicialização do motor servo
Servo motorServo;

void setup() {
  // Inicialização do display LCD
  lcd.begin(16, 2);
  lcd.print("Temperatura:");

  // Inicialização do motor servo
  motorServo.attach(pinServo);

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

  // Verificação da temperatura alta
  if (temperatura > temperaturaLimite) {
    // Ativação do motor servo
    motorServo.write(90); // Defina o ângulo desejado para o motor servo
    delay(1000); // Aguarda 1 segundo com o motor servo ativado
    motorServo.write(0); // Desliga o motor servo
  }

  delay(1000); // Aguarda 1 segundo antes de ler a temperatura novamente
}
