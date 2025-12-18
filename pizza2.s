.section .data
num_pizzas:  .word 0
pizza_price: .word 15
total_cost: .word 0
.section .rodata
prompt: .ascii "Welcome to the HD Pizza Shop, where every pizza is assembled to perfection.\n\0"
.align 2
prompt2: .ascii "How many pizzas would you like to order? \0"
.align 2
prompt3: .ascii "You have ordered %d pizzas.\n\0"
.align 2
prompt4: .ascii "Thank you! Please stop by for a byte again sometime!\n\0"
.align 2
prompt5:	.ascii "Your total is $%d\n\0"
.align 2
format: .ascii "%d\0"
.align 2

.global main
main:
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #12

	
	ldr r0, prompt_ptr /*Welcome statement*/
	bl printf

	ldr r0, prompt2_ptr /*string for how many pizzas the user would like*/
	bl printf

	ldr r0, format_ptr /*getting user input*/
	sub r1, fp, #8
	bl scanf

	
	ldr r0, prompt3_ptr/*reiterating how many pizzas the customer ordered*/
	ldr r1, [fp, #-8]
	bl printf

	/*calculate total cost*/
	ldr r0, [fp, #-8]
	ldr r1, pizza_price_ptr
	ldr r1, [r1]
	mul r2, r0, r1
	/*Print Total Cost*/
	ldr r0, prompt5_ptr
	mov r1, r2
	bl printf
	
	ldr r0, prompt4_ptr /*thank the customer*/
	bl printf

	sub sp, fp, #4
	pop {fp, pc}

prompt_ptr: .word prompt /*Prompt pointer for the first statement*/
prompt2_ptr: .word prompt2 /*Prompt pointer for the second statement*/
prompt3_ptr: .word prompt3 /*Prompt pointer for the third statement*/
prompt4_ptr: .word prompt4 /*Prompt pointer for the fourth statement*/
format_ptr: .word format /*Prompt pointer for formatting string addition response*/
prompt5_ptr:	.word prompt5
pizza_price_ptr: .word pizza_price
