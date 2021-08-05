/* 
    The purpose of this file is to include the actual gx_port.h file for current cpu architecture
    Authors: Neo Xiong <xiongyu0523@gmail.com> / Benjamin Cabé <benjamin.cabe@microsoft.com>
*/

#ifndef GX_PORT_H
#define GX_PORT_H

#if defined(__SAMD21G18A__)
//#include "../ports/arch/cortex_m0/tx_port_cm0.h"
#elif (defined(__SAMD51P19A__) || defined(__SAMD51J19A__) || defined(STM32L4xx))
#include "../ports/cortex_m4/gx_port_cm4.h"
#else
#error "Microcontroller is not supported!"
#endif

#endif


 