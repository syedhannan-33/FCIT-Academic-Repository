.model small
.stack 100h
.data

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	
	MOV BL , 10
L2:	MOV BH , 10
	
L1:	MOV DL , '*'
	MOV AH , 02H
	INT 21H
	
	DEC BH
	JNZ L1
	
	mov DL , 10 
	MOV AH , 02H
	INT 21H
	
	mov DL , 13
	MOV AH , 02H
	INT 21H
	
	DEC BL
	JNZ L2
	
	

	
MOV AH , 4CH
INT 21H

MAIN ENDP
END MAIN