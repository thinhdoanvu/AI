nhapds(0, []).
nhapds(N, [Head|Tail]) :-
    N > 0,
    format('Phan tu thu ~w: ', [N]),
    read(Head),
    NewN is N - 1,
    nhapds(NewN, Tail).

print_list([]).
print_list([Head|Tail]) :-
    write(Head), write(' '),
    print_list(Tail).

tim_so_lon_nhat([K], X):- X=K. %hang nay bat buoc phai co
% tra ve SLN trong ds chi co 1 ptu duy nhat K => X=K.

tim_so_lon_nhat([Head|Tail], Max) :-
    tim_so_lon_nhat(Tail, MaxTail),
    (Head > MaxTail -> Max = Head ; Max = MaxTail).

nhap_va_in_max(N) :-
    nhapds(N, List),
    write('In danh sach: '),
    print_list(List),
    tim_so_lon_nhat(List, Max),
    write('\n'),
    format('So lon nhat: ~w', [Max]).
    
%Luu y: tim_so_lon_nhat([X], X) co the thay cho
%tim_so_lon_nhat([K], X) nhung o tren khong can dung :- X=K.
 
% Quy t?c tim_so_lon_nhat([X], X) trong chuong tr�nh Prolog du?c s? d?ng d? x�c d?nh s? l?n nh?t trong m?t danh s�ch g?m m?t ph?n t? duy nh?t.
% C? th?, n?u danh s�ch ch? ch?a m?t ph?n t?, quy t?c tim_so_lon_nhat([X], X) s? du?c �p d?ng v� s? l?n nh?t trong danh s�ch s? du?c g�n cho bi?n X.
% V� d?, n?u b?n g?i tim_so_lon_nhat([5], Max)., Prolog s? �p d?ng quy t?c tim_so_lon_nhat([X], X) v� g�n gi� tr? 5 cho bi?n Max.

