section .text
global ft_strlen

; rdi : 1er argument = char *str
; rax : valeur de retour
ft_strlen:
    xor rax, rax ; rax = 0
.loop:
    mov cl, [rdi + rax] ; cl prend la valeur à l'adresse rdi + rax
    test cl, cl ; cl AND cl sans stocker le resultat, compare avec 0 ('\0')
    je .end
    inc rax
    jmp .loop
.end:
    ret ; rax a déjà la bonne valeur, c'est lui qui a servi de compteur