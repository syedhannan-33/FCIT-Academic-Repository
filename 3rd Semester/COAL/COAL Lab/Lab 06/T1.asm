.model small
.stack 100h
.386
.data

str1 db 10,13,"Enter a decimal digit : $"
str2 db 10,13,"The sum of hex digits is : $"
str3 db 10,13, "you entered incorrect digit try again $"


.code
main proc
    mov ax,@data
    mov ds,ax
a1:
    mov dx,offset str1
    mov ah,09
    int 21h

    mov bx , 0000

input:
    mov ah , 01h
    int 21h
    cmp al , 39h
    jg check
    cmp al , 13
    je bb
    sub al , 30h
    add bl , al
    jmp input

bb:
    mov dx , offset str2
    mov ah , 09h
    int 21h

    call hexSum

mov ah,4ch
int 21h

check:
    mov dx , offset str3
    mov ah , 09h
    int 21h
    jmp a1

main endp

hexSum proc 

    mov cl , 02h
again:
    rol bl , 04h
    mov dl , bl
    and dl , 0fh
    cmp dl , 09h
    jbe cc
    add dl , 07h
cc:
    add dl , 30h
    mov ah , 02h
    int 21h
    dec cl
    jnz again

    ret

hexSum endp

end main

