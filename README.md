# Side Panel Board Functional Requirements
- - - -
## Sensors to Poll
This is all the data it should collect, the frequency at which they should be sent, and how they should be collected.

* Button state: 50ms
	* SW<7:1> states. Pretty direct, just read the GPIO. 
- - - -
## Protocol
* Serial is set up at 115200 bps 8N1. Use USART2, the one exposed on the header.
* Data is sent in raw bytes, little endian
* Simply sign extend any data that’s not a nice size.
* Start every frame with 0xa5, followed by data identifier 0x04.
* Append every frame with CRC-32 checksum. Just poll for CRC, don’t bother with DMA. Use the default (reset value) ethernet checksum in the hardware CRC peripheral. Don’t enable any bit swapping
* Don’t bother with endianess, make the message a packed struct with the appropriate widths for each value and just write to the struct
* Frame format: (`{name[size]}`)
	* 0x04: Button data
		* `{0xa5[8], 0x04[8], {0b0[1], SW7[1], SW6[1], SW5[1], SW4[1], SW3[1], SW2[1], SW1[1]}[8], CRC[32]}`
- - - -
## Setup
* Install Atollic TrueStudio. Ask Manu for a download if their site is still down at the time of reading.
* Install STM32CUBEMX. Open the .ioc file in the folder with it. You will be able to see pinouts and generate boilerplate code. Ask James to review your clock tree. Poke around to see all the relevant options; the interface is jank but everything you need is there somewhere.
* Plug the 5 pins on the debug header to the corresponding pins on the programmer, and you’re good to go
* Preferably use FreeRTOS. A quick guide to the API can be found here: [FreeRTOS - Quick start guide](https://www.freertos.org/FreeRTOS-quick-start-guide.html)
* If you don’t want to deal with RTOS, a superloop is also okay. Just review the STM32CUBE HAL API included.
