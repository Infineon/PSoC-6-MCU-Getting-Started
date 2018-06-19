# Objective

This code example demonstrates the implementation of an EZI2C Slave using the PSoC<sup>®</sup> Creator™ SCB Component on a PSoC 4 device. It also demonstrates how to control the color and intensity of an RGB LED using TCPWM Components.

<table>
<tbody>
<tr class="odd">
<td></td>
</tr>
</tbody>
</table>

# Overview

This code example implements an I<sup>2</sup>C Slave using a Serial Communication Block (SCB) Component (configured as EZI2C), which receives the data required to control an RGB LED from an I<sup>2</sup>C Master. In this example, a host PC running the Cypress’ Bridge Control Panel (BCP) software is used as an I<sup>2</sup>C Master. RGB LED control is implemented using three TCPWM Components (configured as PWM). The color and intensity of the RGB LED is controlled by changing the duty cycle of the PWM signals.

# Requirements

**Tool:** [PSoC<sup>®</sup> Creator](http://www.cypress.com/products/psoc-creator-integrated-design-environment-ide)™ 4.2

**Programming Language:** C (Arm<sup>®</sup> GCC 5.4.1 and Arm MDK 5.22)

**Associated Parts:** [All PSoC 4 parts](http://www.cypress.com/products/32-bit-arm-cortex-m0-psoc-4)

**Related Hardware:** [CY8CKIT-040](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-040-psoc-4000-pioneer-development-kit), [CY8CKIT-041-40XX](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-psoc-4-s-series-pioneer-kit), [CY8CKIT-041-41XX](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-41xx-psoc-4100s-capsense-pioneer-kit), [CY8CKIT-042](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-psoc-4-pioneer-kit), [CY8CKIT-042-BLE](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-ble-pioneer-kit), [CY8CKIT](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit)‑[042](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit)‑[BLE](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit)‑[A](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit), [CY8CKIT-044](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-044-psoc-4-m-series-pioneer-kit), [CY8CKIT-046](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-046-psoc-4-l-series-pioneer-kit), [CY8CKIT-048,](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-048-psoc-analog-coprocessor-pioneer-kit) [CY8CKIT-149](http://www.cypress.com/cy8ckit-149)

# Hardware Setup

By default, this example project is configured to run on the CY8CKIT-042 development kit from Cypress Semiconductor. The project can be migrated to any supported kit by changing the target device. Open the **Device Selector** from the project’s context menu. Table 1 lists supported kits and corresponding devices.

This example uses the kit’s default configuration. Refer to the kit guide to ensure that the kit is configured correctly.

Table 1. Supported Kits and Devices

<table>
<tbody>
<tr class="odd">
<td>Development Kit</td>
<td>Series</td>
<td>Device</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-040-psoc-4000-pioneer-development-kit">CY8CKIT-040</a></td>
<td>PSoC 4000</td>
<td>CY8C4014LQI-422</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-psoc-4-s-series-pioneer-kit">CY8CKIT-041-40XX</a></td>
<td>PSoC 4000S</td>
<td>CY8C4045AZI-S413</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-41xx-psoc-4100s-capsense-pioneer-kit">CY8CKIT-041-41XX</a></td>
<td>PSoC 4100S</td>
<td>CY8C4146AZI-S433</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-psoc-4-pioneer-kit">CY8CKIT-042</a></td>
<td>PSoC 4200</td>
<td>CY8C4245AXI-483</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-ble-pioneer-kit">CY8CKIT-042-BLE</a></td>
<td>PSoC 4200 BLE</td>
<td>CY8C4247LQI-BL483</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit">CY8CKIT-042-BLE-A</a></td>
<td>PSoC 4200 BLE</td>
<td>CY8C4248LQI-BL483</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-044-psoc-4-m-series-pioneer-kit">CY8CKIT-044</a></td>
<td>PSoC 4200M</td>
<td>CY8C4247AZI-M485</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-046-psoc-4-l-series-pioneer-kit">CY8CKIT-046</a></td>
<td>PSoC 4200L</td>
<td>CY8C4248BZI-L489</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-048-psoc-analog-coprocessor-pioneer-kit">CY8CKIT-048</a></td>
<td>PSoC Analog Coprocessor</td>
<td>CY8C4A45LQI-483</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/cy8ckit-149">CY8CKIT-149</a></td>
<td>PSoC 4100S Plus</td>
<td>CY8C4147AZI-S475</td>
</tr>
</tbody>
</table>

Pin assignments for supported kits are provided in Table 2. For these kits, the project includes control files to automatically assign pins with respect to the kit hardware connections during project build. To change pin assignments, override control file selections in the **Pin Editor** of the **Design Wide Resources** by selecting the new port or pin number.

Table 2. Pin Assignments

<table>
<tbody>
<tr class="odd">
<td>Development Kit</td>
<td>Pin Assignment</td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td></td>
<td>\I2C:scl\</td>
<td>\I2C:sda\</td>
<td>LED_Red</td>
<td>LED_Green</td>
<td>LED_Blue</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-040-psoc-4000-pioneer-development-kit">CY8CKIT-040</a></td>
<td>P1[2]</td>
<td>P1[3]</td>
<td>P3[2]</td>
<td>P1[1]</td>
<td>P0[2]</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-psoc-4-s-series-pioneer-kit">CY8CKIT-041-40XX</a></td>
<td>P3[0]</td>
<td>P3[1]</td>
<td>P3[4]</td>
<td>P2[6]</td>
<td>P3[6]</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-041-41xx-psoc-4100s-capsense-pioneer-kit">CY8CKIT-041-41XX</a></td>
<td>P3[0]</td>
<td>P3[1]</td>
<td>P3[4]</td>
<td>P2[6]</td>
<td>P3[6]</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-psoc-4-pioneer-kit">CY8CKIT-042</a></td>
<td>P4[0]</td>
<td>P4[1]</td>
<td>P1[6]</td>
<td>P0[2]</td>
<td>P0[3]</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-ble-pioneer-kit">CY8CKIT-042-BLE</a></td>
<td>P3[5]</td>
<td>P3[4]</td>
<td>P2[6]</td>
<td>P3[6]</td>
<td>P3[7]</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-42-compliant-pioneer-kit">CY8CKIT-042-BLE-A</a></td>
<td>P3[5]</td>
<td>P3[4]</td>
<td>P2[6]</td>
<td>P3[6]</td>
<td>P3[7]</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-044-psoc-4-m-series-pioneer-kit">CY8CKIT-044</a></td>
<td>P4[0]</td>
<td>P4[1]</td>
<td>P0[6]</td>
<td>P2[6]</td>
<td>P6[5]</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-046-psoc-4-l-series-pioneer-kit">CY8CKIT-046</a></td>
<td>P4[0]</td>
<td>P4[1]</td>
<td>P5[2]</td>
<td>P5[3]</td>
<td>P5[4]</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/development-kitsboards/cy8ckit-048-psoc-analog-coprocessor-pioneer-kit">CY8CKIT-048</a></td>
<td>P4[0]</td>
<td>P4[1]</td>
<td>P1[4]</td>
<td>P2[6]</td>
<td>P1[6]</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/cy8ckit-149">CY8CKIT-149</a></td>
<td>P3[0]</td>
<td>P3[1]</td>
<td>P5[2]</td>
<td>P5[5]</td>
<td>P5[7]</td>
</tr>
</tbody>
</table>

**Note**: CY8CKIT-149 does not have an RGB LED. Instead, this example controls LED11, LED12, and LED13 which are all green.

# Software Setup

For this code example, you need the Bridge Control Panel software, which is installed with PSoC Creator.

# Operation

1.  Plug your kit board into your computer’s USB port.

2.  Build the project and program it into the PSoC 4 device. Choose **Debug** \> **Program**. For more information on device programming, see the PSoC Creator Help.

3.  Confirm that the RGB LED is green.

4.  Open Bridge Control Panel (**Start** \> **All Programs** \> **Cypress** \> **Bridge Control Panel**\<**Version**\> \> **Bridge Control Panel** \<**Version**\>)

5.  Select the KitProg device in **Connected I2C/SPI/RX8 Ports**. Make sure that the selected protocol is I<sup>2</sup>C (Figure 1).

6.  Go to **Tools** \> **Protocol Configuration**, and in the **I2C** tab, select **I2C Speed** as **100kHz**.

7.  Press the **List** button and confirm that the EZI2C Slave device with the address 0x08 (7 bits) is available for communication.

8.  In the **Editor** tab of BCP, type the command to send the RGB LED control data, and then click **Send**. Observe that the RGB LED turns ON with the specified color and intensity.
    
    The packet format for writing to a Slave device from BCP is shown below.

<table>
<thead>
<tr class="header">
<th><strong>Start for Write</strong></th>
<th><strong>Slave Address</strong></th>
<th><strong>Slave Buffer Index to Start Write</strong></th>
<th><strong>Red LED TCPWM Compare Value</strong></th>
<th><strong>Green LED TCPWM Compare Value</strong></th>
<th><strong>Blue LED TCPWM Compare Value</strong></th>
<th><strong>Stop</strong></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>w</td>
<td>(0x08)</td>
<td>(0x00) to (0x02)</td>
<td>(0x00) to (0xFF)</td>
<td>(0x00) to (0xFF)</td>
<td>(0x00) to (0xFF)</td>
<td>p</td>
</tr>
</tbody>
</table>

For example, sending the command ‘w 08 00 00 00 00 p’ will turn the RGB LED OFF. The command ‘w 08 00 FF FF FF p’ will turn the RGB LED ON white with full intensity.

You can also control individual LEDs by writing the value to the specific Slave buffer location. For example, sending the command ‘w 08 02 7F p’ will turn the RGB LED ON with blue color and medium intensity.

> You can check the number of write operations that are performed by reading index 0x03 of the Slave buffer. This can be done by setting the write index to the index of the counter, ‘w 08 03 p’, and then reading that index with ‘r 08 x p’.

The packet format for reading data from the Slave device is shown below.

<table>
<thead>
<tr class="header">
<th><strong>Start for Read</strong></th>
<th><strong>Slave Address</strong></th>
<th><strong>Red LED TCPWM Compare Value</strong></th>
<th><strong>Green LED TCPWM Compare Value</strong></th>
<th><strong>Blue LED TCPWM Compare Value</strong></th>
<th><strong>Number of Write Operations</strong></th>
<th><strong>Stop</strong></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>r</td>
<td>(0x08)</td>
<td>x</td>
<td>x</td>
<td>x</td>
<td>x</td>
<td>p</td>
</tr>
</tbody>
</table>

For example, sending the command ‘r 08 x x x x p’ will return the last value written to each of the TCPWM Components as well as the number of write operations performed.

Figure 1. Bridge Control Panel I<sup>2</sup>C Master Setup

![](.//media/image1.png)

Figure 2. Commands Execution Results

![](.//media/image2.png)

# Design and Implementation

The Top Design Schematic of the project is shown in Figure 3.

Figure 3. PSoC Creator Project Schematic

![](.//media/image3.png)

In this example, the EZI2C Component is configured with a 4-byte buffer (memory), which can be accessed by the I<sup>2</sup>C Master. The first three bytes are writeable and hold the red, green, and blue LED intensity in that order. The fourth byte, which is read-only, holds the number of write operations performed after the device reset.

EZI2C allows an I<sup>2</sup>C Master to either access an individual byte from the Slave memory (by specifying the memory address in the Write command) or all memory bytes at once. For the testing procedure, see [Operation](#operation).

To control the color and intensity of an RGB LED, three PWMs with period value of 255 (~1.2 kHz) are used. Duty cycles of the PWMs are controlled in the firmware and specified by the I<sup>2</sup>C Master. Changing the duty cycle of the PWM signal result in a change in the LED intensity. By changing the intensity of individual LEDs, various colors can be produced on the RGB LED using color mixing. The range of intensity in this example is 0x01 to 0xFF; 0x00 turns the LED OFF.

## Components and Settings

Table 3 lists the PSoC Creator Components used in this example, how they are used in the design, and the non-default settings required so they function as intended.

Table 3. PSoC Creator Components

<table>
<tbody>
<tr class="odd">
<td>Component</td>
<td>Instance Name</td>
<td>Purpose</td>
<td>Non-default Settings</td>
</tr>
<tr class="even">
<td>EZI2C (SCB mode)</td>
<td>EZI2C</td>
<td>Provides I<sup>2</sup>C register-based communication with the Master device</td>
<td>Default settings only</td>
</tr>
<tr class="odd">
<td>Digital Output Pin</td>
<td>LED_RED</td>
<td>Drives the PWM signal to the LED</td>
<td>Default settings only</td>
</tr>
<tr class="even">
<td></td>
<td>LED_GREEN</td>
<td></td>
<td>Default settings only</td>
</tr>
<tr class="odd">
<td></td>
<td>LED_BLUE</td>
<td></td>
<td>Default settings only</td>
</tr>
<tr class="even">
<td>Clock</td>
<td>Clock</td>
<td>Drives the PWM at 24 MHz</td>
<td><strong>Frequency:</strong> 24 MHz</td>
</tr>
<tr class="odd">
<td>PWM (TCPWM mode)</td>
<td>PWM_Red</td>
<td>Generate square wave and bring out the signal to GPIO</td>
<td><p><strong>Period:</strong> 255</p>
<p><strong>Compare:</strong> 0</p></td>
</tr>
<tr class="even">
<td></td>
<td>PWM_Green</td>
<td></td>
<td><p><strong>Period:</strong> 255</p>
<p><strong>Compare:</strong> 0</p></td>
</tr>
<tr class="odd">
<td></td>
<td>PWM_Blue</td>
<td></td>
<td><p><strong>Period:</strong> 255</p>
<p><strong>Compare:</strong> 0</p></td>
</tr>
</tbody>
</table>

For information on the hardware resources used by the Component, see the Component datasheet.

# Reusing This Example

This example is designed for the kits shown in Table 1. To port the design to a different PSoC 4 device and/or kit, change the target device using **Device Selector** and update the pin assignments in the **Design Wide Resources Pins** settings as needed.

# Related Documents

<table>
<tbody>
<tr class="odd">
<td>Application Notes</td>
<td></td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/application-notes/an79953-getting-started-psoc-4">AN79953 – Getting Started with PSoC 4</a></td>
<td>Introduces the PSoC 4 architecture and development tools.</td>
</tr>
<tr class="odd">
<td>PSoC Creator Component Datasheets</td>
<td></td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/go/comp_GPIO_PDL">Pins</a></td>
<td>Supports connection of hardware resources to physical pins</td>
</tr>
<tr class="odd">
<td><a href="http://www.cypress.com/documentation/component-datasheets/psoc-4-serial-communication-block-scb">Serial Communication Block (SCB)</a></td>
<td>Supports the hardware SCB block</td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/documentation/component-datasheets/psoc-4-timer-counter-pulse-width-modulator-tcpwm">Timer/Counter Pulse Width Modulator (TCPWM)</a></td>
<td>Supports generation of Pulse Width Modulation signals</td>
</tr>
<tr class="odd">
<td>Device Documentation</td>
<td></td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/search/all/PSoC%20Datasheet?f%5b0%5d=meta_type%3Atechnical_documents&amp;f%5b1%5d=resource_meta_type%3A575&amp;f%5b2%5d=field_related_products%3A92426&amp;f%5b3%5d=field_related_products%3A1297">PSoC 4 Datasheets</a></td>
<td><a href="http://www.cypress.com/search/all/PSoC%20TRM?f%5b0%5d=meta_type%3Atechnical_documents&amp;f%5b1%5d=field_related_products%3A92426&amp;f%5b2%5d=resource_meta_type%3A583&amp;f%5b3%5d=field_related_products%3A1297">PSoC 4 Technical Reference Manuals</a></td>
</tr>
<tr class="odd">
<td>Development Kit (DVK) Documentation</td>
<td></td>
</tr>
<tr class="even">
<td><a href="http://www.cypress.com/search/all/PSoC%204%20kit?f%5b0%5d=meta_type%3Asoftware_tools&amp;f%5b1%5d=software_tools_meta_type%3A577&amp;f%5b2%5d=field_related_products%3A1297&amp;f%5b3%5d=field_related_products%3A1209">PSoC 4 Kits</a></td>
<td></td>
</tr>
</tbody>
</table>

# 

# Document History

Document Title: CE195362 – PSoC 4 EZI2C Slave with Serial Communication Block (SCB)

Document Number: 001-95362

<table>
<thead>
<tr class="header">
<th>Revision</th>
<th>ECN</th>
<th>Orig. of Change</th>
<th>Submission Date</th>
<th>Description of Change</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>**</td>
<td>6000861</td>
<td>MYKZTMP1</td>
<td>12/28/2017</td>
<td>New code example</td>
</tr>
<tr class="even">
<td>*A</td>
<td>6095934</td>
<td>BFMC</td>
<td>03/14/2018</td>
<td><p>Updated to closely match PSoC 6 EZI2C example</p>
<p>Updated template</p></td>
</tr>
</tbody>
</table>

#   
Worldwide Sales and Design Support

Cypress maintains a worldwide network of offices, solution centers, manufacturer’s representatives, and distributors. To find the office closest to you, visit us at [Cypress Locations](http://www.cypress.com/?id=1062).

# [Products](http://www.cypress.com/products)

<table>
<thead>
<tr class="header">
<th>Arm<sup>®</sup> Cortex<sup>®</sup> Microcontrollers</th>
<th><a href="http://www.cypress.com/products/32-bit-arm-cortex-mcus">cypress.com/arm</a></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>Automotive</td>
<td><a href="http://www.cypress.com/applications/automotive-solutions">cypress.com/automotive</a></td>
</tr>
<tr class="even">
<td>Clocks &amp; Buffers</td>
<td><a href="http://www.cypress.com/products/clocks-buffers">cypress.com/clocks</a></td>
</tr>
<tr class="odd">
<td>Interface</td>
<td><a href="http://www.cypress.com/products/interface">cypress.com/interface</a></td>
</tr>
<tr class="even">
<td>Internet of Things</td>
<td><a href="http://www.cypress.com/internet-things-iot">cypress.com/iot</a></td>
</tr>
<tr class="odd">
<td>Memory</td>
<td><a href="http://www.cypress.com/products/memory-products">cypress.com/memory</a></td>
</tr>
<tr class="even">
<td>Microcontrollers</td>
<td><a href="http://www.cypress.com/mcu">cypress.com/mcu</a></td>
</tr>
<tr class="odd">
<td>PSoC</td>
<td><a href="http://www.cypress.com/psoc/">cypress.com/psoc</a></td>
</tr>
<tr class="even">
<td>Power Management ICs</td>
<td><a href="http://www.cypress.com/products/power-management">cypress.com/pmic</a></td>
</tr>
<tr class="odd">
<td>Touch Sensing</td>
<td><a href="http://www.cypress.com/products/touch-sensing">cypress.com/touch</a></td>
</tr>
<tr class="even">
<td>USB Controllers</td>
<td><a href="http://www.cypress.com/products/usb-controllers">cypress.com/usb</a></td>
</tr>
<tr class="odd">
<td>Wireless Connectivity</td>
<td><a href="http://www.cypress.com/products/wireless-connectivity">cypress.com/wireless</a></td>
</tr>
</tbody>
</table>

#   
[PSoC<sup>®</sup> Solutions](http://www.cypress.com/psoc)

[PSoC 1](http://www.cypress.com/products/psoc-1) | [PSoC 3](http://www.cypress.com/products/psoc-3) | [PSoC 4](http://www.cypress.com/products/psoc-4) | [PSoC 5LP](http://www.cypress.com/products/psoc-5lp) | [PSoC 6 MCU](http://www.cypress.com/psoc6)

# [Cypress Developer Community](http://www.cypress.com/cdc)

[Community Forums](https://community.cypress.com/welcome) | [Projects](http://www.cypress.com/projects) | [Video](http://www.cypress.com/video-library)s | [Blogs](http://www.cypress.com/blog) | [Training](http://www.cypress.com/training) | [Components](http://www.cypress.com/cdc/community-components)

# [Technical Support](http://www.cypress.com/support)

[cypress.com/support](http://www.cypress.com/support)

All other trademarks or registered trademarks referenced herein are the property of their respective owners.

<table>
<tbody>
<tr class="odd">
<td><img src=".//media/image5.png" style="width:1.86111in;height:0.57633in" /></td>
<td>Cypress Semiconductor<br />
198 Champion Court<br />
San Jose, CA 95134-1709</td>
</tr>
</tbody>
</table>

© Cypress Semiconductor Corporation, 2017-2018. This document is the property of Cypress Semiconductor Corporation and its subsidiaries, including Spansion LLC (“Cypress”). This document, including any software or firmware included or referenced in this document (“Software”), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide. Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights. If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products. Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.

TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. No computing device can be absolutely secure. Therefore, despite security measures implemented in Cypress hardware or software products, Cypress does not assume any liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes. It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product. Cypress products are not designed, intended, or authorized for use as critical components in systems designed or intended for the operation of weapons, weapons systems, nuclear installations, life-support devices or systems, other medical devices or systems (including resuscitation equipment and surgical implants), pollution control or hazardous substances management, or other uses where the failure of the device or system could cause personal injury, death, or property damage (“Unintended Uses”). A critical component is any component of a device or system whose failure to perform can be reasonably expected to cause the failure of the device or system, or to affect its safety or effectiveness. Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from or related to all Unintended Uses of Cypress products. You shall indemnify and hold Cypress harmless from and against all claims, costs, damages, and other liabilities, including claims for personal injury or death, arising from or related to any Unintended Uses of Cypress products.

Cypress, the Cypress logo, Spansion, the Spansion logo, and combinations thereof, WICED, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress in the United States and other countries. For a more complete list of Cypress trademarks, visit cypress.com. Other names and brands may be claimed as property of their respective owners.
