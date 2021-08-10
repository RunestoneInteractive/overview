.. Copyright (C) 2012-2020 Bryan A. Jones.

    This file is part of CellBotics.

    CellBotics is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    CellBotics is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with CellBotics.  If not, see <http://www.gnu.org/licenses/>.

****************
Reference manual
****************
This provides a list of the items available in the ``cellbotics`` module.

.. contents:: Table of Contents
    :local:

.. module:: cellbotics
    :synopsis: Import this module to gain access to all Cellbotics items.


CellBot
=======
.. class:: CellBot

    This class uses a BLE (Bluetooth Low Energy) connection with an ESP32 running Arduino libraries to execute functions. An example of its use:

    .. code:: Python

        import cellbotics

        # Define the pin numbers we need.
        LED1 = 7
        LED2 = 5
        PB1 = 0

        # Configure pins.
        cb = cellbotics.CellBot()
        cb.pinMode(LED1, cb.OUTPUT)
        cb.pinMode(PB1, cb.INPUT)

        # Set up PWM at 1000 Hz with 16-bit resolution.
        cb.ledcSetup(channel, 1000, 16)
        cb.ledcAttachPin(LED1, channel)
        # Operate at ~7.6 % (5000/2^16).
        cb.ledcWrite(channel, 5000)


    The Arudino documentation describes the following methods for `digital pins <https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins>`_:

    -   `pinMode <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_
    -   `digitalRead <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/>`_
    -   `digitalWrite <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    Constants to use with these functions:

.. attribute:: Cellbot.INPUT

    Use as the second parameter of `pinMode`_ to confiure a pin as an input.


.. attribute:: Cellbot.OUTPUT

    Use as the second parameter of `pinMode`_ to confiure a pin as an output.


.. method:: Cellbot.__init__()

    This takes no parameters. It invokes the `resetHardware` function.


.. method:: Cellbot.resetHardware()

    Reset the ESP32, leaving it in a default state.

.. method:: Cellbot.ledcSetup(channel, frequency, resolution_in_bits)

    Configure a PWM channel. See the code sample above.

    :param: channel: The PWM channel to use; a number between 0 and 15. Channels 0-7 auto-update new PWM periods, while channels 8-15 don't.
    :param: frequency: The frequency to do the PWM, in Hz.
    :param: resolution_in_bits: The number of bits used to do the PWM. The maximum possible value is floor(log2(processor clock frequency/PWM frequency)); this cannot exceed 20. The processor clock frequency is either 80 MHz or 1 MHz.
    :return: The function returns the actual PWM frequency, due to the limitations of the available clock divisor.

.. method:: Cellbot.ledcAttach(pin, channel)

    Give control of the pin to the specified PWM channel. After the pin is attached, the pinMode_ no longer determines the output of the pin. Detach it to pass control back to the pinMode_.

    :param: pin: the pin number to attach this PWM channel to. This is the same as the first parameter of pinMode_, digitalRead_, or digitalWrite_.
    :param: channel: The PWM channel to use; a number between 0 and 15.


.. method:: Cellbot.ledcDetach(pin)

    Remove control of the pin from the associated PWM channel.

    :param: pin: The pin to detch from PWM control.


.. method:: Cellbot.ledcWrite(channel, duty_cycle)

    Specify the duty cycle of the PWM.

    :param: channel: The PWM channel to use; a number between 0 and 15.
    :param: duty_cycle: The duty cycle, ranging from 2^resolution_in_bits (100%) to 1 (almost 0%). The ``resolution_in_bits`` comes from ``ledcSetup``.


Sensors
=======
The following classes provide a number of sensors. Example use:

.. code:: Python

    import cellbotics
    from time import sleep

    a = cellbotics.Accelerometer()
    a.start()
    for i in range(10):
        print(a.x, a.y, a.z)
        sleep(1)
    a.stop()


For more details on each sensor, see the `Sensor API <https://developer.mozilla.org/en-US/docs/Web/API/Sensor_APIs#interfaces>`_. These sensors all share the following methods:

.. method:: Cellbot.<SensorClass>.start()

    Begin collecting data from the sensor.


.. method:: CellBot.<SensorClass>.stop()

    Finish collecting data from the device. This saves battery life.

XYZ sensors
-----------
The following sensors have ``x``, ``y``, and ``z`` properties.

.. class:: cellbotics.Accelerometer
.. class:: cellbotics.Gyroscope
.. class:: cellbotics.Magnetomoter

    Also known as a digital compass.

.. class:: cellbotics.LinearAcceleration
.. class:: cellbotics.GravitySensor

Orientation sensors
-------------------
These two sensors produce a ``quaternion`` property. See `Quaternions and spatial rotation <https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation>`_.

.. class:: cellbotics.AbsoluteOrientationSensor
.. class:: cellbotics.RelativeOrientationSensor

Other sensors
-------------
.. class:: AmbientLightSensor

    This clss provides one attribute, ``illuminance``, which gives the current light level in lux.

.. class:: GeolocationSensor

    Results from the device's GPS. Attributes:

    -   ``latitude``
    -   ``longitude``
    -   ``altitude``
    -   ``accuracy``
    -   ``altitudeAccuracy``
    -   ``heading``
    -   ``speed``
