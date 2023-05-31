%giai phuong trinh bac 1: ax +b = c
ptb1(0,B,C,X):-
  B==C,
  write("Phuong trinh co vo so nghiem").

ptb1(0,B,C,X):-
  B\==C,
  write("Phuong trinh vo nghiem").
  
ptb1(A,B,C,X):-
  TAM is C-B,
  X = TAM/A,
  format("Nghiem cua pt la ~2f",[X]).
  
  %De hien thi du lieu kie so thuc: ~2f lam tron 2 chu so thap phan
