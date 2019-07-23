#include "switchStates.h"
#include "FreeRTOS.h"
#include "string.h"
#include "gpio.h"
#include "main.h"

uint8_t getSwitchStates(){

	// {0b0[1], SW7[1], SW6[1], SW5[1], SW4[1], SW3[1], SW2[1], SW1[1]}[8]
    uint8_t switchStates = 0x00;

    // Assemble switchStates byte using HAL pin-wise read
    switchStates |= HAL_GPIO_ReadPin(Camera_GPIO_Port, Camera_Pin) << 6;     // SW7
	switchStates |= HAL_GPIO_ReadPin(FwdRev_GPIO_Port, FwdRev_Pin) << 5;     // SW6
	switchStates |= HAL_GPIO_ReadPin(Fan_GPIO_Port, Fan_Pin) << 4;           // SW5
	switchStates |= HAL_GPIO_ReadPin(Array_GPIO_Port, Array_Pin) << 3;       // SW4
	switchStates |= HAL_GPIO_ReadPin(Ignition_GPIO_Port, Ignition_Pin) << 2; // SW3
	switchStates |= HAL_GPIO_ReadPin(Aux_GPIO_Port, Aux_Pin) << 1;           // SW2
	switchStates |= HAL_GPIO_ReadPin(LP_GPIO_Port, LP_Pin);                  // SW1

	return switchStates;
}
