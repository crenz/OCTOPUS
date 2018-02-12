#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Adafruit_Sensor.h>  // Make sure you have the Adafruit Sensor library installed
#ifdef ENABLE_BME280
#include <Adafruit_BME280.h>  // Make sure you have the Adafruit BME280 library installed
#endif
#ifdef ENABLE_BME680
#include <Adafruit_BME680.h>  // Make sure you have the Adafruit BME680 library installed
#endif
#ifdef ENABLE_BNO055
#include <Adafruit_BNO055.h>  // Make sure you have the Adafruit BNO055 library installed
#include <utility/imumaths.h>
#endif
#ifdef ENABLE_NEOPIXEL
#include <Adafruit_NeoPixel.h> // Make sure you have the Adafruit NeoPixel library installed
#endif

// ---- Hardware Configuration ----

#ifdef ENABLE_VCC
ADC_MODE(ADC_VCC); // enable reading in VCC of ESP8266
#endif

const int sensorUpdateRateMS = 2000; // Print updated sensor value every 10 seconds
const int loopDelay = 100;

#define PIN_NEOPIXEL      13
#define SEALEVELPRESSURE_HPA (1013.25)

// ---- Data structures ----

struct Bno055Values {
    float orientationX;
    float orientationY;
    float orientationZ;
    uint8_t calibrationSys;
    uint8_t calibrationGyro;
    uint8_t calibrationAccel;
    uint8_t calibrationMag;
};


