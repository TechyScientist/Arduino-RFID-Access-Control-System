#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 5
#define RST_PIN 53

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 String uid[] = {"7B 90 4E 39", "7C 5A 0D D2"};
 
 int ledRed = ;
 int ledGreen = 6;
 int ledBlue = 7;
 int buzzer = 4;
 int button = 8;
 
void setup() 
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");

}
void loop() {
  if(digitalRead(button) == HIGH) {
    Serial.println("Authorized access");
      RGBWrite(0,255,0);
      tone(buzzer,800);
      delay(2000);
      noTone(buzzer);
      RGBWrite(0,0,255);
      Serial.println();
      Serial.println("Approximate your card to the reader...");
      return;
  }
RGBWrite(0,0,255);
   
    // Look for new cards
   
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return;
    }
    //Show UID on serial monitor
    Serial.print("UID tag :");
    String content= "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
       Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
       Serial.print(mfrc522.uid.uidByte[i], HEX);
       content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
       content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();
    bool flag = false;
    for(int i = 0; i < (sizeof(uid)/sizeof(uid[0]));i++) {
    if (content.substring(1) == uid[i]) //change here the UID of the card/cards that you want to give access
    {
      
      Serial.println("Authorized access");
      RGBWrite(0,255,0);
      tone(buzzer,800);
      delay(2000);
      noTone(buzzer);
      RGBWrite(0,0,255);
      Serial.println();
      flag = true;
      Serial.println("Approximate your card to the reader");
      break;
    }
    }
   
   
  if(!flag)   {
      Serial.println(" Access denied");
       RGBWrite(255,0,0);
      tone(buzzer,1000);
      delay(300);
      noTone(buzzer);
       tone(buzzer,800);
      delay(300);
      noTone(buzzer);                                                                                                                                                                
      RGBWrite(0,0,255);
      Serial.println();
      Serial.println("Approximate your card to the reader");
   }
 }
 
 void RGBWrite(int r, int g, int b) {
   analogWrite(ledRed, r);
   analogWrite(ledGreen, g);
   analogWrite(ledBlue, b);
 }