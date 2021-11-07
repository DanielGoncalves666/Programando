/*0 ímpar, 1 par*/

par(1,0).
par(2,1).

par(X,Y) :- X > 2, T is X - 2, par(T,Y), Y = 0;
			X > 2, T is X - 2, par(T,Y), Y = 1.
