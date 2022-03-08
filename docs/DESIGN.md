## OVERVIEW OF FLIGHT :
* Drop to a reasonable altitude 
* Navigate using gps/compass based control system to within eyeline of ops, or until the battery runs out/run out of potential energy
* Use remote controller to get the rest of the way down
** Remote controller can also serve as back-up in case of emergency, and be used for ground testing of the wings themselves


## ON-CUBE-SYSTEMS :
Autonomously determines direction of flight using Compass and GPS with input from sensors, with goal of arriving at location of remote controller.
* Radio communication - communicate with remote controller on ground
* GPS receiver - determine cubesat's current locaiton
* SD card - store testing data, potential experiment data
* Compass - Use to determine direction cubesat is pointing
* Motor controller - PID for accurate control of motor displacement to move the cubesat
* Sensors
** Option 1 - we use an existing minsensor board to cover the thermistor and barometer functions, plus a new board with the dead reckoning unit (DRU)
** Option 2 - custom sensor board based on mini sensor with space for DRU


## OFF-CUBE SYSTEM :
Remote controller
Communicates with Cubesat and can override autonomous control with manual control
* Radio communication - communicate with cubesat
* GPS receiver - use as reference for cubesat
* SD card - store testing data, experiment data received over radio, good thing to have in case failure on board
* Compass - tell us what direction the cubesat is in
* I/0  input - buttons for manual control of cubesat direction


More information available in Design Docs:
https://docs.google.com/document/d/1taV1tidALE3emlK4XI88u090zswx8rMgQPDmcY7zMuU/edit?usp=sharing
