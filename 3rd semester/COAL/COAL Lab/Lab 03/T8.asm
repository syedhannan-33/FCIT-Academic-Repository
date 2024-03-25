.model small
.stack 100h
.data

str1 db "Enter two digits:$"
str2 db "Error! Sum is greater than 9.$"
str3 db "Sum is $"

.code 
	main proc
	
	MOV AX , @DATA
	MOV DS , AX
	MOV DX , OFFSET str1
	MOV AH , 09H
	INT 21H
	
	MOV AH , 01H
	INT 21H
	
	MOV BL , AL
	SUB BL , 30H
	
	MOV AH , 01H
	INT 21H
	
	MOV CL , AL
	SUB CL , 30H
	
	ADD BL , CL
	
	CMP BL , 9H
	JL AA
	
	MOV DX , OFFSET str2
	MOV AH , 09H
	INT 21H
	JMP BB
	
AA: MOV DX , OFFSET str3
	MOV AH , 09H
	INT 21H
	
	ADD BL , 30H
	MOV DL , BL
	MOV AH , 02H
	INT 21H	
	
	
BB:	MOV AH , 4CH
	INT 21H

MAIN ENDP
END MAIN