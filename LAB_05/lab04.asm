org 0000h
repeat:
mov p2,#01000000b
acall p3subr
mov p2,#11111001b
acall p3subr 
mov p2,#10100100b
acall p3subr 
mov p2,#10110000b
acall p3subr 
mov p2,#10011001b
acall p3subr 
mov p2,#00010010b
acall p3subr 
mov p2,#00000010b
acall p3subr 
mov p2,#11111000b
acall p3subr 
mov p2,#10000000b
acall p3subr 
mov p2,#10010000b
acall p3subr 
sjmp repeat
p3subr:
mov p3,#01000000b ; displaying 0
acall delay
mov p3,#11111001b ; displaying 1
acall delay
mov p3,#10100100b ; displaying 2
acall delay
mov p3,#10110000b ; displaying 3
acall delay
mov p3,#10011001b ; displaying 4
acall delay
mov p3,#00010010b ; displaying 5
acall delay
mov p3,#00000010b ; displaying 6
acall delay
mov p3,#11111000b ; displaying 7
acall delay
mov p3,#10000000b ; displaying 8
acall delay
mov p3,#10010000b ; displaying 9
acall delay
ret
delay:
mov r3,#0003h
l3:mov r2,#0ffh
l2:mov r1,#0ffh
l1:djnz r1,l1
djnz r2,l2
djnz r3,l3
ret
END
