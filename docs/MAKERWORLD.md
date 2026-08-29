# ESP32-C3 Bluetooth MIDI Drum Kit

A compact, fully 3D-printed electronic drum kit with wireless BLE MIDI connectivity. Built around the ESP32-C3 Super Mini microcontroller, this project turns 5 piezo sensors into a playable MIDI drum set that connects to any Bluetooth-enabled device.

## What's Included

- **5 Drum Pads**: Kick, Snare, Hi-Hat, Tom, Crash Cymbal
- **BLE MIDI**: Wireless Bluetooth connection with low latency (~10ms)
- **Velocity Sensitivity**: Dynamic response based on hit strength
- **3D Printed**: All structural parts are 3D printable (PLA/PLA+)
- **Compact Design**: Desktop-sized, fully portable

## 3D Print Files

The included `.3mf` file contains 6 build plates optimized for multi-color printing:

| Plate | Color | Parts |
|-------|-------|-------|
| 01 | White | Pad frames + clips (3 frames, 12 clips) |
| 02 | Black | Drum pad tops (3 round + 2 cymbal) |
| 03 | Black | Cymbal stands/holders |
| 04 | Green | Cymbal top surfaces + clips |
| 05 | Black | Main base plate |
| 06 | Green | Drumsticks |

**Recommended settings**: PLA/PLA+, 0.2mm layer height, 20-30% infill

## Electronics

- **MCU**: ESP32-C3 Super Mini (USB-C, built-in LED on GPIO8)
- **Sensors**: 5x Piezo sensors (27mm)
- **Resistors**: 5x 1MΩ (pull-down)
- **Wiring**: Simple analog connection - each piezo to a GPIO pin + GND

### GPIO Map

| Pad | GPIO | MIDI Note |
|-----|------|-----------|
| Kick | GPIO0 | C1 (36) |
| Snare | GPIO1 | D1 (38) |
| Hi-Hat | GPIO2 | F#1 (42) |
| Tom | GPIO3 | C2 (48) |
| Cymbal | GPIO4 | C2 (49) |

## Software

The firmware is written in Arduino IDE using the BLE MIDI protocol. Features include:

- 12-bit ADC reading for precise velocity detection
- Peak detection algorithm with configurable thresholds
- Inverted trigger support (GPIO2)
- MIDI Channel 10 (standard drum channel)
- Automatic BLE advertising on disconnect

## Compatibility

Works with any BLE MIDI-capable device:

| Platform | App | Status |
|----------|-----|--------|
| macOS | GarageBand, Logic Pro | ✅ |
| iOS | GarageBand, Cubasis 3 | ✅ |
| Android | n-track Studio, Caustic 3 | ✅ |
| Web | BandLab, Soundtrap | ✅ |

## More Information

For full documentation, wiring diagrams, assembly guide, and source code:

**GitHub**: https://github.com/kaanvur/drumkit

## License

CC BY-NC-SA 4.0 - Free for personal use, attribution required, derivative works must use the same license.

## Microcontroller Compatibility

This project uses 5 analog pins (GPIO0-4). You can adapt it to other microcontrollers with more analog pins:

- ESP32-WROOM-32D (18 analog pins → up to 18 pads)
- ESP32-S3 Super Mini (20 analog pins → up to 20 pads)
- Arduino Uno (6 analog pins → up to 6 pads)

Just update `NUM_PADS` and `piezoPins` array in the firmware.
