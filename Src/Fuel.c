/*
 * Ignition.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */

#include "Fuel.h"


void Fuel()
{
	/*SET UP PIN PC6 FOR LED*/
	RCC->AHB1ENR |=  (1<<2);   //GPIOC CLOCK ENABLE

	GPIOC->MODER &= ~(3<<2);   //CLEAR PIN 12 ,13 FOR PC6 LED
	GPIOC->MODER |=  (3<<2);   //SETTING PIN TO OUTPUT MODE-01 SET BIT 12


	RCC->APB2ENR |= (1<<8);    //ENABLE ADC1 CLOCK-ADC1 IS CONNECTED TO APB2 BUS(84MHZ)
	ADC1->CR2=0;     	       //0: DISABLE ADC CONVERSION AND O TO POWER DOWN MODE

	//ADC_SQR1 REGISTER
	ADC1->SQR3  =(0xB);        //CONVERSION SEQUENCE STARTS AT CH 11
	ADC1->SQR3 |= (0xC<<5);

	ADC1->CR1 |= (1<<8);
	ADC1->CR2 |=1;             //ENABLE ADC1
}
