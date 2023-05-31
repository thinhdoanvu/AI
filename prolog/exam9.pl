%viet chuong trinh vua nhap va in ds
nhapds(N,[Head|Tail]):-
  N>0,
  format('Nhap PT ~w: ',N),
  read(Head),
  NewN is N-1,
  nhapds(NewN,Tail).

nhapds(0,[]). %luu y cai nay khac C

inds([Head|Tail]):-
  write(Head),
  write('  '),
  inds(Tail).

nhap_va_in_ds(N) :-
    nhapds(N, List),
    write('M1C vua nhap: '),
    inds(List).