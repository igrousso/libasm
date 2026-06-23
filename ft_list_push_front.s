extern malloc
global ft_list_push_front

section .text

; rdi : 1er argument = t_list **begin_list
; rsi : 2eme argument = void *data
; rax : valeur de retour
ft_list_push_front:
    test rdi, rdi
    je .end         ; si begin_list est null on return
    push rdi        ; save begin_list dans la stack
    push rsi        ; save data dans la stack
    mov rdi, 16     ; l'argument de malloc est 16 bytes, une instance de t_list fait 16 bytes (8 pour data, * pour next)
    sub rsp, 8      ; align stack sur 16 avant un call de fonction
    call malloc
    add rsp, 8
    pop rsi         ; on recupere begin_list de la stack
    pop rdi         ; on recupere data de la stack
    test rax, rax   ; si rax == 0 malloc a fail
    je .end
    mov [rax], rsi  ; on met data à l'adresse retourné par malloc
    mov rdx, [rdi]
    mov [rax + 8], rdx ; on met à next, le debut de la list pointé par begin_list
    mov [rdi], rax     ; on met à jour begin_list
.end:
    ret
