# Arduino RFID Access Control System
###### Created by Johnny Console, 2019

## The Sketches
Included in this repository are five sketch files, outlined below. The sketch file to use depends on what board you will be usinf (Arduino Uno (or compatable) or Arduino Mega (or compatable).

| Board | Button? | Keypad? | RGB? | Sketch File |
| ------- | --------- | --------- | ------ | ------------- |
| Arduino Uno | Yes | No | No | [sketches/RFIDAccessSystemCodeRegular.ino](sketches/RFIDAccessSystemCodeRegular.ino) |
| | No | No | Yes | [sketches/RFIDAccessSystemCodeRegularRGB.ino](sketches/RFIDAccessSystemCodeRegularRGB.ino) |
| | Yes | No | Yes | [sketches/RFIDAccessSystemCodeRegularRGBButton.ino](sketches/RFIDAccessSystemCodeRegularRGBButton.ino) |
| Arduino Mega | Yes | No | No | [sketches/RFIDAccessSystemCodeRegular.ino](sketches/RFIDAccessSystemCodeRegular.ino) |
| | No | No | Yes | [sketches/RFIDAccessSystemCodeRegularRGB.ino](sketches/RFIDAccessSystemCodeRegularRGB.ino) |
| | Yes | No | Yes | [sketches/RFIDAccessSystemCodeRegularRGBButton.ino](sketches/RFIDAccessSystemCodeRegularRGBButton.ino) |
| | Yes | Yes | No | [sketches/RFIDAccessSystemCodeMegaKeypad.ino](sketches/RFIDAccessSystemCodeMegaKeypad.ino) |
| | Yes | Yes | Yes | [sketches/RFIDAccessSystemCodeKeypadRGBBut.ino](sketches/RFIDAccessSystemCodeKeypadRGBBut.ino) |

## The Schematics - Fritzing Files
The schematic diagrams for these were made with Fritzing. The Fritzing files can be found inside the [schematics-fritzing/](schematics-fritzing/) folder.

## The Schematics - PNG Files
There are also PNG images of the schematics available in the [schematics-png/](schematics-png/) folder.

## Libraries
There are two libraries used in this project: Keypad and RFID. The files for both of these libraries are located in the [libraries/](libraries/) folder.

## Usage
1) Determine the board and project you will use. This also determines the components, the schematics, and the sketch that you will use.
2) Download the libraries required. RFID is required for all projects, but Keypad is only required for projects that use a keypad.
3) Gather parts and assemble the circuit.
4) You may need to change some pin numbers if I forgot to add them.
5) Flash the arduino with the appropriate code.
6) You can see output on both the Serial Monitor (text) and the LED(s) on the breadboard.

## Allowing More RFID Cards, FOBs or PINs
To allow more cards or FOBs, simply enter their hexadecimal UID (can be retreived from the Serial Monitor) into the array of uids at the top of the sketch and upload to the arduino. Include all spaces, and all letters must be in capitals.

To allow more PINs (systems with a keypad only), add the PIN to the array at the top of the sketch. PINs are 4 digits, with no spaces and all letters in capitals.
