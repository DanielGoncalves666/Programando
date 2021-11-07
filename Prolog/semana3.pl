x(X,X). /*verifica se as duas variáveis são iguais*/

likes(eu,voce).
likes(voce,eu).
likes(voce,voce).
likes(eu,eu).

r(X) :- likes(X,_).

dup(X,Y) :- Y is 2*X.

sim(X):- X==1.

par(1,0).
par(2,1).

par(X,Y) :- X>2, T is X-1, par(T,R), R=1, Y=0.
par(X,Y) :- X>2, T is X-1, par(T,R), R=0, Y=1.


