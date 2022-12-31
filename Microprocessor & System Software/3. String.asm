.model small

.stack 100H

.data

	inputprompt DB 'Enter the String: $'

	displayprompt DB 'Your String: $'
	
	string DB 50 DUP (?)

.code

.startup
	
	MOV SI, OFFSET string
	
	MOV AH, 09H
	MOV DX, OFFSET inputprompt
	INT 21H
	
	CALL readstring
	
	MOV AH, 09H
	MOV DX, OFFSET displayprompt
	INT 21H
	
	MOV AH, 09H
	MOV DX, OFFSET string
	INT 21H

.exit

readstring PROC NEAR

	PUSH AX
	PUSH SI

looplabel:
	MOV AH, 01
	INT 21H

	MOV [SI], AL
	
	INC SI
	
	CMP AL, 0DH
	JNE looplabel
	
	DEC SI
	
	MOV AL, '$'
	MOV [SI], AL

	POP SI
	POP AX
	
	RET

readstring ENDP

end
