divisores x = [ e | e <- [1..x], x `mod` e == 0 ]

ehprimo x = length (divisores x) == 2
--podemos verificar a igualdade entre a lista recebida de divisores x e [1,x]
