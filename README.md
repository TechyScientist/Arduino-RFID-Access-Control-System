# Arduino RFID Access Control System
## Created by Johnny Console, 2019.

#### The Sketches
1) RFID_Access_System_Code -> Initial build, built for Arduino Uno Boards
This sketch simply includes three LEDs for status indication. There are only enough pind on the Arduino Uno for the RFID reader, LEDs and buzzer, so the keypad option wasn;t an option for this sketch. To assemble, gather the following parts:
 * 1x arduino Uno (or compatable) board
 * 1x large bradboard
 * 1x MFRC-522 RFID module
 * 1x Blue LED
 * 1x Red LED
 * 1x Green LED
 * 3x 220 ohm Resistors
 * 1x Active Buzzer (or Piezo Buzzer)
 * Several Male-To-Male Jumper wires of assorted colours and lengths
  
   Connect the components according to the RFID Control System Schematic.png file
   
   This sketch will also work with the Arduino Mega board, as seen in the RFID Control System Schematic - Mega No Keypad.png file.

2) RFID_Access_System_Code_Mega_Keypad -> Advanced build, built for Arduino Mega boards ONLY
This sketch takes the previous sketch and adds a keypad input to it for either swipe access or PIN access to the system. To assemble, gather the following parts:
 * 1x arduino Mega (or compatable) board
 * 1x large bradboard
 * 1x MFRC-522 RFID module
 * 1x 4x4 Membrane keypad
 * 1x Blue LED
 * 1x Red LED
 * 1x Green LED
 * 3x 220 ohm Resistors
 * 1x Active Buzzer (or Piezo Buzzer)

   Connect the components according to the RFID Control System Schematic - Mega Keypad.png file.
#### Usage
For each board, assemble the corresponding circuit, and ipload the following files to the board:

| Board | Build | Sketch File |
| ------- | ------- | ------------- |
Arduino Uno | RFID Access System | RFID_Access_System_Code.ino |
Arduino Mega | RFID Access System (No Keypad) | RFID_Access_System_Code.ino |
|| RFID Access System (With Keypad) | RFID_Access_System_Code_Mega_Keypad.ino |

#### Required Libraries
You will neeed the following libraries, depending on which sketch you are using:

| Sketch | Libraries Required |
---------|---------------------
Access Control System (Without Keypad) | RFID Library |
Access Control System (With Keypad) | RFID Library and Keypad Library |

The libraries can be downloaded from the libraries/ folder.
