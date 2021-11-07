top(X,Y) :- p(X,Y).
top(X,X) :- s(X).

p(X,Y) :- q(X), r(Y).
p(X,Y) :- s(X), r(Y).

q(a).
q(b).
r(c).
s(e).
