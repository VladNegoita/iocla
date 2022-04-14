%include "../utils/printf32.asm"

%define ARRAY_SIZE 3

section .data
    byte_array db 8, 19, 12
    word_array dw 1893, 9773, 892
    dword_array dd 1392849, 12544, 879923
    print_format db "Array sum is ", 0
    print_form db "Array sq_sum is ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, ARRAY_SIZE     ; Use ecx as loop counter.
    xor eax, eax            ; Use eax to store the sum.
    xor edx, edx            ; Store current value in dl; zero entire edx.

add_byte_array_element:
    mov dl, byte [byte_array + ecx - 1]
    add eax, edx
    loop add_byte_array_element ; Decrement ecx, if not zero, add another element.

    PRINTF32 `%s\x0`, print_format
    PRINTF32 `%u\n\x0`, eax

    mov ecx, ARRAY_SIZE
    xor eax, eax
add_word_array_element:
    mov dx, word [word_array +2*(ecx - 1)]
    add eax, edx
    loop add_word_array_element ; Decrement ecx, if not zero, add another element.

    PRINTF32 `%s\x0`, print_format
    PRINTF32 `%u\n\x0`, eax

    mov ecx, ARRAY_SIZE
    xor eax, eax
add_dword_array_element:
    mov edx, dword [dword_array + 4*(ecx - 1)]
    add eax, edx
    loop add_dword_array_element ; Decrement ecx, if not zero, add another element.

    PRINTF32 `%s\x0`, print_format
    PRINTF32 `%u\n\x0`, eax

    xor ebx, ebx
    mov ecx, ARRAY_SIZE
add_sq_byte_array_element:
    xor edx, edx
    mov dl, byte [byte_array + ecx - 1]
    mov eax, edx  
    mul edx
    add ebx, eax
    loop add_sq_byte_array_element ; Decrement ecx, if not zero, add another element.

    PRINTF32 `%s\x0`, print_form
    PRINTF32 `%u\n\x0`, ebx

    leave
    ret
