global ft_strlen

ft_strlen: 
		mov     rax, 0                  ;   init rax to 0
		jmp     while                   ;   jump to while
while:
		cmp     BYTE[rdi + rax], 0      ;   compare first argument rdi at rax index with null byte
		je      return                  ;   if == jump to return
		inc     rax                     ;   rax = rax + 1
		jmp     while                   ;   jump to while like a loop

return:
		ret                             ;   return rax as length of the string
