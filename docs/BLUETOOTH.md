# Bluetooth MIDI Bağlantı Rehberi / Bluetooth MIDI Connection Guide

## 🇹🇷 Türkçe

### Genel Bakış

ESP32-C3 drum kit'iniz **BLE MIDI** (Bluetooth Low Energy MIDI) protokolü ile çalışır. Bu, iOS, macOS ve Android cihazlarla kablosuz olarak MIDI sinyali gönderebilmenizi sağlar.

Cihaz adı: **ESP32-C3-Drum**

> İlk açılışta veya bağlantı koptuğunda ESP32-C3 otomatik olarak reklam (advertising) yapmaya başlar.

---

### macOS (MacBook / iMac) Bağlantısı

#### Adım 1: Bluetooth'u Açın

1. **Sistem Ayarları** (System Settings) > **Bluetooth** menüsüne gidin
2. Bluetooth'u **Açık** konuma getirin
3. "ESP32-C3-Drum" cihazını arama listesinde görün

> Eğer cihaz görünüyorsa, cihaz zaten reklam modundadır. Görünmüyorsa ESP32-C3'ü USB ile besleyin veya RESET butonuna basın.

#### Adım 2: Cihaza Bağlanın

1. "ESP32-C3-Drum" yanındaki **"Bağlan"** (Connect) butonuna tıklayın
2. Bağlantı kurulana kadar bekleyin
3. Bağlantı başarılı olduğunda "Bağlı" (Connected) yazacak

```
Bluetooth Ayarları:
┌─────────────────────────────────────────┐
│  Bulunan Cihazlar:                       │
│                                         │
│  🎵 ESP32-C3-Drum          [Bağlan]     │
│                                         │
└─────────────────────────────────────────┘
```

#### Adım 3: MIDI Studio'da Doğrulama

1. **Araçlar** (Applications) > **Utilites** (Utilities) > **Audio MIDI Kurulumu** (Audio MIDI Setup) uygulamasını açın
2. Üst menüden **Pencere** (Window) > **MIDI Stüdyo** (MIDI Studio) seçin
3. MIDI Studio penceresinde **"ESP32-C3-Drum"** cihazını görmelisiniz
4. Cihaza çift tıklayarak MIDI portlarının aktif olduğunu doğrulayın

> Bu adım zorunlu değildir, ancak bağlantının doğru kurulduğunu doğrulamak için faydalıdır.

#### Adım 4: GarageBand'de Kullanma

1. **GarageBand**'ı açın
2. Yeni bir proje oluşturun veya mevcut bir projeyi açın
3. **Yeni Parça** (New Track) > **Yazılı Enstrüman** (Software Instrument) seçin
4. Sol panelde **Klavye** (Keyboard) veya **Davul Seti** (Drum Kit) enstrümanını seçin

##### MIDI Bağlantısını Ayarlama

1. GarageBand menü çubuğunda **GarageBand > Tercihler** (Preferences) seçin
2. **MIDI** sekmesine gidin
3. **MIDI Giriş** (MIDI Input) bölümünde **"ESP32-C3-Drum"** seçin

```
GarageBand Tercihler:
┌─────────────────────────────────────────┐
│  MIDI                                    │
│                                         │
│  MIDI Giriş: [ ESP32-C3-Drum ▼]         │
│                                         │
│  ✅ MIDI saatini başlat                  │
│  ✅ Sampringleme hızı: 44.1 kHz          │
└─────────────────────────────────────────┘
```

##### Davul Enstrümanı Seçme

GarageBand'de davul sesi almak için:

1. Yeni bir **Yazılı Enstrüman** parçası ekleyin
2. Sol panelde **"Davul Seti"** (Drum Kit) kategorisine gidin
3. İstediğiniz davul preset'ini seçin (örn: "Classic Studio Kit", "Electronic Kit")
4. Pad'lerinize vurun - ses gelmeli

> **İpucu**: GarageBand'de "Drum Machine" veya "Electronic Drum Kit" preset'leri MIDI velocity'yi daha iyi algılar.

##### MIDI凱rtlama (MIDI Mapping)

GarageBand otomatik olarak General MIDI drum haritalamasını kullanır:

| Pad | MIDI Notu | GarageBand'de |
|-----|-----------|---------------|
| Kick | C1 (36) | Bass Drum |
| Snare | D1 (38) | Snare Drum |
| Hi-Hat | F#1 (42) | Closed Hi-Hat |
| Tom | C2 (48) | Mid Tom |
| Cymbal | C#2 (49) | Crash Cymbal |

##### Sorun Giderme

**Ses gelmiyor:**
- GarageBand'de MIDI girişinin doğru seçildiğinden emin olun
- Pad'lerinize vurduğunuzda Serial Monitor'de "Velocity" değerleri görünmeli
- GarageBand'de parçanın **Sessiz** (Mute) veya **Solo** durumda olmadığından emin olun

**Gecikme var:**
- BLE MIDI düşük gecikmelidir (~10ms), ancak macOS Bluetooth yığınına bağlıdır
- Diğer Bluetooth cihazlarını kapatmayı deneyin
- USB MIDI kullanmak isterseniz, ESP32-C3 USB-MID desteğini araştırın

**Bağlantı kopuyor:**
- ESP32-C3 menzilinin 5-10 metre olduğunu unutmayın
- Fiziksel engeller (duvar, metal) bağlantıyı zayıflatabilir
- Batarya seviyesi düşükse cihazı beslemeyi kontrol edin

---

### Android Bağlantısı

#### Genel Bakış

Android'de BLE MIDI, **Android 6.0 (API 23)** ve üzeri sürümlerde desteklenir. Google'ın **BLE MIDI** özelliği Android 6.0'dan itibaren işletim sistemine entegre edilmiştir.

#### Adım 1: Bluetooth'u Açın

1. **Ayarlar** > **Bağlantılar** > **Bluetooth**
2. Bluetooth'u **Açık** konuma getirin

#### Adım 2: Cihaza Bağlanma

**Önemli**: Android'de BLE MIDI cihazları normal Bluetooth cihazları gibi "Eşleştirilmez". Uygulama içinden bağlanılır.

1. Kullanacağınız MIDI uygulamasını açın (örn: n-track Studio)
2. Uygulama içinde BLE MIDI taraması başlatın
3. "ESP32-C3-Drum" cihazını seçin
4. Bağlantı kurulana kadar bekleyin

> Eğer cihaz Bluetooth ayarlarında görünüyorsa bile, uygulama içinden bağlanmanız gerekir.

#### n-track Studio ile Kullanım

**n-track Studio**, Android'de ücretsiz olarak kullanılabilecek güçlü bir DAW uygulamasıdır.

##### Kurulum

1. Google Play Store'dan **n-track Studio**'yu indirin
2. Uygulamayı açın
3. İlk açılışta gerekli izinleri verin

##### BLE MIDI Bağlantısı

1. n-track Studio'da **Ayarlar** (Settings) > **MIDI** bölümüne gidin
2. **BLE MIDI Cihazları** (BLE MIDI Devices) seçeneğine dokunun
3. Tarama başlatın
4. **"ESP32-C3-Drum"** cihazını seçin
5. Bağlantı başarılı olduğunda yeşil işaret görünecek

```
n-track Studio - MIDI Ayarları:
┌─────────────────────────────────────────┐
│  MIDI Ayarları                           │
│                                         │
│  BLE MIDI Cihazları:                     │
│  ┌─────────────────────────────────┐    │
│  │ ✅ ESP32-C3-Drum    [Bağlı]     │    │
│  └─────────────────────────────────┘    │
│                                         │
│  MIDI Giriş: ESP32-C3-Drum              │
│  MIDI Kanal: 10 (Drum)                  │
└─────────────────────────────────────────┘
```

##### Davul Seti Yükleme

1. Yeni bir **Davul Parçası** (Drum Track) ekleyin
2. **Enstrüman Seç** (Choose Instrument) > **Davul Seti** (Drum Kit) seçin
3. İstediğiniz davul preset'ini seçin
4. Pad'lerinize vurun

##### MIDI Haritalama

n-track Studio General MIDI drum haritalamasını kullanır:

| Pad | MIDI Notu | n-track Studio'da |
|-----|-----------|-------------------|
| Kick | C1 (36) | Bass Drum |
| Snare | D1 (38) | Snare |
| Hi-Hat | F#1 (42) | Closed Hi-Hat |
| Tom | C2 (48) | Tom |
| Cymbal | C#2 (49) | Crash |

##### Kayıt Yapma

1. **Kayıt** (Record) butonuna basın
2. Tempo ayarlayın (BPM)
3. Pad'lerinize vurarak davul loop'u kaydedin
4. Kaydı durdurun ve düzenleyin

##### İpuçları

- **Latency**: n-track Studio'da gecikme ayarını **Audio Setup** > **Buffer Size** bölümünden düşürebilirsiniz (128 veya 256 samples önerilir)
- **Velocity**: Pad'lerinize farklı şiddette vurarak dynamic davul kayıtları yapabilirsiniz
- **Quantize**: Kayıt sonrası "Quantize" özelliği ile vuruşları hizalayabilirsiniz

#### Diğer Android Uygulamaları

| Uygulama | Özellik | Ücretsiz |
|----------|---------|----------|
| **n-track Studio** | Tam DAW, kayıt, düzenleme | ✅ (Temel) |
| **USB MIDI Player** | MIDI dosyalarını çalma | ✅ |
| **MIDI Connector** | BLE MIDI → USB MIDI dönüştürücü | ✅ |
| **Caustic 3** | Synth ve drum machine | ✅ (Tam) |
| **Groovebox** | Beat maker | ✅ (Sınırlı) |

---

### iOS (iPhone / iPad) Bağlantısı

> iOS, BLE MIDI'yi doğrudan destekler.

1. **Ayarlar** > **Bluetooth**
2. Bluetooth'u açın
3. Kullanacağınız uygulamada "ESP32-C3-Drum" seçin

**Önerilen uygulamalar:**
- **GarageBand** (Ücretsiz)
- **Cubasis 3** (Profesyonel DAW)
- **AUM** (Mixer/Router)
- **MIDI Wrench** (MIDI test aracı)

---

### Çevrimiçi Platformlar (Platform Bağımsız)

ESP32-C3 drum kit'iniz sadece yerel uygulamalarla değil, aynı zamanda **çevrimiçi DAW** platformlarıyla da çalışır. Bu sayede herhangi bir uygulama indirmenize gerek kalmadan tarayıcı üzerinden müzik yapabilirsiniz.

#### BandLab (bandlab.com)

BandLab, ücretsiz çevrimiçi DAW'dır. BLE MIDI cihazlarını doğrudan destekler.

##### Bağlantı Adımları

1. **Telefonunuzdan** BandLab uygulamasını veya tarayıcınızdan **bandlab.com** adresini açın
2. Yeni bir proje oluşturun veya mevcut bir projeyi açın
3. **Bluetooth MIDI Bağlantısı**:
   - **Android**: Uygulama içinden BLE MIDI taraması başlatın → "ESP32-C3-Drum" seçin
   - **iOS**: Uygulama BLE MIDI'yi otomatik algılar → "ESP32-C3-Drum" seçin
4. Yeni bir **Davul** (Drum) parçası ekleyin
5. Pad'lerinize vurarak test edin

```
BandLab - Davul Parçası Oluşturma:
┌─────────────────────────────────────────┐
│  + Track > Drum > Empty Kit             │
│                                         │
│  MIDI Input: ESP32-C3-Drum              │
│  Channel: 10                            │
└─────────────────────────────────────────┘
```

##### BandLab İpuçları

- **Davul Preset'leri**: "808 Kit", "Acoustic Kit", "Electronic Kit" gibi preset'leri deneyin
- **Loop Kayıt**: Bir loop kaydedin, sonra其他的 parçaları ekleyin
- **Paylaşım**: Kaydettiğiniz projeleri doğrudan BandLab'de paylaşabilirsiniz

#### Soundtrap (soundtrap.com)

Soundtrap (Spotify'ın online DAW'ı) da BLE MIDI destekler.

1. **soundtrap.com** adresine gidin
2. Yeni proje oluşturun
3. **MIDIForKeyboard** ayarlarında "ESP32-C3-Drum" seçin
4. Davul parçası ekleyin ve çalmaya başlayın

#### CodePen / Web MIDI API

Geliştiriciler için: Web MIDI API ile tarayıcıda doğrudan MIDI alabilirsiniz.

```javascript
// Web MIDI API ile ESP32-C3 drum kit'i okuma
navigator.requestMIDIAccess().then(midiAccess => {
  for (const input of midiAccess.inputs.values()) {
    input.onmidimessage = (event) => {
      const [status, note, velocity] = event.data;
      console.log(`Pad: ${note}, Velocity: ${velocity}`);
    };
  }
});
```

> Bu özellik sadece Chrome ve Edge tarayıcılarında çalışır. Safari'de sınırlı destek vardır.

#### Diğer Çevrimiçi Platformlar

| Platform | URL | MIDI Desteği | Not |
|----------|-----|-------------|-----|
| **BandLab** | bandlab.com | ✅ BLE MIDI | Ücretsiz, mobil + web |
| **Soundtrap** | soundtrap.com | ✅ BLE MIDI | Spotify DAW, ücretli |
| **Amped Studio** | ampedstudio.com | ✅ Web MIDI | Ücretsiz deneme |
| **AudioTool** | audiotool.com | ⚠️ Sadece USB | Android için uygun değil |
| **Soundation** | soundation.com | ⚠️ Sınırlı | Ücretsiz plan mevcut |

> **Not**: Çevrimiçi platformlarda BLE MIDI desteği cihazın işletim sistemine bağlıdır. macOS ve iOS'ta doğrudan çalışır. Android'de uygulama içi BLE MIDI bağlantısı gerekir.

---

### Genel Sorun Giderme

#### Bağlantı Kurulamıyor

1. **ESP32-C3'ün açık olduğundan emin olun**: USB-C ile beslenmeli veya pilli olmalı
2. **Reklam modu**: Bağlantı koptuğunda ESP32 otomatik olarak tekrar reklam yapar. RESET butonuna basarak manuel olarak yeniden başlatın
3. **Menzil**: 5-10 metre menzil içeriside olun
4. **Engeller**: Duvarlar ve metal yüzeyler BLE sinyalini zayıflatabilir
5. **Başka cihazlar**: Önceki Bluetooth MIDI bağlantılarını kesin

#### Ses Gelmiyor

1. **MIDI kanalı**: Drum sesleri genellikle **MIDI Kanal 10**'da çalışır. Kodda bu ayar doğru (Channel 10 / 0x99)
2. **Velocity**: Çok hafif vuruşlar algılanmayabilir. Orta şiddette vurmayı deneyin
3. **MIDI notaları**: Kullandığınız uygulamanın General MIDI drum haritalamasını desteklediğinden emin olun

#### Gecikme (Latency) Sorunu

- BLE MIDI natif olarak ~10ms gecikmeye sahiptir
- macOS/iOS'ta bu genellikle sorun oluşturmaz
- Android'de bazı cihazlarda 20-30ms'ye kadar çıkabilir
- Düşük gecikme için:
  - Başka Bluetooth cihazlarını kapatın
  - Uygulama içinde buffer size'ı düşürün
  - WiFi bağlantısını devre dışı bırakın (2.4GHz çakışma)

---

## 🇬🇧 English

### Overview

Your ESP32-C3 drum kit uses **BLE MIDI** (Bluetooth Low Energy MIDI) protocol. This allows wireless MIDI signal transmission to iOS, macOS, and Android devices.

Device name: **ESP32-C3-Drum**

> On first boot or after disconnection, ESP32-C3 automatically starts advertising.

---

### macOS (MacBook / iMac) Connection

#### Step 1: Enable Bluetooth

1. Open **System Settings** > **Bluetooth**
2. Turn Bluetooth **On**
3. Look for "ESP32-C3-Drum" in the device list

> If the device appears, it's already in advertising mode. If not, power the ESP32-C3 via USB or press RESET.

#### Step 2: Connect

1. Click **"Connect"** next to "ESP32-C3-Drum"
2. Wait for connection to establish
3. Status will change to "Connected"

```
Bluetooth Settings:
┌─────────────────────────────────────────┐
│  Nearby Devices:                         │
│                                         │
│  🎵 ESP32-C3-Drum          [Connect]    │
│                                         │
└─────────────────────────────────────────┘
```

#### Step 3: Verify in MIDI Studio

1. Open **Applications** > **Utilities** > **Audio MIDI Setup**
2. Go to **Window** > **MIDI Studio**
3. You should see **"ESP32-C3-Drum"** in the MIDI Studio window
4. Double-click the device to verify MIDI ports are active

> This step is optional but useful for verifying correct connection.

#### Step 4: Use in GarageBand

1. Open **GarageBand**
2. Create a new project or open existing one
3. **New Track** > **Software Instrument**
4. Select **Keyboard** or **Drum Kit** instrument from the left panel

##### MIDI Configuration

1. In GarageBand menu bar, go to **GarageBand > Preferences**
2. Click the **MIDI** tab
3. Under **MIDI Input**, select **"ESP32-C3-Drum"**

```
GarageBand Preferences:
┌─────────────────────────────────────────┐
│  MIDI                                    │
│                                         │
│  MIDI Input: [ ESP32-C3-Drum ▼]         │
│                                         │
│  ✅ Enable MIDI clock                    │
│  ✅ Sampling rate: 44.1 kHz              │
└─────────────────────────────────────────┘
```

##### Selecting Drum Instrument

1. Add a new **Software Instrument** track
2. In the left panel, go to **"Drum Kit"** category
3. Choose a drum preset (e.g., "Classic Studio Kit", "Electronic Kit")
4. Hit your pads - you should hear sound

> **Tip**: "Drum Machine" or "Electronic Drum Kit" presets in GarageBand respond better to MIDI velocity.

##### MIDI Mapping

GarageBand uses General MIDI drum mapping by default:

| Pad | MIDI Note | In GarageBand |
|-----|-----------|---------------|
| Kick | C1 (36) | Bass Drum |
| Snare | D1 (38) | Snare Drum |
| Hi-Hat | F#1 (42) | Closed Hi-Hat |
| Tom | C2 (48) | Mid Tom |
| Cymbal | C#2 (49) | Crash Cymbal |

##### Troubleshooting

**No sound:**
- Verify MIDI input is correctly selected in GarageBand preferences
- Serial Monitor should show "Velocity" values when hitting pads
- Make sure track is not Muted or in Solo mode

**Latency:**
- BLE MIDI has low latency (~10ms), but depends on macOS Bluetooth stack
- Try turning off other Bluetooth devices
- For USB MIDI, look into ESP32-C3 USB-MIDI support

**Connection drops:**
- BLE range is 5-10 meters
- Physical obstacles (walls, metal) can weaken signal
- Check power supply if running on battery

---

### Android Connection

#### Overview

On Android, BLE MIDI is supported from **Android 6.0 (API 23)** and above. Google integrated BLE MIDI into the OS starting from Android 6.0.

#### Step 1: Enable Bluetooth

1. **Settings** > **Connections** > **Bluetooth**
2. Turn Bluetooth **On**

#### Step 2: Connecting

**Important**: On Android, BLE MIDI devices don't pair like regular Bluetooth devices. Connection happens within the app.

1. Open your MIDI app (e.g., n-track Studio)
2. Start BLE MIDI scan within the app
3. Select "ESP32-C3-Drum"
4. Wait for connection

> Even if the device appears in Bluetooth settings, you must connect through the app.

#### Using n-track Studio

**n-track Studio** is a powerful free DAW app for Android.

##### Setup

1. Download **n-track Studio** from Google Play Store
2. Open the app
3. Grant required permissions on first launch

##### BLE MIDI Connection

1. In n-track Studio, go to **Settings** > **MIDI**
2. Tap **BLE MIDI Devices**
3. Start scan
4. Select **"ESP32-C3-Drum"**
5. Green indicator shows successful connection

```
n-track Studio - MIDI Settings:
┌─────────────────────────────────────────┐
│  MIDI Settings                           │
│                                         │
│  BLE MIDI Devices:                       │
│  ┌─────────────────────────────────┐    │
│  │ ✅ ESP32-C3-Drum    [Connected] │    │
│  └─────────────────────────────────┘    │
│                                         │
│  MIDI Input: ESP32-C3-Drum              │
│  MIDI Channel: 10 (Drum)                │
└─────────────────────────────────────────┘
```

##### Loading Drum Kit

1. Add a new **Drum Track**
2. **Choose Instrument** > **Drum Kit**
3. Select desired drum preset
4. Hit your pads

##### MIDI Mapping

n-track Studio uses General MIDI drum mapping:

| Pad | MIDI Note | In n-track Studio |
|-----|-----------|-------------------|
| Kick | C1 (36) | Bass Drum |
| Snare | D1 (38) | Snare |
| Hi-Hat | F#1 (42) | Closed Hi-Hat |
| Tom | C2 (48) | Tom |
| Cymbal | C#2 (49) | Crash |

##### Recording

1. Press **Record** button
2. Set tempo (BPM)
3. Hit pads to record drum loop
4. Stop recording and edit

##### Tips

- **Latency**: Reduce latency in **Audio Setup** > **Buffer Size** (128 or 256 samples recommended)
- **Velocity**: Hit pads with different force for dynamic drum recordings
- **Quantize**: Use "Quantize" feature after recording to align hits

#### Other Android Apps

| App | Features | Free |
|-----|----------|------|
| **n-track Studio** | Full DAW, recording, editing | ✅ (Basic) |
| **USB MIDI Player** | Play MIDI files | ✅ |
| **MIDI Connector** | BLE MIDI → USB MIDI converter | ✅ |
| **Caustic 3** | Synth and drum machine | ✅ (Full) |
| **Groovebox** | Beat maker | ✅ (Limited) |

---

### iOS (iPhone / iPad) Connection

> iOS natively supports BLE MIDI.

1. **Settings** > **Bluetooth**
2. Turn Bluetooth on
3. Select "ESP32-C3-Drum" in your app

**Recommended apps:**
- **GarageBand** (Free)
- **Cubasis 3** (Professional DAW)
- **AUM** (Mixer/Router)
- **MIDI Wrench** (MIDI testing tool)

---

### Online Platforms (Platform Independent)

Your ESP32-C3 drum kit works not only with local apps but also with **online DAW** platforms. This allows you to make music directly in your browser without installing any applications.

#### BandLab (bandlab.com)

BandLab is a free online DAW that natively supports BLE MIDI devices.

##### Connection Steps

1. Open the **BandLab app** on your phone or go to **bandlab.com** in your browser
2. Create a new project or open an existing one
3. **BLE MIDI Connection**:
   - **Android**: Start BLE MIDI scan within the app → Select "ESP32-C3-Drum"
   - **iOS**: App auto-detects BLE MIDI → Select "ESP32-C3-Drum"
4. Add a new **Drum** track
5. Test by hitting your pads

```
BandLab - Creating Drum Track:
┌─────────────────────────────────────────┐
│  + Track > Drum > Empty Kit             │
│                                         │
│  MIDI Input: ESP32-C3-Drum              │
│  Channel: 10                            │
└─────────────────────────────────────────┘
```

##### BandLab Tips

- **Drum Presets**: Try "808 Kit", "Acoustic Kit", "Electronic Kit" presets
- **Loop Recording**: Record a loop, then add other tracks
- **Sharing**: Share your projects directly on BandLab

#### Soundtrap (soundtrap.com)

Soundtrap (Spotify's online DAW) also supports BLE MIDI.

1. Go to **soundtrap.com**
2. Create a new project
3. Select "ESP32-C3-Drum" in MIDI keyboard settings
4. Add a drum track and start playing

#### CodePen / Web MIDI API

For developers: You can read MIDI directly in the browser using the Web MIDI API.

```javascript
// Reading ESP32-C3 drum kit with Web MIDI API
navigator.requestMIDIAccess().then(midiAccess => {
  for (const input of midiAccess.inputs.values()) {
    input.onmidimessage = (event) => {
      const [status, note, velocity] = event.data;
      console.log(`Pad: ${note}, Velocity: ${velocity}`);
    };
  }
});
```

> This feature works only in Chrome and Edge browsers. Safari has limited support.

#### Other Online Platforms

| Platform | URL | MIDI Support | Note |
|----------|-----|-------------|------|
| **BandLab** | bandlab.com | ✅ BLE MIDI | Free, mobile + web |
| **Soundtrap** | soundtrap.com | ✅ BLE MIDI | Spotify DAW, paid |
| **Amped Studio** | ampedstudio.com | ✅ Web MIDI | Free trial |
| **AudioTool** | audiotool.com | ⚠️ USB only | Not suitable for Android |
| **Soundation** | soundation.com | ⚠️ Limited | Free plan available |

> **Note**: BLE MIDI support on online platforms depends on the device's operating system. Works directly on macOS and iOS. On Android, in-app BLE MIDI connection is required.

---

### General Troubleshooting

#### Cannot Connect

1. **Ensure ESP32-C3 is powered**: Via USB-C or battery
2. **Advertising mode**: After disconnection, ESP32 re-advertises automatically. Press RESET to restart manually
3. **Range**: Stay within 5-10 meters
4. **Obstacles**: Walls and metal surfaces weaken BLE signal
5. **Other devices**: Disconnect previous Bluetooth MIDI connections

#### No Sound

1. **MIDI channel**: Drums typically use **MIDI Channel 10**. Code is configured correctly (Channel 10 / 0x99)
2. **Velocity**: Very light hits may not be detected. Try medium force
3. **MIDI notes**: Ensure your app supports General MIDI drum mapping

#### Latency Issues

- BLE MIDI has ~10ms native latency
- On macOS/iOS this is usually not an issue
- On Android, some devices may show 20-30ms
- For low latency:
  - Turn off other Bluetooth devices
  - Reduce buffer size in app settings
  - Disable WiFi (2.4GHz interference)
