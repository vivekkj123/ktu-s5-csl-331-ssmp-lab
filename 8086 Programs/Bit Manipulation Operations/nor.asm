MOV AX,[1200H]
MOV BX,[1202H]
OR AX,BX
NOT AX
MOV [1204H],AX
HLT