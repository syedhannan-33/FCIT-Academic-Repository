.model small
.stack 100h
.386
.data

str1 db 10,13,"Enter a string: $"
str2 db 10,13,"You Enter: $"
str3 db 50 dup('$')


.code
main proc
    mov ax,@data
    mov ds,ax

    mov si , offset str3
    mov cl , 0

    mov dx,offset str1
    mov ah,09
    int 21h

input:
    mov ah , 01h
    int 21h
    cmp al , 13
    je cc
    inc cl
    push ax
    
    cmp al , 20h
    je abc

    jmp input

cc:
	mov bl , 20h
	mov [si] , bl
	inc si
	
abc:
    pop bx
    mov [si] , bl
    inc si
    dec cl
    jnz abc
	cmp al , 13
	je bb
    jmp input


bb:
	
    mov dx,offset str2
    mov ah,09
    int 21h

    mov dx,offset str3
    mov ah,09
    int 21h

mov ah,4ch
int 21h

main endp
end main

