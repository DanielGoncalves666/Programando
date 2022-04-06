import Ex4
-- no VisualCode, esse tipo de importação aparece como erro. Apenas ignorar.


fatoresPrimos :: Int -> [Int]
fatoresPrimos num
    | num <= 0 = error "Apenas valores positivos são permitidos"
    | otherwise = obterFatores num 1

obterFatores :: Int -> Int -> [Int]
obterFatores num n
    | num == 1 = []
    | num `mod` p == 0 = p : obterFatores resto n
    | otherwise = obterFatores num (n + 1)
    where p = enesimoPrimo n
          resto = num `div` p