.MODEL SMALL
.STACK
.DATA
        M1 DB 10,13,"Current Time is $"
        M2 DB 10,13,"Current Date is $"
.CODE
        MOV AX,@DATA
        MOV DS,AX

        LEA DX,M1
        MOV AH,09H
        INT 21H

        MOV AH,2CH
        INT 21H

        MOV AL,CH
        CALL DISP

        MOV DL,':'
        MOV AH,2
        INT 21H

        MOV AL,CL
        CALL DISP

        LEA DX,M2
        MOV AH,09H
        INT 21H

        ;DAY
        MOV AH,2AH
        INT 21H

        MOV AL,DL
        CALL DISP

        MOV DL,'/'
        MOV AH,02H
        INT 21H

        ;MONTH
        MOV AH,2AH
        INT 21H

        MOV AL,DH
        CALL DISP

        MOV DL,'/'
        MOV AH,02H
        INT 21H

        ;YEAR
        MOV AH,2AH
        INT 21H
        ADD CX,0C30H

        MOV AL,CH
        CALL DISP

        MOV AL,CL
        CALL DISP

        MOV AH,4CH
        INT 21H

        DISP PROC NEAR
        AAM
        ADD AX,3030H
        MOV BX,AX

        MOV DL,BH
        MOV AH,2
        INT 21H

        MOV DL,BL
        MOV AH,02H
        INT 21H
        RET
        DISP ENDP
END
