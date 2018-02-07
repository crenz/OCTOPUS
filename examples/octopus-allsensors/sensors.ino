#ifdef ENABLE_BME280
Adafruit_BME280 bme280; // I2C
bool bme280Initialized = false;
#endif
#ifdef ENABLE_BME680
Adafruit_BME680 bme680; // I2C
bool bme680Initialized = false;
#endif
#ifdef ENABLE_BNO055
Adafruit_BNO055 bno055 = Adafruit_BNO055(55);
bool bno055Initialized = false;
Bno055Values bnoValues; 
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

unsigned long lastSensorUpdateMillis = 0;

// ---- Functions ----

void setupSensors() {
#ifdef ENABLE_NEOPIXEL
    printMsg("Neopixel", "Initializing Neopixels");
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
#endif

    delay(1000); // give sensors some time to start up
    
 #ifdef ENABLE_BME280
    printMsg("Sensors", "Initializing BME280: ");
    if (bme280.begin()) {
        bme280Initialized = true;
        Serial.println("OK");
    } else {
        Serial.println("Not found");
    }
#endif
#ifdef ENABLE_BME680
    printMsg("Sensors", "Initializing BME680: ");
    if (bme680.begin()) {
        bme680Initialized = true;
        Serial.println("OK");
    } else {
        Serial.println("Not found");
    }
#endif
#ifdef ENABLE_BNO055
    printMsg("Sensors", "Initializing BNO055: ");
    if (bno055.begin()) {
        bno055Initialized = true;
        Serial.println("OK");
    } else {
        Serial.println("Not found");
    }
#endif
    delay(500);
}

float getVcc () {
  return ESP.getVcc() / 1000.0;
}

// ---- Pretty-printing Functions ----

void loopSensors() {
    if (millis() - lastSensorUpdateMillis > sensorUpdateRateMS) {
        lastSensorUpdateMillis = millis();
        printSensors();
    }
    delay(loopDelay);
}

void printSensors () {
#ifdef ENABLE_VCC
    printMsg("VCC", "ESP8266 supply voltage: ");
    Serial.println(getVcc());
#else
#ifdef ENABLE_A0
    printMsg("AnalogIn", "");
    Serial.println(analogRead(A0));
#endif
#endif
}

