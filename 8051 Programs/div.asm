MOV A,#20
MOV B,#10
DIV AB
MOV DPTR,#4500
MOVX @DPTR,A
INC DPTR
MOV A,B
MOVX @DPTR,A
SJMP 300E