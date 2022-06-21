%include "../utils/printf32.asm"

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov eax, 172    ; to be broken down into powers of 2
    mov ebx, 1      ; stores the current power

start:
		
	test ebx, eax
	jnz print
	jmp next

print:

	PRINTF32 `%u\n\x0`, ebx

next:

	shl ebx, 1
	test ebx, ebx
	jz finish
	jmp start

finish:
	leave
	ret
