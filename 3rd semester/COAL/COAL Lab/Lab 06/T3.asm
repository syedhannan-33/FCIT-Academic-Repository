.model small
.stack 100h
.386
.data

str1 db 10,13,"Enter Expression: $"
str2 db 10,13,"You Enter correct: $"
str3 db 10,13,"You Enter incorrect: $"


.code
main proc
    mov ax,@data
    mov ds,ax

    mov ch , 0
    mov cl , 0

start:
    mov dx,offset str1
    mov ah,09
    int 21h

input:
    mov ah , 01h
    int 21h
    cmp al , 40
    inc cl
    cmp al , 41
    inc ch

    cmp al , 13
    je bb

    jmp input



bb:

    cmp ch , cl
    je cc

    jmp aa

aa:
    mov dx,offset str2
    mov ah,09
    int 21h
    jmp start

cc:
    mov dx,offset str3
    mov ah,09
    int 21h

mov ah,4ch
int 21h

main endp
end main

