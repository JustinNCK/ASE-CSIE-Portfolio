bucla dw 0
proc binar
	mov bx, 2
	xor cx, cx	
	desc:    ;pe stiva se pun 21212121
		pop ax
		mov aux, ax
		xor dx, dx
		div bx
		pop ax
		push dx
		div bx
		push dx
		inc cx
		mov dx, aux
		push ax
		push dx
		cmp ax, 1
			je doi
		cmp dx, 1
			je unu
		jmp desc
	doi:    ;aici se va descompune al doilea numar
		mov exp1, cx
		pop ax
		xor dx, dx
		div bx
		mov aux, dx
		mov dx, 0
		push dx
		mov dx, aux
		push dx
		inc cx
		cmp ax, 1
			je adunare
		jmp doi
	unu:
		mov exp2, cx
		pop ax
		xor dx, dx
		div bx
		push dx
		mov dx, 0
		push dx
		inc cx
		cmp ax, 1
			je adunare
		jmp unu
	adunare:
		mov ax, 0
		push ax
		rep:
			pop ax
			pop bx
			pop cx
			mov dx, 10
			add bx, cx
			//un test pentru transport dar nu mai stiu exact care era flagul si daca are transport il retinem in cx cred
			mul dx
			add ax, bx
			push ax
			add bucla, 1
			cmp bucla, 15
				je axEstePlin
			jmp rep
	axExtePlin:	
		mov mantisaFinal16, ax
		mov ax, 0
		push ax
		repeta:
			pop ax
			pop bx
			pop cx
			mov dx, 10
			add bx, cx
			//un test pentru transport dar nu mai stiu exact care era flagul si daca are transport il retinem in cx cred
			mul dx
			add ax, bx
			push ax
			add bucla, 1
			cmp bucla, 15
				je axEstePlin
			jmp repeta
		mantise:
			mov mantisaInceput8, ax
endp