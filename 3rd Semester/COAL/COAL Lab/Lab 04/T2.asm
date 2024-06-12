.model small
.stack 100h

.data

message1 db "Enter a Word : $"
message2 db "Reverse is  : $"


reverse db 10 dup('$')


.code
main proc

	MOV AX , @DATA
	MOV DS , AX
	
	MOV DX , OFFSET message1
	MOV AH , 09H
	INT 21H
	
	MOV SI , OFFSET reverse
	MOv di , SI
	
aa:	MOV AH , 01	;input1
	INT 21H
	
	
	CMP AL  , 13
	JE exit
	MOV [SI] , AL
	INC SI
	jmp aa

exit:
	MOV DX , OFFSET message2
	MOV AH , 09H
	INT 21H

	dec si

bb:	MOV DL , [SI]
	MOV AH , 02
	INT 21H
	DEC SI
	CMP SI , di
	JaE bb
	

	
terminate :mov ah , 4ch
int 21h

main endp
end main