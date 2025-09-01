bits 64

section .text
    global ft_read
    extern __errno_location

ft_read:
    mov rax, 0
    syscall
    test rax, rax
    jns .done             ; neg jump à .done
    mov rdi, rax          ; copie rax dans rdi
    neg rdi
    call [rel __errno_location wrt ..gotpc]
    mov [rax], edi
    mov rax, -1
.done:
    ret                   ; retourne eax (zero-extended rax)
