#include <LiquidCrystal.h> 
#include <SoftwareSerial.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

SoftwareSerial mySerial(9, 10);

int gasValue = A0; // smoke / gas sensor connected with analog pin A1 of the arduino / mega.
int data = 0;

void setup()
{
randomSeed(analogRead(0));
Serial.begin(9600); // Setting the baud rate of GSM Module 
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
lcd.begin(16,2); 
pinMode(gasValue, INPUT); 
lcd.print (" Gas Leakage "); 
lcd.setCursor(0,1);
lcd.print (" Detector Alarm "); 
delay(3000);
lcd.clear();
}

void loop()
{
 
data = analogRead(gasValue);
Serial.print("Gas Level: "); 
Serial.println(data);
lcd.print ("Gas Scan is ON"); 
lcd.setCursor(0,1); 
lcd.print("Gas Level: "); 
lcd.print(data);
delay(1000);

if ( data > 170) //
{
SendMessage(); 
Serial.print("Gas detect alarm"); 
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("Gas Level Exceed"); 
lcd.setCursor(0,1); 
lcd.print("SMS Sent"); 
delay(1000);

}
else
{
Serial.print("Gas Level Low"); 
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("Gas Level Normal"); 
delay(1000);
}

lcd.clear();
}
void SendMessage()
{
Serial.println("I am in send mode ");
Serial.println("AT+CMGF=1");
delay(1000); // Delay of 1000 milli seconds or 1 second
Serial.println("AT+CMGS=\"+916354669986\"\r");
delay(1000);
Serial.println("Excess Gas Detected. Open Windows");
delay(100);
Serial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
