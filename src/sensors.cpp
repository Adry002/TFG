//---------------------------------------
//FASE 1: ADQUISICIÓN DE DATOS SIN MODBUS
//---------------------------------------

#include "sensors.h"

GestionSensores::GestionSensores() : 
    oneWire(PIN_DS18B20), 
    dsSensores(&oneWire), 
    dht(PIN_DHT, DHT22) {}

void GestionSensores::init() {
    dsSensores.begin();
    dht.begin();
    if (!bmp.begin(0x76)) { // 0x76 es la dirección común del GY-BMP280
        Serial.println("Error: No se encuentra el BMP280");
    }
}

DatosSensores GestionSensores::leerTodo() {
    DatosSensores datos;
    
    // Leer DS18B20
    dsSensores.requestTemperatures();
    datos.tempDS1 = dsSensores.getTempCByIndex(0);
    datos.tempDS2 = dsSensores.getTempCByIndex(1); // Leemos la segunda sonda
    
    // Leer DHT22
    datos.tempDHT = dht.readTemperature();
    datos.humDHT = dht.readHumidity();
    
    // Leer BMP280
    datos.tempBMP = bmp.readTemperature();
    datos.presBMP = bmp.readPressure() / 100.0F; // Convertir a hPa
    
    return datos;
}