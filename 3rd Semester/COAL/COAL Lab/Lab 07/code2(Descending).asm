.model small
.386
.stack 100h

.data

message1 db 10,13,"Enter a String : $"
message2 db 10,13,"Sorted String : $"
input db 50 dup("$")
output db 50 dup ("$")
len dw 0

.code

main proc

	mov ax , @data
	mov ds , ax
	lea si , input

	lea dx , message1
	mov ah , 09h
	int 21h
	
	call stringInput
	
	call stringCMP
	
	lea dx , message2
	mov ah , 09h
	int 21h
	
	lea dx , input
	mov ah , 09h
	int 21h

mov ah , 4ch
int 21h

main endp

stringInput proc

again:
	mov ah , 01
	int 21h
	
	cmp al , 13
	JE exit
	
	inc [len]
	mov [si] , al
	inc si
	
	jmp again
	
exit:
	ret
stringInput endp

stringCMP proc

	lea si , input
	mov cx , [len]
outerloop:
	mov bx , 0
innerloop:
abc:
	mov al , [si + bx]
	mov dl , [si+bx + 1]
	cmp al , dl
	jl swap

bb:
	inc bx
	cmp bx , [len]
	JE	cc
	JMP abc
	
swap:

	mov [si+bx] , dl
	mov [si+bx+1] , al
	jmp bb
cc:
	dec cx
	jnz outerloop
exit:
	ret

stringCMP endp
end main