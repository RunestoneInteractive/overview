.. Copyright (C) 2012-2020 Bryan A. Jones.

    This file is part of CellBotics.

    CellBotics is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    CellBotics is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with CellBotics.  If not, see <http://www.gnu.org/licenses/>.

***********************
Examples and scratchpad
***********************
Here are some example programs and a place to try them out; see also the `reference manual`.


Blink the LED until the pushbutton is pressed
=============================================
.. code:: Python

    import cellbotics

    # Define the pin numbers we need.
    LED1 = 2
    PB1 = 0

    # Set up the pushbutton and LED.
    cb = cellbotics.CellBot()
    cb.pinMode(LED1, cb.OUTPUT)
    cb.pinMode(PB1, cb.INPUT)

    # Blink the LED until the pushbutton is pressed.
    out = 0
    while True:
        # Read the pushbutton.
        val, msg = cb.digitalRead(PB1)
        # A value of 0 means the pushbutton is pressed.
        if not val:
            break

        # Toggle the LED to make it blink.
        out = not out
        cb.digitalWrite(LED1, out)


Vary the brightness of the LED
==============================
Shake your device to make the LED light up!

.. code:: Python

    import cellbotics

    # Define the pin numbers we need.
    LED1 = 2

    # Select a PWM channel and configure the LED for PWM.
    channel = 0
    cb = cellbotics.CellBot()
    cb.ledcSetup(channel, 1000, 16)
    cb.ledcAttachPin(LED1, channel)

    # Start the gyro.
    gyro = cellbotics.Gyroscope()
    gyro.start()

    # Read the gyro and display it on the LED.
    for i in range(20):
        gyro_x2 = gyro.x**2
        cb.ledcWrite(channel, min(2**16 - 1, gyro_x2*10000))
        print(gyro_x2)


Your code
=========
.. ble-pair-button::

.. activecode:: bCulhkWMfG
