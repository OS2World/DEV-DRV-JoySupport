SpiceWare Joystick Support                                     May 5, 1997

NOTE: If you do not already have the joystick driver installed you will need
      to install it. Start by unzipping JOYSTICK.ZIP, then run INSTALL.CMD.
      After installation, you will have to reboot in order to cause the new
      device driver to be loaded.

The Joystick Support routines are free for all to use, even for shareware
and commercial products.  The only requirement is that you mention in the
docs that you are using the SpiceWare Joystick Support routines by 
Darrell Spice Jr., and that you include the SpiceWare URL 
   http://www.geocities.com/SiliconValley/Pines/2281/
so that others who would like to use the routines can find them.

This package is designed to make using the joysticks as easy as possible.
Just include the files JOYOS2.H and JOYOS2.OBJ (or JOYOS2.H and JOYOS2.C) in
the project that needs joystick support and your your code will have access
to six functions which make reading the joystick a breeze.

When initially used, the values returned will jump around.  This is because the
routines have not had enough information go through them for calibration
purposes.  Due to the nature of the PC joysticks, different joysticks will
return different values.  My digital game pad returns a range of values between
15 and 770, and my flight stick returns a range between 16 and 950. The
routines will self calibrate as the end user moves the joystick.  To get the
best results, the joystick should be moved to the four extreme positions(up,
down, left and right) as soon as possible.  By using the JoystickSaveCalibration
function when the program quits, the JoystickInit function can then be used to
reload the calibration information and prevent the user from having to
re-calibrate the joystick each time the program is run.

The JoystickRange function defines the kind of values that will be returned
to the calling program.  As a default, the values returned are -1, 0, and 1
for each axis.  -1 corresponds to up on the Y axis, and left on the X axis.
0 means the stick is centered on the axis, and 1 means down or right, depending
on the axis.  For games, such as Centipede, where you need to know a larger
range of values to control not only direction but also speed, you can request
a range such as -5 to 5.  For a paddle style game, such as Breakout or Pong,
a range of 0 to 639 may be more appropriate. The fire buttons will return a
value of 1 when pressed, and 0 when not.

The new functions are:
   JoystickInit()             Optional
   JoystickRange()            Optional
   JoystickOn()
   JoystickValues()
   JoystickOff()
   JoystickSaveCalibration()  Optional

See the sample file joydemo.c for how to use these functions, and the file
joyos2.c for specific information on each function.


Please let me know if this is useful for you, or if any changes should be made
to the programs to make them work even better!


The current release can always be found at the SpiceWare homepages at:
http://www.geocities.com/SiliconValley/Pines/2281/


Darrell Spice Jr.
spice@ibm.net
