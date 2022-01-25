EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Motor:Motor_Servo M?
U 1 1 61F03EE0
P 8675 2900
F 0 "M?" H 9007 2965 50  0000 L CNN
F 1 "Motor_Servo" H 9007 2874 50  0000 L CNN
F 2 "" H 8675 2710 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 8675 2710 50  0001 C CNN
	1    8675 2900
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M?
U 1 1 61F0532A
P 8700 3600
F 0 "M?" H 9032 3665 50  0000 L CNN
F 1 "Motor_Servo" H 9032 3574 50  0000 L CNN
F 2 "" H 8700 3410 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 8700 3410 50  0001 C CNN
	1    8700 3600
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 61F05B55
P 3650 3750
F 0 "A?" H 3650 4931 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 3650 4840 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 3800 2700 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 3450 4800 50  0001 C CNN
	1    3650 3750
	-1   0    0    -1  
$EndComp
$Comp
L payload2022_custom:OrangeRX U?
U 1 1 61F0D18E
P 6300 750
F 0 "U?" H 8228 163 50  0000 L CNN
F 1 "OrangeRX" H 8228 72  50  0000 L CNN
F 2 "" H 6300 750 50  0001 C CNN
F 3 "" H 6300 750 50  0001 C CNN
	1    6300 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT?
U 1 1 61F11BC6
P 3050 1575
F 0 "BT?" H 3168 1671 50  0000 L CNN
F 1 "Battery_Cell" H 3168 1580 50  0000 L CNN
F 2 "" V 3050 1635 50  0001 C CNN
F 3 "~" V 3050 1635 50  0001 C CNN
	1    3050 1575
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT?
U 1 1 61F120D4
P 3050 1275
F 0 "BT?" H 3168 1371 50  0000 L CNN
F 1 "Battery_Cell" H 3168 1280 50  0000 L CNN
F 2 "" V 3050 1335 50  0001 C CNN
F 3 "~" V 3050 1335 50  0001 C CNN
	1    3050 1275
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT?
U 1 1 61F12BAB
P 3050 975
F 0 "BT?" H 3168 1071 50  0000 L CNN
F 1 "Battery_Cell" H 3168 980 50  0000 L CNN
F 2 "" V 3050 1035 50  0001 C CNN
F 3 "~" V 3050 1035 50  0001 C CNN
	1    3050 975 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 61F13727
P 3050 775
F 0 "#PWR?" H 3050 625 50  0001 C CNN
F 1 "+12V" H 3065 948 50  0000 C CNN
F 2 "" H 3050 775 50  0001 C CNN
F 3 "" H 3050 775 50  0001 C CNN
	1    3050 775 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61F13DAE
P 3050 1675
F 0 "#PWR?" H 3050 1425 50  0001 C CNN
F 1 "GND" H 3055 1502 50  0000 C CNN
F 2 "" H 3050 1675 50  0001 C CNN
F 3 "" H 3050 1675 50  0001 C CNN
	1    3050 1675
	1    0    0    -1  
$EndComp
$Comp
L payload2022_custom:HK-30A-ESC J?
U 1 1 61F1652F
P 4500 850
F 0 "J?" H 4600 925 50  0000 C CNN
F 1 "HK-30A-ESC" H 4600 834 50  0000 C CNN
F 2 "" H 4500 850 50  0001 C CNN
F 3 "" H 4500 850 50  0001 C CNN
	1    4500 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 800  4050 1100
Wire Wire Line
	3050 1650 4050 1650
Wire Wire Line
	4050 1650 4050 1200
Text Notes 3875 775  0    50   ~ 10
XT60
Wire Wire Line
	5150 1000 5750 1000
Wire Wire Line
	5150 1100 5750 1100
Wire Wire Line
	5150 1200 5750 1200
Text Notes 5275 975  0    50   ~ 10
Dupont
NoConn ~ 4250 1800
NoConn ~ 4350 1800
NoConn ~ 4450 1800
Text Notes 4050 1925 0    50   ~ 10
3.5mm Bullet Plugs
Wire Wire Line
	3050 1650 3050 1675
Connection ~ 3050 1675
Wire Wire Line
	3050 800  3050 775 
Connection ~ 3050 775 
Wire Wire Line
	3750 2775 3750 2750
Wire Wire Line
	3050 800  3750 800 
Connection ~ 3750 800 
Wire Wire Line
	3750 800  4050 800 
Connection ~ 3750 2750
Wire Wire Line
	3750 2750 3750 800 
Text Notes 3825 2225 3    50   ~ 10
Barrel
$Comp
L power:GND #PWR?
U 1 1 61F1C8A7
P 3550 5000
F 0 "#PWR?" H 3550 4750 50  0001 C CNN
F 1 "GND" H 3555 4827 50  0000 C CNN
F 2 "" H 3550 5000 50  0001 C CNN
F 3 "" H 3550 5000 50  0001 C CNN
	1    3550 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4850 3550 5000
$EndSCHEMATC
