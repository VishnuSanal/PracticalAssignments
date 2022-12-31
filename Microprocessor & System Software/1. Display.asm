.model small

.stack 100H

.data

message DB "HelloWorld!$"

.code

.startup

MOV AH, 09H
MOV DX, OFFSET message
INT 21H

.exit

end
