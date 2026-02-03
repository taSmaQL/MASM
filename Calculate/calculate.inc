.data 

	szMenuChoice	db "+---------------------------------+",13,10
					db "|1:         Use: +                |",13,10
					db "|2:         Use: -                |",13,10
					db "|3:         Use: *                |",13,10
					db "|4:         Use: /                |",13,10
					db "|5:         Use: N^2              |",13,10
					db "+---------------------------------+",13,10,0


.code

calculate proc uses ebx esi edi

	LOCAL dexit:DWORD
	LOCAL numb1:DWORD
	LOCAL numb2:DWORD
	
	printf("%s",offset szMenuChoice)
	
	xor edi,edi
	xor ebx,ebx
	xor eax,eax
	xor ecx,ecx
	xor edx,edx
	
	mov eax,input("What do you wanna choice?",62,20h)
	movzx ebx, byte ptr[eax]
	
	mov eax,input("Ok. Say first number",62,20h)
	movzx eax, byte ptr[eax]
	sub al, 30h
	mov esi,eax
	
	mov eax,input("Ok. Say first number",62,20h)
	movzx eax, byte ptr[eax]
	sub al, 30h
	
	cmp bl,31h
	jne @F
	
	add eax,esi
	printf("Your number is: %u. Operetaion was (+, add)\n",eax)
	
	fn Sleep,2000

@@:

	cmp bl,32h
	jne @F
	
	sub esi,eax
	printf("Your number is: %d. Operetaion was (-,subtraction)\n",esi)
	
	fn Sleep,2000
	
@@:

	cmp bl,33h
	jne @F
	
	imul eax,esi
	printf("Your number is: %d. Operetaion was (*,multiple)\n",eax)
	
	fn Sleep,2000
	
@@:
	
	cmp bl,34h
	jne @F
	
	mov ecx,eax
	mov eax,esi
	cdq
	
	idiv ecx
	printf("Your number is: %d. Operetaion was (/,divide)\n",eax)
	
	fn Sleep,2000
	
@@:
	cmp bl,35h
	jne @F
	
	mov ecx,eax
	mov eax,1
	
@@For:
	imul eax,esi
	loop @@For

	printf("Your number is: %d. Operetaion was (N^N, exponentiation)\n",eax)
	fn Sleep,2000
	
@@:

	Ret
calculate EndP

