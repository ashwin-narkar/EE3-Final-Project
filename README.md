# EE3-Final-Project

By: Ashwin Narkar, Adrienne Mok, and Charlotte McGinn

Video: https://youtu.be/_X1ppX7fblk

Keyboard HEERO was our final project for EE3: Introduction to Electrical Engineering with Dr. Briggs. Our inspiration for this project came from the popular video game Guitar Hero, where the player has a guitar controller to play notes as the appear on the screen. Our interpretation was to have 4 NeoPixel LED Strips with lights of different colors "fall" down the strip until a final point, at which the player would have to push the button corresponding to that strip, like a piano key. The different colors of the LEDs would represent different lengths of the note.

We used a Teensy 3.2 and a Neopixel LED Strip for this project. We also used 4 push buttons, a breadboard, a speaker, and a 7 segment display for the score. There were challenges in getting the LED strip and the speaker to work in unison as the Teensy could only run one process at at time. The driver code for the 7 segment display was also challenging, as the display had a common anode for each digit. 

To improve this project, we would like to add song choices and the ability to view your score as the game was being played, which was not possible due to the common anode of the 7 segment display. To do this, we would most likely need a second microcontroller to drive the display, and one running the game. These two microcontrollers would be serially communicating with each other as well.
