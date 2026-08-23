.model small
.stack 200h

.data
    nr1 dw 0000h
    nr2 dw 0000h
    bit1 dw 0000h
    bit2 dw 0000h
    carry dw 0000h
    aux dw 0000h

.code

citireNumar PROC ;numarul va fi construit in ax

        mov cx, 10
        xor bx, bx ;echivalent cu mov bx
        push bx

        citireCifra:
            mov ah, 01h
            int 21h         ;codul citi se retine in al
            cmp al, 13      ;comparam daca in al s-a citi "enter"
                je numarCitit

            sub al, '0'     ;transforma din ascii in numar zecimal
            mov bl, al      ;valoare numerica este copiata in bl
            pop ax          ;scoatem valoarea curenta numarului partial construit de pe stiva si o punem in ax
            mul cx          ;inmulti numarul curent pentru a face loc pentru cifra noua
            add ax, bx      ;adunam cifra curenta la numarul partial
            push ax         ;sticam numarul din nou in stiva
            jmp citireCifra

        numarCitit:
            pop ax
            ret
    ENDP citireNumar

ProcAfisareNumar PROC
        mov cx, 0
        mov bx, 10

        descompunere:
            xor dx, dx
            div bx
            push dx
            inc cx
            cmp ax, 0
                je afisareNumar
            jmp descompunere
        
        afisareNumar:
            pop dx
            add dx, '0'
            mov ah, 02h
            int 21h
        loop afisareNumar
        ret
    ENDP ProcAfisareNumar

;in am cele doua variabile nr1 si nr2 care imi retin cele doua numere

    adunare:

        inc bx

        mov bit1, 0
        mov bit2, 0 
        mov cx, 2       ;ca sa fac in binar

        mov ax, nr1 
        div cx          ;fac ax/cx = ax rest in dx
        mov bit1, dx    ;mutam restul care este fie 1 fie 0 in bit1
        mov nr1, ax     ;mutam in nr1 catul rezultatului anterior

        mov ax, nr2
        div cx          ;fac ax/cx = ax rest in dx
        mov bit2, dx    ;mutam restul care este fie 1 fie 0 in bit2
        mov nr2, ax     ;mutam in nr2 catul rezultatului anterior

        mov ax, bit1    ;mut in ax bit1
        mov dx, bit2    ;mut in dx bit2
        add ax, dx      ;facem adunarea caturiilor/bitiilor celor 2 numere bit cu bit    
        mov dx, carry   ;in "carry" vom tine overflow atunci cand adunarea intre biti este 2 sau 3
        add ax, dx

        cmp ax, 2       ;comparam ax cu 2 sa vedem daca adunarea bitnr1 + bitnr2 + carry este mai mare sau eala cu 2
        jge mare2       ;daca este mai mare sarim la alta operatie
        jmp gata        ;daca nu inseamna ca ax este 1 sau 0 asa ca poate fi bagat in stiva

        mare2:          ;cazul in care adunarea celor 3 este mai mare sau egal cu 2
        cmp ax, 3       ;acum vedem cazul in care adunarea este mai mare sau egala cu 3
        jge mare3        ;daca este 3 sarim la labelul specificat
        mov ax, 0       ;in acest caz suma a 2 atunci in carry vom pune 1 si in stiva 0
        mov carry, 1    ;punem 1 in carry
        jmp gata

        mare3:          ;cazul in care suma celor 3 este 3
        mov ax, 1       ;punem 1 in stiva, iar carry il facem 1
        mov carry, 1    ;carry il facem 1


        gata:
        push ax         ;pagam in stiva pe ax, deoarece stim ca lam caluculat corect cu situatiile anterioare

        ;in urmatoarele lini vom vedea daca ambele numere au devit zero
        ;in cazul in care cel putin un numar este fiferit de 0 vom contiunua cu rularea programulu
        ;daca ambele numere sunt 0 atunci de se va executa jump-ul si programul se va termina stiind ca numerele s-au adunat cu succes
        cmp nr1, 0
        jg adunare
        cmp nr2, 0
        jg adunare

        ;dar mai avem cazul in care carry este 1 la final, atunci acesta va trebuii bagat in stiva
        cmp carry, 1
        jl finish
        mov ax, carry
        inc bx

        push ax

        finish:

        jmp gataAdunare
        

    a2la10:

        mov dx, 2
        pop ax
        mov cx, bx
        dec cx
        nrTransformare:

            mov dx, 2
            mul dx

        loop nrTransformare

        mov dx, aux
        add ax, dx
        mov aux, ax

        dec bx

    cmp bx, 1
    jg a2la10
    jmp gatatot

    main:
        call citireNumar
        mov nr1, ax

        mov ax, 0

        call citireNumar
        mov nr2, ax

        ;mov nr1, 3
        ;mov nr2, 4
        mov aux, 0
        mov carry, 0
        mov bx, 0       ;bx va fi folosit pentru a determina cati biti are suma in binar
        mov bit1, 0
        mov bit2, 0

        jmp adunare

        gataAdunare:

        jmp a2la10
        gataNumar:

        mov ax, aux
        call afisareNumar

        ;afisareStiva:
            ;pop dx
            ;add dx, '0'
            ;mov ah, 02h
            ;int 21h
        ;loop afisareStiva
        gatatot:

        pop ax          ;scoatem ultimul bit din stiva
        mov dx, aux     ;el este fie 1 fie 0 asa ca nu mai trebuie sa il prelucram
        add ax, dx

        call ProcAfisareNumar
        mov ah, 4ch
        int 21h

    end main