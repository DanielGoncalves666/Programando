conta :: Int -> Int -> Int -> Int -> [[Int]]
conta b larg min max
    | b <= 0 = error "Base inválida"
    | larg <= 0 = error "Largura inválida"
    | min > b ^ larg || max > b ^ larg = error "Largura insuficiente para representar o intervalo"
    | min > max = []
    | otherwise = representação b min larg [] : conta b larg (min + 1) max

-- função do exercício 10 alterada
representação :: Int -> Int -> Int -> [Int] -> [Int]
representação b n larg list
    | n == 0 = if length list < larg then representação b n larg (0:list)
                                     else list
    | otherwise = let digito = n `mod` b
                      resto = n `div` b
                  in representação b resto larg (digito:list)
