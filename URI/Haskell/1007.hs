main = do
    a <- getLine
    b <- getLine 
    c <- getLine 
    d <- getLine 
    putStrLn $ "DIFERENCA = " ++ diferenca (read a) (read b) (read c) (read d)

diferenca :: Int -> Int -> Int -> Int -> String 
diferenca a b c d = show $ a * b - c * d