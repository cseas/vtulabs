.MODEL SMALL
.STACK 64
.DATA
	N DB 6
        K DB 3
	RES DB 0
.CODE
	MOV AX,@DATA
	MOV DS,AX

	MOV AL,N
	MOV BL,K

        CALL NCK

	MOV AH,4CH
	INT 21H

NCK PROC

        CMP BL,0 			; nC0 = 1
	JNE L1
	ADD RES,1
	RET

L1:	CMP BL,AL			; nCn = 1
	JNE L2
	ADD RES,1
	RET

L2:	CMP BL,1 			; nC1 = n
	JNE L3
	ADD RES,AL
	RET

L3:	DEC AL 				; nC(n-1) = n
	CMP BL,AL
	JNE L4
	INC AL
	ADD RES,AL
	RET

L4:     PUSH AX                     ; store AX BX and call NCK
	PUSH BX

	CALL NCK

	POP BX
	POP AX

	DEC BX 				; decrement BX and repeat

	PUSH AX
	PUSH BX

	CALL NCK

	POP BX
	POP AX
	RET 				; DON'T FORGET RETURN STATEMENT

NCK ENDP
END

