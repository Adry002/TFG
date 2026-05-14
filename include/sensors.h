#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>

// Definición de Pines
constexpr uint8_t PIN_DS18B20 = 4;
constexpr uint8_t PIN_DHT = 5;

struct DatosSensores {
    float tempDS1;
    float tempDS2;
    float tempDHT;
    float humDHT;
    float tempBMP;
    float presBMP;
};

class GestionSensores {
private:
    // Objetos para DS18B20
    OneWire oneWire;
    DallasTemperature dsSensores;
    
    // Objeto para DHT22
    DHT dht;
    
    // Objeto para BMP280
    Adafruit_BMP280 bmp;

public:
    GestionSensores();
    void init();
    DatosSensores leerTodo();
};

#endif