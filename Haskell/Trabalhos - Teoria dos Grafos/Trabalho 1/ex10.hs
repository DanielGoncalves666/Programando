representação :: Int -> Int -> [Int]
representação b n
    | b <= 0 = error "Base inválida"
    | n == 0 = [0]
    | otherwise = let digito = n `mod` b
                      resto = n `div` b
                      list = representação b resto
                  in if head list == 0 then [digito]    -- evita que a lista tenha um zero à esquerda
                                       else list ++ [digito]