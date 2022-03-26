# Barcode Reader
A barcode consists of 12 data frames with a guard frame on each side, to help locate a barcode
within an image, for easier processing. This program assumes each guard frame will be the three
binary bits: `101`.

Each of the 12 data frames excode a number between 0-9 which can be used to uniquely identitfy
each barcode. The data frames are organised with an alignment marker on either side to allow the 
reader to read an upsidedown barcode. The digit from 0-9 is found after merging the `MSB` and `LSB`.
Both the `MSB` and `LSB` have their own even parity bit for error checking.

<img src = "https://static.au.edusercontent.com/files/KvL5qk8AF7ysh19fpbWud2Gy" alt="barcode image">

## Input
The program receives a bitmap file as a command line argument with an optional `-d` for diagnostic mode.
Input validation is done within the program to ensure a file has been passed or is successfully opened.

If diagnostic mode is invoked with the `-d` flag, the bitmap files width and height is output and the
program ends. If not, the program enteres `Scanning Mode` where the encoded number is read and returned
as output.

If a frame is unable to be read, the program returns which frames are unable to be read and ends.

## Code References
Code found in `functions.c` and `main.c` are of my own work, with functions found in `bitmap.c` and
the makefile being someone elses.
