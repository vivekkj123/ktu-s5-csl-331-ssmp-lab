MOV AX,[1200H]
MOV BX,[1202H]
AND AX,BX
NOT AX
MOV [1204H],AX
HLT