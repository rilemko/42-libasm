bits 64

section .text
    global ft_strlen

ft_strlen:
    xor rax, rax          ; met rax à 0 (compteur)
.loop:
    cmp byte [rdi], 0     ; si *rdi == 0 (fin de chaîne)
    je .done              ;     alors on saute à la fin
    inc rax               ; sinon on incrémente le compteur
    inc rdi               ;         on avance le pointeur
    jmp .loop             ;         on recommence
.done:
    ret                   ; retourne rax (longueur)
