import Data.Array
-- >>> matMult [[3,2],[5,-1]] [[6,4,-2],[0,7,1]]
-- [[18,26,-4],[30,13,-11]]

matMult :: [[Int]] -> [[Int]] -> [[Int]]
matMult mat1 mat2
    | verificarDimensoes mat1 mat2 == 1 = multMat (matriz mat1) (matriz mat2)
    | verificarDimensoes mat1 mat2 == -1 = multMat (matriz mat2) (matriz mat1)
    | otherwise = error "Dimensões Incompatíveis"

multMat :: (Num a) => Array (Int, Int) a -> Array (Int,Int) a -> [[a]]
multMat mat1 mat2 =
    let (x,_) = snd $ bounds mat1
        (_,y) = snd $ bounds mat2
        lc = fst $ snd $ bounds mat2 -- coluna mat1 == linha mat2
    in [[sum [ mat1 ! (i1,j) * mat2 ! (j,i2) | j <- [1..lc] {--}] | i2 <- [1..y] {--}] | i1 <- [1..x] {--}]

matriz :: [[a]] -> Array (Int, Int) a
matriz mat = array ((1,1), (n,m)) (aplaina 1 mat)
    where n = length mat
          m = length $ head mat
          linha i xs = [((i,j), xs !! (j - 1) ) | j <- [1 .. m]]
          aplaina i [] = []
          aplaina i (l:ls) = linha i l ++ aplaina (i+1) ls

-- 1 pra OK na ordem passada
-- 0 pra incompatível
-- -1 para OK na ordem inversa
verificarDimensoes :: [[Int]] -> [[Int]] -> Int
verificarDimensoes mat1 mat2
    | colunas1 == linhas2 = 1
    | colunas2 == linhas1 = -1
    | otherwise = 0
    where linhas1 = length mat1
          linhas2 = length mat2
          colunas1 = length $ head mat1
          colunas2 = length $ head mat2
