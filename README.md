# Maxim MAX17043 Integer Arduino Library
A Maxim MAX17043 lithium cell fuel gauge Arduino library using integer calculations.
This library has been written from the ground up to not use float math so its resource requirements will be much lower than other equivalent libraries.

The most recent release version 1.1.0 has the following functionality which is all you need to get started.

* Retrieve the battery's voltage in millivolts.
* Read the state of charge percentage.
* Set the charge percentage under which the *ALRT* interrupt will fire.
* Read the state of the *ALRT* interrupt.
* Clear the interrupt flag.

# Examples
One example is included.
## Monitor MAX17043
This example is to test drive the MAX17043 lithium fuel cell gauge integer library.
It allows you to query the lithium cell's state as well as adjust, monitor and clear the low charge state *ALRT* interrupt.
