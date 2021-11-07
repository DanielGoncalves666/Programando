/* Divisibilidade por 7*/

/*0 para nao divisível, 1 para diviśivel */
div7(Num, S) :- Num < 50, Num mod 7 =:= 0, S = 1, !;
				Num < 50, S = 0, !.

div7(Num, S) :- R is Num mod 10, Q is Num // 10, Num_novo is Q - R * 2, div7(Num_novo, S).
