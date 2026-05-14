#include <Arduino.h>
#include "sensors.h"

GestionSensores sistema;

void setup() {
    Serial.begin(115200);
    sistema.init();
    Serial.println("--- Fase 1: Adquisicion Multivariable ---");
}

void loop() {
    DatosSensores misDatos = sistema.leerTodo();

    Serial.println("----- LECTURA -----");
    Serial.print("DS18B20 Sonda 1: "); Serial.print(misDatos.tempDS1); Serial.println(" C");
    Serial.print("DS18B20 Sonda 2: "); Serial.print(misDatos.tempDS2); Serial.println(" C");
    Serial.print("DHT22 Humedad: "); Serial.print(misDatos.humDHT); Serial.println(" %");
    Serial.print("BMP280 Presion: "); Serial.print(misDatos.presBMP); Serial.println(" hPa");
    
    delay(2000); 
}