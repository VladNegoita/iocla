%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 139
    mov ebx, 169
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

    ; TODO1: reuniunea a doua multimi
    xor ecx, ecx
    or ecx, eax
    or ecx, ebx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO2: adaugarea unui element in multime
    xor edx, edx
    or edx, 1
    shl edx, 2 ; adaug elementul 2
    or ecx, edx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO3: intersectia a doua multimi
    xor ecx, ecx
    or ecx, eax
    and ecx, ebx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO4: complementul unei multimi
    xor ecx, ecx
    or ecx, eax
    not ecx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO5: eliminarea unui element
    xor ecx, ecx
    xor ecx, eax
    xor edx, edx
    or edx, 1
    shl edx, 0 ; elimin elementul 0
    not edx
    and ecx, edx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO6: diferenta de multimi EAX-EBX
    xor ecx, ecx
    or ecx, eax
    xor ecx, ebx
    and ecx, eax
    PRINTF32 `%u\n\x0`, ecx

    xor eax, eax
    ret
