bits 64

section .text
    global ft_strdup
    extern malloc
    extern ft_strcpy
    extern ft_strlen

ft_strdup:
    push rbx
    mov rbx, rdi
    call ft_strlen
    add rax, 1
    mov rdi, rax
    call malloc wrt ..plt
    test rax, rax
    je .done
    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy
.done:
    pop rbx
    ret                   ; retourne rax
