%include "printf32.asm"

section .data
    myString: db "Hello, World!", 0
    yourString: db "Goodbye, World!", 0

section .text
    global main
    extern printf

main:
    mov ecx, 6                      ; N = valoarea registrului ecx
    mov eax, 2
    mov ebx, 1
    cmp eax, ebx
    jg print
    ret

print:
    mov eax, 0

here:
    PRINTF32 `%s\n\x0`, myString
    add eax, 1
    cmp eax, ecx
    je out
    jne here
    
out:
    PRINTF32 `%s\n\x0`, yourString

    ret
