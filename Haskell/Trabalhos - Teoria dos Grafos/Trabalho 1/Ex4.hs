module Ex4 where

enesimoPrimo :: Int -> Int 
enesimoPrimo num
    | num > 0 = [e | e <- [2..], ehPrimo e 2 $ truncate (sqrt $ fromIntegral e) ] !! (num - 1)
    | otherwise = error "Apenas valores positivos são permitidos"
    
-- div é o divisor
-- limite é a raiz quadrada de num
ehPrimo :: Int -> Int -> Int -> Bool
ehPrimo num div limite
    | div > limite = True 
    | num `mod` div == 0 = False 
    | otherwise = ehPrimo num (div + 1) limite
