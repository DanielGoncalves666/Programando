somaDigitos(Num, 0) :- Num < 10, Num mod 2 =\= 0, !.
somaDigitos(Num, Num) :- Num < 10, Num mod 2 =:= 0, !.

somaDigitos(Num, Soma) :- NovoNumero is Num // 10, somaDigitos(NovoNumero, Soma_aux), Resto is Num mod 10, somaDigitos(Resto, Soma_aux_2), Soma is Soma_aux + Soma_aux_2. 
