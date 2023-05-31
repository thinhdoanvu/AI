%viet chuong trinh nhap va in cac phan tu cua M1C
%List = [Head|Tail] CTDL dang List  quy dinh rua

nhapds(N,[Head|Tail]):-
  N>0,
  format('Nhap phan tu thu ~w', N),
  write(': '),
  read(Head),
  NewN is N - 1,
  nhapds(NewN,Tail).

nhapds(0,[]).%bat dau tu phan tu thu 0 va ds rong

%RUN:
%?- nhapds(2,X).
%Nhap phan tu thu 2: 2.
%Nhap phan tu thu 1: 3.
%Luu y co dau . sau khi ket thuc
