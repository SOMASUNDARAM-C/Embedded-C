#ifndef __ADC_ACTIVITY_H__
#define __ADC_ACTIVITY_H__

/**
 * @brief Initialize registers for ADC
 * 
 */
void InitADC(void);

/**
 * @brief Reads analog value from the input channel and converts into digital value
 * 
 * @param ch Analog channel number
 * @return uint16_t ADC output value
 */
uint16_t Read_ADC(uint8_t ch);

#endif