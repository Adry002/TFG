#pragma once
#ifndef SENSORS_H
#define SENSORS_H

#include <stdint.h>
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

constexpr uint8_t SENSOR_PIN = 4;


class TempSensor {
private:
    OneWire* oneWire=nullptr;
    DallasTemperature sensors;
public:
    TempSensor(const TempSensor& other) = delete; // Eliminar el constructor de copia
    TempSensor();
    ~TempSensor();
    TempSensor& operator=(const TempSensor& other) = delete; // Eliminar el operador de asignación

    float leerTemperatura();

    void init();
};

#endif