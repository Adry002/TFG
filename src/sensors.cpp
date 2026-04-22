//---------------------------------------
//FASE 1: ADQUISICIÓN DE DATOS SIN MODBUS
//---------------------------------------

#include "sensors.h" // <--- Fundamental para conectar el .cpp con el .h
#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_PIN 4

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

void initSensors() {
    sensors.begin();
}

float leerTemperatura() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}