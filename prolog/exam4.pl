%hay viet chuong trinh so sanh 2 so a va
sosanh(A,B):-
  A==B,
  %write("So A bang voi so B").
  format("~w bang voi ~w",[A,B]).

sosanh(A,B):-
  A>B,
  format("~w > ~w",[A,B]).
  
sosanh(A,B):-
  A<B,
  format("~w < ~w",[A,B]).
  
% luu ys dinh dang format khac voi write