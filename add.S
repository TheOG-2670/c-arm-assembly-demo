/*purpose: adds 2 numbers and returns the sum*/
	
	.global 	add_ /*exposes the 'add' as a symbol so other modules that need it can refer to it during the linking stage*/
	.type 		add_, %function /*defines the type of 'add_' (a function)*/

add_: /*label that defines assembly code below*/
	.fnstart /*denotes the start of a function*/
	/*as per ABI and the structure of RISC-V instructions, the first argument of 'add_' from the C source file is stored in the second r0 (first source register for the 
	operation) and the second argument is stored in r1 (second source register for the operation). Since r0 and r1 can either be function argument registers or return 
	value registers, the first r0 in the operation will store the result of the 'add_' operation.
	*/
	add 		r0,r0,r1
	bx 			lr /*return the sum by branch to the link register*/
	.fnend /*denotes the end of a function*/
