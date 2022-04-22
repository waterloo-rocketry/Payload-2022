
#include <Servo.h> //RC controller 
#include "CytronMotorDriver.h" //Brushed motor 
#include <Wire.h> //I2C for IMU
#include <LSM6.h> //Orientation sensing IMU
#include <SPI.h>
#include <SD.h>


// Configure the motor driver.
CytronMD motor(PWM_DIR, 9, 8);  // PWM = Pin 9, DIR = Pin 9.


// Select Servo Direction, Rates and Sub-atrim (the size of each array must match the number of servos)

// Direction: 0 is normal, 1 is reverse
boolean servo_dir[] = {0,1};
// Rates: range 0 to 2 (1 = +-500us (NORMAL), 2 = +-1000us (MAX)): The amount of servo deflection in both directions        
float servo_rates[] = {1,0.5};
// Subtrimrange -1 to +1 (-1 = 1000us, 0 = 1500us, 1 = 2000us): The neutral position of the servo      
float servo_subtrim[] = {0.0,0.0};  
boolean servo_mix_on = true;

// timing variables to update data at a regular interval
unsigned long now;                                          
unsigned long rc_update;

// Receiver variables

// specify the number of receiver channels
const int channels = 3;
// an array to store the calibrated input from receiver                   
float rc_in[channels];  
//channel used to control motor
const uint8_t CHANNEL = 3; 
//testing variables
const bool PRINT = false;
//SD card filename
String filename = "test_2022_04_22.txt";
File datalog;



void setup() {

  if(PRINT)
    Serial.begin(115200);

  setup_error();
  setup_pwm_read();
  if(!setup_IMU())
    print_error("IMU Disconnected");
                      
}

void loop() {  
      
                     
  get_rc_command();
  get_motor_speed();
  get_IMU_data();
  get_gps();
  set_motor_speed();
  save_sd_data();
      

}
