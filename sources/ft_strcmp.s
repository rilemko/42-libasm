bits 64

section .text
    global ft_strcmp

ft_strcmp:
.loop:
    mov al, [rdi]         ; copie [rdi] dans al
    mov dl, [rsi]         ; copie [rsi] dans dl
    cmp al, dl            ; si al != dl
    jne .diff             ;     alors on saute à .diff
    cmp al, 0
    je .done
    inc rdi               ; sinon on avance le pointeur 1ere arg
    inc rsi               ;       on avance le pointeur 2eme arg
    jmp .loop             ;       on recommence
.diff:
    movzx eax, al          ; zero-extend al en eax (unsigned char s1)
    movzx edx, dl          ; zero-extend dl en edx (unsigned char s2)
    sub eax, edx           ; eax = eax - edx = s1[i] - s2[i]
    ret
.done:
    xor     eax, eax
    ret                   ; retourne eax (zero-extended rax)
