.model small
.stack 100h

.data

message1 db "Enter 1ST Number from 0 to 9 :$"
message2 db "Enter 2ND Number from 0 to 9 :$"
message3 db "Do you want to exit (y) or restart (n) :$"

err1 db "Sorry you have entered wrong $"
err2 db "first number is greater than second number $"
err3 db "you have entered wrong options thrice , program aborted $"

.code
main proc

	MOV AX , @DATA
	MOV DS , AX
		
	MOV CH , 03H
	
START:	MOV DX , OFFSET message1
	MOV AH , 09H
	INT 21H
	

	
	MOV AH , 01	;input1
	INT 21H
	
	MOV BL , AL	; cmp for error1
	CMP BL , 40H
	JGE	ERROR1
	
	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	MOV DX , OFFSET message2
	MOV AH , 09H
	INT 21H
	
	MOV AH , 01	;input 2
	INT 21H
	
	MOV CL , AL	; cmp for error1
	CMP CL , 40H
	JGE	ERROR1

	
	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	CMP CL , BL		;cmp error 2
	JL	m3
	

aa:	MOV DL , BL
	MOV AH , 02
	INT 21H
	
	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	INC BL
	CMP CL , BL
	JGE	aa
	
	JMP m3
	
	
ERROR1:	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	MOV DX , OFFSET err1
	MOV AH , 09H
	INT 21H
	JMP m3
	
ERROR2:	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H

	MOV DX , OFFSET err2
	MOV AH , 09H
	INT 21H
	JMP m3
	
abort: MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	MOV DX , OFFSET err3
	MOV AH , 09H
	INT 21H
	
	JMP terminate
	
	
m3:	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	MOV DX , OFFSET message3
	MOV AH , 09H
	INT 21H
	
	MOV AH , 01
	INT 21H
	
	MOV BH , AL
	
	MOV DL , 10
	MOV AH , 02
	INT 21H
	
	MOV DL , 13
	MOV AH , 02
	INT 21H
	
	DEC CH
	JZ abort
	
	CMP BH , 'n'
	JE START
	

	
	
terminate :mov ah , 4ch
int 21h

main endp
end main