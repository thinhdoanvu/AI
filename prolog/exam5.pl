%viet chuong trinh tinh a luy thua b
power(A,0,RES):-
  RES is 1.
  
power(A,1,RES):-
  RES is A.

power(A,B,RES):-
  B>1,
  NEWB is B-1,
  power(A,NEWB,TEMP),
  RES is A*TEMP.
  
%Khi b?n s? d?ng is trong m?t quy t?c Prolog,
%n� s? th?c hi?n t�nh to�n bi?u th?c b�n ph?i c?a is
%v� g�n gi� tr? t�nh to�n du?c cho bi?n b�n tr�i.
%�i?u n�y cho ph�p b?n t�nh to�n c�c bi?u th?c s? h?c
%ph?c t?p v� g�n gi� tr? k?t qu? cho bi?n trong quy t?c
%Prolog.
