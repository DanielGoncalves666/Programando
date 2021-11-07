entrada(alface,10).
entrada(tomate,12).
entrada(legumes,17).
entrada(rucula,15).

principal(pf,75).
principal(lasanha,99).
principal(feijoada,120).
principal(macarrao,83).

sobremesa(gelatina,22).
sobremesa(sorvete,33).
sobremesa(pudim,15).
% Sem sobremesa
sobremesa(sem,0).

tipo(diet).
tipo(normal).
tipo(glutao).


menu(Tipo, Entrada, Principal, Sobremesa) :- Tipo = diet, tipo(Tipo), entrada(Entrada, X), principal(Principal, Y), sobremesa(Sobremesa, Z), Maximo is X + Y + Z, Maximo =< 130.
menu(Tipo, Entrada, Principal, Sobremesa) :- Tipo = glutao, tipo(Tipo), entrada(Entrada, X), principal(Principal, Y), sobremesa(Sobremesa, Z), Maximo is X + Y + Z, Maximo >= 145.
menu(Tipo, Entrada, Principal, Sobremesa) :- Tipo = normal, tipo(Tipo), entrada(Entrada, _), principal(Principal, _), sobremesa(Sobremesa, Z), Z > 0.

