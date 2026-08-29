# ESP32-C3 Bluetooth MIDI Drum Kit

> 3D Printer ile basılmış, BLE MIDI ile kablosuz çalışan DIY elektronik davul seti.

![Hero](images/hero.png)

## 🇹🇷 Türkçe

### Proje Hakkında

Bu proje, **ESP32-C3 Super Mini** mikrodenetleyicisi kullanılarak oluşturulmuş компакт bir elektronik davul setidir. 3D printer ile basılmış pad'ler, piezo sensörler ve Bluetooth Low Energy (BLE) MIDI bağlantısı ile çalışır.

### Ozellikler

- **5 Pad**: Kick, Snare, Hi-Hat, Tom, Crash Cymbal
- **BLE MIDI**: Kablosuz Bluetooth bağlantısı (düşük gecikme)
- **Velocity Sensitivity**: Vuruş şiddetine göre MIDI velocity
- **3D Baskı**: Tamamı 3D printer ile basılabilir gövde
- **Kompakt**: Masaüstü boyutunda, taşınabilir tasarım

### Gerekli Malzemeler

| Bileşen | Adet | Not |
|---------|------|-----|
| ESP32-C3 Super Mini | 1 | USB-C girişli |
| Piezo Sensör (27mm) | 5 | Her pad için bir adet |
| Direnç (1MΩ) | 5 | Pull-down direnç |
| LED (Opsiyonel) | 1 | GPIO8'e bağlı |
| Jumper Kablo | ~20 | Erkek-dişi |
| USB-C Kablo | 1 | Kod yükleme için |

### 3D Baskı Parçaları

[`drumkit.3mf`](3d-models/drumkit.3mf) dosyası 6 baskı plakası içerir:

| Plaka | Renk | İçerik |
|-------|------|--------|
| 01 | Beyaz | Pad çerçeveleri + klipsler |
| 02 | Siyah | Pad üst yüzeyleri (3 yuvarlak + 2 zil) |
| 03 | Siyah | Zil ayakları / tutucular |
| 04 | Yeşil | Zil üst yüzeyleri + klipsler |
| 05 | Siyah | Ana gövde (base plate) |
| 06 | Yeşil | Davul çubukları |

**Önerilen malzeme**: PLA veya PLA+ ( PETG de olur )

### Bağlantı Şeması

```
ESP32-C3 Super Mini
┌─────────────────┐
│                 │
│  GPIO0 ──────────── Piezo 1 (Kick)    + 1MΩ direnç
│  GPIO1 ──────────── Piezo 2 (Snare)   + 1MΩ direnç
│  GPIO2 ──────────── Piezo 3 (Hi-Hat)  + 1MΩ direnç
│  GPIO3 ──────────── Piezo 4 (Tom)     + 1MΩ direnç
│  GPIO4 ──────────── Piezo 5 (Cymbal)  + 1MΩ direnç
│                 │
│  GPIO8 ──────────── LED (+)           │
│  GND ────────────── Piezo (-)         │
│  3.3V ───────────── LED (-)           │
│                 │
│  USB-C ──────── Kod yükleme           │
└─────────────────┘
```

Detaylı bağlantı için: [docs/WIRING.md](docs/WIRING.md)

### Montaj

1. 3D parçaları bas
2. Piezo sensörleri pad'lere yapıştır
3. Kablo lehimleme / bağlama
4. ESP32'yi gövdeye yerleştir
5. Kodu yükle
6. Bluetooth ile bağlan

Detaylı montaj için: [docs/ASSEMBLY.md](docs/ASSEMBLY.md)

### Kod Yükleme

Arduino IDE ile:
1. ESP32 board paketini yükle
2. `firmware/drumkit/drumkit.ino` dosyasını aç
3. Board: "ESP32C3 Dev Module" seç
4. Upload

Detaylı yükleme için: [docs/FLASHING.md](docs/FLASHING.md)

### Bluetooth MIDI Kullanma

Cihaz adı: **ESP32-C3-Drum**

| Platform | Uygulama | Durum |
|----------|----------|-------|
| macOS | GarageBand | ✅ Doğrudan çalışır |
| macOS | Logic Pro | ✅ Doğrudan çalışır |
| iOS | GarageBand | ✅ Doğrudan çalışır |
| iOS | Cubasis 3 | ✅ Doğrudan çalışır |
| Android | n-track Studio | ✅ Doğrudan çalışır |
| Android | Caustic 3 | ✅ Doğrudan çalışır |
| Windows | loopMIDI + DAW | ⚠️ BLE-MIDI sürücü gerekli |

Detaylı bağlantı ve uygulama kılavuzları için: [docs/BLUETOOTH.md](docs/BLUETOOTH.md)

---

## 🇬🇧 English

### About

A compact DIY electronic drum kit built with an **ESP32-C3 Super Mini** microcontroller. Features 3D-printed pads, piezo sensors, and wireless Bluetooth Low Energy (BLE) MIDI connectivity.

![Assembled](images/assembled-front.jpg)

### Features

- **5 Pads**: Kick, Snare, Hi-Hat, Tom, Crash Cymbal
- **BLE MIDI**: Wireless Bluetooth connection (low latency)
- **Velocity Sensitivity**: MIDI velocity based on hit strength
- **3D Printed**: Fully printable body and pads
- **Compact**: Desktop-sized, portable design

### Required Components

| Component | Qty | Note |
|-----------|-----|------|
| ESP32-C3 Super Mini | 1 | USB-C port |
| Piezo Sensor (27mm) | 5 | One per pad |
| Resistor (1MΩ) | 5 | Pull-down resistor |
| LED (Optional) | 1 | Connected to GPIO8 |
| Jumper Wires | ~20 | Male-to-female |
| USB-C Cable | 1 | For flashing |

### 3D Printed Parts

[`drumkit.3mf`](3d-models/drumkit.3mf) contains 6 build plates:

| Plate | Color | Contents |
|-------|-------|----------|
| 01 | White | Pad frames + clips |
| 02 | Black | Pad top surfaces (3 round + 2 cymbal) |
| 03 | Black | Cymbal stands / holders |
| 04 | Green | Cymbal top surfaces + clips |
| 05 | Black | Main base plate |
| 06 | Green | Drumsticks |

**Recommended material**: PLA or PLA+ (PETG works too)

### Wiring Diagram

```
ESP32-C3 Super Mini
┌─────────────────┐
│                 │
│  GPIO0 ──────────── Piezo 1 (Kick)    + 1MΩ resistor
│  GPIO1 ──────────── Piezo 2 (Snare)   + 1MΩ resistor
│  GPIO2 ──────────── Piezo 3 (Hi-Hat)  + 1MΩ resistor
│  GPIO3 ──────────── Piezo 4 (Tom)     + 1MΩ resistor
│  GPIO4 ──────────── Piezo 5 (Cymbal)  + 1MΩ resistor
│                 │
│  GPIO8 ──────────── LED (+)           │
│  GND ────────────── Piezo (-)         │
│  3.3V ───────────── LED (-)           │
│                 │
│  USB-C ──────── Flashing              │
└─────────────────┘
```

For detailed wiring: [docs/WIRING.md](docs/WIRING.md)

### Assembly

1. 3D print all parts
2. Attach piezo sensors to pads
3. Solder / connect wires
4. Mount ESP32 into base
5. Flash the firmware
6. Connect via Bluetooth

For detailed assembly: [docs/ASSEMBLY.md](docs/ASSEMBLY.md)

### Flashing

Using Arduino IDE:
1. Install ESP32 board package
2. Open `firmware/drumkit/drumkit.ino`
3. Select board: "ESP32C3 Dev Module"
4. Upload

For detailed instructions: [docs/FLASHING.md](docs/FLASHING.md)

### Using Bluetooth MIDI

Device name: **ESP32-C3-Drum**

| Platform | App | Status |
|----------|-----|--------|
| macOS | GarageBand | ✅ Works out of the box |
| macOS | Logic Pro | ✅ Works out of the box |
| iOS | GarageBand | ✅ Works out of the box |
| iOS | Cubasis 3 | ✅ Works out of the box |
| Android | n-track Studio | ✅ Works out of the box |
| Android | Caustic 3 | ✅ Works out of the box |
| Windows | loopMIDI + DAW | ⚠️ BLE-MIDI driver needed |

For detailed connection and app guides: [docs/BLUETOOTH.md](docs/BLUETOOTH.md)

---

## 📁 Project Structure / Proje Yapısı

```
drumkit/
├── README.md              # This file / Bu dosya
├── LICENSE                # MIT License
├── firmware/
│   └── drumkit/
│       └── drumkit.ino    # Arduino code / Arduino kodu
├── 3d-models/
│   └── drumkit.3mf        # 3D print file / 3D baskı dosyası
├── docs/
│   ├── WIRING.md          # Wiring guide / Bağlantı rehberi
│   ├── ASSEMBLY.md        # Assembly guide / Montaj rehberi
│   ├── FLASHING.md        # Flashing guide / Kod yükleme rehberi
│   └── BLUETOOTH.md       # Bluetooth MIDI guide / Bluetooth rehberi
└── images/                # Documentation images / Görseller
```

## 📜 License

MIT License - Özgürce kullanabilir, değiştirebilir ve dağıtabilirsiniz.

## � Katkıda Bulunma

Hata bildirimi veya geliştirme önerileriniz için Issue açabilirsiniz.
