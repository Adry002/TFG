//---------------------------------------
//FASE 1: ADQUISICIÓN DE DATOS SIN MODBUS
//---------------------------------------

#include "sensors.h"
   
    TempSensor::TempSensor(): oneWire(new OneWire(SENSOR_PIN)), sensors(oneWire) {
        sensors.begin();
    }
    TempSensor::~TempSensor() {
        delete oneWire;
    }
    
    float TempSensor::leerTemperatura() {
        sensors.requestTemperatures();
        return sensors.getTempCByIndex(0);
    }

    void TempSensor::init() {
        sensors.begin();
    };

