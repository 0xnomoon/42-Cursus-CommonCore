global  ft_strcmp

ft_strcmp:
		mov     rax, 0                                  ; 0 in rax
		mov     rcx, 0                                  ; 0 in rcx as an index
		mov     dl, 0                                   ; 0 in dl (char)
		jmp     loop                                    ; jump to loop
loop:
		cmp     BYTE[rdi + rcx], 0                      ; compare 1st arg with null byte
		je      return                                  ; if so jump to return
		cmp     BYTE[rsi + rcx], 0                      ; compare 2nd arg with null byte
		je      return                                  ; if so jump to return
		mov     dl, BYTE[rsi + rcx]                     ; put 2nd byte at rcx index in dl
		cmp     BYTE[rdi + rcx], dl                     ; compare 1st arg and 2nd arg at equals rcx index
		jne     return                                  ; if != go to return
		inc     rcx                                     ; index rcx = rcx + 1
		jmp     loop                                    ; jump to loop
negative:
		mov     rax, -1                                 ; put return value rax at -1
		ret                                             ; return fonction
positive:
		mov     rax, 1                                  ; put return value rax at 1
		ret                                             ; return fonction
return:
		mov     dl, BYTE[rsi + rcx]                     ; put 2nd arg byte at rcx index in dl (char)
		cmp     BYTE[rdi + rcx], dl                     ; compare 1st arg at rcx index byte with dl
		jb      negative                                ; if dl is > go to negative
		mov     dl, BYTE[rdi + rcx]                     ; pute 1st arg byte at rcx index in dl (char)
		cmp     BYTE[rsi + rcx], dl                     ; compare 2nd arg at rcx index byte with dl
		jb      positive                                ; if dl is > go to positive
		ret                                             ; return fonction
