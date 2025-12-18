.section .data
num_pizzas:  .word 0
pizza_price: .word 15
total_cost: .word 0
small_price: .word 10
medium_price: .word 15
large_price:  .word 20
.section .rodata
prompt: .ascii "Welcome to the HD Pizza Shop, where every pizza is assembled to perfection.\n\0"
.align 2
prompt2: .ascii "How many pizzas would you like to order? \0"
.align 2
prompt3: .ascii "You have ordered %d pizzas.\n\0"
.align 2
prompt4: .ascii "Thank you! Please stop by for a byte again sometime!\n\0"
.align 2
prompt5: .ascii "Your total is $%d\n\0"
.align 2
prompt6: .ascii "How many small pizzas would you like? \0"
.align 2
prompt7: .ascii "How many medium pizzas would you like? \0"
.align 2
prompt8: .ascii "How many large pizzas would you like? \0"
.align 2

format: .ascii "%d\0"
.align 2

.text
.global main
main:
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #28

	
	ldr r0, prompt_ptr /*Welcome statement*/
	bl printf

	ldr r0, prompt6_ptr /*string for how many small pizzas the user would like*/
	bl printf

	ldr r0, format_ptr /*getting user input*/
	sub r1, fp, #8
	bl scanf

	ldr r0, prompt7_ptr /*string for how many medium pizzas the user would like*/
	bl printf

	ldr r0, format_ptr /*getting user input*/
	sub r1, fp, #12
	bl scanf
	
	ldr r0, prompt8_ptr /*string for how many large pizzas the user would like*/
	bl printf

	ldr r0, format_ptr /*getting user input*/
	sub r1, fp, #16
	bl scanf

	/*calculate total number of pizzas by calling function sum*/
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	ldr r2, [fp, #-16]
	bl sum
	str r0, [fp, #-20]
	/*print total amount of pizzas*/
	ldr r0, prompt3_ptr
	ldr r1, [fp, #-20]
	bl printf
	
	/*calculate total cost*/
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	ldr r2, [fp, #-16]
	bl cost
	str r0, [fp, #-24]
	/*Print Total Cost*/
	ldr r0, prompt5_ptr
	ldr r1, [fp, #-24]
	bl printf
	
	ldr r0, prompt4_ptr /*thank the customer*/
	bl printf

	sub sp, fp, #4
	pop {fp, pc}



.text
.global sum
sum:
push {fp, lr}
add fp, sp, #4
sub sp, sp, #12

str r0, [fp, #-8]
str r1, [fp, #-12]
str r2, [fp, #-16]

add r0, r0, r1
add r0, r0, r2

str r0, [fp, #-8]

sub sp, fp, #4
pop {fp, pc}


.text
.global cost
cost:	
push {fp, lr}
add fp, sp, #4
sub sp, sp, #24

str r0, [fp, #-8]
str r1, [fp, #-12]
str r2, [fp, #-16]

ldr r0, [fp, #-8]/*small pizza price count*/
ldr r1, =small_price
ldr r1, [r1]
mul r0, r0, r1
str r0, [fp, #-20]

/*medium pizza price count*/
ldr r0, [fp, #-12]
ldr r1, =medium_price
ldr r1, [r1]
mul r0, r0, r1
str r0, [fp, #-24]


/*large pizza price count*/
ldr r0, [fp, #-16]
ldr r1, =large_price
ldr r1, [r1]
mul r0, r0, r1
str r0, [fp, #-28]
/*add the cost together by calling sum*/	
ldr r0, [fp, #-20]
ldr r1, [fp, #-24]
ldr r2, [fp, #-28]
bl sum


sub sp, fp, #4
pop {fp, pc}
	


	
	
prompt_ptr: .word prompt /*Prompt pointer for the first statement*/
prompt2_ptr: .word prompt2 /*Prompt pointer for the second statement*/
prompt3_ptr: .word prompt3 /*Prompt pointer for the third statement*/
prompt4_ptr: .word prompt4 /*Prompt pointer for the fourth statement*/
format_ptr: .word format /*Prompt pointer for formatting string addition response*/
prompt5_ptr:	.word prompt5
pizza_price_ptr: .word pizza_price
prompt6_ptr:	.word prompt6
prompt7_ptr:	.word prompt7
prompt8_ptr:	.word prompt8
