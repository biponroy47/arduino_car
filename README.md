## Notes

With no prior experience working with circuits and Arduinos, this project has appeared to be trickier than expected.

My goal is to create a simple robot car from scratch. My initial thought process was to replicate the functionality of an actual car, where the front wheels are designated for steering, and the rear wheels are for forward/reverse movement. Implementing the motors for forward/reverse movement is simple but steering was a bit of an issue. My idea was to use 2 servo motors attached to their respective axles and wheels to implement this, but I only have 1 servo motor at the moment. 

No worries, my next solution was to use the single servo motor and attach it to a singular longer axle with both wheels attached to the sides,  but once again I did not have a simple connector to attach to the 21-spline gear-shaped tip of the motor that would be able to hold the axle. 

I then thought of printing my own connector. I found a 3D model of the 21-spline tip online and attempted to print a custom model utilizing it and my own design for the axle. The model was functional in theory, however the 3D printer was unable to print such precise details, the teeth of the gear-shaped insert to be specific. 

At this point I had given up on the idea for separate steering. I could always print out some arms, buy some bearings, some screws, attach all the arms together with the servo to achieve this, but simplicity was my priority here as I have a bad habit of uncessessarily overcomplicating things. 

Anyways, here I decided to go back to the original plan, the standard 4 wheel design where each wheel can only move forwards or backwards, and rotation can be achieving by alternating the direction of the linearly grouped motors. Personally, I'm not a fan of this design but it'll have to do.

So now I've begun laying out the schematic for the circuit on TinkerCAD. I was hoping to control the vehicle wirelessly, but my only options are an analog joystick which must be wired, or this IR Remote. I chose the IR Remote, and while everything is functional at the moment, there is one issue. The issue is that the IR Remote does not transmit a signal once an input is released, therefore my car will continue moving in the last inputted direction without ever coming to a stop. 

Simple solution would be to add a few buttons to control speed of the car, or a brake, or I could code a timeout function that would automatically bring the car to a rolling stop if an input hasn't been clicked in a while. I'll play around with this and update this when I do, till then. # arduino_car
