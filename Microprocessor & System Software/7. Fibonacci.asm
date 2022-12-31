; Develop an assembly language program in MASM to generate first N Fibonacci numbers. Use procedures for reading and displaying numbers.

.model small

.stack 100H

.data

	limitprompt DB 'Enter the Limit (N): $'
	
	newline DB 10, 13, '$'

.code

.startup
	
	MOV AH, 09H
	MOV DX, OFFSET limitprompt
	INT 21H

	CALL readnumber

	MOV CX, AX
	
	MOV BX, 1H ; PREV = 1
	MOV AX, 0H ; CURRENT = 0
	MOV DX, 1H ; NEXT = 1
	
fibonacciloop:

	CALL displaynumber ; Print CURRENT i.e, AL
	
	PUSH AX
	PUSH DX
	MOV AH, 09H
	MOV DX, OFFSET newline
	INT 21H
	POP DX
	POP AX

	MOV BL, AL ; PREV = CURRENT
	MOV AL, DL ; CURRENT = NEXT
	
	MOV DL, BL ; NEXT = PREV + CURRENT
	ADD DL, AL ; ^

	; ALTERNATE APPROACH
	
;	MOV DL, BL ; NEXT = PREV
;	ADD BL, AL ; PREV += CURRENT
;	MOV AL, DL ; CURRENT = NEXT

	DEC CX
	JNZ fibonacciloop

endlabel:

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
