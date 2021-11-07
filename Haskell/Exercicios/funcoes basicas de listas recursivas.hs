
-- Take
{-
>>> take' 3 [1,2,3,4,5]
[1,2,3]
-}
take' :: Int -> [a] -> [a]
take' _ [] = []
take' t (x:xs)
    | t <= 0 = []
    | otherwise = x : take' (t - 1) xs


-- Drop
{-
>>> drop' 3 ['f','o','o',' ','b','a','r']
" bar"
-}
drop' :: Int -> [a] -> [a]
drop' _ [] = []
drop' t l@(x:xs)
    | t <= 0 = l
    | otherwise = drop' (t-1) xs 
    


--uniao de listas com recursão
{-
>>> uniao [1,2,3,4] [2,4,6,8]
[1,3,2,4,6,8]

-}
uniao :: [Int] -> [Int] -> [Int]
uniao [] [] = []
uniao [] l = l
uniao (x:xs) l
    | x `elem` l = uniao xs l
    | otherwise = x:uniao xs l

{-
>>> uniao' [1,2,3,4] [2,4,6,8]
[1,3,2,4,6,8]

-}
--união de listas com compreensão
uniao' :: [Int] -> [Int] -> [Int]
uniao' x y = [e | e <- x, e `notElem` y] ++ y
