Kalman Filter definition:

Bayesian logic -- a process of making predictions and then seeing whether those predictions are true, iteratively
over time, (due to the law of large numbers), the prediction should tend to converge on a good estimationo

"However, when using the Kalman filter to estimate the state x, the probability distribution of interest is associated with the current states conditioned on the measurements up to the current timestep. (This is achieved by marginalising out the previous states and dividing by the probability of the measurement set.)"

[](https://en.wikipedia.org/wiki/Recursive_Bayesian_estimation)

The tl;dr on this is that we can  predict, update, and refine our model over time, which results in having a
pretty decent method of estimation for single variable or multivariate systems

in terms of like a markov chain, you might write this as:

`p(x_k | x_{k-1}, x_{k-2}, ... ,x_0) = p(x_k | x_{k-1}`

which basically implies that the prediction of the current state based on the previous state depends on all the
other states

now, we get to the fun part!!!!!

because we can very nicely put predictions and probabilities into matrices, computers can do it pretty easily

### What do we need to predict? 

well, it would be kinda nice to know something like position, acceleration, heading, angular velocity etc. etc. 
(y'know, the essentials!)


`THE FOLLOWING IS JUST FROM THE BASIC README`

# Payload-2022
Electronics and Software for Payload 2022 Deployable :Cube:

OVERVIEW OF FLIGHT :
* Drop to a reasonable altitude 
* Navigate using gps/compass based control system to within eyeline of ops, or until the battery runs out/run out of potential energy
* Use remote controller to get the rest of the way down
** Remote controller can also serve as back-up in case of emergency, and be used for ground testing of the wings themselves


ON-CUBE-SYSTEMS :
Autonomously determines direction of flight using Compass and GPS with input from sensors, with goal of arriving at location of remote controller.
* Radio communication - communicate with remote controller on ground
* GPS receiver - determine cubesat's current locaiton
* SD card - store testing data, potential experiment data
* Compass - Use to determine direction cubesat is pointing
* Motor controller - PID for accurate control of motor displacement to move the cubesat
* Sensors
** Option 1 - we use an existing minsensor board to cover the thermistor and barometer functions, plus a new board with the dead reckoning unit (DRU)
** Option 2 - custom sensor board based on mini sensor with space for DRU


OFF-CUBE SYSTEM :
Remote controller
Communicates with Cubesat and can override autonomous control with manual control
* Radio communication - communicate with cubesat
* GPS receiver - use as reference for cubesat
* SD card - store testing data, experiment data received over radio, good thing to have in case failure on board
* Compass - tell us what direction the cubesat is in
* I/0  input - buttons for manual control of cubesat direction


More information available in Design Docs:
https://docs.google.com/document/d/1taV1tidALE3emlK4XI88u090zswx8rMgQPDmcY7zMuU/edit?usp=sharing

SENSING COMPONENTS DATA:
https://docs.google.com/spreadsheets/d/1w2s266TZ0PPDU81SyGsCCDq5ps78rXRAA3cDaBvMYBY/edit#gid=174579378
