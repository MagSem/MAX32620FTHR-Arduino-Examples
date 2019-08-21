//=============================================================================>
// 1. Project - start

// Author:    MagSem
// Data:      21.08.2019
// Details:   Some examples for Arduino       
// uC board:  MAX32620FTHR

// 1. Project - finish
//=============================================================================<

/**
 * @file    
 * @brief   GPIO Example 01
 * @details Config Normal and blink GPIO Port 3 Pin 1
 */

//=============================================================================>
// 2. Includes - start

#include <stdio.h>
#include <stdint.h>
#include "mxc_config.h"
#include "mxc_sys.h"
#include "gpio.h"

#include "MAX32620FTHRM.h"            // MAX32620FTHRM  MagSem Lib

// 2. Includes - finish
//=============================================================================<

//=============================================================================>
// 3. Definitions - start

// 3. Definitions - finish
//=============================================================================<

//=============================================================================>
// 4. Globals - start

uint8_t LED_Status[] = {0, 0, 0, 0};

const gpio_cfg_t pin = { PORT_3, PIN_1, GPIO_FUNC_GPIO, GPIO_PAD_NORMAL };

// 4. Globals - finish
//=============================================================================<

//=============================================================================>
// 5. Functions - start

//----------------------------------------------------------------------------->
void pin_pulse(void)
{
  GPIO_OutSet(&pin);
  delay(500);
  GPIO_OutClr(&pin);
  delay(1500);
}
//-----------------------------------------------------------------------------<

// 5. Functions - finish
//=============================================================================<

//=============================================================================>
// 6. SetUp - start

void setup(void)
{
  // Common SetUp ------------------------------------------------------------->

  // Prepare the User LEDs
  pinMode(MAX32620FTHR_RLED, OUTPUT);
  pinMode(MAX32620FTHR_GLED, OUTPUT);
  pinMode(MAX32620FTHR_BLED, OUTPUT);
  // Prepare the User PUSH BUTTON
  pinMode(MAX32620FTHR_PBUT, INPUT_PULLUP);

  // USB to Serial (PC to uC)
  Serial.begin(0);
  //while(!Serial.availableForWrite()); // 1.1.3
  //while (!Serial);                    // 1.1.5
  // 96 MHz very fast for first Serial print
  delay(500);
  
  // Special SetUp ------------------------------------------------------------>

  /* Configure port pin */
  GPIO_Config(&pin);
}

// 6. SetUp - finish
//=============================================================================<

//=============================================================================>
// 7. Loop - start

void loop(void)
{
  pin_pulse();
}

// 7. Loop - finish
//=============================================================================<
