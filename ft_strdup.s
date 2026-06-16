extern __errno_location
extern ft_strcpy
extern ft_strlen
extern malloc
global ft_strdup

section .text

; rdi : 1er argument = char *str
; rax : valeur de retour
ft_strdup:
    push rdi ; save ptr sur str
    call ft_strlen
    inc rax
    mov rdi, rax ; donne la taille à allouer pour malloc
    call malloc
    pop rsi
    test rax, rax ; si rax == 0 malloc a fail
    je .error
    mov rdi, rax ; donner le nouveau ptr au premier argument pour strcpy
    call ft_strcpy    
.error:
    ret
