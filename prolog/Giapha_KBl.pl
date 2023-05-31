%Day la tri thuc cua cay pha he
%NAM:15
nam(tranminhtong).
nam(trannghetong).
nam(trandutong).
nam(tranhientong).
nam(tranduetong).
nam(tranthuantong).
nam(tranphede).
nam(duongnhatle).
nam(tranthieude).
nam(tranquangde).
nam(cungtuc).
nam(tranngac).
nam(giandinhde).
nam(hoquyly).

%NU: 6
nu(hientu).
nu(huyninh).
nu(thuctu).
nu(gitu).
nu(vuongmau).
nu(lethanhngau).

%VOCHONG
chong(tranminhtong,hientu).
chong(hoquyly,huyninh).
chong(trannghetong,thuctu).
chong(tranduetong,giatu).
chong(cungtuc,vuongmau).
chong(tranthuantong,lethanhngau).

%X la CHA cua Y
cha_con(tranminhtong,huyninh).
cha_con(tranminhtong,trannghetong).
cha_con(tranminhtong,trandutong).
cha_con(tranminhtong,tranhientong).
cha_con(tranminhtong,tranduetong).
cha_con(tranminhtong,cungtuc).
cha_con(hoquyly,hohanthuong).
cha_con(hoquyly,lethanhngau).
cha_con(trannghetong,tranthuantong).
cha_con(trannghetong,tranngac).
cha_con(trannghetong,giandinhde).
cha_con(tranduetong,tranphede).
cha_con(cungtuc,duongnhatle).
cha_con(tranthuantong,tranthieude).
cha_con(tranngac,tranquangde).

%ME
me_con(hientu,huyninh).
me_con(hientu,trannghetong).
me_con(hientu,trandutong).
me_con(hientu,tranhientong).
me_con(hientu,tranduetong).
me_con(hientu,cungtuc).
me_con(huyninh,hohanthuong).
me_con(huyninh,lethanhngau).
me_con(thuctu,tranthuantong).
me_con(thuctu,tranngac).
me_con(thuctu,giandinhde).
me_con(giatu,tranphede).
me_con(vuongmau,duongnhatle).
me_con(lethanhngau,tranthieude).

%ANH TRAI
anhtrai(trannghetong,huyninh).

anhtrai(trandutong,trannghetong).
anhtrai(trandutong,huyninh).

anhtrai(tranhientong,trandutong).
anhtrai(tranhientong,trannghetong).
anhtrai(tranhientong,huyninh).

anhtrai(tranduetong,tranhientong).
anhtrai(tranduetong,trandutong).
anhtrai(tranduetong,trannghetong).
anhtrai(tranduetong,huyninh).

anhtrai(cungtuc,tranduetong).
anhtrai(cungtuc,tranhientong).
anhtrai(cungtuc,trandutong).
anhtrai(cungtuc,trannghetong).
anhtrai(cungtuc,huyninh).

anhtrai(giandinhde,tranngac).
anhtrai(giandinhde,tranthuantong).

anhtrai(tranngac,tranthuantong).

%EM GAI
emgai(trannghetong,huyninh).
emgai(trandutong,huyninh).
emgai(tranhientong,huyninh).
emgai(tranduetong,huyninh).
emgai(cungtuc,huyninh).
emgai(tranthuantong,lethanhngau).

%CHIGAI
chigai(hohanthuong,lethanhngau).

%VUA
vua(tranminhtong).
vua(hoquyly).
vua(trannghetong).
vua(trandutong).
vua(tranhientong).
vua(tranduetong).
vua(tranthuantong).
vua(tranphede).
vua(hohanthuong).
vua(tranthieude).
vua(tranquangde).

%MOI QUAN HE X la CON TRAI cua Y (cha)
con_trai_bo(X,Y):-
  cha_con(Y,X),
  nam(X).
%MOI QUAN HE X la CON TRAI cua Z (me)
  con_trai_me(X,Z):-
  me_con(Z,X),
  nam(X).

%MOI QUAN HE X la CON GAI cua Y (cha)
con_gai_bo(X,Y):-
  cha_con(Y,X),
  nu(X).
%MOI QUAN HE X la CON GAI cua Z (me)
  con_gai_me(X,Z):-
  me_con(Z,X),
  nu(X).
  
%MOI QUAN HE X la CON cua BO va ME Y
con(X,Y):-
  cha_con(Y,X);
  me_con(Y,X).
  
%MOI QUAN HE HOANG HAU CUA VUA
hoanghau(X):-
  chong(Y,X),
  vua(Y).

%MOI QUAN HE ANH  EM RUOT
anh_em_ruot(X,Y):-
  cha_con(C,X),
  cha_con(C,Y),
  me_con(M,X),
  me_con(M,Y),
  X\==Y.
  
%MOI QUAN HE ANH EM HO HANG
anh_em_ho(X,Y):-
  %not(anh_em_ruot(X,Y)),
  X\==Y,
  (
    (
      cha_con(C,X),
      cha_con(D,Y),
      anh_em_ruot(C,D)
    )
    ;
    (
      me_con(M,X),
      me_con(N,Y),
      anh_em_ruot(M,N)
    )
    ;
    (
      cha_con(C,X),
      cha_con(D,Y),
      me_con(M,X),
      me_con(N,Y),
     (
        anh_em_ruot(C,D);
        anh_em_ruot(M,N);
        anh_em_ruot(C,M);
        anh_em_ruot(C,N);
        anh_em_ruot(D,M);
        anh_em_ruot(D,N)
      )
    )
  ).

%MOI QUAN HE ONG - CHAU
ong_noi(X,Y):-
  cha_con(Z,Y),
  cha_con(X,Z).
  
ong_ngoai(X,Y):-
  me_con(M,Y),
  cha_con(X,M).
  
%MOI QUAN HE CO - THIM - CHU - BAC  - DI - CAU
co_chau(X,Y):-
  cha_con(C,Y),
  anh_em_ruot(X,C),
  nu(X).
  
bac_chau(X,Y):-
  (nu(X),
  chong(P,X),
  cha_con(C,Y),
  anh_em_ruot(P,C),
  anhtrai(P,C));
  (nam(X),
  cha_con(C,Y),
  anh_em_ruot(X,C),
  anhtrai(X,C)).
