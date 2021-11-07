
/* 1 para sim, 0 para não.*/
bissexto(Num, R) :-
		Num mod 4 =:= 0, Num mod 100 =\= 0, R = 1, !;		
		Num mod 4 =:= 0, Num mod 100 =:= 0, Num mod 400 =:= 0, R = 1, !;
		R = 0.
		
hunuculu(Num, R) :- 
		Num mod 15 =:= 0, R = 1,!;
		R = 0.
		
bulukulu(Num, R) :-
		Num mod 55 =:= 0, bissexto(Num, Aux), Aux = 1, R = 1,!;
		R = 0.
		
tratamento(R1, R2, R3, R) :- 
		R1 = 1, R2 = 0, R3 = 0, R = 'Bissexto',!;
		R1 = 0, R2 = 1, R3 = 0, R = 'Huluculu',!;
		R1 = 1, R2 = 1, R3 = 0, R = 'Bissexto, Huluculu',!;
		R1 = 1, R2 = 0, R3 = 1, R = 'Bissexto, Bulukulu',!;
		R1 = 1, R2 = 1, R3 = 1, R = 'Bissexto, Huluculu, Bulukulu',!;
		R = 'Ordinary Year'.

ano(Num, R) :-
	bissexto(Num, R1), hunuculu(Num, R2), bulukulu(Num, R3), tratamento(R1,R2,R3,R).

