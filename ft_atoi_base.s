extern __errno_location
extern ft_strlen
global ft_atoi_base

section .text

; rdi : 1er argument = char *str
; rsi : 2eme argument = char *base
; rax : valeur de retour
ft_atoi_base:
.check_arg:
    mov r9, rdi ; save rdi
    mov rdi, rsi ; pass char *base en 1er argument pr strlen
    ; r9 = char *str
    ; rdi = char *base
    call ft_strlen
    cmp rax, 1
    jle .error_arg
    mov rsi, rax    ; save la taille dans rsi puisque je ne l'utilise pas (rsi) apres
    mov r8, rdi
    dec r8
.check_loop: ; check duplicate + whitespace + '+' et '-'
    inc r8
    mov cl, [r8]
    test cl, cl ; check si on arrive au '\0'
    je .end_loop
    cmp cl, 0x20     ; check si
    je .error_arg    ; espace
    cmp cl, 0x2b    ; check si
    je .error_arg   ; '+'
    cmp cl, 0x2d     ; check si
    je .error_arg    ; '-'
    cmp cl, 0xd     ; check si > de /r
    jg .end_check   ; si > , on passe à la suite direct
    cmp cl, 0x7      ; check si >= de /a
    jge .error_arg   ; si >= , alors c'est un whitespace 
.end_check:
    mov r10, r8
.check_loop_2:
    inc r10
    mov dl, [r10]
    test dl, dl ; check si on arrive au '\0'
    je .check_loop
    cmp cl, dl  ; check si
    je .error   ; duplicate
    jmp .check_loop_2
.end_loop:
    ; r9 = char *str
    ; rdi = char *base

.skip_whitespace_loop:
    mov cl, [r9]
    cmp cl, 0x20
    je .skip_whitespace
    cmp cl, 0xd
    jg .end_skip
    cmp cl, 0x7
    jl .end_skip
.skip_whitespace:
    inc r9
    jmp .skip_whitespace_loop
.end_skip:
    mov r11, 1  ; setup variable pour le negatif
    cmp cl, 0x2b
    je .symbol
    cmp cl, 0x2d
    jne .nosymbol 
    mov r11, -1  ; variable pour le negatif à -1 si un - est trouvé devant
.symbol:
    inc r9
.nosymbol:
    xor rax, rax ; reset rax à 0 avant de le remplir
.start_convert:
    mov cl, [r9]
    test cl, cl
    je .end
    mov r8, rdi  ; r8 = char *base
.check_base:
    mov dl, [r8]
    test dl, dl  ; test si dl == '\0'
    je .end
    cmp cl, dl   ; on a la position du chiffre par rapport à la base (r8 - rdi)
    je .end_check_base
    inc r8
    jmp .check_base
.end_check_base:
    imul rax, rsi   ; nbr * taille de la base
    mov r10, r8
    sub r10, rdi    ; calcule la position du chiffre (r8 - rdi)
    add rax, r10
    inc r9
    jmp .start_convert
.end:
    imul rax, r11   ; multiplie la valeur finale par la variable pour le negatif
    ret

.error_arg:
    mov edi, 0x16 ; 1er argument pour __errno_location (0x16 = EINVAL)
    sub rsp, 8 ; alignement de la stack
    call __errno_location
    add rsp, 8
    mov [rax], edi ; change errno
.error:
    xor rax, rax
    ret 