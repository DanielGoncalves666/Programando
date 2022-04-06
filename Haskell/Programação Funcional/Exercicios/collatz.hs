{--

>>> converge 27 5
False

>>> converge 12 4
False

>>> converge 12 20
True

>>> converge 7 5
False

>>> converge 7 20
True

--}

collatz :: Int -> Int -> Int
collatz n i
    | i == 1 = n
    | even (collatz n (i-1)) = collatz n (i-1) `div` 2
    | otherwise = collatz n (i-1) * 3 + 1


converge :: Int -> Int -> Bool
converge n passos = convergeInterna n passos 1 


convergeInterna :: Int -> Int -> Int -> Bool
convergeInterna n qtd passo
    | collatz n passo == 1 = True
    | qtd == 0 = False
    | otherwise = convergeInterna n (qtd - 1) (passo + 1)
