main = do
    a <- getLine 
    b <- getLine
    putStrLn $ "PROD = " ++ prod (read a) (read b)

prod :: Int -> Int -> String 
prod a b = show $ a * b