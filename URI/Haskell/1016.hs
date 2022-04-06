main = do
    dist <- getLine 
    putStrLn $ tempo (read dist) ++ " minutos"

tempo :: Int -> String 
tempo t = show $ t * 2