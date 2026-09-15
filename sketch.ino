#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct Lirik {
    String teks;
    int speed;
    int jeda;
};

Lirik lagu[] = {
  {"You know its true", 120, 2100}, #yang 120 itu kecepatan teksnya kalo yang 2100 itu jeda nya
  {"Yeah I miss you", 120, 1500},
  {"You know its true", 120, 3000},
  {"So what if I call", 100, 1600},
  {"And you pick up the phone", 90, 2500},
  {"And I use this holiday to make my way to your ghost", 90, 2900} ,
  {"Oh what if youre lonely", 120, 2500},
};

int jumlahBaris = sizeof(lagu) / sizeof (lagu[0]);
int lcdCols = 16;

void setup() {
    lcd.init();
    lcd.backlight();
}

  void tampilBaris(String teks, int baris, int speed) {
      lcd.setCursor(0, baris);
      lcd.clear();

      if (teks.length() <= lcdCols) {

          for (int i = 0; i < teks.length(); i++) {
              lcd.print(teks[i]);
              delay(speed);
          }

      } else {

          for (int i = 0; i < lcdCols; i++) {
              lcd.print(teks[i]);
              delay(speed);
          }

          for (int i = 1; i <= teks.length() - lcdCols; i++) {
              lcd.setCursor(0, baris);
              lcd.print(teks.substring(i, i + lcdCols));
              delay(speed);
          }
      }
  }

  void loop() {
      for (int i = 0; i < jumlahBaris; i++) {
          tampilBaris(lagu[i].teks, 0, lagu[i].speed);
          delay(lagu[i].jeda);
          lcd.clear();
      }
  }

#created By Adiwangsa Cihuyyy
