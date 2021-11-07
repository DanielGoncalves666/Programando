fib(1,1) :- !.
fib(2,1) :- !.
fib(3,2) :- !.
fib(4,3) :- !.
fib(5,5) :- !.
fib(6,8) :- !.
fib(7,13) :- !.
fib(8,21) :- !.
fib(9,34) :- !.
fib(10,55) :- !.

fib(N,F) :- N mod 2 =:= 0, M1 is N // 2, fib(M1,R1), M2 is M1 - 1, fib(M2, R2), quadrado(R1,F1), F is F1 + 2*R2*R1, !;
			N mod 2 =:= 1, M1 is (N - 1) // 2, fib(M1,R1), M2 is M1 + 1, fib(M2,R2), quadrado(R1,F1), quadrado(R2,F2), F is F1 + F2. 

quadrado(N,Q) :- Q is (N*N).
