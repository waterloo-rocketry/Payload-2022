Rogallo Wing Test 1:
* Set up RC controller and execute commands through servo motors

RC controller: Spektrum DX5e
RC receiver: OrangeRX 2.4Ghz

Servo commands recieved from OrangeRX reciever are sent intput into Arduino UNO, which then sends them back to the servo motors.
**This may be redundant w/servo motors, but it will be necessary as the motor control interface gets more complicated


Inital RC controller code stolen from: 
https://create.arduino.cc/projecthub/kelvineyeone/read-pwm-decode-rc-receiver-input-and-apply-fail-safe-6b90eb