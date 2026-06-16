section .text
global ft_strcpy

;# rdi : 1er argument = char *dst
;# rsi : 2er argument = char *src
;# rax : valeur de retour
ft_strcpy:
  mov rax, rdi
loop:
  mov bl, [rsi] ;# on check byte par byte donc bl (taille de 1 byte) prend la valeur à l'adresse rsi
  cmp bl, 0x0 ;# compare avec 0 ('\0')
  je end
  mov [rdi], bl ;# remplace le byte à l'adresse rdi par bl
  inc rdi
  inc rsi
  jmp loop
end:
  mov [rdi], bl ;# rajout du '\0'
  ret
