# DS1307-Real-Time-Clock

A real-time clock (RTC) is the centerpiece of any project that needs to keep an accurate track of time. Your wrist and nightstand watch are certainly equipped with one of these modules. Also, as it runs on a battery, the RTC can keep track of longer time periods even if you have to reflash the microcontroller or disconnect it from the main power supply.

Most microcontrollers have timers embedded into the chip that have the ability to keep track of short time periods. Also, the Arduino has a timer-based function called millis() that can keep track of the time since it was last powered or reset.

However, the problem with this type of timekeeping is that the microcontroller doesn't know if it's 'Monday' or 'September 9th'. It only knows how many milliseconds have passed since it was last powered on. Also, [millis()](http://arduino.cc/en/Reference/millis) will overflow after approximately 50 days.

This sort of basic timekeeping might be enough for projects that don't need to have consistent timekeeping. On the other hand, if you're planning to build a clock or a data-logger, a real-time clock is mandatory.

Quoting the [datasheet](resources/DS1307.pdf), the DS1307 serial real-time clock is a low power, full binary-coded decimal (BCD) clock/calendar plus 56 bytes of NV SRAM. Address and data are transferred serially through an I2C bidirectional bus.

The clock/calendar provides seconds, minutes, hours, day, date, month, and year information. The end-of-the-month date is automatically adjusted for months with fewer than 31 days, including corrections for leap year. The clock operates in either the 24-hour or 12-hour format with an AM/PM indicator.

The DS1307 has a built-in power-sense circuit that detects power failures and automatically switches to the backup supply. Timekeeping operation continues while the part operates from the backup supply.

For this tutorial you need:
- Arduino Nano 3.0
- DS1307 real-time clock module
- Breadboard and wires

Regarding the I2C bus and to avoid communication problems, make sure that your RTC module is equipped with pull-up resistors on the SDA and SCL lines. If your module doesn't have these resistors, you can add them externally. Even though knowing that choosing the correct resistance is not that trivial, for a project like this, a value between 2.2kOhm and 10kOhm should be just fine.

Now you have to replicate the circuit below:

![alt text](resources/DS1307-Real-Time-Clock_bb.png?raw=true)

Before compiling the code below, you need to download, uncompress, and install the [RTClib](https://github.com/adafruit/RTClib) library. To install, simply copy it into the "libraries" folder. Alternatively, you can read the official tutorial: [Installing Additional Arduino Libraries](http://arduino.cc/en/Guide/Libraries).

Upload the [code](DS1307_Real_Time_Clock.ino) to the board.

Open the Serial Monitor and watch the clock ticking.

![alt text](resources/SerialMonitor.jpg?raw=true)