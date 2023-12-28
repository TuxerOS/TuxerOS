#include "hal.h"
#include <arch/i686/gdt.h>
#include <arch/i686/idt.h>
#include <arch/i686/isr.h>
#include <stdio.h>

void HAL_Initialize()
{
    i686_GDT_Initialize();
    printf("[HAL]: Initilaized GDT\n\r");
    i686_IDT_Initialize();
    printf("[HAL]: Initilaized IDT\n\r");
    i686_ISR_Initialize();
    printf("[HAL]: Initilaized ISR\n\r");
}
