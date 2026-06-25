    global ft_list_remove_if

    section .text

    ; rdi : 1er argument = t_list **begin_list
    ; rsi : 2eme argument = void *data_ref
    ; rdx : 3eme argument = int (*cmp)()
    ; rcx : 4eme argmuent = void (*free_fct)(void *)
    ; rax : valeur de retour = void
    ft_list_remove_if:
        push r12
        push r13
        push r14
        push r15        
        push rbx        ; tous preserved registers + alignement 16
        test rdi, rdi
        je .end
        test rsi, rsi
        je .end
        test rdx, rdx
        je .end
        test rcx, rcx
        je .end
        mov r15, rdi    ; save begin_list
        mov r14, rsi    ; save data_ref
        mov r13, rdx    ; save ptr sur fonction cmp
        mov r12, rcx    ; save ptr sur fonction free
        mov rbx, [r15]  ; *begin_list
    .loop1:
        test rbx, rbx
        je .all_remove
        mov rdi, [rbx]      ; data
        mov rsi, r14        ; data_ref
        call r13
        test rax, rax
        jne .endloop1
        mov rdi, [rbx]      ; data
        call r12
        mov rbx, [rbx + 8]  ; next
        jmp .loop1
    .endloop1:
        mov [r15], rbx
        mov rdi, [rbx + 8]
    .loop2:
        test rdi, rdi
        je .end
        mov rdi, [rdi]      ; data
        mov rsi, r14        ; data_ref
        call r13
        test rax, rax
        jne .skip
        mov rdi, [rbx + 8]
        mov rdi, [rdi]      ; data
        call r12
        mov rdi, [rbx + 8]
        mov rdi, [rdi + 8]
        mov [rbx + 8], rdi
        jmp .loop2
    .skip:
        mov rbx, [rbx + 8]
        mov rdi, [rbx + 8]
        jmp .loop2
    .all_remove:
        mov qword [r15], 0x0
    .end:
        pop rbx
        pop r15
        pop r14
        pop r13
        pop r12
        ret