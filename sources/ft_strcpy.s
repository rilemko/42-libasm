bits 64

section .text
    global ft_strcpy

ft_strcpy:
    mov rax, rdi
.loop:
    mov dl, [rsi]         ; copie rsi dans dl
    mov [rdi], dl         ; copie dl dans rdi
    cmp dl, 0             ; si *dl == 0 (fin de chaîne)
    je .done              ;     alors on saute à la fin
    inc rdi               ; sinon on avance le pointeur 1ere arg
    inc rsi               ;       on avance le pointeur 2eme arg
    jmp .loop             ;       on recommence
.done:
    ret                   ; retourne rax
