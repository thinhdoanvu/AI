%viet chuong trinh in danh sach cac phan tu co trong mang
inds([Head|Tail]):-
  format('~w ',Head),
  inds(Tail).
  
inds([]).
%Dung rule inds de in voi cac dieu kien nhu sau:
% Neu danh sach rong: khong co phan tu nao de in
% Neu khac rong, in phan tu dau tien Head - dequy
% inds voi cac phan tu con lai cua Tail
