-- File containing utility functions for lists.

funçãoExemploR x y = x+y

funçãoExemploL x y = x+y


{-
Resolva os seguintes exercícios, inspirados em https://www.cantab.net/users/antoni.diller/haskell/questions/quest06.pdf
usando foldr e foldl. 
Para a versão que usa foldr, o nome da função termina R; para a função que usa foldl, termina com L.


Escreva pelo menos 2 testes para cada função, no arquivo FinderSpec.hs


1 - Usando foldX, defina uma função somaQuadsX que recebe como parâmetro um inteiro n e retorna a soma dos quadrados dos primeiros n inteiros, isto é,
somaQuads n = 1^2 + 2^2 + 3^2 ... n^2

>>> somaQuadsR 3
15
-}


operacao1R :: Int -> Int -> Int
operacao1R n1 n2 = n1 ^ 2 + n2

somaQuadsR :: Int -> Int
somaQuadsR n = foldr operacao1R 0 [1..n]


operacao1L :: Int -> Int -> Int
operacao1L n1 n2 = n1 + n2 ^ 2

somaQuadsL :: Int -> Int
somaQuadsL n = foldl operacao1L 0 [1..n]

{-

2 - Usando foldX, defina uma função compX que calcule o comprimento de uma lista.

>>>compR [1..10]
10

-}

operacao2R :: Int -> Int -> Int
operacao2R _ n2 = 1 + n2

compR :: Foldable t => t Int -> Int
compR l = foldr operacao2R 0 l

operacao2L :: Int -> Int -> Int
operacao2L n1 _ = n1 + 1

compL :: Foldable t => t Int -> Int
compL l = foldl operacao2L 0 l

{-
3 - Usando foldX, defina uma função mínimoX que calcule o menor número em uma lista não vazia de inteiros.
>>> mínimoL [10,9..0]
0
>>> mínimoL [10..100]
10

-}

mínimoR :: Foldable t => t Int -> Int
mínimoR l = foldr1 min l

mínimoL :: Foldable t => t Int -> Int
mínimoL l = foldl1 min l

{-

4 - Usando foldX, defina uam função reverteX que reverte uma lista.

>>> reverte [1..10]
[10,9,8,7,6,5,4,3,2,1]

-}

operacao4R :: Int -> [Int] -> [Int]
operacao4R n l = l ++ [n]

reverteR :: Foldable t => t Int -> [Int]
reverteR l = foldr operacao4R [] l

operacao4L :: [Int] -> Int -> [Int]
operacao4L l n = n : l

reverteL :: Foldable t => t Int -> [Int]
reverteL l = foldl operacao4L [] l

{-

5 - Usando foldX, defina uma função removeDupX que recebe duas listas e que remova todo elemento da segunda lista 
que aparece na primeira lista.

>>>removeDupL [1,2,3] [0,1,2,4,3,5]
[0,4,5]

-}

-- lista L1 e um elemento da lista L2
remove' :: [Int] -> Int -> [Int]
remove' [] _ = []
remove' l e = if e `elem` l then [] else [e] 

-- com a função parcial é determinado se o elemento está em l1 ou não. Concatena-se o resultado com a lista que foi passada
operacao5R :: (Int -> [Int]) -> Int -> [Int] -> [Int]
operacao5R f e l2 = f e ++ l2

-- O Resultado é o conjunto l2 - l1
removeDupR :: [Int] -> [Int] -> [Int]
removeDupR l1 l2 = foldr (operacao5R (remove' l1)) [] l2

operacao5L:: (Int -> [Int]) -> [Int] -> Int -> [Int]
operacao5L f l2 e = l2 ++ f e

removeDupL :: [Int] -> [Int] -> [Int]
removeDupL l1 l2 = foldl (operacao5L (remove' l1)) [] l2


{-


6 - Defina a função filterX usando foldX e que tenha o mesmo comportamento a função padrão filter

-}



operacao6R :: (Int -> Bool) -> Int -> [Int] -> [Int]
operacao6R f e l
    | f e = e : l
    | otherwise = l

filterR :: (Int -> Bool) -> [Int] -> [Int]
filterR f l = foldr (operacao6R f) [] l

operacao6L :: (Int -> Bool) -> [Int] -> Int -> [Int]
operacao6L f l e
    | f e = l ++ [e]
    | otherwise = l

filterL :: (Int -> Bool) -> [Int] -> [Int]
filterL f l = foldl (operacao6L f) [] l