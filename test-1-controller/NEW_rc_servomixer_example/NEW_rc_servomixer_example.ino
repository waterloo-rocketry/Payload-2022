// servo variables

// include the servo library to control the servos
#include <Servo.h> 
#include <Stepper.h>


// name each servo output for use with the servo library
Servo servo_1;       
Servo servo_2;
Servo servo_3;      

// Each servo must be attached to a pin that has a PWM output
// on the arduino uno, nano and pro mini these pins are 3, 5, 6, 9, 10 and 11


// change this to fit the number of steps per revolution
const int steps_per_revolution = 2048;  
// Adjustable range of 28BYJ-48 Stepper is 0~17 rpm
const int role_per_minute = 17;         

// initialize the Stepper library on pins 8 through 11:
Stepper my_Stepper(steps_per_revolution, 8, 10, 9, 11);


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

void setup() {
  
    my_Stepper.set_speed(role_per_minute);

    setup_pwm_read();                      
    Serial.begin(115200);
}

void loop() {  
    
    now = millis();
    
    // if RC data is available or 25ms has passed since last update (adjust to > frame rate of receiver)
    if(rc_avail() || now - rc_update > 25){    
      
      rc_update = now;                           
      
      // uncommment to print raw data from receiver to serial
      print_rc_pwm();                          
      
      // run through each RC channel
      for (int i = 0; i<channels; i++){       
        int CH = i+1;
        
        // decode receiver channel and apply failsafe
        rc_in[i] = rc_decode(CH);             
        
        // uncomment to print calibrated receiver input (+-100%) to serial
        print_decimal_2_percentage(rc_in[i]);          
      }
     // uncomment when printing calibrated receiver input to serial.
     Serial.print_ln();                       

      
      // MIXING ON
      if (servo_mix_on == true){              
        int num_steps = calc_steps(3); 
        
        Serial.print("step width: "); Serial.print_ln(num_steps); 

        my_Stepper.step(num_steps);

    }
  }
}
