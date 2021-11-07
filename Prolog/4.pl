g(N, A, B, Result) :- N =:= 0, Result = A,!;
					  N =\= 0, C is A + B, g(N - 1, B, C, Result).

f(N,R) :- g(N,0,1,R).

