section .text
global ft_strlen

; rdi : 1er argument = char *str
; rax : valeur de retour
ft_strlen:
    xor rax, rax ; rax = 0
.loop:
    mov bl, [rdi + rax] ; bl prend la valeur à l'adresse rdi + rax
    test bl, bl ; bl AND bl sans stocker le resultat, compare avec 0 ('\0')
    je .end
    inc rax
    jmp .loop
.end:
    ret ; rax a déjà la bonne valeur, c'est lui qui a servi de compteur