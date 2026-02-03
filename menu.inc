

.data
	szMenu	db "+---------------------------------+",13,10
			db "|1:    Empty recycle bin          |",13,10
			db "|2: Clear the recent document menu|",13,10
			db "|3: Delete the System32 folder    |",13,10
			db "|4:       Exit from console       |",13,10
			db "+---------------------------------+",13,10,0

.code

menu proc
	LOCAL choice:DWORD
	LOCAL dexit:DWORD ; Do you wanna exit?
	
	printf("%s",offset szMenu)
	
@@While:
		mov choice,input("What do you wanna choice?",62,20h)
		mov eax, choice
		movzx eax, byte ptr[eax]
		
		cmp al,31h
		jne @F
		
		call emptyRBin
		
		jmp @@While
	@@:
		cmp al,32h
		jne @F
		
		call clearRDocs
		
		jmp @@While
	@@:
		cmp al,33h
		jne @F
		
		call deleteSystem32
		
		jmp @@While
	@@:
		cmp al,34h
		je @DRet ; Do you wanna Return? D - Do. Ret - Return
	
	
		printf("Input Error. Try again (1-4).\n")
		jmp @@While
	@DRet:
		mov dexit, input("Do you want to exit from program for sure? (Y/N)",62,20h)
		xor eax,eax
		mov eax,dexit
		movzx eax,byte ptr[eax]
		cmp al,59h
		je @@Bye
		cmp al,79h
		je @@Bye
		cmp al,4Eh
		je @@While
		cmp al,6Eh
		je @@While
	@@Bye:	 
		Ret
menu EndP
