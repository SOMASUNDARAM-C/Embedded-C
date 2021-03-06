#ifndef __PWM_ACTIVITY_H__
#define __PWM_ACTIVITY_H__

/**
 * @brief Function to generate PWM output 
 * 
 * @param ADC_value Output digital value from ADC
 * @return uint8_t Returns the temperature value in decimal corresponding to the PWM output
 */
uint8_t PWM_output(uint16_t ADC_value);

#endif