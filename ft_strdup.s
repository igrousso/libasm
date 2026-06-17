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
    sub rsp, 8 ; alignement de la stack avant un call, rsp doit etre un multiple de 16
    call ft_strcpy
    add rsp, 8 ; restaure RSP à sa valeur initiale, garantissant que l'adresse de retour est correctement placée pour le ret
.error:
    ret
