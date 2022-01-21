#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "Test.h"

void Test()
{
    // start screen (press start to continue)
    gotogxy(3,8); // set text start position
    gprintf("Press Start...");
    waitpad(J_START); // wait for start
    gotogxy(3,8); // reset text start position
    gprintf("              "); // clear message

    // display message to screen
    gotogxy(3,8); // set text start position
    gprintf("Welcome, Turbo!"); // print message
}