{--
    Defina uma função que arredonde um número Real para Integer de forma que se for maior que 0,
    arredonde para baixo e se for menor que zero, para cima.

>>> arredonda0 (-1.5)
-1

>>> arredonda0 1.5
1


--}

arredonda0 :: Double -> Integer 
arredonda0 x 
    | x > 0 = chao
    | x < 0 = teto
    | otherwise = 0
    where chao = floor x
          teto = ceiling x

{--
    Defina uma função que arredonde um número Real para Integer de forma que se for maior que 0,
    arredonde para cima e se for maior que zero, para baixo.


>>> arredonda1 (-1.5)
-2


>>> arredonda1 1.5
2


--}

arredonda1 :: Double -> Integer 
arredonda1 x 
    | maior0 = teto
    | menor0 = chao
    | otherwise = 0
    where chao = floor x
          teto = ceiling x
          maior0 = x > 0
          menor0 = x < 0

{--
    arrendonda1 só que com o uso de where

>>> arredonda2 (-1.5)
-2


>>> arredonda2 1.5
2

--}
arredonda2 :: Double -> Integer 
arredonda2 x 
    | x > 0 = let teto = ceiling x in teto
    | x < 0 = let chao = floor x in chao
    | otherwise = 0
