.model small
.stack 100h
.data

str db "Hello$"

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	MOV DX , OFFSET str
	MOV AH , 09H
	INT 21H
	
MOV AH , 4CH
INT 21H

MAIN ENDP
END MAIN