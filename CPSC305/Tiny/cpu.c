#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include <string.h>
#include <string.h>
#include <string.h>
#include "isa.h"

static int registers[16];

static int cpsr; // status register

/* For future implementation of breakpoints
 *
#define NUM_BREAKPOINTS 2
static int breakpoints[NUM_BREAKPOINTS]; // allow 2 break points 
*/

void set_reg(int reg, int value) {
	registers[reg] =  value;
}

int get_reg(int reg) {    
	return registers[reg];
}

int get_cpsr() {
    	return cpsr;
}

void show_regs() {
    for (int i = 0; i < 16; i++){
        printf("R%d: %d\n",registers[i]);
    }
}

void step() {
    	//given
        int pc = registers[PC];
        int inst;
        system_bus(pc, &inst, READ);
        //print inst and PC
        printf("PC: 0x%08x, ",ps)
        printf("inst: 0x%08x, \n",inst);

        decoded *d = decode(inst);
        int x = 0;
        //print CPSR
        printf("CPSR: 0x08x\n",get_cpsr());
        registers[PC] += 4;

        //switch statments depending on opcode
        switch(d->opcode){
                case B:
                        //switch statement depending on which type of branching
                        switch(d->condition){
                                case 0:
                                        registers[PC] = d->address;
                                        break;
                                case 1:
}

void step_n(int n) {
    	printf("You need to implement step_n().\n");
}

void step_show_reg() {
    	printf("You need to implement step_show_reg().\n");
}

void step_show_reg_mem() {
    	printf("You need to implement step_show_reg_mem().\n");
}
