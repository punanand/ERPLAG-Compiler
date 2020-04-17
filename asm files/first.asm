
section .data
	fmt: db "%hu %hu", 0
	p_fmt: db "%hu %hu", 0xA, 0

section .bss
	var1: resb 2
	var2: resb 2

section .text
	global main
	extern printf, scanf

main:
	push rbp
	mov rdi, fmt
	mov rsi, var1
	mov rdx, var2
	call scanf
	pop rbp

	push rbp
	mov rdi, p_fmt
	mov si, word [var1]
	mov dx, word [var2]
	mov rax, 2
	call printf
	pop rbp
	ret