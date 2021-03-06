#ifndef _VACUUM_PUMP_H_
#define _VACUUM_PUMP_H_

#define VACUUM_PUMP_CONFIG_COUNT_MAX 9
#define VACUUM_SWITCH_RELASE_TIME 200

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <can/can_wrapper.h>
#include <util/delay.h>
#include "Utils.h"
#include "CanBus.h"
#include "Pin.h"

typedef struct _VacuumPump {
    Pin* pumpPin;
    Pin* switchPin;
    uint16_t canId;
} VacuumPump;

typedef struct _SVacuumPump {
    Pin* pumpPin;
    Pin* switchPin1;
    Pin* switchPin2;
    uint16_t canId;
} SVacuumPump;

void VacuumPump_Add(Pin* pumpPin, Pin* switchPin, uint8_t number);
void SpecialPump_Add(Pin* pumpPin, Pin* switchPin1,Pin* switchPin2, uint8_t number);
bool VacuumPump_OnMessage(can_t* canMsg);
bool SingleVacuumPump_OnMessage(can_t* canMsg);
bool SingleSpecialPump_OnMessage(can_t* canMsg);

#endif
