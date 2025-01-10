#ifndef BME680_H
#define BME680_H

#include "bme680.h"
#include "mbed.h"

namespace mbed_nuvoton {
    
#define BME680_DEFAULT_ADDRESS (0x77 << 1)  // The default I2C address (shifted for MBed 8 bit address)
//#define BME680_DEBUG_MODE  // Use this for enhance debug logs for I2C and more.

/**
 * BME680 Class for I2C usage.
 * Wraps the Bosch library for MBed usage.
 */
class BME680 {
public:
    BME680(PinName sda, PinName scl, int address = BME680_DEFAULT_ADDRESS, int hz = 100000);

    bool begin();

    bool setTemperatureOversampling(uint8_t os);

    bool setPressureOversampling(uint8_t os);

    bool setHumidityOversampling(uint8_t os);

    bool setIIRFilterSize(uint8_t fs);

    bool setGasHeater(uint16_t heaterTemp, uint16_t heaterTime);

    bool performReading();

    bool isGasHeatingSetupStable();

    int16_t getRawTemperature();
    uint32_t getRawPressure();
    uint32_t getRawHumidity();
    uint32_t getRawGasResistance();

    float getTemperature();

    float getPressure();

    float getHumidity();

    float getGasResistance();

protected:
    I2C     i2c;

private:
    bool _filterEnabled, _tempEnabled, _humEnabled, _presEnabled, _gasEnabled;
    int32_t _sensorID;
    struct bme680_dev gas_sensor;
    struct bme680_field_data data;
    uint8_t _adr;

    static void log(const char *format, ...);

    // BME680 - hardware interface
    int8_t i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
    int8_t i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
    void delay_msec(uint32_t ms);
};

}   /* namespace mbed_nuvoton */

#endif