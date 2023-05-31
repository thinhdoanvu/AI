%tim so lon nhat trong day so
tim_so_lon_nhat([X], X).
tim_so_lon_nhat([Head|Tail], Max) :-
    tim_so_lon_nhat(Tail, MaxTail),
    (Head > MaxTail -> Max = Head ; Max = MaxTail).


%Trong Prolog, cu phap [Head|Tail] dung de phan tach
%mot danh sach thanh 2 phan tu:
%phan tu dau tien: (Head)
%va phan con lai cua danh sach (Tail).
%Vi du, cho ds [3, 5, 8, 2],
%khi ta viet [Head|Tail]. Ta co
%3 = Head
%[5, 8, 2] = Tail.

%RUN:
% ?- tim_so_lon_nhat([1,2,3,4,5],X).
% X = 5 ;
