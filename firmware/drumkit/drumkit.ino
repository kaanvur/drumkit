#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <Arduino.h>
#include <math.h>

// =====================================================
// BLE MIDI UUID
// =====================================================

#define SERVICE_UUID        "03b80e5a-ede8-4b33-a751-6ce34ec4c700"
#define CHARACTERISTIC_UUID "7772e5db-3868-4112-a1a9-f2669d106bf3"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;


// =====================================================
// PAD SAYISI
// =====================================================

#define NUM_PADS 5


// =====================================================
// PAD PINLERI
// =====================================================

const int piezoPins[NUM_PADS] = {
  0,  // GPIO0 - Kick
  1,  // GPIO1 - Snare
  2,  // GPIO2 - Tom (TERS OKUMA)
  3,  // GPIO3 - Hi-Hat
  4   // GPIO4 - Cymbal
};


// =====================================================
// TRIGGER YONU
//
// true  = normal: vurunca ADC degeri yukselir
// false = ters:   vurunca ADC degeri duser
// =====================================================

const bool triggerPositive[NUM_PADS] = {
  true,   // GPIO0
  true,   // GPIO1
  false,  // GPIO2 -> Bos durumda 4095, vurunca asagi duser
  true,   // GPIO3
  true    // GPIO4
};


// =====================================================
// MIDI NOTALARI
// =====================================================

const uint8_t midiNotes[NUM_PADS] = {
  36, // GPIO0 - Kick
  38, // GPIO1 - Snare
  42, // GPIO2 - Closed Hi-Hat
  48, // GPIO3 - Tom
  49  // GPIO4 - Crash Cymbal
};


// =====================================================
// PAD ISIMLERI
// =====================================================

const char* padNames[NUM_PADS] = {
  "KICK",
  "SNARE",
  "HI-HAT",
  "TOM",
  "CYMBAL"
};


// =====================================================
// DRUM TRIGGER AYARLARI
// =====================================================

const int thresholds[NUM_PADS] = {
  200, // GPIO0
  200, // GPIO1
  60, // GPIO2
  200, // GPIO3
  200  // GPIO4
};

const int resetThreshold = 50;

const unsigned long peakWindow = 8;
const unsigned long maskTime = 70;
const unsigned long noteDuration = 20;


// =====================================================
// LED
// =====================================================

const int ledPin = 8;
const unsigned long ledDuration = 50;

bool ledActive = false;
unsigned long ledStartTime = 0;


// =====================================================
// TRIGGER STATE
// =====================================================

enum TriggerState {
  READY,
  CAPTURING_PEAK,
  WAIT_FOR_RESET
};

TriggerState triggerStates[NUM_PADS];

int peakValues[NUM_PADS];

unsigned long triggerStartTimes[NUM_PADS];

unsigned long lastTriggerTimes[NUM_PADS];

bool notesOn[NUM_PADS];

unsigned long noteOnTimes[NUM_PADS];


// =====================================================
// BLE CALLBACK
// =====================================================

class MyServerCallbacks : public BLEServerCallbacks {

  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Bluetooth cihazi baglandi!");
  }

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;

    Serial.println("Bluetooth baglantisi koptu.");

    delay(100);

    BLEDevice::startAdvertising();
  }
};


// =====================================================
// LED FLASH
// =====================================================

void flashLED() {
  digitalWrite(ledPin, HIGH);

  ledActive = true;

  ledStartTime = millis();
}


// =====================================================
// MIDI NOTE ON
// =====================================================

void sendMidiNoteOn(int pad, uint8_t velocity) {

  // BLE bagli degilse trigger ve LED yine calisir
  if (!deviceConnected) {
    return;
  }

  uint8_t midiPacket[] = {
    0x80,
    0x80,
    0x99, // MIDI Channel 10 - Drum
    midiNotes[pad],
    velocity
  };

  pCharacteristic->setValue(
    midiPacket,
    sizeof(midiPacket)
  );

  pCharacteristic->notify();

  notesOn[pad] = true;
  noteOnTimes[pad] = millis();
}


// =====================================================
// MIDI NOTE OFF
// =====================================================

void sendMidiNoteOff(int pad) {

  if (!deviceConnected) {
    notesOn[pad] = false;
    return;
  }

  uint8_t midiPacket[] = {
    0x80,
    0x80,
    0x89,
    midiNotes[pad],
    0
  };

  pCharacteristic->setValue(
    midiPacket,
    sizeof(midiPacket)
  );

  pCharacteristic->notify();

  notesOn[pad] = false;
}


// =====================================================
// VELOCITY HESAPLAMA
// =====================================================

uint8_t calculateVelocity(
  int peak,
  int threshold
) {

  const int maxPeak = 3500;

  peak = constrain(
    peak,
    threshold,
    maxPeak
  );

  float normalized =
    (float)(peak - threshold) /
    (float)(maxPeak - threshold);

  normalized = constrain(
    normalized,
    0.0,
    1.0
  );

  // Daha hassas dusuk ve orta vuruslar
  normalized = sqrt(normalized);

  int velocity =
    1 + (normalized * 126);

  velocity = constrain(
    velocity,
    1,
    127
  );

  return velocity;
}


// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(115200);


  // LED

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);


  // ADC

  analogReadResolution(12);


  // PAD STATE INITIALIZATION

  for (int i = 0; i < NUM_PADS; i++) {

    triggerStates[i] = READY;

    peakValues[i] = 0;

    triggerStartTimes[i] = 0;

    lastTriggerTimes[i] = 0;

    notesOn[i] = false;

    noteOnTimes[i] = 0;
  }


  // BLE MIDI

  BLEDevice::init("ESP32-C3-Drum");

  BLEServer *pServer =
    BLEDevice::createServer();

  pServer->setCallbacks(
    new MyServerCallbacks()
  );

  BLEService *pService =
    pServer->createService(
      SERVICE_UUID
    );

  pCharacteristic =
    pService->createCharacteristic(

      CHARACTERISTIC_UUID,

      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY |
      BLECharacteristic::PROPERTY_WRITE_NR

    );

  pCharacteristic->addDescriptor(
    new BLE2902()
  );

  pService->start();

  BLEAdvertising *pAdvertising =
    BLEDevice::getAdvertising();

  pAdvertising->addServiceUUID(
    SERVICE_UUID
  );

  pAdvertising->setScanResponse(true);

  pAdvertising->start();


  Serial.println();
  Serial.println("================================");
  Serial.println("ESP32-C3 5 PAD DRUM HAZIR");
  Serial.println("GPIO2 TERS TRIGGER MODUNDA");
  Serial.println("================================");
}


// =====================================================
// LOOP
// =====================================================

void loop() {

  unsigned long now = millis();


  // ===================================================
  // LED TIMER
  // ===================================================

  if (
    ledActive &&
    now - ledStartTime >= ledDuration
  ) {

    digitalWrite(ledPin, LOW);

    ledActive = false;
  }


  // ===================================================
  // HER PAD'I KONTROL ET
  // ===================================================

  for (int i = 0; i < NUM_PADS; i++) {


    // ADC OKU

    int sensorValue =
      analogRead(
        piezoPins[i]
      );


    // =================================================
    // TRIGGER DEGERINI NORMALIZE ET
    //
    // Normal pinler:
    //   Bos -> dusuk
    //   Vurus -> yuksek
    //
    // GPIO2:
    //   Bos -> 4095
    //   Vurus -> asagi duser
    // =================================================

    int triggerValue;

    if (triggerPositive[i]) {

      triggerValue = sensorValue;

    } else {

      // GPIO2 icin ters trigger
      triggerValue = 4095 - sensorValue;
    }


    // =================================================
    // READY
    // =================================================

    if (triggerStates[i] == READY) {

      if (
        triggerValue > thresholds[i] &&
        now - lastTriggerTimes[i] >= maskTime
      ) {

        peakValues[i] = triggerValue;

        triggerStartTimes[i] = now;

        triggerStates[i] = CAPTURING_PEAK;
      }
    }


    // =================================================
    // CAPTURING PEAK
    // =================================================

    else if (
      triggerStates[i] == CAPTURING_PEAK
    ) {

      // Peak degerini bul

      if (
        triggerValue > peakValues[i]
      ) {

        peakValues[i] = triggerValue;
      }


      // Peak window tamamlandi

      if (
        now - triggerStartTimes[i] >= peakWindow
      ) {

        uint8_t velocity =
          calculateVelocity(
            peakValues[i],
            thresholds[i]
          );


        // DEBUG

        Serial.print(padNames[i]);

        Serial.print(" | ADC: ");

        Serial.print(sensorValue);

        Serial.print(" | Trigger: ");

        Serial.print(triggerValue);

        Serial.print(" | Peak: ");

        Serial.print(peakValues[i]);

        Serial.print(" | Velocity: ");

        Serial.println(velocity);


        // LED her zaman calisir

        flashLED();


        // MIDI

        sendMidiNoteOn(
          i,
          velocity
        );


        lastTriggerTimes[i] = now;

        triggerStates[i] = WAIT_FOR_RESET;
      }
    }


    // =================================================
    // WAIT FOR RESET
    // =================================================

    else if (
      triggerStates[i] == WAIT_FOR_RESET
    ) {

      if (
        triggerValue < resetThreshold &&
        now - lastTriggerTimes[i] >= maskTime
      ) {

        triggerStates[i] = READY;
      }
    }


    // =================================================
    // MIDI NOTE OFF
    // =================================================

    if (
      notesOn[i] &&
      now - noteOnTimes[i] >= noteDuration
    ) {

      sendMidiNoteOff(i);
    }
  }
}