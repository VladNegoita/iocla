%include "../utils/printf32.asm"

section .data
    N dd 9 ; compute the sum of the first N fibonacci numbers
    print_format_1 db "Sum first %d", 10, 0
    print_format_2 db "fibo is %d", 10, 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    push dword [N]
    push print_format_1
    call printf
    add esp, 8

    ; TODO: calculate the sum of first N fibonacci numbers
    ;       (f(0) = 0, f(1) = 1)

    mov eax, 1

    mov ecx, dword [N]
    sub ecx, 1

    mov ebx, 0
    mov edx, 1

add_fibo:

    xor esi, esi
    add esi, ebx
    add esi, edx

    add eax, esi

    mov ebx, edx
    mov edx, esi

    loop add_fibo


    push eax
    push print_format_2
    call printf
    add esp, 8

    xor eax, eax
    leave
    ret
