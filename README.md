# Arduino Pin Overview
Little Sketch which outputs the current values of all pins.

**Table of Contents**
- [Intension](#intension)
- [Requirements](#requirements)
- [LICENSE](#license)


## Intension
I wanted to monitor the pins of the AAR-04 AREXX ARDUINO ROBOT which I lent me out.

Every X seconds the values should be refreshed. For this I intentional refresh the hole table. Not nice but should work was what I thought. Unfortunately, the buffer was not big enough and not the hole table was printed. The result was that I only print the table structure and update only the values. To realize this, I wrote a little library (for more see [Requirements](#requirements)). Due to this lirary I am able to set the courser to the right place and override the old values.

** picture **


## Requirements
For this project you will need the following library:
- [Arduino serial extention](https://github.com/HeinrichAD/Arduino-SerialExtended)

Furthermore you will not be able to use the Arduino IDE serial monitor. I recommend [PuTTY] for Windows user.


## Troubleshooting
For problems with terminal try to look [here](https://github.com/HeinrichAD/Arduino-SerialExtended#terminal-settings).

For library install problems try to look [here](https://github.com/HeinrichAD/Arduino-SerialExtended#how-to-install-arduino-libraries)


## LICENSE
GNU General Public License v3.0<br />
For more information see LICENSE file.



[PuTTY]:(http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html)
