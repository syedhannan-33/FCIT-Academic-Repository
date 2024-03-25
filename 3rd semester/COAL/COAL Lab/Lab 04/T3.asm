.model small
.stack 100h

.data

message1 db "Enter String : $"
message2 db "Vowel Character  : $"


string db 10 dup('$')


.code
main proc

	MOV AX , @DATA
	MOV DS , AX
	
	MOV DX , OFFSET message1
	MOV AH , 09H
	INT 21H
	
	MOV SI , OFFSET string
	
	MOV CL , '0'
	
	
aa:	MOV AH , 01	;input1
	INT 21H
	
	MOV [SI] , AL
	MOV BL , AL
	INC SI

	
	CMP BL, 'a'
	JE CC
	CMP BL , 'e'
	JE CC
	CMP BL , 'i'
	JE CC
	CMP BL , 'o'
	JE CC
	CMP BL , 'u'
	JE CC
	

	
ab:	CMP AL  , 13
	JNE aa
	
	MOV DX , OFFSET message2
	MOV AH , 09H
	INT 21H
	
	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	MOV DL , CL
	MOV AH , 02H
	INT 21H
	
	JMP terminate
	
CC: Add CL , 1
	JMP ab
	
	
terminate :mov ah , 4ch
int 21h

main endp
end main