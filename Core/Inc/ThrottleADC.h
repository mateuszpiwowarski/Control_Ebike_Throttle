/*
 * ThrottleADC.h
 *
 *  Created on: Feb 13, 2024
 *      Author: mateu
 */

#ifndef INC_THROTTLEADC_H_
#define INC_THROTTLEADC_H_

#include "adc.h"

#define ADC_RESOLUTION 2000.0
#define VMIN 0.8
#define VMAX 4.2
#define ADC_MAX_VALUE 4095.0

void Throttle_Get_ADC_Value(ADC_HandleTypeDef* hadc, uint32_t* adc_val);

void Throttle_Get_Voltage(ADC_HandleTypeDef* hadc, float* outputVoltage);

#endif /* INC_THROTTLEADC_H_ */
