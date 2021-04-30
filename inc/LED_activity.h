#ifndef __LED_ACTIVITY_H__
#define __LED_ACTIVITY_H__

/**
 * @brief Initialize ports for input switches and output LED
 * 
 */
void ports_init(void);


volatile unsigned SEAT_OCCUPANCY;  ///Variable to indicate the seat occupancy


volatile unsigned SWITCH_STATE;   ///Variable to indicate the switch state

#endif