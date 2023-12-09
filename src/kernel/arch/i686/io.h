#pragma once
#include <stdint.h>
#include <stdio.h>
#include <arch/i686/isr.h>

void __attribute__((cdecl)) i686_outb(uint16_t port, uint8_t value);
uint8_t __attribute__((cdecl)) i686_inb(uint16_t port);


void __attribute__((cdecl)) i686_Panic();

// yes I am crinimal for this

// how 2 center message: 80 / 2 - (messageLen / 2)

static void TuxerPanic(char* errorMessage, Registers* regs) {
    clrscr();
    putColorWholeScreen(0x4F);
    printf("\n\r");
    printf("                                 Kernel Panic\r\n");
    printf("                       Encountered an error in TuxerOS\r\n");
    printf("\r\n");
    printf("Error: %s \n\r", errorMessage);
    printf("Registers:\n\r");
    printf("\teax=%x  ebx=%x  ecx=%x  edx=%x  esi=%x  edi=%x\n\r",
           regs->eax, regs->ebx, regs->ecx, regs->edx, regs->esi, regs->edi);
    printf("\tesp=%x  ebp=%x  eip=%x  eflags=%x  cs=%x  ds=%x  ss=%x\n\r",
           regs->esp, regs->ebp, regs->eip, regs->eflags, regs->cs, regs->ds, regs->ss);
    printf("Interrupt: %x\n\r", regs->interrupt);
    printf("Error: %x\n\r", regs->error);
    printf("\r\n");
    printf("               Please Reset your Computer using the Power Button");
    i686_Panic();
}