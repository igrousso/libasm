global ft_list_size

section .text

; rdi : 1er argument =  t_list *begin_list
; rax : valeur de retour = int
ft_list_size:
    xor rax, rax        ; rax = 0
    test rdi, rdi       ; check si rdi == 0
    je .end
    inc rax
.loop:
    mov rsi, [rdi + 8]  ; on donne à rsi la partie next de l'instance
    test rsi, rsi
    je .end
    inc rax
    mov rdi, rsi        ; rdi devient l'instance pointé par next
    jmp .loop
.end:
    ret