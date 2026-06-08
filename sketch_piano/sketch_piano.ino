//当Webサイトに掲載された内容によって生じた損害等の一切の責任を負いません。
//当webサイトの免責事項に同意いただける場合に限り、プログラムをご利用いただけます。
//ライブラリTonePitch by Rodrigoのインストールが必要です。

//ヘッダーファイルの読み込み
#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>

//スイッチのピン番号
#define SW_C4 2   //ド
#define SW_D4 3   //レ
#define SW_E4 4   //ミ
#define SW_F4 5   //ファ
#define SW_G4 6   //ソ
#define SW_A4 7   //ラ
#define SW_B4 8   //シ
#define SW_C5 9   //（高い）ド

#define BUZZ_PIN 10 //ブザーのピン

void setup() {
  pinMode( SW_C4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_D4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_E4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_F4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_G4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_A4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_B4, INPUT_PULLUP );    //入力ピンに設定
  pinMode( SW_C5, INPUT_PULLUP );    //入力ピンに設定
  pinMode( BUZZ_PIN, OUTPUT );    //出力ピンに設定
}

void loop() {
  if(digitalRead(SW_C4)==LOW){  //ドが押された時
    buzzSound(NOTE_C4);
  }
  else if(digitalRead(SW_D4)==LOW){ //レが押された時
    buzzSound(NOTE_D4);
  }
  else if(digitalRead(SW_E4)==LOW){ //ミが押された時
    buzzSound(NOTE_E4);
  }
  else if(digitalRead(SW_F4)==LOW){ //ファが押された時
    buzzSound(NOTE_F4);
  }
  else if(digitalRead(SW_G4)==LOW){ //ソが押された時
    buzzSound(NOTE_G4);
  }
  else if(digitalRead(SW_A4)==LOW){ //ラが押された時
    buzzSound(NOTE_A4);
  }
  else if(digitalRead(SW_B4)==LOW){ //シが押された時
    buzzSound(NOTE_B4);
  }
  else if(digitalRead(SW_C5)==LOW){ //高いドが押された時
    buzzSound(NOTE_C5);
  }
  else{   //何も押されてない時
    noTone(BUZZ_PIN);   //消音
  }
}

//音を鳴らす関数
void buzzSound(int frequency){
  tone(BUZZ_PIN, frequency);  //音を鳴らす
  delay(50);
}