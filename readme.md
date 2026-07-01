# 個人制作プロジェクト

[概要](https://github.com/nRen28/GraduationProject_vsShooting#概要)

## 概要

本プロジェクトはマイコンのArduino UNO R4 Wifiで製作する木管型の電子楽器です。

### 主な特徴

- 1オクターブ12音×2の切り替えが可能
- 2オクターヴの音域を出すことが可能
- 楽器に息を入れる事で音の出力をする
- 息の量によって音量の調整が可能
- 音の出力にはパッシブブザーを採用
- スイッチの配線はラダー型回路を採用
- 空気圧の検知にはSTEMMA QT/Qwiic互換 LPS33HW搭載 防水圧力センサを採用
- タンギングなどの細かい息の量の変化にも対応

## 構成

### ハードウェア構成

#### 使用パーツ

| 部品名 | 数量 | 備考 |
| ------ | ------ | ------ |
| Arduino UNO R4 WiFi | 1 | |
| ブレッドボード | 3 | うち1つはオクターブキー用に反対につける |
| 空気圧センサー | 1 | 防水機能あり |
| チューブ | 1 | 60cm程で直径は3cm |
| パッシブブザー | 1 | |
| オクターブキー | 1 | タクトスイッチ |
| タクトスイッチ | 12 | 柔らかいタクトスイッチを採用 |
| サランラップの棒 | 1 | 基盤やスイッチなどをこちらに貼り付ける |
| ジャンプワイヤー | 沢山 | およそ20本ほど |

### 配線図

空気圧センサーをRFIDで代用している。
![alt text](image.png)

### 使用ライブラリ

```c
#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
```

### ソースコード

```cpp
#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#include <Adafruit_LPS35HW.h>

Adafruit_LPS35HW lps35hw = Adafruit_LPS35HW();

// For SPI mode, we need a CS pin
#define LPS_CS 10
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LPS_SCK 13
#define LPS_MISO 12
#define LPS_MOSI 11

const int SENSOR_PIN = A0;
const int BUZZ_PIN = 8;
void setup()
{
    Serial.begin(115200);
    pinMode(BUZZ_PIN, OUTPUT);
    pinMode(SENSOR_PIN, INPUT);
}

void loop()
{
    int value = analogRead(SENSOR_PIN);
    Serial.println(value);

    if (1020 < lps35hw.readPressure())
    {
        if ((value >= 1000) && (1024 >= value))
        {
            buzzSound(NOTE_A4);
        }
        else if ((value >= 850) && (890 >= value))
        {
            buzzSound(NOTE_GS4);
        }
        else if ((value >= 725) && (750 >= value))
        {
            buzzSound(NOTE_G4);
        }
        else if ((value >= 625) && (650 >= value))
        {
            buzzSound(NOTE_F4);
        }
        else if ((value >= 540) && (580 >= value))
        {
            buzzSound(NOTE_FS4);
        }
        else if ((value >= 460) && (525 >= value))
        {
            buzzSound(NOTE_DS4);
        }
        else if ((value >= 400) && (450 >= value))
        {
            buzzSound(NOTE_E4);
        }
        else if ((value >= 340) && (380 >= value))
        {
            buzzSound(NOTE_D4);
        }
        else if ((value >= 290) && (335 >= value))
        {
            buzzSound(NOTE_C4);
        }
        else if ((value >= 230) && (280 >= value))
        {
            buzzSound(NOTE_CS4);
        }
        else if ((value >= 180) && (200 >= value))
        {
            buzzSound(NOTE_AS3);
        }
        else if ((value >= 110) && (165 >= value))
        {
            buzzSound(NOTE_B3);
        }
        else
        {                     // 何も押されてない時
            noTone(BUZZ_PIN); // 消音
        }
        delay(100);
    }
}

void buzzSound(int frequency)
{
    tone(BUZZ_PIN, frequency); // 音を鳴らす
    delay(50);
}
```

## フローチャート

```mermaid
flowchart TD;
    a([デバイスの起動])-->初期化;
    初期化-->id1{オクターヴキー};
    息を入れる-->音が出力される;
    音が出力される-->スイッチによって出す音を変える;
    スイッチによって出す音を変える-->息を入れる;
    id1{オクターヴキー}--押す-->オクターヴが上になる;
    id1{オクターヴキー}--押さない-->そのままのオクターヴ
    オクターヴが上になる-->スイッチによって出す音を変える;
    そのままのオクターヴ-->スイッチによって出す音を変える;
```

## 参考サイト・参考動画

- [【永久保存版】はんだ付けのやり方を解説します【はんだづけの原理, DIP部品, 表面実装】【イチケン電子基礎シリーズ】RX-802AS](https://www.youtube.com/watch?v=dQ7AUjb1tkA)
- [電子工作初心者が電子楽器を作ってみた](https://zenn.dev/fxxxxxrest/articles/d6195045540d3d)
- [楽しい電子管楽器の作り方](https://zenn.dev/fxxxxxrest/articles/d6195045540d3d)
- [ESP32マイコンで電子リコーダーを作る](https://coderdojo-gifu.org/blog/2024/01/making-an-electronic-recorder-with-an-arduinoesp32-microcontroller-03)
