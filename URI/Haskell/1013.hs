main = do
    l <- getLine
    let lista = words l
    putStrLn $ show (maior (maior (read $ head lista) (read $ lista !! 1)) (read $ lista !! 2)) ++ " eh o maior"

maior :: Int -> Int -> Int
maior a b = (a + b + abs (a-b)) `div` 2