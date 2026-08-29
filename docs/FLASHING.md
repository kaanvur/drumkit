# Kod Yükleme Rehberi / Flashing Guide

## 🇹🇷 Türkçe

### Ön Gereksinimler

1. **Arduino IDE** (v2.x önerilir): https://www.arduino.cc/en/software
2. **ESP32 Board Paketi**

### ESP32 Board Paketini Yükleme

1. Arduino IDE'i açın
2. `Dosya > Tercihler` (File > Preferences) menüsüne gidin
3. "Additional Boards Manager URLs" alanına şunu ekleyin:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. `Tamam` (OK) butonuna tıklayın
5. `Araçlar > Panolar > Panolar Yöneticisi` (Tools > Board > Boards Manager)gidin
6. "esp32" arayın
7. **"esp32 by Espressif Systems"** paketini yükleyin

### Board Seçimi

1. `Araçlar > Panolar` (Tools > Board) menüsüne gidin
2. **"ESP32C3 Dev Module"** seçin

Diğer ayarlar (varsayılan olabilir):
- Upload Speed: 921600
- Flash Frequency: 80MHz
- Flash Mode: QIO
- Flash Size: 4MB
- Partition Scheme: Default 4MB with spiffs

### Kodu Yükleme

1. `firmware/drumkit/drumkit.ino` dosyasını Arduino IDE'de açın
2. USB-C kablo ile ESP32-C3'ü bilgisayara bağlayın
3. `Araçlar > Port` menüsünden doğru portu seçin
   - macOS: `/dev/cu.usbmodem*` veya `/dev/cu.usbserial*`
   - Windows: `COM*`
   - Linux: `/dev/ttyACM*` veya `/dev/ttyUSB*`
4. **Upload** (Yükle) butonuna tıklayın

### Yükleme Sırasında Sorun Yaşarsanız

**ESP32 modu algılanmıyor:**
- ESP32-C3 Super Mini'de **BOOT** butonuna basılı tutun
- Upload butonuna tıklayın
- Yazma başladığında butonu bırakın

**Port görünmüyor:**
- USB-C kablosunun veri aktarımı desteklediğinden emin olun
- Farklı bir kablo deneyin
- USB sürücüsünü kontrol edin

**Hata: "Failed to connect"**
- BOOT butonunu basılı tutarak deneyin
- Serialmonitore bağlanıp 115200 baud'de hata mesajını kontrol edin

### BLE MIDI Kullanma

1. Kod yüklendikten sonra ESP32-C3 otomatik olarak reklam yapmaya başlar
2. Telefonunuzda / bilgisayarınızda Bluetooth'u açın
3. **"ESP32-C3-Drum"** cihazını arayın ve bağlanın
4. MIDI uygulamasında bu cihazı seçin (GarageBand, y MIDI Connector, etc.)

### Seri Monitör (Debug)

Kod yüklendikten sonra Serial Monitor'de şu bilgileri görebilirsiniz:
```
================================
ESP32-C3 5 PAD DRUM HAZIR
GPIO2 TERS TRIGGER MODUNDA
================================
KICK | ADC: 1200 | Trigger: 1200 | Peak: 1800 | Velocity: 85
SNARE | ADC: 800 | Trigger: 800 | Peak: 1400 | Velocity: 72
```

Baud hızı: **115200**

---

## 🇬🇧 English

### Prerequisites

1. **Arduino IDE** (v2.x recommended): https://www.arduino.cc/en/software
2. **ESP32 Board Package**

### Installing ESP32 Board Package

1. Open Arduino IDE
2. Go to `File > Preferences`
3. In "Additional Boards Manager URLs", add:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. Click OK
5. Go to `Tools > Board > Boards Manager`
6. Search for "esp32"
7. Install **"esp32 by Espressif Systems"**

### Board Selection

1. Go to `Tools > Board`
2. Select **"ESP32C3 Dev Module"**

Other settings (should be defaults):
- Upload Speed: 921600
- Flash Frequency: 80MHz
- Flash Mode: QIO
- Flash Size: 4MB
- Partition Scheme: Default 4MB with spiffs

### Flashing

1. Open `firmware/drumkit/drumkit.ino` in Arduino IDE
2. Connect ESP32-C3 via USB-C cable
3. Select correct port in `Tools > Port`
   - macOS: `/dev/cu.usbmodem*` or `/dev/cu.usbserial*`
   - Windows: `COM*`
   - Linux: `/dev/ttyACM*` or `/dev/ttyUSB*`
4. Click **Upload**

### Troubleshooting

**ESP32 not detected:**
- Hold the **BOOT** button on ESP32-C3 Super Mini
- Click Upload
- Release button when writing starts

**Port not showing:**
- Make sure USB-C cable supports data transfer
- Try a different cable
- Check USB drivers

**Error: "Failed to connect"**
- Try holding BOOT button
- Connect to Serial Monitor at 115200 baud to check error messages

### Using BLE MIDI

1. After flashing, ESP32-C3 starts advertising automatically
2. Enable Bluetooth on your phone / computer
3. Look for **"ESP32-C3-Drum"** device and connect
4. Select this device in your MIDI app (GarageBand, MIDI Connector, etc.)

### Serial Monitor (Debug)

After flashing, you can see these in Serial Monitor:
```
================================
ESP32-C3 5 PAD DRUM HAZIR
GPIO2 TERS TRIGGER MODUNDA
================================
KICK | ADC: 1200 | Trigger: 1200 | Peak: 1800 | Velocity: 85
SNARE | ADC: 800 | Trigger: 800 | Peak: 1400 | Velocity: 72
```

Baud rate: **115200**
