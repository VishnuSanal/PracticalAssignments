.model small

.stack 100H

.data

	inputprompt DB 'Enter the String: $'

	displayprompt DB 'Your String: $'

	searchprompt DB 'Character to search: $'

	notfound DB 'Character not found $'

	foundat DB 'Character found at index: $'

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

	MOV DX, OFFSET searchprompt
	INT 21H

	MOV AH, 01
	INT 21H

	MOV BL, AL

	MOV SI, OFFSET string

	CALL searchstring

	MOV DX, OFFSET newline
	INT 21H

	CMP CL, -1
	JNE successlabel
	
	MOV AH, 09H
	MOV DX, OFFSET notfound
	INT 21H

	JMP finishlabel

successlabel:

	MOV AH, 09H
	MOV DX, OFFSET foundat
	INT 21H

	ADD CL, 30H

	MOV AH, 02H
	MOV DL, CL
	INT 21H

finishlabel:

.exit

searchstring PROC NEAR

	PUSH AX
	PUSH BX
	PUSH SI

	MOV CL, -1

looplabel:

	MOV AL, [SI]

	INC SI
	INC CL

	CMP AL, '$'
	JE endlabel

	CMP AL, BL
	JE exitlabel

	JMP looplabel

endlabel:

	MOV CL, -1

exitlabel:

	POP SI
	POP BX
	POP AX

	RET

searchstring ENDP

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

end
