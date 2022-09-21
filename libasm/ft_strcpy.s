global ft_strcpy

ft_strcpy:
		mov     rcx, 0                  ;   rcx at 0
		mov     dl, 0                   ;   dl (char) at 0
		jmp     loop                    ;   jump to loop
loop:
		cmp     BYTE[rsi + rcx], 0      ;   compare 2nd argument src with null character
		je      return                  ;   if == go to return
		mov     dl, BYTE[rsi + rcx]     ;   put 2nd argument at rcx index char in dl
		mov     BYTE[rdi + rcx], dl     ;   put dl char in 1st argument rdi
		inc     rcx                     ;   rcx = rcx + 1
		jmp     loop                    ;   jump to loop
return:
		mov     dl, BYTE[rsi + rcx]     ;   put 2nd argument at rcx index char in dl (null char)
		mov     BYTE[rdi + rcx], dl     ;   put dl char in 1st argument rdi (null char)
		mov     rax, rdi                ;   put 1st argument rdi in rax
		ret                             ;   return rax
