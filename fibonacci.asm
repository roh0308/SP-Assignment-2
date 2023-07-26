segment .data
a dq 0
b dq 1
segment .text

global main
main:
push rbp
mov rbp,rsp
sub rsp,16

mov rdx,8
mov rax,0
mov rbx,1
mov rcx,1

forloop:
add rax,rbx
xchg rax,rbx
inc rcx
cmp rcx,rdx
jnz forloop

exit:
mov rax,60
xor rdi,rdi
syscall
