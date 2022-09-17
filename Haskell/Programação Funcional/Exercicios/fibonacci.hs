{-
	if then else

		Fib(1) = 1
Fib(2) = 1
Fib(n) = Fib(n-1) + Fib(n-2)
-}

fibonacci1 :: Int -> Int
fibonacci1 n = 
    if n == 1 || n == 2 then 1
        else if n <= 0 then error "Valor inválido."
            else fibonacci1 (n - 1) + fibonacci1 (n - 2)

{-
	Guardas
-}

fibonacci2 :: Int -> Int
fibonacci2 n  
    | n == 1 || n == 2 = 1
    | n <= 0 = error "Valor inválido."
    | otherwise = fibonacci1 (n - 1) + fibonacci1 (n - 2)


{-
	Casamento de padrões
-}

fibonacci3 :: Int -> Int 
fibonacci3 1 = 1
fibonacci3 2 = 2
fibonacci3 n
    | n > 0 = fibonacci3 ( n - 1) + fibonacci3 ( n - 2 )
fibonacci3 _ = error "Valor inválido."