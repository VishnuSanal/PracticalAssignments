; Write a procedure checkprime in MASM to check whether a number in AX is prime or not. If prime set BL = 1, else set BL=0 and return. Use the checkprime procedure to generate first N prime numbers. Use procedures for reading and displaying numbers.

.model small

.stack 100H

.data

	limitprompt DB 'Enter the Limit (N): $'
	
	newline DB 10, 13, '$'

.code

.startup
	
	MOV DX, 0H
	
	PUSH AX
	PUSH DX
	
	MOV AH, 09H
	MOV DX, OFFSET limitprompt
	INT 21H

	POP DX
	POP AX

	CALL readnumber

	MOV CX, AX

checkloop:

	MOV AX, DX
	
	CALL checkprime
	
	CMP BL, 0H
	JE notprime
	
isprime:

	DEC CX
	
	MOV AX, DX
	CALL displaynumber
	
	PUSH AX
	PUSH DX
	MOV AH, 09H
	MOV DX, OFFSET newline
	INT 21H
	POP DX
	POP AX

notprime:

	INC DX

	CMP CX, 0H
	JNE checkloop

.exit

checkprime PROC NEAR
	
	PUSH AX
	PUSH CX
	PUSH DX
	
	MOV BL, 0H
	
	CMP AL, 2
	JE primelabel
	
	CMP AL, 1H
	JBE notprimelabel

	MOV CL, AL
	MOV DL, AL

primeloop:
	
	DEC CL
	
	DIV CL
	
	CMP AH, 0H
	JE notprimelabel

	MOV AH, 0H
	MOV AL, DL
	
	CMP CL, 2H
	JA primeloop
	
primelabel:
	
	MOV BL, 1H
	
notprimelabel:
	
	POP DX
	POP CX
	POP AX
	
	RET

checkprime ENDP

readnumber PROC NEAR

	PUSH BX
	PUSH CX
	PUSH DX

	MOV BX, 00
	MOV CX, 10

looplabel:
	MOV AH, 01
	INT 21H

	CMP AL, '0'
	JB exitlabel

	CMP AL, '9'
	JA exitlabel

	MOV AH, 00
	
	SUB AL, 30H
	
	PUSH AX
	
	MOV AX, BX
	MUL CX
	MOV BX, AX
	
	POP AX
	
	ADD BX, AX
	
	JMP looplabel
	
exitlabel:
	MOV AX, BX

	POP DX
	POP CX
	POP BX
	
	RET

readnumber ENDP

displaynumber PROC NEAR

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	
	MOV CX, 00
	
	MOV BX, 10

looplabelone:
	MOV DX, 00
	
	DIV BX
	
	PUSH DX
	
	INC CX
	
	CMP AX, 00
	JNE looplabelone
	
looplabeltwo:	
	POP DX
	ADD DL, 30H
	
	MOV AH, 02H
	INT 21H
	
	LOOP looplabeltwo	
	
	POP DX
	POP CX
	POP BX
	POP AX

	RET

displaynumber ENDP

end
