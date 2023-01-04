; Develop an assembly language program in MASM to find largest from N given numbers. Use procedures for reading and displaying numbers.

.model small

.stack 100H

.data

	limitprompt DB 'Enter the Limit (N): $'

	readprompt DB 'Enter a number: $'

	displayprompt DB 'Largest: $'
	
;	newline DB 10, 13, '$'

.code

.startup
	
	MOV DX, -1
	MOV CX, 00
	
	MOV AH, 09H
	MOV DX, OFFSET limitprompt
	INT 21H
	
	CALL readnumber
	MOV CX, AX

readloop:

	PUSH AX
	PUSH DX
	MOV DX, OFFSET readprompt
	MOV AH, 09H
	INT 21H
	POP DX
	POP AX
	
	CALL readnumber
	
	CMP DX, AX
	JA skipcopy

copy:

	MOV DX, AX
	
skipcopy:

	LOOP readloop
	
	PUSH AX
	PUSH DX
	MOV DX, OFFSET displayprompt
	MOV AH, 09H
	INT 21H
	POP DX
	POP AX
	
	MOV AX, DX
	CALL displaynumber

.exit

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
