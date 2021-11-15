main = do
    a <- getLine 
    b <- getLine 
    putStrLn $ "SOMA = " ++ soma (read a) (read b)

soma :: Int -> Int -> String
soma a b = show $ a + b