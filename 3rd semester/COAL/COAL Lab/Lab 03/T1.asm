.model small
.stack 100h
.data

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	MOV DL , 'A'
	MOV AH , 02H
	INT 21H
	
MOV AH , 4CH
INT 21H

MAIN ENDP
END MAIN