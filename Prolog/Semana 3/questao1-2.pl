gosta(joao,maria).
gosta(pedro,maria).
gosta(maria,pedro).
gosta(maria,joao).

gosta(velma,maria).
gosta(pedro,velma).
gosta(joao,velma).

triangulo(A,B,C) :- gosta(A,C),gosta(B,C),gosta(C,A),gosta(C,B).

romanceBarato(A,B,C) :- gosta(A,C),gosta(B,C),(gosta(C,A);gosta(C,B)).


