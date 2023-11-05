% Wangs Hao Algorithm

% Define operators.
% • sequent ( |= )
% • negation ( ! )
% • conjunction ( & )
% • disjunction ( v )
% • implication ( -> )
% • equivalence ( <-> )

%ALGORITHM
% • Rule 1: Replace negation (!) on the left or the right.
% • Rule 2: Replace conjunction (&) by commas on the left.
% • Rule 3: Replace disjunction (v) by commas on the right.
% • Rule 4: Branch disjunction (v) on the left.
% • Rule 5: Branch conjunction (&) on the right.
% • Rule 6: Replace implication (->) on the left or the right.
% • Rule 7: Replace equivalence (<-> on the left or the right.

:-op(700,xfy,<->). %toan tu 2 ngoi
:-op(700,xfy,->).  %toan tu 2 ngoi
:-op(600,xfy,v).   %toan tu 2 ngoi
:-op(600,xfy,&).   %toan tu 2 ngoi
:-op(500,fy,!).    %toan tu 1 ngoi

% Main call.
%[]: ky hieu cua danh sach
%[|]: tach thanh 2 danh sach
prove([],[]):-nl.    %in dong trong khi ve trai va ve phai deu rong
prove([L|P],[R|A]):- %L,R: bieu thuc logic can CM; P,A: phan con lai sau CM
  nl, write(L), write(' |= '), write(R), nl,
  wang(L,R),
  prove(P,A).

%Giai quyet thuat toan.
wang(L,R):-         %neu ton tai rules(L,R) -> 'TRUE'
  rules(L,R),
  write('TRUE').
wang(_,_):-         %khi khong con quy tac nao nua: FALSE
  write('FALSE').
  
/**************************************/
/*Tap cac luat cua thuat giai Vuong Hao*/
/**************************************/

%RULE1a: Chuyen ky hieu not (phu) tu ve left sang ve right.
%!p, q -> r <=> q->p,r
rules(L,R):-
  member(!X,L),       %neu tim thay phu cua X cua danh sach ben trai
  select(!X,L,Ld),    %Xoa !X ra khoi L va luu ket qua vao Ld
  rules(Ld,[X|R]).    %De quy viec xoa phu dinh cua X voi X noi vao dau R

%RULE1b: Chuyen ky hieu not (phu) tu ve right sang ve left.
%p -> !q,r <=> p,q->r
rules(L,R):-
  member(!X,R),       %neu tim thay phu cua X cua danh sach ben phai
  select(!X,R,Rd),    %Xoa !X ra khoi L va luu ket qua vao Rd
  rules([X|L],Rd).    %De quy viec xoa phu dinh cua X voi X=Rd

%RULE2: Thay the ky hieu VA (&) o ve left thanh dau phay (,).
%p & q -> r <=> p,q->r
rules(L,R):-
  member(X & Y,L),    %neu ton tai ky hieu X & Y o ve trai
  select(X & Y,L,Ld), %Xoa X&Y ra khoi ve trai (L), ket qua luu vao list Ld
  rules([X,Y|Ld],R).  %De quy luat rules voi chen dau [X,Y va truoc Ld]

%RULE3: Thay the ky hieu HOAC (v) o ve right thanh dau phay (,).
%p -> q  v r <=> p ->q,r
rules(L,R):-
  member(X v Y,R),    %neu ton tai ky hieu X v Y o ve phai
  select(X v Y,R,Rd), %Xoa X v Y ra khoi ve phai (R), ket qua luu vao list Rd
  rules(L,[X,Y|Rd]).  %De quy luat rules voi chen dau [X,Y va truoc Rd]

%RULE4: Tach thanh 2 menh de khi co ky hieu HOAC (v) o ve left.
%p v q -> r <=> menh de 1: p ->r va menh de 2: q -> r
rules(L,R):-
  member(X v Y,L),    %neu ton tai ky hieu X v Y o ve trai
  select(X v Y,L,Ld), %Xoa X v Y ra khoi ve trai (L), ket qua luu vao list Ld
  rules([X|Ld],R),    %De quy luat moi voi X o dau danh sach Ld
  rules([Y|Ld],R).    %De quy luat moi voi Y o dau danh sach Ld

%RULE5: Tach thanh 2 danh sach neu co menh de & o ve phai
rules(L,R):-
  member(X & Y,R),    %neu ton tai ky hieu X & Y o ve phai
  select(X & Y,R,Rd), %Xoa X & Y ra khoi ve phai (R), ket qua luu vao list Rd
  rules(L,[X|Rd]),    %De quy luat moi voi X o dau danh sach Rd
  rules(L,[Y|Rd]).    %De quy luat moi voi Y o dau danh sach Rd

%RULE 6a: Thay the ky hieu -> o ve trai
%p->q <=> !p v q
rules(L,R):-
  member(X -> Y,L),    %neu ton tai ky hieu X -> Y o ve trai
  select(X -> Y,L,Ld), %Xoa X -> Y ra khoi danh sach L, ket qua luu vao list Ld
  rules([!X v Y|Ld],R).%thay the bang !X v Y va chen vao dau danh sach Ld

%RULE 6b: Thay the ky hieu -> o ve phai
%p->q <=> !p v q
rules(L,R):-
  member(X -> Y,R),    %neu ton tai ky hieu X -> Y o ve phai
  select(X -> Y,R,Rd), %Xoa X -> Y ra khoi danh sach R, ket qua luu vao list Rd
  rules(L,[!X v Y|Rd]).%thay the bang !X v Y va chen vao dau danh sach Rd

%RULE 7a: Thay the bieu thuc tuong duong o ve trai.
%p <-> q === (p->q) & (q->p)
rules(L,R):-
  member(X <-> Y,L),   %neu ton tai ky hieu X <-> Y o ve trai
  select(X <-> Y,L,Ld),%Xoa X <-> Y ra khoi danh sach L, ket qua luu vao list Ld
  rules([(X -> Y) & (Y -> X)|Ld],R).
                       %thay the bang (X->Y)&(Y->X) o dau danh sach Ld

%RULE 7b: Thay the bieu thuc tuong duong o ve phai.
%p <=> q === (p->q) & (q->p)
rules(L,R):-
  member(X <-> Y,R),    %neu ton tai ky hieu X <-> Y o ve phai
  select(X <-> Y,R,Rd), %Xoa X <-> Y ra khoi danh sach R, ket qua luu vao list Rd
  rules(L,[(X -> Y) & (Y -> X)|Rd]).
                        %thay the bang (X->Y)&(Y->X) o dau danh sach Rd

%CUOI CUNG: SO SANH X ton tai ca 2 ve
rules(L,R):-
  member(X,L),  %Neu X ton tai o ve trai va
  member(X,R).  %Neu X ton tai o ve phai => TRUE
  

% prove([[]],[[tobe v !tobe]]).   %true
% prove([[p]],[[p v q]]). % true
% prove([[]],[[(((p -> q) -> p ) -> p)]]). % true
% prove([[(p -> q) & (!r -> !q)]],[[p -> r]]). % true
% prove([[]],[[(!p & !q) -> (p <-> q)]]). % true
% prove([[p <-> q]],[[(p <-> r) -> (q <-> r)]]). % true
% prove([[]],[[(((p & q) -> !((!p v !q))) & (!((!p v !q)) -> (p & q)))]]). % true
% prove([[]],[[((!p -> q) & ((p & q) -> !r) & ((r v !p) -> !q) -> p)]]). % true
% prove([[]],[[((!p -> q) & ((p & q) -> !r) & ((r v !p) -> !q) -> (r & q))]]). % true
% prove([[(p -> q) & (!r -> !q)]],[[p -> r]]).   %true

/*CAI NAY NE:
Cho p->q, q->r. CMR p->r
prove([[(p->q),(q->r)]],[[(p->r)]]).  %true
prove([[(a&b->c),(b&c->d),(a&b)]],[d]). %false
prove([[(a->b),(a->c v e),(b & c->d),(f->d),(a)]],[g]).
prove([(a -> b v d),(d -> e & f),(e & a -> !b)],[(a -> !d)]).  %false

prove([[(p -> (q & r)),(q -> s), (r -> t)]],[[(s & t)]]).
prove([[((a&b) -> c),((b & c) -> d), (a),(b)]],[[(d)]]).
prove([[(!p v (q & r)),(!q & s),(!r & t)]],[[(s & t)]]).
*/