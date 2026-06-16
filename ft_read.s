extern __errno_location
global ft_read

section .text

; rdi : 1er argument = int fd
; rsi : 2eme argument = void *buf
; rdx : 3eme argument = size_t count
; rax : valeur de retour
ft_read:
    xor rax, rax ; syscall 0 =  read
    syscall
    cmp rax, 0
    jl .error
    ret
.error:
    neg rax ; inverse rax, devient le bon code errno
    mov rdi, rax
    call __errno_location ; return un pointeur sur errno
    mov [rax], rdi ; change errno
    mov rax, -1 ; code de retour de read
    ret
