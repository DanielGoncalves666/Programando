{-
	Usando foldr, defina uma função somaQuads que recebe 
	como parâmetro um inteiro n e retorna a soma dos quadrados
	dos primeiros n inteiros. 
	somaQuads n = 1^2 + 2^2 + 3^2 ... n^2

>>> somaQuads' 5
55

>>> somaQuads'' 5
55
-}


somaQuads :: Int -> Int
somaQuads n = foldr (+) 0 [ e^2 | e <- [1..n]]

operacao :: Int -> Int -> Int
operacao n1 n2 = n1 ^ 2 + n2

somaQuads' :: Int -> Int
somaQuads' n = foldr operacao 0 [1..n]

operacao' :: Int -> Int -> Int
operacao' n1 n2 = n1 + n2 ^ 2

somaQuads'' :: Int -> Int
somaQuads'' n = foldl operacao' 0 [1..n]

---------------------------------------------------
{-
Usando fold, defina uma função que calcule o comprimento
de uma lista.

>>> comp' [1..10]
10

>>> comp [0,2..100]
51
-}

op :: Int -> Int -> Int
op _ n2 = 1 + n2

comp :: Foldable t => t Int -> Int
comp l = foldr op 0 l

op' :: Int -> Int -> Int
op' n1 _ = n1 + 1

comp' l = foldl op' 0 l

--------------------------------------------------
{-
Usando foldr, defina uma função que calcule o menor
número em uma lista não vazia de inteiros.

>>> mínimo [9,-1,0,9,14,-8]
-8

>>> mínimo' [9,-1,0,9,14,-8]
-8

-}


mínimo :: Foldable t => t Int -> Int
mínimo l = foldr1 min l

mínimo' :: Foldable t => t Int -> Int
mínimo' l = foldl1 min l

-------------------------------------------------------
{-
Usando foldr, defina uam função que reverta uma lista.

[] e [1,2,3] = 1 : ( 2 : ( 3 : [])) 
						lista ++ [elemento]
[] e [1,2,3] = ((([] : 1) : 2) : 3)
					[elemento] ++ lista


>>> reverter [1..10]
[10,9,8,7,6,5,4,3,2,1]
>>> reverter [10,9..1]
[1,2,3,4,5,6,7,8,9,10]
-}

op'' :: Int -> [Int] -> [Int]
op'' n l = l ++ [n]

reverter :: Foldable t => t Int -> [Int]
reverter l = foldr op'' [] l

op''' :: [Int] -> Int -> [Int]
op''' l n = n : l

reverter' :: Foldable t => t Int -> [Int]
reverter' l = foldl op''' [] l

---------------------------------------------------------
{-
Usando foldr, defina uma função que 
recebe duas listas e que remova todo 
elemento da segunda lista que aparece na primeira lista.

>>> diferença [1,4,5] [1..6]
[2,3,6]


>>> diferença' [1,4,5] [1..6]
[2,3,6]
-}

-- lista L1 e um elemento da lista L2
remove' :: [Int] -> Int -> [Int]
remove' [] _ = []
remove' l e = if e `elem` l then [] else [e] 

-- com a função parcial é determinado se o elemento está em l1 ou não. Concatena-se o resultado com a lista que foi passada
oper :: (Int -> [Int]) -> Int -> [Int] -> [Int]
oper f e l2 = f e ++ l2

-- O Resultado é o conjunto l2 - l1
diferença :: [Int] -> [Int] -> [Int]
diferença l1 l2 = foldr (oper (remove' l1)) [] l2

oper' :: (Int -> [Int]) -> [Int] -> Int -> [Int]
oper' f l2 e = l2 ++ f e

diferença' :: [Int] -> [Int] -> [Int]
diferença' l1 l2 = foldl (oper' (remove' l1)) [] l2

----------------------------------------------------------
{-
Defina a função filter' usando foldr.

>>> filter' (>5) [1..10]
[6,7,8,9,10]

>>> filter'' (<5) [1..10]
[1,2,3,4]
-}

operar :: (Int -> Bool) -> Int -> [Int] -> [Int]
operar f e l
    | f e = e : l
    | otherwise = l

filter' :: (Int -> Bool) -> [Int] -> [Int]
filter' f l = foldr (operar f) [] l

operar' :: (Int -> Bool) -> [Int] -> Int -> [Int]
operar' f l e
    | f e = l ++ [e]
    | otherwise = l

filter'' :: (Int -> Bool) -> [Int] -> [Int]
filter'' f l = foldl (operar' f) [] l
