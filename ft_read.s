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
    test rax, rax
    jl .error
    ret
.error:
    neg rax ; inverse rax, devient le bon code errno
    mov rdi, rax
    sub rsp, 8 ; alignement de la stack
    call __errno_location ; return un pointeur sur errno
    add rsp, 8
    mov [rax], edi ; change errno, utilisation de edi au lieu de rdi car errno est un int (4 bytes)
    mov rax, -1 ; code de retour de read
    ret
