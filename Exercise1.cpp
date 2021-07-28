#include <Servo.h>
Servo myservo; // 建立一個 servo
#define photocellPin A2 //定義光敏電阻 (photocell) 腳位
int photocellVal = 0; // photocell variable
int minLight = 100;   // 最小光線門檻值
int pos = 0; // 設定 Servo 角度的變數
int reset = 0; 
int flag = 0 ; // 判斷順時轉(0)、逆時轉(1)的旗幟

void setup() {
  Serial.begin(9600);
  myservo.attach(9); // 將 servo 物件連接到 pin 9
  myservo.write(reset); // reset 至 0 度
}

void loop() {
  Serial.println(/*photocellVal*/pos); // 可監控亮度值or角度
  photocellVal = analogRead(photocellPin); // 讀取亮度值
  if(photocellVal < minLight){
      if(flag == 0){
          pos++;
          myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
          delay(5); // 等待 5ms 讓 servo 走到指定位置
          if(pos == 180) // 角度++到180度時，改逆時針轉
              flag = 1 ;
      }
      if(flag == 1){
          pos--;
          myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
          delay(5); // 等待 5ms 讓 servo 走到指定位置
          if(pos == 0) // 角度--到0度時，改順時針轉
              flag = 0 ;
      }
  }
}
