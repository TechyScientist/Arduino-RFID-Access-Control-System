#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 String uid[] = {"7B 90 4E 39", "7C 5A 0D D2"};
 
 int blu = 12;
 int grn = 3;
 int red = 2;
 int buzzer = 4;
 int button = 0;
 
void setup() 
{
  pinMode(red, OUTPUT);
  pinMode(blu, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");

}
void loop() 
 {
    if(digitalRead(button) == HIGH) {
    Serial.println("Authorized access");
       digitalWrite(blu,LOW);
    digitalWrite(grn, HIGH);
    tone(buzzer,800);
    delay(2000);
    noTone(buzzer);
    digitalWrite(blu,HIGH);
    digitalWrite(grn, LOW);
      Serial.println();
      Serial.println("Approximate your card to the reader...");
      return;
  }
 // Serial.println(digitalRead(btn));
  digitalWrite(blu,HIGH);
 
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
    digitalWrite(blu,LOW);
    digitalWrite(grn, HIGH);
    tone(buzzer,800);
    delay(2000);
    noTone(buzzer);
    digitalWrite(blu,HIGH);
    digitalWrite(grn, LOW);
    Serial.println();
    flag = true;
     Serial.println("Approximate your card to the reader...");
    break;
  }
  }
 
 
if(!flag)   {

    Serial.println(" Access denied");
      digitalWrite(blu,LOW);
    digitalWrite(red, HIGH);
    tone(buzzer,1000);
    delay(300);
    noTone(buzzer);
     tone(buzzer,800);
    delay(300);
    noTone(buzzer);                                                                                                                                                                
    digitalWrite(blu,HIGH);
    digitalWrite(red, LOW);
    Serial.println();
    Serial.println("Approximate your card to the reader...");
 }
  
} 
