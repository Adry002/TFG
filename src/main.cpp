#include <Arduino.h>
#include "sensors.h"

TempSensor sensor; // Creamos una instancia global del sensor

void setup() {
    Serial.begin(115200);
    sensor.init(); // Configuramos el sensor
    Serial.println("--- Fase 1: Prueba de Hardware ---");
}

void loop() {
    float temp = sensor.leerTemperatura();
    
    if (temp != -127.0) {
        Serial.print("Temperatura actual: ");
        Serial.print(temp);
        Serial.println(" C");
    }

    delay(2000); // Solo para la Fase 1 usamos delay, en la Fase 3 lo quitaremos
}