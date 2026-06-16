global ft_strcmp
section .text

; rdi : 1er argument = char *s1
; rsi : 2eme argument = char *s2
; rax : valeur de retour
ft_strcmp:
    xor r10, r10 ; r10 = 0
    xor rax, rax ; rax = 0
    xor rcx, rcx ; rcx = 0
.loop:
    mov al, [rdi + r10] ; al prend la valeur à l'adresse rdi + r10
    mov cl, [rsi + r10] ; cl prend la valeur à l'adresse rsi + r10
    cmp al, cl
    jne .end
    test al, al ; equivalent de cmp al, 0 (en plus rapide)
    inc r10
    jmp .loop 
.end:
    sub rax, rcx
    ret 