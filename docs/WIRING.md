# Bağlantı Rehberi / Wiring Guide

## 🇹🇷 Türkçe

### Analog Pin Gerekliliği

Piezo sensörler **analog pinlere** bağlanır. ADC (Analog-to-Digital Converter) ile okuma yapılır. Her piezo için bir analog pin gereklidir.

| Mikrodenetleyici | Analog Pin Sayısı | Kullanılabilir GPIO'lar |
|------------------|-------------------|-------------------------|
| ESP32-C3 Super Mini | 5 | GPIO0, GPIO1, GPIO2, GPIO3, GPIO4 |
| ESP32-WROOM-32D | 18 | GPIO32-39, GPIO0-5, GPIO34-39 |
| ESP32-S3 Super Mini | 20 | GPIO1-20 |
| Arduino Uno | 6 | A0-A5 |
| Arduino Nano | 8 | A0-A7 |

> **Daha fazla pad için**: ESP32-WROOM-32D gibi daha çok analog pin'e sahip kartlar kullanarak更大鼓组 kurabilirsiniz. Kodda `NUM_PADS` ve `piezoPins` dizisini güncellemeniz yeterlidir.

### Malzeme Listesi

- 1x ESP32-C3 Super Mini (dahili LED: GPIO8)
- 5x Piezo sensör (27mm çap)
- 5x 1MΩ direnç (pull-down)
- Jumper kablolar

### Bağlantı Şeması

Her piezo sensör bir **analog pina** ve **GND**'ye bağlanır. Ayrıca her piezo'ya paralel bir **1MΩ pull-down direnç** eklenir.

```
Piezo Sensör Bağlantısı (her pad için):
                    
    Piezo (+) ────── GPIO Pin ──┐
                               │
    Piezo (-) ────── GND       │
                               │
                    1MΩ direnç ─┘
                   (GPIO ↔ GND)
```

### GPIO Haritası

| Pad | GPIO | MIDI Notu | Eşik Değeri | Trigger Yönü |
|-----|------|-----------|-------------|--------------|
| Kick | GPIO0 | C1 (36) | 200 | Normal (↑) |
| Snare | GPIO1 | D1 (38) | 200 | Normal (↑) |
| Hi-Hat | GPIO2 | F#1 (42) | 60 | **Ters** (↓) |
| Tom | GPIO3 | C2 (48) | 200 | Normal (↑) |
| Cymbal | GPIO4 | C#2 (49) | 200 | Normal (↑) |

> **Not**: GPIO2 ters trigger modundadır. Bos durumda ADC degeri yuksektir (4095), vuruşta düşer.

### Dahili LED

ESP32-C3 Super Mini üzerinde yerleşik bir LED bulunur (GPIO8). Devreye ekstra LED bağlamaya gerek yoktur. Kodda her vuruşta 50ms yanıp söner.

### Direnç Bağlantısı Detayı

Her piezo için pull-down direnci:
- Bir ucu: Piezo (+) / GPIO pinine
- Diğer ucu: GND'ye

Bu direnç, piezo'dan gelen yüksek empedanslı sinyali GND'ye çekerek boş durumda stabil bir okuma sağlar.

### Tam Devre Şeması

```
                    ┌──────────────────────┐
                    │   ESP32-C3 Super Mini │
                    │                      │
    Piezo 1 ────────┤ GPIO0            GND ├──── Piezo (-) hepsi
    Piezo 2 ────────┤ GPIO1                │
    Piezo 3 ────────┤ GPIO2                │
    Piezo 4 ────────┤ GPIO3                │
    Piezo 5 ────────┤ GPIO4                │
                    │                      │
                    │  GPIO8 (Dahili LED)  │
                    │          USB-C ──────┤
                    └──────────────────────┘

    1MΩ dirençler: her GPIO ↔ GND arası
```

### Lehimleme İpuçları

1. Piezo kablolarını uzun tutun (esneklik için)
2. Dirençleri breadboard'da test edin, sonra lehimleyin
3. Tüm GND bağlantılarını birleştirin (ortak toprak)
4. Short devre kontrolü yapın

---

## 🇬🇧 English

### Analog Pin Requirement

Piezo sensors connect to **analog pins**. They are read using ADC (Analog-to-Digital Converter). Each piezo requires one analog pin.

| Microcontroller | Analog Pin Count | Available GPIOs |
|-----------------|------------------|-----------------|
| ESP32-C3 Super Mini | 5 | GPIO0, GPIO1, GPIO2, GPIO3, GPIO4 |
| ESP32-WROOM-32D | 18 | GPIO32-39, GPIO0-5, GPIO34-39 |
| ESP32-S3 Super Mini | 20 | GPIO1-20 |
| Arduino Uno | 6 | A0-A5 |
| Arduino Nano | 8 | A0-A7 |

> **For more pads**: Use microcontrollers with more analog pins like ESP32-WROOM-32D to build larger drum kits. Just update `NUM_PADS` and `piezoPins` array in the code.

### Components

- 1x ESP32-C3 Super Mini (built-in LED: GPIO8)
- 5x Piezo sensors (27mm diameter)
- 5x 1MΩ resistors (pull-down)
- Jumper wires

### Wiring Diagram

Each piezo sensor connects to an **analog pin** and **GND**. A **1MΩ pull-down resistor** is placed in parallel with each piezo.

```
Piezo Sensor Connection (for each pad):

    Piezo (+) ────── GPIO Pin ──┐
                               │
    Piezo (-) ────── GND       │
                               │
                    1MΩ resistor ─┘
                   (GPIO ↔ GND)
```

### GPIO Map

| Pad | GPIO | MIDI Note | Threshold | Trigger Direction |
|-----|------|-----------|-----------|-------------------|
| Kick | GPIO0 | C1 (36) | 200 | Normal (↑) |
| Snare | GPIO1 | D1 (38) | 200 | Normal (↑) |
| Hi-Hat | GPIO2 | F#1 (42) | 60 | **Inverted** (↓) |
| Tom | GPIO3 | C2 (48) | 200 | Normal (↑) |
| Cymbal | GPIO4 | C#2 (49) | 200 | Normal (↑) |

> **Note**: GPIO2 is in inverted trigger mode. Idle ADC value is high (4095), drops on hit.

### Built-in LED

ESP32-C3 Super Mini has a built-in LED on GPIO8. No external LED connection is needed. In the code, it flashes for 50ms on each hit.

### Full Circuit

```
                    ┌──────────────────────┐
                    │   ESP32-C3 Super Mini │
                    │                      │
    Piezo 1 ────────┤ GPIO0            GND ├──── Piezo (-) all
    Piezo 2 ────────┤ GPIO1                │
    Piezo 3 ────────┤ GPIO2                │
    Piezo 4 ────────┤ GPIO3                │
    Piezo 5 ────────┤ GPIO4                │
                    │                      │
                    │  GPIO8 (Built-in LED)│
                    │          USB-C ──────┤
                    └──────────────────────┘

    1MΩ resistors: between each GPIO ↔ GND
```
