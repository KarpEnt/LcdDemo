# LcdDemo
Sample code to test usage of LiquidCristal library for **LM060L** 2x24 character display.

Other names for **LM060L** display: 
- UC-242-04GNAR 
- LM2227A2C24S 
- EA-D24025AR-S 
- HDM-24216H


###### Pin Connections
| Display Pin # | Arduino Yun Pin Name | Description |
| --- | --- | --- |
| 1 | GND | Vss, 0V Power supply |
| 2 | +5 | Vcc, +5V Power supply |
| 3 | GND | VL, Display brightness |
| 4 | Digital 8 | RS, H: Data input, L: Instruction data input |
| 5 | Digital 9 | R/W, H: Data read, L: Data write |
| 6 | Digital 10 | E, H,H->L Enable signal |
| 7 | Digital 0 | D0 Data bus (Not connected in 4-bit mode) |
| 8 | Digital 1 | D1 Data bus (Not connected in 4-bit mode) |
| 9 | Digital 2 | D2 Data bus (Not connected in 4-bit mode) |
| 10 | Digital 3 | D3 Data bus (Not connected in 4-bit mode) |
| 11 | Digital 4 | D4 Data bus |
| 12 | Digital 5 | D5 Data bus |
| 13 | Digital 6 | D6 Data bus |
| 14 | Digital 7 | D7 Data bus |


###### Initialization for 4-bit mode :
```C
LiquidCrystal lcd(8, 9, 10, 4, 5, 6, 7);
```

###### Initialization for 8-bit mode :
```C
LiquidCrystal lcd(8, 9, 10, 0, 1, 2, 3, 4, 5, 6, 7);
```