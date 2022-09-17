module FuncoesAuxiliares where

import System.Random
import Data.List

-- qtd indica quantas diferenças existem entre as strings e k indica o tamanho em digitos
comparar :: String -> String -> Int -> Int -> Bool 
comparar [] [] qtd k = qtd == 1
comparar n m qtd k
    | length n /= length m = comparar (completa n '0' k) (completa m '0' k) qtd k
    | qtd > 1 = False
    | otherwise = if head n == head m then comparar (tail n) (tail m) qtd (k - 1)
                                      else comparar (tail n) (tail m) (qtd + 1) (k - 1)

-- Retorna uma string com a representação de n na base b
representação :: Int -> Int -> String
representação b n
    | b <= 0 = error "Base inválida"
    | n == 0 = "0"
    | otherwise = let digito = n `mod` b
                      resto = n `div` b
                      list = representação b resto
                  in if head list == '0' then show digito    -- evita que a lista tenha um zero à esquerda
                                       else list ++ show digito

-- completa à esquerda uma string com o caracter passado
completa :: String -> Char -> Int -> String
completa xs c n
    | length xs >= n = xs
    | otherwise = completa (c:xs) c n

-- fatorial com recursão de cauda, precisa passar 1 como cauda
fatorial :: Int -> Int -> Int 
fatorial 0 cauda = cauda;
fatorial n cauda = fatorial (n - 1) (cauda * n) 

combinações :: (Ord a) => [a] -> Int -> [[a]]
combinações [] _ = []
combinações ls@(l:lx) k
    | k <= 0 || length ls < k = []
    | k == 1 = [[e] | e <- ls]
    | k == 2 = [[p,e] | p <- ls, e <- tail ls, p /= e, p < e]
    | otherwise = [ l:e | e <- combinações lx (k - 1)] ++ combinações lx k

-- recebe duas listas e retorna uma lista contendo a interseção entre elas
-- a ordem dos elementos da interseção é de avalordo com sua aparição na primeira lista
intersecao :: (Ord a) => [a] -> [a] -> [a]
intersecao [] _ = []
intersecao _ [] = []
intersecao (x:xs) lb
    | x `elem` lb = x : intersecao xs lb
    | otherwise = intersecao xs lb

sorteia :: Int -> Int -> IO Int
sorteia ini fim = do randomRIO (ini, fim)

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort [x] = [x]
quicksort (chave:ls) = 
    let menoresIguais = [a | a <- ls, a <= chave]
        maiores = [a | a <- ls, a > chave]
    in quicksort menoresIguais ++ [chave] ++ quicksort maiores
 

-- começa com n = 1
seqBasica :: Int -> [Int] -> [Int]
seqBasica _ [] = []
seqBasica n l = [ n | a <- [1..(head l)]] ++ seqBasica (n + 1) (tail l)

permuta :: [Int] -> [[Int]]
permuta [] = [[]]
permuta l = [ cab : recur | cab <- l, recur <- permuta (delete cab l)]

permutaSemDup :: [Int] -> [[Int]]
permutaSemDup l = nub (permuta l)

-- considera a primeira posição como sendo 1
substituiPosicao :: [Int] -> Int -> Int -> [Int]
substituiPosicao l i valor = take (i - 1) l  ++ [valor] ++ drop i l

substituiVarios :: [Int] -> [Int] -> Int -> [Int]
substituiVarios original [] valor = original
substituiVarios original (c:cs) valor = substituiVarios originalN cs valor
    where originalN = substituiPosicao original c valor

-- precisa receber uma lista já ordenada
existeRepetidos :: [Int] -> Bool
existeRepetidos [] = False
existeRepetidos [a] = False
existeRepetidos (a:b:as)
    | a == b = True
    | otherwise = existeRepetidos (b:as)