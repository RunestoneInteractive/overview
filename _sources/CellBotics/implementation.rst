.. Copyright (C) 2012-2020 Bryan A. Jones.

    This file is part of CellBotics.

    CellBotics is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    CellBotics is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with CellBotics.  If not, see <http://www.gnu.org/licenses/>.

**************
Implementation
**************
This section of the book presents the core code which implements the CellBot's ability to connect a smart device to the mobile base and to access sensors on a smart device. It consists of three components:

-   JavaScript code which runs in a web browser and send commands to the ESP32 microcontroller on the mobile base. This is available in `Runestone Components <https://runestonecomponents.readthedocs.io/en/latest/runestone/cellbotics/toctree.html>`_.
-   A Skulpt wrapper around this JavaScript to make it available in Python.
-   Arduino/C++ code which runs on the ESP32 mobile base which receives commands from the web browser, executes them, then returns the results back to the browser.

It also contains files used to create this book.


To do
=====
-   Write up basic hardware connection instructions, software install to do ESP32 development if desired.
-   Add a 10 uF cap between EN and GND to avoid `flaky reprogramming <https://randomnerdtutorials.com/solved-failed-to-connect-to-esp32-timed-out-waiting-for-packet-header/>`_.
-   Provide some kind of version/CPU info, so we could talk to an older version of the code or to other types of chip.
-   Fix the reset function to actually reset all pins.
-   Include a disconnect function so that everything will be turned off after "running" a Python program.
-   Find a cheaper ESP32 -- some possibilities at https://makeradvisor.com/esp32-development-boards-review-comparison/.
-   Put the ESP32 to sleep when not paired or no BLE running.

Hardware
========
This gives one realization of a CellBot; however, it can easily support a wide variety of motors and be equipped with additional sensors and actuators.

Bill of Materials
-----------------
.. list-table::
    :widths: 5 15 10 60 10
    :header-rows: 1

    -   -   Qty
        -   Vendor
        -   SKU
        -   Description
        -   Price (USD)
    -   -   1
        -   `Sparkfun <https://www.sparkfun.com>`_
        -   `PRT-12083 <https://www.sparkfun.com/products/12083>`_
        -   Battery Holder 4xAA with Cover and Switch
        -   $1.95
    -   -   1
        -   Sparkfun_
        -   `ROB-13258 <https://www.sparkfun.com/products/13258>`_
        -   Hobby Gearmotor - 65 RPM (Right Angle, Pair)
        -   $4.95
    -   -   1
        -   Sparkfun_
        -   `ROB-13259 <https://www.sparkfun.com/products/13259>`_
        -   Wheel - 65mm (Rubber Tire, Pair)
        -   $2.95
    -   -   1
        -   Sparkfun_
        -   `ROB-14450 <https://www.sparkfun.com/products/14450>`_
        -   SparkFun Motor Driver - Dual TB6612FNG (with Headers)
        -   $5.45
    -   -   1
        -   Sparkfun_
        -   `PRT-00124 <https://www.sparkfun.com/products/124>`_
        -   Jumper Wire Kit - 140pcs
        -   $5.95
    -   -   1
        -   `Amazon/HiLetgo <https://www.amazon.com/stores/HiLetgo/page/C26BFC88-B8DE-4AD8-AE34-502CCD226542>`_
        -   `B00LSG5BJK <https://www.amazon.com/dp/B00LSG5BJK>`_
        -   400 point solderless breadboard, pack of 3
        -   $5.99
    -   -   1
        -   `Amazon/HiLetgo`_
        -   `B0718T232Z <https://www.amazon.com/dp/B0718T232Z>`_
        -   HiLetgo ESP-WROOM-32 Development Board 2.4GHz
        -   $10.99
    -   -
        -
        -   Total
        -   Includes 3 breadboards; need only 1. No quantity discounts.
        -   $38.99

Design notes
------------
The design presented here is driven by cost and simplicity. Other technical considerations:

Battery voltage
^^^^^^^^^^^^^^^
At the heart of the design is an `ESP32-WROOM-32D <https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/modules-and-boards.html#esp32-wroom-32d-esp32-wroom-32u>`_. This development kit contains an `AMS1117-3.3 linear regulator <https://datasheet.lcsc.com/szlcsc/2001081204_Shikues-AMS1117-1-2_C475600.pdf>`_, so its minimum input voltage is 3.3 V + V\ :sub:`drop`, the dropout voltage, where V\ :sub:`drop` = 1.5 V at 1 A. Therefore, the minimum allowable battery voltage is 4.7 V. The recommended maximum input voltage to the AMS1117 is 18 V, which defines the maximum battery voltage for the ESP32.

The DC motors must operate within the provided battery voltage as well. The motors selected above operate between 3 V - 6 V.

Finally, the `TB6612FNG <https://toshiba.semicon-storage.com/ap-en/semiconductor/product/motor-driver-ics/brushed-dc-motor-driver-ics/detail.TB6612FNG.html>`_ motor drivers allow a motor voltage (V\ :sub:`M`) from 2.5 V to 13.5 V.

Combining all three ranges (4.7 V - 18 V, 3 V - 6 V, and 2.5 V - 13.5 V) gives an allowable range of 4.7 V - 6 V for the batteries.

Other notes
^^^^^^^^^^^
While many motor drivers (also termed an H-bridge) exist, the TB6612FNG_ is one of the few that operates at a logic supply voltage (V\ :sub:`CC`) of 3.3 V. Since the ESP32 development kit already provides 3.3 V, this voltage drives the selection of a motor driver. For example, the LM298N provides higher drive current, a wider range of motor voltages, and a sense output to allow determination of the drive current (a very nice feature). However, its minimum V\ :sub:`CC` is 4.5 V.

With a wheel diameter of 65 mm and a no-load speed of 65 RPM for the motors, this robot's max speed is π·65 mm·65 RPM·1 min/60 sec = 0.2 m/s, compared to a typical walking speed of 1.4 m/s.


Firmware
========
.. toctree::
    :maxdepth: 2

    Arduino/BLE_server/BLE_server.ino
