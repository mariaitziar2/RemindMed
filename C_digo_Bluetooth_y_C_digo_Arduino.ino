#include <SoftwareSerial.h>

// Configura los pines 8 y 9 para RX y TX (para el módulo Bluetooth HC-05)
SoftwareSerial BTSerial(8, 9); // RX, TX

// Definimos los pines de los tres sensores
const int sensorManana = 2;
const int sensorMediodia = 3;
const int sensorNoche = 4;

void setup() {
  Serial.begin(9600);  // Para la comunicación con el monitor serial
  BTSerial.begin(9600); // Para la comunicación con el módulo Bluetooth
  
  pinMode(sensorManana, INPUT);
  pinMode(sensorMediodia, INPUT);
  pinMode(sensorNoche, INPUT);
}

void loop() {
  // Leemos los valores de los sensores
  int valorManana = digitalRead(sensorManana);
  int valorMediodia = digitalRead(sensorMediodia);
  int valorNoche = digitalRead(sensorNoche);

  // Depuración: Imprime en el monitor serial
  Serial.print("Manana: ");
  Serial.print(valorManana);
  Serial.print(" | Mediodia: ");
  Serial.print(valorMediodia);
  Serial.print(" | Noche: ");
  Serial.println(valorNoche);

  // Enviamos los datos al Bluetooth
  BTSerial.print(valorManana);
  BTSerial.print("|");
  BTSerial.print(valorMediodia);
  BTSerial.print("|");
  BTSerial.println(valorNoche);

  delay(1000); // Esperamos 1 segundo antes de enviar de nuevo
}
