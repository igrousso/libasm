section .text
global ft_strlen

;# rdi : premier argument = char *str
;# rax : valeur de retour
ft_strlen:
  xor rax, rax ;# rax = 0
loop:
  mov bl, [rdi + rax] ;# bl = valeur à l'adresse rdi + rax
  cmp bl, 0x0
  je end
  inc rax
  jmp loop
end:
  ret ;# rax a déjà la bonne valeur, c'est lui qui a servi de compteur