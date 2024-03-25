.model small
.386
.stack 100h

.data

arr db 5 dup(0)

.code 

main proc	
	
	mov ax , @data
	mov ds , ax
	
	lea si , arr
	lea di , arr
	mov cl , 05

input:	
	xor bl , bl
	call BinaryInput
	dec cl
	Jnz input
	
	mov ch , 05
	
output:	

	call HexaDecimalOutput
	dec ch
	jnz output
	
	
	
mov ah , 4ch
int 21h

main endp

BinaryInput proc
	
	mov ch , 8
aa:
	rol bl , 1
	
	mov ah , 01
	int 21h
	
	sub al , 30h
	or bl , al
	
	dec ch
	jnz aa
	
	mov [si] , bl
	inc si
	
	mov dl , 10
	mov ah , 02h
	int 21h
	
	mov dl , 13
	mov ah , 02h
	int 21h
	
	ret
	
BinaryInput endp

HexaDecimalOutput proc
	mov bx , 0
	mov bl , [di]
	mov cl , 04
again:
	rol bx , 4
	mov dl , bl
	and dl , 0fh
	cmp dl , 09h
	Jbe aa
	add dl , 07
aa:
	add dl , 30h
	mov ah , 02
	int 21h
	dec cl
	jnz again
	
	inc di

	mov dl , 10
	mov ah , 02h
	int 21h
	
	mov dl , 13
	mov ah , 02h
	int 21h
	
	ret
HexaDecimalOutput endp


end main