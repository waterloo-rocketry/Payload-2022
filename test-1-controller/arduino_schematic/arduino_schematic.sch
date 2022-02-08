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
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 61F05B55
P 3650 3750
F 0 "A1" H 3650 4931 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 3650 4840 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 3800 2700 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 3450 4800 50  0001 C CNN
	1    3650 3750
	-1   0    0    -1  
$EndComp
$Comp
L payload2022_custom:OrangeRX U2
U 1 1 61F0D18E
P 6300 750
F 0 "U2" H 8228 163 50  0000 L CNN
F 1 "OrangeRX" H 8228 72  50  0000 L CNN
F 2 "" H 6300 750 50  0001 C CNN
F 3 "" H 6300 750 50  0001 C CNN
	1    6300 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT3
U 1 1 61F11BC6
P 3050 1575
F 0 "BT3" H 3168 1671 50  0000 L CNN
F 1 "Battery_Cell" H 3168 1580 50  0000 L CNN
F 2 "" V 3050 1635 50  0001 C CNN
F 3 "~" V 3050 1635 50  0001 C CNN
	1    3050 1575
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT2
U 1 1 61F120D4
P 3050 1275
F 0 "BT2" H 3168 1371 50  0000 L CNN
F 1 "Battery_Cell" H 3168 1280 50  0000 L CNN
F 2 "" V 3050 1335 50  0001 C CNN
F 3 "~" V 3050 1335 50  0001 C CNN
	1    3050 1275
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 61F12BAB
P 3050 975
F 0 "BT1" H 3168 1071 50  0000 L CNN
F 1 "Battery_Cell" H 3168 980 50  0000 L CNN
F 2 "" V 3050 1035 50  0001 C CNN
F 3 "~" V 3050 1035 50  0001 C CNN
	1    3050 975 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR01
U 1 1 61F13727
P 3050 775
F 0 "#PWR01" H 3050 625 50  0001 C CNN
F 1 "+12V" H 3065 948 50  0000 C CNN
F 2 "" H 3050 775 50  0001 C CNN
F 3 "" H 3050 775 50  0001 C CNN
	1    3050 775 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 61F13DAE
P 3050 1675
F 0 "#PWR02" H 3050 1425 50  0001 C CNN
F 1 "GND" H 3055 1502 50  0000 C CNN
F 2 "" H 3050 1675 50  0001 C CNN
F 3 "" H 3050 1675 50  0001 C CNN
	1    3050 1675
	1    0    0    -1  
$EndComp
$Comp
L payload2022_custom:HK-30A-ESC J1
U 1 1 61F1652F
P 4500 850
F 0 "J1" H 4600 925 50  0000 C CNN
F 1 "HK-30A-ESC" H 4600 834 50  0000 C CNN
F 2 "" H 4500 850 50  0001 C CNN
F 3 "" H 4500 850 50  0001 C CNN
	1    4500 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 800  4050 1100
Wire Wire Line
	3050 1650 3600 1650
Wire Wire Line
	4050 1650 4050 1200
Text Notes 3875 775  0    50   ~ 10
XT60
Wire Wire Line
	5150 1000 5750 1000
Wire Wire Line
	5150 1100 5400 1100
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
$Comp
L power:GND #PWR03
U 1 1 61F1C8A7
P 3550 5000
F 0 "#PWR03" H 3550 4750 50  0001 C CNN
F 1 "GND" H 3555 4827 50  0000 C CNN
F 2 "" H 3550 5000 50  0001 C CNN
F 3 "" H 3550 5000 50  0001 C CNN
	1    3550 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4850 3550 4950
NoConn ~ 5900 1850
NoConn ~ 6100 1850
NoConn ~ 6300 1850
NoConn ~ 6500 1850
NoConn ~ 7100 1850
NoConn ~ 7200 1850
NoConn ~ 7300 1850
NoConn ~ 7600 1850
NoConn ~ 7700 1850
NoConn ~ 7900 1850
NoConn ~ 8000 1850
NoConn ~ 8100 1850
$Comp
L Motor:Stepper_Motor_unipolar_6pin M1
U 1 1 62024EEC
P 7450 4800
F 0 "M1" H 7638 4924 50  0000 L CNN
F 1 "Stepper_Motor_unipolar_6pin" H 7638 4833 50  0000 L CNN
F 2 "" H 7460 4790 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 7460 4790 50  0001 C CNN
	1    7450 4800
	1    0    0    -1  
$EndComp
$Comp
L payload2022_custom:X113647-Stepper-Driver U1
U 1 1 62026126
P 6050 3500
F 0 "U1" H 6125 3615 50  0000 C CNN
F 1 "X113647-Stepper-Driver" H 6125 3524 50  0000 C CNN
F 2 "" H 6050 3500 50  0001 C CNN
F 3 "" H 6050 3500 50  0001 C CNN
	1    6050 3500
	1    0    0    -1  
$EndComp
Text Notes 7025 3775 0    50   ~ 10
JST Connector
Wire Wire Line
	6900 1850 6900 2550
Wire Wire Line
	6900 2550 5600 2550
Wire Wire Line
	5600 2550 5600 1200
Connection ~ 5600 1200
Wire Wire Line
	5600 1200 5750 1200
Wire Wire Line
	6550 3850 7550 3850
Wire Wire Line
	7550 3850 7550 4500
Wire Wire Line
	6550 4050 7350 4050
Wire Wire Line
	7350 4050 7350 4500
Wire Wire Line
	7450 4250 7450 4500
Wire Wire Line
	6550 4250 6850 4250
Wire Wire Line
	6550 3950 6950 3950
Wire Wire Line
	6950 3950 6950 4700
Wire Wire Line
	6950 4700 7150 4700
Wire Wire Line
	6850 4250 6850 4800
Wire Wire Line
	6850 4800 7150 4800
Connection ~ 6850 4250
Wire Wire Line
	6850 4250 7450 4250
Wire Wire Line
	6550 4150 6550 4250
Wire Wire Line
	6550 4900 7150 4900
Connection ~ 6550 4250
Wire Wire Line
	6550 4250 6550 4900
Wire Wire Line
	5700 3650 5500 3650
Wire Wire Line
	6800 1850 6800 2450
Wire Wire Line
	6800 2450 5400 2450
Wire Wire Line
	5400 2450 5400 1100
Connection ~ 5400 1100
Wire Wire Line
	5400 1100 5750 1100
Wire Wire Line
	4150 3650 4050 3650
Wire Wire Line
	5700 3950 4150 3950
Wire Wire Line
	5700 4050 4150 4050
Wire Wire Line
	4150 4150 5700 4150
Wire Wire Line
	5700 4250 4150 4250
Text Notes 4850 3900 0    50   ~ 10
Dupont
Wire Wire Line
	5300 3750 5300 2000
Wire Wire Line
	5300 2000 6000 2000
Wire Wire Line
	6000 2000 6000 1850
Wire Wire Line
	5300 3750 5700 3750
NoConn ~ 6400 1850
Wire Wire Line
	6700 1850 6700 2250
Wire Wire Line
	6700 2250 2900 2250
Wire Wire Line
	2900 2250 2900 3750
Wire Wire Line
	2900 3750 3150 3750
Wire Wire Line
	3600 1650 3600 2150
Wire Wire Line
	3600 2150 2700 2150
Wire Wire Line
	2700 2150 2700 4950
Wire Wire Line
	2700 4950 3550 4950
Connection ~ 3600 1650
Wire Wire Line
	3600 1650 4050 1650
Connection ~ 3550 4950
Wire Wire Line
	3550 4950 3550 5000
Text Notes 3700 1900 3    50   ~ 10
Barrel
Wire Wire Line
	5150 1200 5600 1200
Wire Wire Line
	5500 3650 5500 4950
Wire Wire Line
	5500 4950 3750 4950
Wire Wire Line
	3750 4950 3750 4850
NoConn ~ 7500 1850
$EndSCHEMATC
