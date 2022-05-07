section .data
    before_format db "before %s", 13, 10, 0
    after_format db "after %s", 13, 10, 0
    mystring db "abcd ! efghij", 0
    mystring2 db "ana", 0, "are", 0, "mere", 0

section .text

extern printf
global main



toupper:
    push ebp
    mov ebp, esp

    mov eax, dword [ebp + 8]
in:

    mov bl, byte [eax]
    mov cl, 0x61
    mov dl, 0x7a

    test bl, bl
    jz out

    cmp bl, cl
    jl next

    cmp bl, dl
    jg next

    sub bl, 0x20
    mov byte [eax], bl

next:

    inc eax
    jmp in

out:

    leave
    ret




rot13:
    push ebp
    mov ebp, esp

    mov eax, dword [ebp + 8]
    mov ecx, dword [ebp + 12]

start:
    mov bl, byte [eax]

    test bl, bl
    jz end_c

    cmp bl, 0x6e
    jl plus

minus:
    sub bl, 13
    jmp step

plus:
    add bl, 13
    jmp step


end_c:
    mov bl, 0x20

step:
    mov byte [eax], bl
    inc eax
    dec ecx
    jz stop
    jmp start

stop:
    leave
    ret



main:
    push ebp
    mov ebp, esp

    push mystring
    push before_format
    call printf
    add esp, 8

    push mystring
    call toupper
    add esp, 4

    push mystring
    push after_format
    call printf
    add esp, 8


    push dword 12
    push mystring2
    call rot13
    add esp, 8

    push mystring2
    push after_format
    call printf
    add esp, 8

    leave
    ret
