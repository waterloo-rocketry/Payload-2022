// X DIRECTION ONLY

/*
 * Run an example of Kalman filter.
 * This example simulates a sinusoidal position of an object.
 * The 'SIMULATOR_' functions below simulate the physical process and its measurement with sensors. 
 * Results are printed on Serial port. You can use 'kalman_full.py' to analyse them with Python.
 * 
 * Author:
 *  R.JL. Fétick
 *  
 * Revision:
 *  31 Aug 2019 - Creation
 * 
 */

#include <Kalman.h>
using namespace BLA;

//------------------------------------
/****  MODELIZATION PARAMETERS  ****/
//------------------------------------

#define Nstate 15 // position, speed, acceleration
#define Nobs 15   // position, acceleration 

// measurement std of the noise (R)

#define n_px 0.09 // position measurement noise x (m)
#define n_py 0.09 // position measurement noise y (m)
#define n_pz 0.09 // position measurement noise z (m)
#define n_sx 0.09 // speed measurement noise x (m)
#define n_sy 0.09 // speed measurement noise y (m)
#define n_sz 0.09 // speed measurement noise z (m)
#define n_ax 0.012 // acceleration measurement noise x (m/s^2)
#define n_ay 0.012 // acceleration measurement noise y (m/s^2)
#define n_az 0.012 // acceleration measurement noise z (m/s^2)
#define n_hx 0.048 // heading measurement noise x (gauss)
#define n_hy 0.048 // heading measurement noise y (gauss)
#define n_hz 0.048 // heading measurement noise z (gauss)
#define n_rx 0.088 // angular velocity measurement noise x (dps)
#define n_ry 0.088 // angular velocity measurement noise y (dps)
#define n_rz 0.088 // angular velocity measurement noise z (dps)

// model std (1/inertia) (Q)
#define m_px 0.09 
#define m_py 0.09 
#define m_pz 0.09 
#define m_sx 0.09 
#define m_sy 0.09 
#define m_sz 0.09 
#define m_ax 0.012
#define m_ay 0.012
#define m_az 0.012
#define m_hx 0.048
#define m_hy 0.048
#define m_hz 0.048
#define m_rx 0.088
#define m_ry 0.088
#define m_rz 0.088

BLA::Matrix<Nobs> obs; // observation vector
KALMAN<Nstate,Nobs> K; // your Kalman filter
unsigned long T; // current time
float DT; // delay between two updates of the filter

// Note: I made 'obs' a global variable so memory is allocated before the loop.
//       This might provide slightly better speed efficiency in loop.


//------------------------------------
/****    SIMULATOR PARAMETERS   ****/
//------------------------------------

// These variables simulate a physical process to be measured
// In real life, the SIMULATOR is replaced by your operational system

BLA::Matrix<Nstate> state; // true state vector

#define SIMUL_PERIOD 0.3 // oscillating period [s]
#define SIMUL_AMP 1.0    // oscillation amplitude
#define LOOP_DELAY 10    // add delay in the measurement loop [ms]

//------------------------------------
/****        SETUP & LOOP       ****/
//------------------------------------

void setup() {

  Serial.begin(57600);

  // time evolution matrix (whatever... it will be updated inloop)
 K.F = {1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1
       };

  // measurement matrix n the position (e.g. GPS) and acceleration (e.g. accelerometer)
 K.H = {1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1
       };
  // measurement covariance matrix
 K.R = {n_px*n_px,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    n_py*n_py,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    n_pz*n_pz,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    n_sx*n_sx,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    n_sy*n_sy,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    n_sz*n_sz,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    n_ax*n_ax,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    n_ay*n_ay,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    n_az*n_az,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    n_hx*n_hx,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    n_hy*n_hy,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    n_hz*n_hz,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    n_rx*n_rx,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    n_ry*n_ry,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    n_rz*n_rz
        };
  // model covariance matrix
 K.Q = {m_px*m_px,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    m_py*m_py,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    m_pz*m_pz,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    m_sx*m_sx,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    m_sy*m_sy,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    m_sz*m_sz,    0,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    m_ax*m_ax,    0,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    m_ay*m_ay,    0,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    m_az*m_az,    0,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    m_hx*m_hx,    0,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    m_hy*m_hy,    0,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    m_hz*m_hz,    0,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    m_rx*m_rx,    0,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    m_ry*m_ry,    0,    
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    m_rz*m_rz 
       };
  
  T = millis();
  
  // INITIALIZE SIMULATION
  SIMULATOR_INIT();
  
}

void loop() {
	
  // TIME COMPUTATION
  DT = (millis()-T)/1000.0;
  T = millis();

  // UPDATE STATE EQUATION
  // Here we make use of the Taylor expansion on the (position,speed,acceleration)
  // position_{k+1} = position_{k} + DT*speed_{k} + (DT*DT/2)*acceleration_{k}
  // speed_{k+1}    = speed_{k} + DT*acceleration_{k}
  // acceleration_{k+1} = acceleration_{k}
         
  K.F = {1, 0,  0,  DT, 0,  0,  DT*DT/2,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  1,  0,  0,  DT, 0,  0,  DT*DT/2,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  1,  0,  0,  DT, 0,  0,  DT*DT/2,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  1,  0,  0,  DT, 0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  1,  0,  0,  DT, 0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  1,  0,  0,  DT, 0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  DT, 0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  DT, 0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  DT,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1
         };

    

  // UPDATE THE SIMULATED PHYSICAL PROCESS
  SIMULATOR_UPDATE();
  
  // SIMULATE A NOISY MEASUREMENT WITH A SENSOR
  // Result of the measurement is written into 'obs'
  SIMULATOR_MEASURE();
  
  // APPLY KALMAN FILTER
  K.update(obs);

  // PRINT RESULTS: true state, measurements, estimated state, posterior covariance
  // The most important variable for you might be the estimated state 'K.x'
  Serial << state << ' ' << obs << ' ' << K.x << ' ' << K.P << '\n';
}

//------------------------------------
/****     SIMULATOR FUNCTIONS   ****/
//------------------------------------

void SIMULATOR_INIT(){
  // Initialize stuff for the simulator
  randomSeed(analogRead(0));
  state.Fill(0.0);
  obs.Fill(0.0);
}

void SIMULATOR_UPDATE(){
  // Simulate a physical process
  // Here we simulate a sinusoidal position of an object
  unsigned long tcur = millis();
  state(0) = SIMUL_AMP*sin(tcur/1000.0/SIMUL_PERIOD); // position
  state(1) = SIMUL_AMP/SIMUL_PERIOD*cos(tcur/1000.0/SIMUL_PERIOD); // speed
  state(2) = -SIMUL_AMP/SIMUL_PERIOD/SIMUL_PERIOD*sin(tcur/1000.0/SIMUL_PERIOD); // acceleration
  state(3) = SIMUL_AMP*2*sin(tcur/1000.0/SIMUL_PERIOD); // angle
  state(4) = SIMUL_AMP*2/SIMUL_PERIOD*cos(tcur/1000.0/SIMUL_PERIOD); // angular velocity

  state(5) = state(0);
  state(6) = state(1);
  state(7) = state(2);
  state(8) = state(3);
  state(9) = state(4);

  state(10) = state(0);
  state(11) = state(1);
  state(12) = state(2);
  state(13) = state(3);
  state(14) = state(4);
}

void SIMULATOR_MEASURE(){
  // Simulate a noisy measurement of the physical process
  BLA::Matrix<Nobs> noise;
  noise(0) = n_px * SIMULATOR_GAUSS_NOISE();
  noise(1) = n_sx * SIMULATOR_GAUSS_NOISE();
  noise(2) = n_ax * SIMULATOR_GAUSS_NOISE();
  noise(3) = n_hx * SIMULATOR_GAUSS_NOISE();
  noise(4) = n_rx * SIMULATOR_GAUSS_NOISE();

  noise(5) = noise(0);
  noise(6) = noise(1);
  noise(7) = noise(2);
  noise(8) = noise(3);
  noise(9) = noise(4);

  noise(10) = noise(0);
  noise(11) = noise(1);
  noise(12) = noise(2);
  noise(13) = noise(3);
  noise(14) = noise(4);
  
  obs = K.H * state + noise; // measurement
  delay(LOOP_DELAY); //simulate a delay in the measurement
}

double SIMULATOR_GAUSS_NOISE(){
  // Generate centered reduced Gaussian random number with Box-Muller algorithm
  double u1 = random(1,10000)/10000.0;
  double u2 = random(1,10000)/10000.0;
  return sqrt(-2*log(u1))*cos(2*M_PI*u2);
}
