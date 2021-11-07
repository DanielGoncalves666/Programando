{--
Binomial

>>> binomial 5 5
1

>>> binomial 5 6
Inválido

>>> binomial 5 0
1

>>> binomial 5 2
10

--}


binomial :: Int -> Int -> Int 
binomial n 0 = 1
binomial n k
    | k == n = 1
    | k > n = error "Inválido"
    | otherwise = binomial (n - 1) k + binomial (n - 1) (k - 1)
