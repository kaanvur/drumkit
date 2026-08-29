# Bağlantı Rehberi / Wiring Guide

## 🇹🇷 Türkçe

### Malzeme Listesi

- 1x ESP32-C3 Super Mini
- 5x Piezo sensör (27mm çap)
- 5x 1MΩ direnç (pull-down)
- 1x LED (opsiyonel)
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

### LED Bağlantısı

```
GPIO8 ──── LED (+) ──── 220Ω ──── 3.3V
```

> LED opsiyoneldir. Her vuruşta 50ms yanıp söner.

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
    Piezo 1 ────────┤ GPIO0           3.3V ├──── LED (-)
    Piezo 2 ────────┤ GPIO1            GND ├──── Piezo (-) hepsi
    Piezo 3 ────────┤ GPIO2              8 ├──── LED (+)
    Piezo 4 ────────┤ GPIO3              │ │
    Piezo 5 ────────┤ GPIO4              │ │
                    │                      │ │
                    │          USB-C ──────┤ │
                    └──────────────────────┘ │
                                             │
    1MΩ dirençler: her GPIO ↔ GND arası    │
```

### Lehimleme İpuçları

1. Piezo kablolarını uzun tutun (esneklik için)
2. Dirençleri breadboard'da test edin, sonra lehimleyin
3. Tüm GND bağlantılarını birleştirin (ortak toprak)
4. Short devre kontrolü yapın

---

## 🇬🇧 English

### Components

- 1x ESP32-C3 Super Mini
- 5x Piezo sensors (27mm diameter)
- 5x 1MΩ resistors (pull-down)
- 1x LED (optional)
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

### LED Connection

```
GPIO8 ──── LED (+) ──── 220Ω ──── 3.3V
```

> LED is optional. Flashes for 50ms on each hit.

### Full Circuit

```
                    ┌──────────────────────┐
                    │   ESP32-C3 Super Mini │
                    │                      │
    Piezo 1 ────────┤ GPIO0           3.3V ├──── LED (-)
    Piezo 2 ────────┤ GPIO1            GND ├──── Piezo (-) all
    Piezo 3 ────────┤ GPIO2              8 ├──── LED (+)
    Piezo 4 ────────┤ GPIO3              │ │
    Piezo 5 ────────┤ GPIO4              │ │
                    │                      │ │
                    │          USB-C ──────┤ │
                    └──────────────────────┘ │
                                             │
    1MΩ resistors: between each GPIO ↔ GND  │
```
