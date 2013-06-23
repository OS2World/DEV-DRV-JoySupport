// SpiceWare sample source for easy reading of joysticks.
// by Darrell Spice Jr.         February 16, 1997

#define INCL_DOSPROCESS         // needed for DosSleep
#include <os2.h>                // needed for DosSleep
#include <stdio.h>              // included needed for printf support
#include <stdlib.h>             // included for atoi function

//-----------------------------------------------------------------------------
// include this file to add joystick support to your routines
#include "joyos2.h"             // included for joystick support
//-----------------------------------------------------------------------------


main(int argc, char* argv[])
{
   JOYSTICK_STATUS stick;      // joystick readings
   int rc;                     // return code
   int low = -1;               // low range
   int high = 1;               // high range

   if (argc == 3)              // arguements passed are low and high values
   {                           // of expected joystick ranges
      low = atoi(argv[1]);     // load low range
      high = atoi(argv[2]);    // load high range
      printf("Low = %d, high = %d\n", low, high);
      DosSleep(500);
   }




   // Initialize Joystick Calibration Info from JOYSTICK.INI file (if it exists)
   rc = JoystickInit(0);
   if (rc)
      printf("Joystick calibration info loaded\n");
   else
      printf("Joystick calibration info defaulted\n");
   DosSleep(500); // delay for readability




   // Set the range of values to be returned
   rc = JoystickRange(low, high); // sets the inclusive low-high range for return values
   if (rc)
      printf("Joystick Range of %d to %d loaded\n", low, high);
   else
      printf("Joystick Range of -1 to 1 defaulted\n");
   DosSleep(500); // delay for reaadability




   // Allow the reading of the joystick (opens game port)
   rc = JoystickOn();
   if (rc==0)
      printf("Port Opened!\nPress both fire buttons on either joystick to stop.\n");
   else
   {
      printf("Problem opening port, DosOpen returned %d\n", rc);
      DosSleep(2000);
      return 4;
   }
   DosSleep(2000);




   for (;;)     // loop until user presses two buttons on same joystick
   {
      rc = JoystickValues(&stick);// returns the values of the joysticks
     // display the joystick values
     printf("joy1 X: %3d Y: %3d A: %2x B: %2X    joy2 X: %3d Y: %3d A: %2x B: %2x\n",
             stick.Joy1X,    // Joystick 1's X value
             stick.Joy1Y,    //              Y value
             stick.Joy1A,    //              A Firebutton
             stick.Joy1B,    //              B Firebutton
             stick.Joy2X,    // Joystick 2's X Value
             stick.Joy2Y,    //              Y Value
             stick.Joy2A,    //              A Firebutton
             stick.Joy2B);   //              B Firebutton
     DosSleep(100); //slow up display
     if ((stick.Joy1A == TRUE) && (stick.Joy1B == TRUE) ||       // if both buttons on joystick 1, or
         (stick.Joy2A == TRUE) && (stick.Joy2B == TRUE))         // both buttoms on joystick 2 are pressed
         break;                                                        // stop the forever loop
   }




  // disable the reading of joystick values(closes game port)
  rc = JoystickOff();
  if (rc)
     printf("Joystick Port closed\n");
  else
     printf("Problem closing joystick port\n");
  DosSleep(500);




  // Save the current calibration information to JOYSTICK.INI for next time
  rc = JoystickSaveCalibration();
  if (rc)
     printf("Calibration information saved!\n");
  else
     printf("Warning - was not able to save calibration information!\n");
  DosSleep(2000); // delay 2 seconds to be able to read message



  return 0;
}
