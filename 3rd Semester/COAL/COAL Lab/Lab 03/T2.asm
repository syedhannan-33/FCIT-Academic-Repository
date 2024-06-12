.model small
.stack 100h
.data

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	MOV AH , 01H
	INT 21H
	
	MOV BL , AL
	
	mov DL , 10 
	MOV AH , 02H
	INT 21H
	
	mov DL , 13
	MOV AH , 02H
	INT 21H
	
	MOV DL , BL
	MOV AH , 02H
	INT 21H
	
MOV AH , 4CH
INT 21H

MAIN ENDP
END MAIN