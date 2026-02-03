include main.inc

.code
start:

	call main
	push eax
	call ExitProcess
	
	
main proc
	call menu
	xor eax,eax
	ret
main EndP

end start

