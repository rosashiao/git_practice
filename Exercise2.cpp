#define LED 6 
#define buzzer 5 
#define threshold 10// 容許誤差值(error)
int r = random(0, 255); // 0-255間取一數字

void setup() {
  pinMode(LED,OUTPUT); // 定義LED腳位
  pinMode(buzzer,OUTPUT); // 定義buzzer 腳位
}

void loop() {
  int pwm = analogRead(A0)/4;  // 讀取A0腳位的值(範圍0-1023)，pwm(範圍0-255)
  if (abs(pwm-r) < threshold){  // abs取絕對值
      tone(buzzer,523); // buzzer發聲
      delay(2000); // 持續2秒
      r = random(0, 255); // 重取隨機數
  }
  else{
      noTone(buzzer); //  buzzer不發聲
  } 
  analogWrite(LED,255-abs(r-pwm)); // 越靠近隨機數Led越亮 
}
