global ft_list_sort

section .text

; rdi : 1er argument = t_list **begin_list
; rsi : 2eme argument = int (*cmp)()
; rax : valeur de retour = void
ft_list_sort:
    push r12        ; preserved register
    push r13        ; preserved register
    push r14        ; preserved register + aligné la stack sur 16
    test rdi, rdi
    je .end
    test rsi, rsi
    je .end
    mov r12, [rdi]   ; save *begin_list
    mov r13, rsi     ; save ptr sur fonction
.loop1:
    mov r14, [r12 + 8]
    test r14, r14    ; check si null
    je .end
.loop2:
    test r14, r14
    je .end_loop
    mov rdi, [r12]   ; ->data
    mov rsi, [r14]   ; ->data
    call r13         ; on appelle la fonction cmp
    test rax, rax
    jle .skip
    mov r8, [r14]    ; ->data
    mov r9, [r12]    ; ->data
    mov [r14], r9
    mov [r12], r8    ; swap
.skip:
    mov r14, [r14 + 8]  ; next
    jmp .loop2
.end_loop:
    mov r12, [r12 + 8]  ; next
    jmp .loop1
.end:
    pop r14
    pop r13
    pop r12
    ret