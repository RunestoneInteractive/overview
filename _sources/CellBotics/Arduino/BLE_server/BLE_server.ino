// .. Copyright (C) 2012-2020 Bryan A. Jones.
//
//  This file is part of the CellBotics system.
//
//  The CellBotics system is free software: you can redistribute it and/or
//  modify it under the terms of the GNU General Public License as
//  published by the Free Software Foundation, either version 3 of the
//  License, or (at your option) any later version.
//
//  The CellBotics system is distributed in the hope that it will be
//  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
//  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with the CellBotics system.  If not, see
//  <http://www.gnu.org/licenses/>.
//
// *********************
// BLE Cellbotics server
// *********************
// This is based on `Neil Kolban's example for IDF <https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp>`_. It was ported to the Arduino ESP32 by Evandro Copercini, with updates by chegewara, then extended by Bryan A. Jones.

// Includes
// ========
#include <string>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>


// Macros
// ======
//
// .. _UUIDs:
//
// UUIDs
// -----
// See `here <https://www.uuidgenerator.net/>`_ for generating UUIDs.
//
// The UUID for the CellBot service.
#define SERVICE_UUID ("6c533793-9bd6-47d6-8d3b-c10a704b6b97")
// Characteristic for resetHardware.
#define RESET_HARDWARE_CHARACTERISTIC_UUID ("60cb180e-838d-4f65-aff4-20b609b453f3")
// Characteristic for pinMode.
#define PIN_MODE_CHARACTERISTIC_UUID ("6ea6d9b6-7b7e-451c-ab45-221298e43562")
// Characteristic for digitalWrite
#define DIGITAL_WRITE_CHARACTERISTIC_UUID ("d3423cf6-6da7-4dd8-a5ba-3c980c74bd6d")
// Characteristic for digitalRead
#define DIGITAL_READ_CHARACTERISTIC_UUID ("c370bc79-11c1-4530-9f69-ab9d961aa497")
// Characteristic for ledcSetup
#define LEDC_SETUP_CHARACTERISTIC_UUID ("6be57cea-3c46-4687-972b-03429d2acf9b")
// Characteristic for ledcAttachPin
#define LEDC_ATTACH_PIN_CHARACTERISTIC_UUID ("2cd63861-078f-436f-9ed9-79e57ec8b638")
// Characteristic for ledcDetachPin
#define LEDC_DETACH_PIN_CHARACTERISTIC_UUID ("b9b0cabe-25d8-4965-9259-7d3b6330e940")
// Characteristic for ledcWrite
#define LEDC_WRITE_CHARACTERISTIC_UUID ("40698030-a343-448f-a9ea-54b39b03bf81")

// Define this to return a textual description of each function executed to the Bluetooth client, and also print these descriptions to the serial port.
#define VERBOSE_RETURN

// Hardware
// ^^^^^^^^
// The only blue LED on the ESP32.
#define LED1 (2)
// The only pushbutton on the ESP32.
#define PB1 (0)


// Configure a pushbutton and LED to enable BLE pairing.
void configPairing() {
    // Configure the on-board pushbutton as the pairing enable button.
    pinMode(LED1, OUTPUT);
    // Configure the on-board LED controlled by the ESP32 to flash quickly while pairing.
    pinMode(PB1, INPUT);
}

// Variables
// =========
BLEServer *pServer = NULL;


// Reset
// =====
// Reset the device to a power-on like state in terms of the I/Os affected by the characteristics above. Also used as an e-stop when Bluetooth disconnects.
void reset_hardware() {

#ifdef VERBOSE_RETURN
    Serial.println("reset_hardware()");
#endif

    // TODO.
}


// Characteristic callbacks
// ========================
// Provide return values and checks used by all the following characteristics.
class InvokeArduinoCallback: public BLECharacteristicCallbacks {
    public:
    // A buffer for messages; a C string.
    char buf[100];
    // A string holding read data to return to the client.
    std::string ret;
    // The value read from a characteristic.
    std::string value;

    InvokeArduinoCallback() : ret(100, 0) {
        ret.assign("Not yet invoked.");
    };

    // On a read, return ``buf``.
    void onRead(BLECharacteristic* pCharacteristic) {
        pCharacteristic->setValue(ret);
    };

    // Get a write value and check its length.
    bool checkLength(size_t sz_expected_length, BLECharacteristic* pCharacteristic) {
        value = pCharacteristic->getValue();
        if (value.length() != sz_expected_length) {
            snprintf(buf, sizeof(buf), "Error: message length was %u, but expected %u.\n", value.length(), sz_expected_length);
            ret.assign(buf);
            return false;
        }

        // The default response is an empty string.
        ret.clear();
        return true;
    };
};


// Any write to this characteristic invokes ``reset_hardware``.
class ResetHardwareCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
            reset_hardware();
#ifdef VERBOSE_RETURN
            ret.assign("reset_hardware()");
#endif
    }
};


// A write to this characteristic invokes ``pinMode``; results are reported by a read of this characteristic.
class PinModeCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        ///                 value[0]    value[1]
        /// void pinMode(uint8_t pin, uint8_t mode)
        uint8_t u8_pin;
        uint8_t u8_mode;

        if (checkLength(2, pCharacteristic)) {
            u8_pin = static_cast<uint8_t>(value[0]);
            u8_mode = static_cast<uint8_t>(value[1]);
            pinMode(u8_pin, u8_mode);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "pinMode(%u, %u)", u8_pin, u8_mode);
            Serial.println(buf);
            ret.assign(buf);
#endif
        }
    }
};


// A write to this characteristic invokes ``digitalWrite``; results are reported by a read of this characteristic.
class DigitalWriteCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        ///                     value[0]     value[1]
        /// void digitalWrite(uint8_t pin, uint8_t val);
        uint8_t u8_pin;
        uint8_t u8_val;

        if (checkLength(2, pCharacteristic)) {
            u8_pin = static_cast<uint8_t>(value[0]);
            u8_val = static_cast<uint8_t>(value[1]);
            digitalWrite(u8_pin, u8_val);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "digitalWrite(%u, %u)", u8_pin, u8_val);
            Serial.println(buf);
            ret.assign(buf);
#endif
        }
    };
};


// A write to this characteristic invokes ``digitalWrite``; results are reported by a read of this characteristic.
class DigitalReadCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        /// ret[0]               value[0]
        /// int    digitalRead(uint8_t pin);
        uint8_t u8_pin;

        if (checkLength(1, pCharacteristic)) {
            u8_pin = static_cast<uint8_t>(value[0]);
            // Although ``digitialRead`` returns an ``int``, store it in a ``char``, since we assume it's a one-bit value.
            ret.resize(1);
            ret[0] = static_cast<char>(digitalRead(u8_pin));
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "%u = digitalRead(%u)", ret[0], u8_pin);
            Serial.println(buf);
            ret.replace(1, 99, buf);
#endif
        }
    };
};


// Same as above, for ``ledcSetup``.
class LedcSetupCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        // This wraps:
        /// ret[0:7]            value[0]      value[9:1]         value[10]
        /// double ledcSetup(uint8_t channel, double freq, uint8_t resolution_bits)
        double d_ret;
        uint8_t u8_channel;
        double d_freq;
        uint8_t u8_resolution_bits;

        if (checkLength(11, pCharacteristic)) {
            // Extract function parameters.
            u8_channel = static_cast<uint8_t>(value[0]);
            memcpy(&d_freq, value.data() + 1, 8);
            u8_resolution_bits = static_cast<uint8_t>(value[10]);

            // Call the function.
            d_ret = ledcSetup(u8_channel, d_freq, u8_resolution_bits);
            ret.resize(8);
            ret.assign(reinterpret_cast<char*>(&d_ret), 8);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "%lf = ledcSetup(%u, %lf, %u)", d_ret, u8_channel, d_freq, u8_resolution_bits);
            Serial.println(buf);
            ret.replace(8, 92, buf);
#endif
        }
    };
};


// Same as above, for ``ledcAttachPin``.
class ledcAttachPinCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        ///                      value[0]     value[1]
        /// void ledcAttachPin(uint8_t pin, uint8_t channel)
        uint8_t u8_pin;
        uint8_t u8_channel;

        if (checkLength(2, pCharacteristic)) {
            u8_pin = static_cast<uint8_t>(value[0]);
            u8_channel = static_cast<uint8_t>(value[1]);
            ledcAttachPin(u8_pin, u8_channel);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "ledcAttachPin(%u, %u)", u8_pin, u8_channel);
            Serial.println(buf);
            ret.assign(buf);
#endif
        }
    };
};


// Same as above, for ``ledcAttachPin``.
class ledcDetachPinCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        ///                      value[0]
        /// void ledcDetachPin(uint8_t pin)
        uint8_t u8_pin;

        if (checkLength(2, pCharacteristic)) {
            u8_pin = static_cast<uint8_t>(value[0]);
            ledcDetachPin(u8_pin);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "ledcDetachPin(%u)", u8_pin);
            Serial.println(buf);
            ret.assign(buf);
#endif
        }
    };
};


// Same as above, for ``ledcWrite``.
class LedcWriteCallback: public InvokeArduinoCallback {
    void onWrite(BLECharacteristic* pCharacteristic) {
        // This wraps:
        ///                    value[0]      value[4:1]
        /// void ledcWrite(uint8_t channel, uint32_t duty)
        uint8_t u8_channel;
        uint32_t u32_duty;

        if (checkLength(5, pCharacteristic)) {
            // Extract function parameters.
            u8_channel = static_cast<uint8_t>(value[0]);
            // Since the data isn't aligned, use memcpy.
            memcpy(&u32_duty, value.data() + 1, 4);

            // Call the function.
            ledcWrite(u8_channel, u32_duty);
#ifdef VERBOSE_RETURN
            snprintf(buf, sizeof(buf), "ledcWrite(%u, %u)", u8_channel, u32_duty);
            Serial.println(buf);
            ret.assign(buf);
#endif
        }
    };
};


// On a server disconnect, reset and update paired status.
class CellBotServerCallback : public BLEServerCallbacks {
    virtual void onDisconnect(BLEServer* pServer) {
#ifdef VERBOSE_RETURN
        Serial.println("BLE disconnected.");
#endif
        reset_hardware();
        // Now that the board isn't connected, allow pairing.
        configPairing();
    };
};


// Functions
// =========
void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");

    // Define the name visible when pairing this device.
    BLEDevice::init("CellBot");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new CellBotServerCallback());

    // Define the primary service for this server.
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // Define characteristics for this server
    //***************************************
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
        RESET_HARDWARE_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new ResetHardwareCallback());

    pCharacteristic = pService->createCharacteristic(
        PIN_MODE_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new PinModeCallback());

    pCharacteristic = pService->createCharacteristic(
        DIGITAL_WRITE_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new DigitalWriteCallback());

    pCharacteristic = pService->createCharacteristic(
        DIGITAL_READ_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new DigitalReadCallback());

    pCharacteristic = pService->createCharacteristic(
        LEDC_SETUP_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new LedcSetupCallback());

    pCharacteristic = pService->createCharacteristic(
        LEDC_WRITE_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new LedcWriteCallback());

    pCharacteristic = pService->createCharacteristic(
        LEDC_ATTACH_PIN_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new ledcAttachPinCallback());

    pCharacteristic = pService->createCharacteristic(
        LEDC_DETACH_PIN_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new ledcDetachPinCallback());

    // Complete Bluetooth config.
    pService->start();
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    // Functions that help with iPhone connections issue. Why is this done twice?
    pAdvertising->setMinPreferred(0x06);
    pAdvertising->setMinPreferred(0x12);
    Serial.println("Characteristic defined! Now you can read it in your phone!");

    configPairing();
}


void loop() {
    // Time in 0.1 s intervals since the pair pushbutton was pressed.
    static uint u_pairing_time_ds = 0;

    // Look for a paring pushbutton press only if we're not connected.
    if (!pServer->getConnectedCount()) {
        if (!digitalRead(PB1)) {
            // Set the timer to 30 s.
            u_pairing_time_ds = 300;
            BLEDevice::getAdvertising()->start();
        }
    }

    // Blink while pairing.
    if (u_pairing_time_ds) {
        --u_pairing_time_ds;
        // Turn the LED off and pairing off for the last blink.
        if (!u_pairing_time_ds) {
            digitalWrite(LED1, 0);
            BLEDevice::getAdvertising()->stop();
        } else {
            digitalWrite(LED1, !digitalRead(LED1));
        }
    }

    delay(100);
}
