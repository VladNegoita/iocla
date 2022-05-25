section .text

global get_max

get_max:
	push rbp
	mov rbp, rsp

	; rdi first arg
	; rsi second arg

	xor rax, rax
	mov rcx, rsi
	mov rbx, rdi

compare:
	cmp eax, [rbx+rcx*4-4]
	jge check_end
	mov eax, [rbx+rcx*4-4]
check_end:
	loopnz compare

	leave
	ret
