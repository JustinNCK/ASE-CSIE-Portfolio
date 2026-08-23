.model small
.stack 200h
.data
.code
    main:
        mov ax, @data
        mov ds, ax

        mov ax, 1
        not al
        add ax, 1
        mov bx, ax
        mov ax, 2
        not al
        add ax, 1
        add ax, bx

        not ax
        
        afisare:
            mov cx, 8
            mov bx, 2
            desc:
                xor dx, dx
                div bx
                push dx
                cmp ax, 0
                    je numar
                jmp desc
            numar:
                pop dx
            loop numar
            mov cx, 8
            finish:
                pop dx
                add dx, '0'
                mov ah, 02h
                int 21h
            loop finish

        mov ah, 4ch
        int 21h
    end main