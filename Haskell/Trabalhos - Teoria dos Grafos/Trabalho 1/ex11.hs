completa :: [Int] -> Int -> [Int] 
completa xs n
    | length xs >= n = xs
    | otherwise = completa (0:xs) n
