USB Composite HID Keyboard Mouse Device

This example application turns the evaluation board into a composite USB
keyboard and mouse example using the Human Interface Device class.  The
color LCD displays a blank area which acts as a mouse touchpad.  The button
on the bottom of the screen acts as a toggle between keyboard and mouse
mode.  Pressing it toggles the screen to keyboard mode and allows keys
to be sent to the USB host.  The board status LED is used to indicate the
current Caps Lock state and is updated in response to pressing the ``Caps''
key on the virtual keyboard or any other keyboard attached to the same USB
host system.

-------------------------------------------------------------------------------

Copyright (c) 2013-2015 Texas Instruments Incorporated.  All rights reserved.
Software License Agreement

Texas Instruments (TI) is supplying this software for use solely and
exclusively on TI's microcontroller products. The software is owned by
TI and/or its suppliers, and is protected under applicable copyright
laws. You may not combine this software with "viral" open-source
software in order to form a larger program.

THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
DAMAGES, FOR ANY REASON WHATSOEVER.

This is part of revision 2.1.1.71 of the DK-TM4C129X Firmware Package.
