// servo variables

#include <Servo.h> // include the servo library to control the servos
#include <Stepper.h>


Servo servo1;   // name each servo output for use with the servo library    
Servo servo2;
Servo servo3;      

// Each servo must be attached to a pin that has a PWM output
// on the arduino uno, nano and pro mini these pins are 3, 5, 6, 9, 10 and 11


const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 17;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


// Select Servo Direction, Rates and Sub-atrim (the size of each array must match the number of servos)

boolean servo_dir[] = {0,1};     // Direction: 0 is normal, 1 is reverse
float servo_rates[] = {1,0.5};  // Rates: range 0 to 2 (1 = +-500us (NORMAL), 2 = +-1000us (MAX)): The amount of servo deflection in both directions
float servo_subtrim[] = {0.0,0.0};  // Subtrimrange -1 to +1 (-1 = 1000us, 0 = 1500us, 1 = 2000us): The neutral position of the servo
boolean servo_mix_on = true;

unsigned long now;                  // timing variables to update data at a regular interval                        
unsigned long rc_update;

// Receiver variables

const int channels = 3;                   // specify the number of receiver channels
float RC_in[channels];                    // an array to store the calibrated input from receiver 

void setup() {
  
    myStepper.setSpeed(rolePerMinute);

    setup_pwmRead();                      
    Serial.begin(115200);
}

void loop() {  
    
    now = millis();
    
    if(RC_avail() || now - rc_update > 25){   // if RC data is available or 25ms has passed since last update (adjust to > frame rate of receiver)
      
      rc_update = now;                           
      
      print_RCpwm();                        // uncommment to print raw data from receiver to serial
      
      for (int i = 0; i<channels; i++){       // run through each RC channel
        int CH = i+1;
        
        RC_in[i] = RC_decode(CH);             // decode receiver channel and apply failsafe
        
        print_decimal2percentage(RC_in[i]);   // uncomment to print calibrated receiver input (+-100%) to serial       
      }
     Serial.println();                       // uncomment when printing calibrated receiver input to serial.

      
          
//      for(int stepnum = 0; stepnum < 2048; stepnum = stepnum+2)
//      {
//        
//        Serial.print("step width: "); Serial.println(stepnum); 
//      
//        now = millis();
//        while(millis() < now + 2000)
//        {
//            myStepper.step(stepsPerRevolution);
//        }
//
//      }
      if (servo_mix_on == true){              // MIXING ON
        int num_steps = calc_steps(3); 
        
        Serial.print("step width: "); Serial.println(num_steps); 

        myStepper.step(num_steps);

    }
  }
}
