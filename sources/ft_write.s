bits 64

section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1
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
