.data
	szMenu	db "+---------------------------------+",13,10
			db "|1:         Calculate             |",13,10
			db "|2:       Exit from console       |",13,10
			db "+---------------------------------+",13,10,0
			
.code

menu proc
	LOCAL choice:DWORD
	
	printf("%s",offset szMenu)
	
@@While:
		mov choice,input("What do you wanna choice?",62,20h)
		mov eax, choice
		movzx eax, byte ptr[eax]
		
		cmp al,31h
		jne @F
		call calculate
		
		jmp @@While
	@@:
		cmp al,32h
		je @Ret
		
		printf("Input Error. Try again (1-2).\n")
		jmp @@While
		
	@Ret:		 
		Ret
menu EndP
