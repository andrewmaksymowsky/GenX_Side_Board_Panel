/*
 * Serializer to convert data into UART bytes
 */

#include "serializer.h"
#include "string.h"
#include "crc.h"
#include "usart.h"

void serializeSwitchStates(uint8_t *buf, uint8_t switchStates){

	buf[0] = '{';
	buf[1] = MODULE_CODE;
	buf[2] = ',';
	buf[3] = DATA_IDENTIFIER;
	buf[4] = ',';
	buf[5] = switchStates;
	buf[6] = ',';
	*((uint32_t *)(&(buf[7]))) = HAL_CRC_Calculate(&hcrc, &(buf[1]), 5); // CRC of buf[1] to buf[5]
	buf[11] = '}';
	buf[12] = '\n';
}

void send_data(uint8_t* buf, uint8_t bufLen){
	HAL_UART_Transmit(&huart2, buf, bufLen, UART_TRANSMIT_TIMEOUT);
}
