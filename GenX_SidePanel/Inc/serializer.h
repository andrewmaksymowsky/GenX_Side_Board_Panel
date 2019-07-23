#ifndef __serializer_H
#define __serializer_H
#ifdef __cpluscplus
 extern "C" {
#endif

#include "FreeRTOS.h"
#include "string.h"
#include "stdbool.h"

#define UART_TRANSMIT_TIMEOUT 3 //ms

#define MODULE_CODE 0xa5  //Module ID

#define DATA_IDENTIFIER 0x04

// All lengths are actual char length + 1 for string null terminator
#define MSG_LEN_SS 12

void serializeSwitchStates(uint8_t *buf, uint8_t switchStates);
void send_data(uint8_t* buf, uint8_t bufLen);

#ifdef __cplusplus
 }
#endif
#endif
