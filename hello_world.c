/**
 * this is a demo of combining a simple C program with an assembly module using the ARM ISA
 */

#include <stdio.h>

/*
'extern' keyword used here to tell GCC that the 'add_' function exists but is defined OUTSIDE this source file
of which it is called and it should resolve the function's definition with this main program during the linking stage
*/
extern int add_(int x, int y);

int main(void)
{
	int sum=0;
	printf("hello world!\n");

	/*
	Arguments passed to the 'add_' function and the result of the function are stored in special-purpose registers,
	of which 4 exist in the ARM32 ISA specification and are part of calling conventions defined by the Application
	Binary Interface (ABI), which for arguments are r0-r3. More specifically, r0 and r1 can be either arguments or return values;
	r2 and r3 are just function arguments.

	sum should be 0xFF (255 in decimal) -> 0xF0 (240 in decimal), 0x0F (15 in decimal)
	*/
	sum=add_(0xF0, 0x0F); //As per the ABI calling conventions, 0xF0 should be stored in r0 and 0x0F should be stored in r1
	printf("sum of 0x%x, and 0x%x is: 0x%x\n", 0xF0, 0x0F, sum);
	return 0;
}
