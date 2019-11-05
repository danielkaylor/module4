# Module 4 - Kinetic Sculpture 

## Table of Contents  
* [Overview](#overview)  
* [Details](#details)
* [Hardware](#hardware)
* [Code](#code)
* [Demo](#demo)
* [Challenges](#challenges)

<a name="overview"/> 

## Overview 

The goal of our project was to use 4 motors to create an artistic piece. One of our initial thoughts was to create moving wings, and that eventually expanded to include moving antennas. We chose to model our design off of a butterfly. We decided to make the wings smaller (smaller as in, not large enough for a person to where) in order to lessen the load for the servo motors. The size of the wings ended up being a perfect size for a teddy bear we have! We decided to add some interactivity, so with everything planned out, we started coding and “building” the bear!

<a name="details"/> 

## Details

We made wings by using paper, popsicle sticks, hot glue, and paint. These were attached to the fans of the servo motors.

![Wings](/task2/documentation/back_view.jpg)

The antennas were made using popsicles and pipe cleaners. There was not an easy to attach the antennas to the stepper motors, so we used a small piece of a popsicle stick and cut a hole through it to stick to the motor. Then, it became a base for our antenna.

![Antennas](/task2/documentation/top_down.jpg)

The teddy bear was just a build-a-bear we had. We put the wings inside the backs and the antennas inside its head. We inserted the DIY force resistance sensor we made in module 3 inside the hand of the bear, so in order to make the wings and antennas move, you have to squeeze its hand! We had to cut it open to insert the motors, and apparently, all build-a-bears have a heart inside!

![Sensor](/task2/documentation/sensor_in_arm.jpg)

<a name="code"/> 

## Code

The basic code was developed further from our lab. We controlled two stepper and servo motors on one ESP32. At first, the wings (attached to the servo motors) moved linearly in increments of 5 degrees from 0-90 (or 90-0) depending on the orientation of the wings; however, the movement did not seem natural. We decided to go with a cosine interpolation to have a slow in and slow out (refer to video below).

[Moving Wings](https://www.youtube.com/watch?v=in5EBcCJYbA)

Then we had to move the antennas using the stepper motors, and that worked out fine; however, since all of this is running in the loop() function, the stepper motors delayed the speed of the wings to make the flapping more discrete. To accommodate for that, we increased the speed of the motors.

We used the force resistance motor to move the wings and antennas; however, we were getting some unpredictable values, so we had to make some minor adjustment in the code to also look at the previous value we received from the sensor.

<a name="hardware"/> 

## Hardware

* 28BYJ-48 Step Motor (x2)
* SG90 Tower Pro MicroServo (x2)
* ESP 32
* DIY Force Resistance Sensor

The hardware for it was not too bad. There were some complications finding the correct GPIO pins to use, but aside from that, wiring everything up was relatively simple; however, we had a lot of trouble with the power source. An ESP32 powered by my laptop did not have enough voltage to power two stepper motors, and we did not realize that mistake for a long time. We assumed that that we had problems with the pins, but we tried using a power board to power our ESP32, and it was strong enough to move all four of our motors.

![Sensor](/task2/documentation/sensor_connects.jpg)

The power board we used below.

![Sensor](/task2/documentation/project_board.jpg)

<a name="demo"/> 

## Demo Video 

[Demo Video](https://www.youtube.com/watch?time_continue=1&v=4MACWwSohuA)

<a name="challenges"/> 

## Challenges/Improvements

Some of the challenges we faced were:

* Powering our ESP32 to run 4 motors
  * Improvements: Our peer suggested using a board to power our motors separately from our ESP32 by using an external power source. This would make things easier and out piece must less bulky
* Making the piece sturdy enough as the motors run

