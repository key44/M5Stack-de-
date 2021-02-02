#include <M5stack.h>
#include <Arduino.h>
#include <Wire.h>
#include <time.h>
#include <WiFi.h>

WiFiClient client; //WiFiオブジェクト定義

//WiFiのssidとpasswordを設定
const char *ssid = "ssid";
const char *password = "password";

//タイムサーバーの設定
const char *ntpServer = "ntp.jst.mfeed.ad.jp"; // NTPサーバのURL
const long gmtOffset_sec = 9 * 3600;           //  GMT+9(日本時間)
const int daylightOffset_sec = 0;              // サマータイム時差(無し)

int i = 0;
uint16_t x = 0;
uint16_t y = 0;
uint16_t x1 = 0;
uint16_t ya = 0;
uint16_t x2 = 0;
uint16_t y2 = 0;
uint16_t x3 = 0;
uint16_t y3 = 0;

void setup()
{
  M5.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) //  Wi-Fi AP接続待ち
  {
    while (i == 120) //20秒立ってもwifiに接続されない場合10秒間隔でエラー表示
    {
      M5.Lcd.println(".");
      M5.Lcd.setTextColor(RED);
      M5.Lcd.setTextSize(4);
      M5.Lcd.println("ERRER: wifi don't conect");
      M5.Lcd.printf("Please reset");
      Serial.println("ERRER: wifi don't conect");
      Serial.println("Please reset");
      delay(100000);
    }
    delay(500);
    M5.Lcd.setTextSize(2);
    M5.Lcd.printf(".");
    Serial.printf(".");
    i++;
  }
  i = 0;

  if (WiFi.status() == WL_CONNECTED)
  {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    struct tm t;
    if (!getLocalTime(&t))
    {
      M5.Lcd.printf("Time error");
      delay(100000);
    }
  }

  M5.Lcd.print("WiFi connected\r\nIP address: ");
  M5.Lcd.println(WiFi.localIP());
  Serial.print("WiFi connected\r\nIP address: ");
  Serial.println(WiFi.localIP());
  delay(2000);
  M5.Lcd.clear();
}

void timer()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    M5.Lcd.println("Failed to obtain time");
    return;
  }

  int m10 = timeinfo.tm_min / 10;
  int m1 = timeinfo.tm_min - m10 * 10;
  int h10 = timeinfo.tm_hour / 10;
  int h1 = timeinfo.tm_hour - h10 * 10;

  switch (m1)
  {
  case 0:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/000o.jpg", x, y);
    break;
  case 1:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0001.jpg", x, y);
    break;
  case 2:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0002.jpg", x, y);
    break;
  case 3:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0003.jpg", x, y);
    break;
  case 4:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0004.jpg", x, y);
    break;
  case 5:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0005.jpg", x, y);
    break;
  case 6:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0006.jpg", x, y);
    break;
  case 7:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0007.jpg", x, y);
    break;
  case 8:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0008.jpg", x, y);
    break;
  case 9:
    x = 240;
    y = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0009.jpg", x, y);
    break;

  default:
    break;
  }

  switch (m10)
  {
  case 0:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/00o0.jpg", x1, ya);
    break;
  case 1:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0010.jpg", x1, ya);
    break;
  case 2:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0020.jpg", x1, ya);
    break;
  case 3:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0030.jpg", x1, ya);
    break;
  case 4:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0040.jpg", x1, ya);
    break;
  case 5:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0050.jpg", x1, ya);
    break;
  case 6:
    x1 = 160;
    ya = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0060.jpg", x1, ya);
    break;

  default:
    break;
  }

  switch (h1)
  {
  case 0:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0o00.jpg", x2, y2);
    break;
  case 1:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0100.jpg", x2, y2);
    break;
  case 2:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0200.jpg", x2, y2);
    break;
  case 3:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0300.jpg", x2, y2);
    break;
  case 4:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0400.jpg", x2, y2);
    break;
  case 5:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0500.jpg", x2, y2);
    break;
  case 6:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0600.jpg", x2, y2);
    break;
  case 7:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0700.jpg", x2, y2);
    break;
  case 8:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0800.jpg", x2, y2);
    break;
  case 9:
    x2 = 80;
    y2 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/0900.jpg", x2, y2);
    break;

  default:
    break;
  }

  switch (h10)
  {
  case 0:
    x3 = 0;
    y3 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/o000.jpg", x3, y3);
    break;
  case 1:
    x3 = 0;
    y3 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/1000.jpg", x3, y3);
    break;
  case 2:
    x3 = 0;
    y3 = 0;
    M5.Lcd.drawJpgFile(SD, "/nixie/2000.jpg", x3, y3);
    break;

  default:
    break;
  }
}

void loop()
{
  timer();
  delay(300);
}