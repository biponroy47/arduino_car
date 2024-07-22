
## Notes

#### 1st Update
My initial idea was to replicate the functionality of an actual RWD car, where the front wheels are designated for steering, and the rear wheels are for forward/reverse movement. Implementing the motors for forward/reverse movement is simple but steering was a bit of an issue. My idea was to use 2 servo motors attached to their respective axles and wheels to implement this, but I only had 1 servo motor at the moment. 

My next solution for this problem was to use the single servo motor and attach it to a singular longer axle with both wheels attached to the sides,  but once again I did not have a simple T-shaped shaft to attach to the 21-spline gear-shaped tip of the servo.

I then thought of printing my own connector. I found a 3D model of the 21-spline tip online and attempted to print a custom model for this shaft. The model was functional in theory, however the 3D printer was unable to print such precise details of the spline, it ended up fusing together to create a small cylindrical tube instead. 

At this point I had given up on the idea for separate steering. I could always print out some arms, buy some bearings, some screws, attach all the arms together with the servo to achieve this, but simplicity was my priority here as I have a bad habit of uncessessarily overcomplicating things. 
#### 2nd Update
Anyways, here I decided to go back to my original plan, the standard 4 wheel design where each wheel can only move forwards or backwards, and rotation can be achieving by alternating the direction of the linearly grouped motors. Personally, I'm not a fan of this design but it'll have to do.

So now I've begun laying out the schematic for the circuit on TinkerCAD. I was hoping to control the vehicle wirelessly, but my only options were an analog joystick which must be wired, or this IR Remote/receiver pair. I chose the IR Remote, and while everything is functional at the moment, there is one issue. The issue is that the IR Remote does not transmit a signal once an input is released, therefore my car will continue moving in the last inputted direction without ever coming to a stop. 

Simple solution would be to add a few buttons to control speed of the car, or a brake, or I could code a timeout function that would automatically bring the car to a rolling stop if an input hasn't been clicked in a while. For the sake of simplicity, I decided to set one of the buttons as a break. 
#### 3rd Update
So now I've got the prototype layed out on the UNO and it appears there are a few issues. First issue is that it appears the Arduino isn't receiving enough power via the 5v Vin pin. I've remedied this using a separate 9v battery to power the arduino separately which I will attach to the same switch in the near future.

The second issue is that the 4th motor is not working. I've implemented a simple program to run all the motors once the switch is enabled, this lost one remains stationary. I imagine this to be due to a poor soldering connection to the motor terminals, or misplaced/loose jumper cables. 

The final and main issue is the IR sensor/remote not working. I suspect it is due to the code being from a newer library which I will likely have to downgrade to the older IR Remote 2.0 library.
#### 4th Update
After inspecting the motor, I was correct and the motor was faulty. I removed it, testing it with it's own isolated battery, different jumper cables, and resoldered connections, but it did not work. Luckily I did have a couple spares to replace it with.

For the IR Remote issue, I downgraded the library and reverted the code to the older syntax. At this point the IR sensor was still not working. It turns out 2 jumper cables were swapped, specifically the power cable, and output cable. Now the LED onboard the sensor lit up indicating it received power, however the sensor still did not work.

After further research, I realized that the sensor was not compatible with an analog pin. I had run out of digital PWM pins. I realized 1 of the cables did not need PWM so after some reconfigration, the IR sensor outpput was connected to a digital output PWM pin, and the sensor finally began receiving codes from the remote.
#### Final Update
Now everything is connected properly and the prototype is complete. All motors were functional, the remote was mapped and we were ready to begin testing. Upon testing, I noticed a few things. The first thing I noticed was that the sensor would not always respond right away, I would have to click multiple times. This could not be remedied and I would just have to use a different wireless communication method for the future.

The second thing I noticed was that the car would sometimes crash after it was signalled to stop. This was due to the momentum of the motors that remained even after losing power. The car would only come to a rolling stop. I remedied this by inputting the oposite direction for a split second, then signalled it to stop. I could code it to automatically do this everytime the brake was clicked, but I couldn't be bothered.
## Future Design Improvements
- Use pre-built RC transmitter or create a custom controller with analog joysticks, arduino nano, and RF transmitted/receiver modules for wireless comunication (more accurate and responsive than IR remote/receiver)
- Separate steering by using 1 servo motor, and rack and pinion steering system (more control over movement, precise turning, but may be difficult to model/coordinate componenents)
- Create custom chasis for drive train using appropriate gear ratios for optimized torque/speed, and only utilizes 1 motor (reduces number of motors, power consumption, more efficient)
- Solder all components using perfboard/veroboard/strip board (reduces wires, space, and improves organization)
## Lessons Learned 
- Put more focus into circuit planning and pre-testing
- Model entire build before building prototype (component by component)
- Incorporate screws, nuts, bolts, and bearings into 3D model
- Animate the assembly before 3D printing
- Once 3D model and circuit is sound, then and only then buy the necessary parts needed to build the prototype
#### Final Remark
I think the main flaw with my process was trying to force the parts I had to be used in the project. Before starting the project, I bought a simple Arduino kit and a  DC motor kit. The latter kit had wheels, axles, gears, and an assortment of other parts. Now what I should've done here is modelled those parts (the ones to be used) and incorporated them into a master 3D model. Instead I went on ahead glueing parts together, attaching things, soldering wires, 3D printing stuff, and I did all this before planning how it should all work together. This caused more problems expected and things became complicated quite quickly. Had I planned better and bought/used parts according to the model instead, this project would have gone much smoother. 

The main lesson I learned here is to <b>PLAN EVERYTHING</b>. Do not rush and buy parts for the sake of having it available. Don't force parts or assemble them into your project before planning how they will work. <b>PLAN EVERYTHING!</b> 

Anyways, here are some photos of the prototype if you're curious :)

![1](https://github.com/biponroy47/arduino_car/blob/main/images/image1.jpg?raw=true)

![2](https://github.com/biponroy47/arduino_car/blob/main//images/image2.jpg?raw=true)

![3](https://github.com/biponroy47/arduino_car/blob/main//images/image3.jpg?raw=true)




 