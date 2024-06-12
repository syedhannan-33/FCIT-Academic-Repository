.model small
.386
.stack 100h

.data
message1 db  10,13,"Enter a character: $"
message2 db  10,13,"The ASCII code of "
var db 0
message3 db " in HEX is $"

.code 

main proc 
	
	MOV AX , @DATA
	MOV DS , AX
	
start:
	MOV DX , OFFSET message1
	MOV AH , 09H
	INT 21H
	
	MOV AH , 01h	;input1
	INT 21H
	
	CMP AL , 13
	JE exit
	
	mov [var] , al
	mov bl , [var]
	
	MOV DX , OFFSET message2
	mov ah , 09h
	INT 21H
	
	MOV CL,2
	
aa:	
	ROL BL , 4
	MOV DL , BL
	AND DL , 15
	cmp dl , 9
	JLE bb
	
	add dl , 07h
	
bb: add dl , 30h
	
	MOV AH , 02h
	INT 21h
	
	dec CL
	jnz aa
	
	JMP start
	
	
	
	
exit:
	MOV AH , 4Ch
	INT 21h

main endp
end  main
