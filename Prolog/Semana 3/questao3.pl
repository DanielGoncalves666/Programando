eh(pedro,influenciador).
eh(joao,ninguem).

gosta(joao,batata).
gosta(pedro,batata).
gosta(joao,pedro).
gosta(pedro,joao).

gostaDe(X,Y) :- gosta(X,T),eh(T,influenciador),gosta(T,Y). 
