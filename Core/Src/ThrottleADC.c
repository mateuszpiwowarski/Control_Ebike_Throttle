/*
 * ThrottleADC.c
 *
 *  Created on: Feb 13, 2024
 *      Author: mateu
 */

#include "ThrottleADC.h"
#include "adc.h"


uint32_t Throttle_Get_ADC_Value(ADC_HandleTypeDef* hadc)
{
	HAL_ADC_Start(hadc);

    uint32_t adc_val;
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);
    adc_val = HAL_ADC_GetValue(hadc);
    return adc_val;
}


float Throttle_Get_Voltage(ADC_HandleTypeDef* hadc)
{
	float outputVoltage;
    uint32_t adc_val = Throttle_Get_ADC_Value(hadc);
    outputVoltage = (((float)adc_val - 1000) / ADC_RESOLUTION) * (VMAX - VMIN) + VMIN;
    HAL_ADC_Stop(hadc);
    return outputVoltage;
}
