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
%nó s? th?c hi?n tính toán bi?u th?c bên ph?i c?a is
%và gán giá tr? tính toán du?c cho bi?n bên trái.
%Ði?u này cho phép b?n tính toán các bi?u th?c s? h?c
%ph?c t?p và gán giá tr? k?t qu? cho bi?n trong quy t?c
%Prolog.
