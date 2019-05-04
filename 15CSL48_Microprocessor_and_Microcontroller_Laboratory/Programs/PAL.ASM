.MODEL SMALL
.STACK
.DATA
	ARRAY1 DB 30 DUP(?)
	ARRAY2 DB 30 DUP(?)

	M1 DB 10,13,"ENTER THE STRING:",10,13,'$'
	M2 DB 10,13,"ENTERED STRING IS PALINDROME",10,13,'$'
	M3 DB 10,13,"ENTERED STRING IS NOT A PALINDROME"

.CODE
	MOV AX,@DATA
	MOV DS,AX
	MOV ES,AX 			; Need Extra segment for palindrome program

	LEA SI,ARRAY1		; Load effective address
	LEA DI,ARRAY2

	LEA DX,M1			; display M1
	MOV AH,9
	INT 21H

	MOV CX,00			; clear counter

UP1:	MOV AH,1
		INT 21H			; take input from keyboard

		CMP AL,13		; check if enter key is pressed
		JZ UP2

		INC CX
		MOV [SI],AL
		INC SI
		JMP UP1			; store character in array and repeat

UP2:	DEC SI

UP3:	MOV AL,[SI]		; copy reverse string to ARRAY2
		MOV [DI],AL

		INC DI
		DEC SI
		JNZ UP3

		LEA SI,ARRAY1
		LEA DI,ARRAY2

		CLD 			; clear direction
		REPE CMPSB 		; repeat comparing string byte

		JE PALIN 		; if equal, print palindrome

		LEA DX,M3 		; print M3
		MOV AH,9
		INT 21H
		JMP EXIT1

PALIN:	LEA DX,M2
		MOV AH,9
		INT 21H

EXIT1:	MOV AH,4CH
		INT 21H
END