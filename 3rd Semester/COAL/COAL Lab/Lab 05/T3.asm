.model small
.386
.stack 100h

.data
message1 db  10,13,"Enter a hex number(0 to FFFF): $"
message2 db  10,13,"Illegal hex digit, try again: $"
message3 db 10 , 13 ," in binary it is $"

.code 

main proc 
	
	MOV AX , @DATA
	MOV DS , AX
	
	mov bx , 0000h
	
	MOV DX , OFFSET message1
	MOV AH , 09H
	INT 21H
	
	mov ch , 4 ; 4 CHAR INPUT
	
aa:
	mov ah , 01h
	int 21h
	
	cmp al , 60h
	Ja	validity
	
	
	cmp al , 13
	je zz
	
	cmp al , '9'
	Jle xyz
	sub al , 07h
	
xyz:
	sub al , 30h
	
	and al , 8
	
	or bl , al
	ROL bx , 4
	dec ch
	jnz aa
	
	jmp zz

validity:
	MOV DX , OFFSET message2
	MOV AH , 09H
	INT 21H
	
	mov ch , 4
	JMP  aa

zz:
	MOV DX , OFFSET message3
	MOV AH , 09H
	INT 21H
	
	mov cl , 16
	
BIN:	
	ROL Bx , 1
	MOV DL , BL
	AND DL , 01h
	cmp dl , 9
	jle yyy
	add dl , 07h
	
yyy:
	add dl , 30h
	
	
BIN2: 
	MOV AH , 02h
	INT 21h
	
	DEC  CL
	JNZ	BIN	
	
exit:
	MOV AH , 4Ch
	INT 21h

main endp
end  main
