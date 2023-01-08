; Develop an assembly language program in MASM to reverse each word in a string

.model small

.stack 100H

.data

	inputprompt DB 'Enter the String: $'

	displayprompt DB 'Your String: $'
	
	resultprompt DB 'Reversed String: $'
	
	debug DB 'debug$'
	debugreverse DB 'reverse$'
	
	newline DB 10, 13, '$'
	
	string DB 50 DUP (?)

.code

.startup

	MOV SI, OFFSET string

	MOV AH, 09H
	MOV DX, OFFSET inputprompt
	INT 21H
	
	CALL readstring
	
	MOV DX, OFFSET displayprompt
	INT 21H
	
	MOV DX, OFFSET string
	INT 21H

	MOV DX, OFFSET newline
	INT 21H
	
	MOV SI, OFFSET string
	MOV DI, SI

whitespacespaceloop:
	
	MOV AH, 0H
	MOV AL, [SI]
	
	CMP AL, 20H ; whitespace
	JNE checkforend
	
	CALL reversestring
	
	MOV DI, SI
	INC DI
	
checkforend:

	INC SI
	
	CMP AL, '$'
	JNE whitespacespaceloop
	
	DEC SI
	
	CALL reversestring
	
	MOV [SI], '$'

	MOV AH, 09H
	MOV DX, OFFSET resultprompt
	INT 21H
	
	MOV DX, OFFSET string
	INT 21H

.exit

reversestring PROC NEAR

	PUSH AX
	PUSH SI
	PUSH DI
	PUSH CX
	PUSH DX
	
	MOV CX, 0H

	MOV DX, DI
	
traverselabel:

	MOV AH, 0H
	MOV AL, [DI]
	
	PUSH AX
	
	INC DI
	INC CX
	
	CMP DI, SI
	JNE traverselabel

	MOV DI, DX

looplabel:

	POP AX

	MOV [DI], AX
	
	INC DI

	LOOP looplabel

exitlabel:

	POP DX
	POP CX
	POP DI
	POP SI
	POP AX

	RET

reversestring ENDP

readstring PROC NEAR

	PUSH AX
	PUSH SI

readlooplabel:
	MOV AH, 01
	INT 21H

	MOV [SI], AL
	
	INC SI
	
	CMP AL, 0DH
	JNE readlooplabel
	
	DEC SI
	
	MOV AL, '$'
	MOV [SI], AL

	POP SI
	POP AX
	
	RET

readstring ENDP

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
