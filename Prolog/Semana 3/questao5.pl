/*0 para nao divide, 1 para divide)*/
divide(_,0,1).
divide(_,T,0) :- T < 0.

divide(D,N,R) :- N > 0, T is N - D, divide(D,T,R).
