
;x86_64 win call conv

%define arg0 rcx
%define arg1 rdx
%define arg2 r8
%define arg3 r9

%define float_arg0 xmm0
%define float_arg1 xmm1
%define float_arg2 xmm2
%define float_arg3 xmm3

%macro push 2-*
%rep %0
push %1
%rotate 1
%endrep
%endmacro


%macro pop 2-*
%rep %0
pop %1
%rotate 1
%endrep
%endmacro

struc Shape
.type resb 4
.color resb 4
.perimeter resb 8
endstruc


section .text
global sort
extern printf

binarySearch:
enter 4, 0
cmp arg3, arg2
jg .else_0
	mov float_arg1, [arg1 + Shape.perimeter]
	mov float_arg0, [arg0 + arg2*Shape_size + Shape.perimeter]
	cmppd float_arg1, float_arg0
	jle .else_1
		add arg2, 1
		push arg2
		jmp .exit
	.else_1:
		push arg2
		jmp .exit
.else_0:
mov  dword [rsp], arg2
add dword [rsp], arg2
shrx dword [rsp]

mov float_arg1, [arg1 + Shape.perimeter]
mov rax, dword [rsp]
mov float_arg0, [rax + arg2*Shape_size + Shape.perimeter]

cmppd float_arg1, float_arg0
jne .else_2
	inc rax
	push rax
	jmp .exit

.else_2:
cmppd float_arg1, float_arg0
jg .else_3
	push arg0, arg1
	inc rax
	push rax
	push arg3
	call binarySearch
	pop rax
	push rax
	jmp .end

.else_3:
push arg0, arg1, arg2
	dec rax
	push rax
	call binarySearch
	pop rax
	push rax
	jmp .end

.end
pop rax
leave
ret

sort:

ret