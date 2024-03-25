.model small
.stack 100h
.data

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	MOV DL , '?'
	MOV AH , 02H
	INT 21H
	
	MOV AH , 01H
	INT 21H
	MOV BL , AL
	
	MOV AH , 01H
	INT 21H
	MOV CL , AL
	
	mov DL , 10 
	MOV AH , 02H
	INT 21H
	
	mov DL , 13
	MOV AH , 02H
	INT 21H
	
	CMP BL , CL
	JG aa
	
	MOV DL , BL
	MOV AH , 02H
	INT 21H
	
	MOV DL , CL
	MOV AH , 02H
	INT 21H
	
	JMP bb
	
	
aa: MOV DL , CL
	MOV AH , 02H
	INT 21H
	
	MOV DL , BL
	MOV AH , 02H
	INT 21H
	
	
	
	
bb: MOV AH , 4CH
	INT 21H

MAIN ENDP
END MAIN