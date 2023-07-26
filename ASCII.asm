segment .text
global main
main:
mov rax,8
add rax,48
mov rdx,rax

Exit:
mov rax,1
xor rbx,rbx
int 0x80
