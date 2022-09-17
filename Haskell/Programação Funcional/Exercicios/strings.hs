{-
Defina função que retorne substring de t elementos começando na posição i
	minhaFuncao "entrada1" 2 2 retorna "tr"
Defina função que retorne substring com os últimos u elementos	
	minhaFuncao "entrada1" 2 retorna "a1"
Defina função que receba duas strings e retorne a resultado da concatenação das substrings de t elementos começando na posição i
	minhaFuncao "entrada1" "entrada2" 2 2 retorna "trtr"
-}

{-
>>> substring "Entrada" 2 2
"tr"

-}
substring s t i =  reverse (take t (reverse ( take (t + i) s )))

{-
>>> substringLast "Entrada" 2 
"da"

-}
substringLast s u = reverse (take u (reverse s)) 

{-
>>> subsconcatena "Entrada" "Entrada2" 3 0
"EntEnt"

-}

subsconcatena s1 s2 t i = substring s1 t i ++ substring s2 t i 
