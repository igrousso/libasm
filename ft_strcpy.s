section .text
global ft_strcpy

; rdi : 1er argument = char *dst
; rsi : 2eme argument = char *src
; rax : valeur de retour
ft_strcpy:
    mov rax, rdi
.loop:
    mov cl, [rsi] ; on check byte par byte donc cl (taille de 1 byte) prend la valeur à l'adresse rsi
    test cl, cl ; cl AND cl : (cl == 0 ?)
    je .end
    mov [rdi], cl ; remplace le byte à l'adresse rdi par cl
    inc rdi
    inc rsi
    jmp .loop
.end:
    mov [rdi], cl ; rajout du '\0'
    ret
