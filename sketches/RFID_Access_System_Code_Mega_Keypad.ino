// Keypad - Version: Latest 
// Keypad - Version: 3.1.1
#include <Keypad.h>

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 String uid[] = {"7B 90 4E 39", "7C 5A 0D D2"};
 String pins[] = {"7B90","7C5A"};
 
 int blu = 5;
 int grn = 3;
 int red = 2;
 int buzzer = 4;
 
 byte rowPins[4] = {22,23,24,25};
 byte colPins[4] = {26,27,28,29};
 
 char keymap[4][4] {
   {'1','2','3','A'},
   {'4','5','6','B'},
   {'7','8','9','C'},
   {'*','0','#','D'}
 };
 
 Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
 
void setup() 
{
  pinMode(red, OUTPUT);
  pinMode(blu, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader, or press the \'#\' button on the keypad to enter a PIN");

}
void loop() 
 {
 // Serial.println(digitalRead(btn));
 if(keypad.getKey() == '#') {
   Serial.print("Enter PIN (End with \'#\'): ");
   int pinLength = 0;
   String pin = "";
   while(keypad.getKey() != '#') {
     if(pinLength == 4) break;
     if(keypad.getKey() != NO_KEY) {
       pin += keypad.getKey();
       pinLength++;
       
     } 
   }
   bool keyFlag = false;
   for(int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
     if(pin == pins[i]) {
        Serial.println("Authorized access");
      digitalWrite(blu,LOW);
      digitalWrite(grn, HIGH);
      tone(buzzer,800);
      delay(2000);
      noTone(buzzer);
      digitalWrite(blu,HIGH);
      digitalWrite(grn, LOW);
      Serial.println();
      keyFlag = true;
       Serial.println("Approximate your card to the reader...");
      break;
     }
   }
   if(!keyFlag) {
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
      Serial.println("Approximate your card to the reader, or press the \'#\' button on the keypad to enter a PIN");
   }
 }
 else if(keypad.getKey() == NO_KEY) {
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
       Serial.println("Approximate your card to the reader, or press the \'#\' button on the keypad to enter a PIN");
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
      Serial.println("Approximate your card to the reader, or press the \'#\' button on the keypad to enter a PIN");
   }
 }
  
} 
