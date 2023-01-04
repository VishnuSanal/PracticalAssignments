; Not Working : Always shows not a pallindrome!

.model small

.stack 100H

.data

	inputprompt DB 'Enter the String: $'

	displayprompt DB 'Your String: $'

	validpallindrome DB 'Given String is a Valid Pallindrome$'

	invalidpallindrome DB 'Given String is a not a Valid Pallindrome$'
	
	debugprompt DB 'Debug: $'

	newline DB 10, 13, '$'

	string DB 50 DUP ('$')

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
	
	CALL pallindromecheck

	MOV DX, OFFSET newline
	INT 21H
	
	CMP CL, 01H
	JE successlabel
	
	MOV AH, 09H
	MOV DX, OFFSET invalidpallindrome
	INT 21H

	JMP finishlabel

successlabel:

	MOV AH, 09H
	MOV DX, OFFSET validpallindrome
	INT 21H

finishlabel:

.exit

pallindromecheck PROC NEAR

	PUSH AX
	PUSH BX
	PUSH DX
	PUSH DI
	PUSH SI

	MOV AX, 00
	MOV CX, 00
	
	MOV SI, OFFSET string

traverselabel:

	MOV AH, 0H
	MOV AL, [SI]

	CMP AL, '$'
	JE endlabel

	INC SI
	INC CL

	JMP traverselabel

endlabel:

	DEC SI

	MOV DI, SI
	
	MOV SI, OFFSET string

checklooplabel:

	MOV AL, [SI]
	MOV BL, [DI]

	CMP AL, BL
	JNE falselabel
	
	CMP SI, DI
	JE truelabel
	
	INC SI
	DEC DI

	JMP checklooplabel

falselabel:

	MOV CL, 00H
	JMP exitlabel
	
truelabel:
	
	MOV CL, 01H
	
exitlabel:

	POP SI
	POP DI
	POP DX
	POP BX
	POP AX

	RET

pallindromecheck ENDP

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
