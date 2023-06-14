#include <LiquidCrystal.h>
#include <DHT.h>

int sensor = 0;
int vee_lcd = 13;
int rs_lcd = 12;
int e_lcd = 11;
int d4_lcd = 9;
int d5_lcd = 8;
int d6_lcd = 7;
int d7_lcd = 6;
int temp;
int humedad;
String mensaje1 = "Mensaje UNO";
String mensaje2 = "Mensaje DOS";

DHT dht(sensor, DHT11);
LiquidCrystal lcd(rs_lcd, e_lcd, d4_lcd, d5_lcd, d6_lcd, d7_lcd);
void setup() {
  dht.begin();
  lcd.begin(16, 2);
  analogWrite(vee_lcd, 50);
}

void loop() {
  int tam = mensaje1.length();
  int tam2 = mensaje2.length();
  humedad = dht.readHumidity();
  temp = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humedad);
  lcd.print("%");
  delay(4000);

  for(int i = 1; i <= tam; i++)
  {
    String texto = mensaje1.substring(i - 1);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(texto);

    delay(182);        
  }

  for(int i = 1; i <= tam2; i++)
  {
    String texto2 = mensaje2.substring(i - 1);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(texto2);

    delay(200);        
  }
}
