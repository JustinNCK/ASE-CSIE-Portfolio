.model small
.stack 100h
.data
    num1l dw 0000h   
    num1h dw 4050h   ;num1 4050 0000h  -  3.25
    num2l dw 0000h
    num2h dw 4020h   ;num2 4020 0000h  -  2.5

    result_sign db 00h

    result_exponent db 00h

    num1_mantissa dw 0000h
    num2_mantissa dw 0000h

    result dd 00000000h
.code
    main:
        mov ax, @data
        mov ds, ax

        ;to calculate the sign bit we xor the MSB
        ;for that, we need to extract it with a mask

        mov ax, num1h
        mov bx, num2h

        and ax, 8000h           ;mask ax MSB with 1000 0000 0000 0000
        and bx, 8000h           ;mask bx MSB with 1000 0000 0000 0000
        xor ax, bx              ;xor the sign bits
        
        ;ah's MSB now stores the sign of our result

        mov result_sign, ah
        

        ;next we extract exponents to add
        mov ax, num1h
        mov bx, num2h 

        and ax, 7E80h        ;mask ax exponent with mask 0111 1111 1000 0000
        and bx, 7E80h        ;mask bx exponent with mask 0111 1111 1000 0000

        shr ax, 7
        shr bx, 7

        ;now al and bl should have the exponent values
        ;we need to add them now

        sub al, 127 ;because we are adding 2 exponents, we also have 2 127-biases so we need to remove one of them
        add al,bl ; exponent sum result is stored in al, any carry bits carry over to ah, so result is in ax;

        mov result_exponent, al

        ;mantissa multiplication
        ;we take the last 7 bits from numxh and the first 9 from numxl
        ;and we move them into a single register

        mov ax, num1h
        mov bx, num2h

        and ax, 007Fh  ;mask last 7 bits of high reg
        and bx, 007Fh  ;mask last 7 bits of high reg

        shl ax, 9       ;shift them to be the first 7 bits
        shl bx, 9       ;shift them to be the first 7 bits

        mov num1_mantissa, ax
        mov num2_mantissa, bx

        mov ax, num1l
        mov bx, num2l

        shr ax, 7      ;shift them to be the last 9 bits
        shr bx, 7      ;shift them to be the last 9 bits

        xor ax, num1_mantissa   ;if i did this right, the mantissas should be in ax and bx
        xor bx, num2_mantissa   ;but we need to account for the 1 behind the floating point

        shr ax, 1           ;shift right by one to make room for the 1
        shr bx, 1           ;shift right by one to make room for the 1

        xor ax, 8000h       ;add 1
        xor bx, 8000h       ;add 1

        mul bx          ;finally multiply mantissas

        ;result stored in dx:ax
        ;but now we need to somehow check if we need to shift the mantissa and change the exponent

        afisareNumar:
            ;pop dx
            ;extragem din stiva
            add dx, 48
            ;transformam din cifra in caracter ASCII
            mov ah, 02h
            int 21h
            ;invocarea intreruperii cu codul 02H
            ;adica afisarea caracterului al carui cod este in DL
        loop afisareNumar

        mov ah, 4ch
        int 21h
    end main

;4050h 0000h 2x 16 bit representation of 3.25
;4020h 0000h 2x 16 bit representation of 2.5

;mul multiplies ax with bx, result is in dx:ax
