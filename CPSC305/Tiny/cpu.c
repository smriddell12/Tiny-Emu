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
					if(bit_test(cpsr,Z) == 1){
                                                registers[PC] = d->address;
                                        }
                                        break;
                                case 2:
                                        if(bit_test(cpsr,Z) == 0){
                                                registers[PC] = d->address;
                                        }
                                        break;
                                case 3:
                                        if(bit_test(cpsr,Z) == 1 || bit_test(cpsr,N) != bit_test(cpsr,V)){
                                                registers[PC] = d->address;
                                        }
                                        break;
                                case 4:
                                        if(bit_test(cpsr,N) != bit_test(cpsr,V)){
                                                registers[PC] = d->address;
                                        }
                                        break;
                                case 5:
                                        if(bit_test(cpsr,N) == bit_test(cpsr,V)){
                                                registers[PC] = d->address;
                                        }
                                        break;
                                case 6:
                                        if(bit_test(cpsr,Z) == 0 && bit_test(cpsr,N) == bit_test(cpsr,V)){
                                                registers[PC] = d->address;
                                        }
                                        break;
				case 80:
                                        registers[LR] = pc + 4;
                                        registers[PC] = d->address;
                                        break;
                                default:
                                        printf("Instruction is invalid.\n");
                                        exit(-1);
                        }
                        break;
                case LDR:
                        system_bus(d->address, &registers[d->rd], READ);
                        break;
                case STR:
                        system_bus(d->address, &registers[d->rd], WRITE);
                        break;
                case MOV:
                        if(d->flag == 128){
                                registers[d->rd] = d->rn;
                        }else{
                                registers[d->rd] = d->immediate;
                        }
                        break;
                case ADD:
                        registers[d->rd] = registers[d->rm] + registers[d->rn];
                        break;
                case SUB:
                        registers[d->rd] = registers[d->rm] - registers[d->rn];
                        break;
                case MUL:
			registers[d->rd] = registers[d->rm] * registers[d->rn];
                        break;
                case DIV:
                        registers[d->rd] = registers[d->rm] / registers[d->rn];
                        break;
                case ORR:
                        registers[d->rd] = registers[d->rm] | registers[d->rn];
                        break;
                case EOR:
                        registers[d->rd] = registers[d->rm] ^ registers[d->rn];
                        break;
                case AND:
                        registers[d->rd] = registers[d->rm] & registers[d->rn];
                        break;
                case CMP:
                        x = registers[d->rm] - registers[d->rn];
                        if(x == 0){
                                bit_set(&cpsr,Z);
                                bit_clear(&cpsr,N);
                        }else if(v < 0){
                                bit_set(&cpsr,N);
                                bit_clear(&cpsr,Z);
                        }else{
                                bit_clear(&cpsr,N);
                                bit_clear(&cpsr,Z);
                        }
                        break;
        }
}

void step_n(int n) {
        for (int i = 0; i < n; i++){
                step();
        }
}

void step_show_reg() {
    	printf("You need to implement step_show_reg().\n");
}

void step_show_reg_mem() {
    	printf("You need to implement step_show_reg_mem().\n");
}
