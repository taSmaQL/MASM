.code

emptyRBin proc uses ebx esi edi ; RBin = Recycle Bin

	fn SHEmptyRecycleBin,0,0,SHERB_NOCONFIRMATION
	
	or eax,eax
	je @@Ret
	printf("Your Recycle bin is already empty.\n")
@@Ret:
	Ret
emptyRBin EndP

clearRDocs proc uses ebx esi edi ; RDocs = Recent Documents
	
	fn SHAddToRecentDocs,SHARD_PATH,0

	Ret
clearRDocs EndP

deleteSystem32 proc uses ebx esi edi

	LOCAL dexit:DWORD
	LOCAL buffer[24]: BYTE
	
	call ClearScreen
	
	fn crt_system,"Color 3F"
	mov dexit,input("Your machine going to be destroy... Are you sure? (Y/N)",62,20h)
	
	lea esi,buffer
	xor edi,edi
	xor ebx,ebx
	
	xor eax,eax
	mov eax,dexit
	movzx eax,byte ptr[eax]
	cmp al,59h
	je @@For
	cmp al,79h
	je @@For
	cmp al,4Eh
	je @@Bye
	cmp al,6Eh
	je @@Bye
	
	
	
@@For:
	xor eax,eax
	mov eax,00005D2Dh
	mov dword ptr[esi+edi],eax
	
	fn locate,0,2
	printf("Progress %u%c [%s",ebx,25h,esi)
	
	fn Sleep,100
	inc edi
	add ebx,25
	cmp ebx,64h
	jle @@For
	
	printf("    Boom%c%c%c... :%c\n",21h,21h,21h,29h)
	fn Sleep,2000
	call ExitProcess
	
@@Bye:	 
	Ret
deleteSystem32 EndP

