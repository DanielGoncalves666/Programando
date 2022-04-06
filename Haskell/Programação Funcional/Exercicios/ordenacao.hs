{-
Selection-Sort

>>> fs [2,5,3,7,9,6,3,5]
[2,3,3,5,5,6,7,9]


-}

fr :: Int -> [Int] -> [Int]
fr _ [] = []
fr e (x:xs)
    | x == e = xs
    | otherwise = x : fr e xs

fm :: [Int] -> Int 
fm [] = error "Lista vazia"
fm [x] = x
fm (x:xs)
    | x < resto = x
    | otherwise = resto
    where resto = fm xs 

fs :: [Int] -> [Int]
fs [] = []
fs l =
    let m = fm l
    in m : fs (fr m l)      

{-
    -- MergeSort


>>> fm' [2,5,3,7,9,6,3,5] 
[2,3,3,5,5,6,7,9]

-}

fd' :: [Int] -> ([Int],[Int])
fd' [] = ([],[])
fd' l = splitAt metade l
    where metade = length l `quot` 2

fu' :: [Int] -> [Int] -> [Int]
fu' [] l = l
fu' l [] = l
fu' lx@(x:xs) ly@(y:ys)
    | x <= y = x : fu' xs ly
    | otherwise = y : fu' lx ys

fm' :: [Int] -> [Int]
fm' [] = []
fm' [x] = [x]
fm' l =
    let (m1,m2) = fd' l
    in fu' (fm' m1) (fm' m2)


{-
	Quick-sort

>>> fq'' [2,5,3,7,9,6,3,5]
[2,3,3,5,5,6,7,9]


-}

fp'' :: [Int] -> (Int, [Int], [Int])
fp'' [] = error "lista vazia"
fp'' [p] = (p,[],[])
fp'' (p:xs) =  (p,[ e | e <- xs, e <= p], [f | f <- xs, f > p])

fq'' :: [Int] -> [Int]
fq'' [] = []
fq'' [x] = [x]
fq'' l =
    let (p,m1,m2) = fp'' l
    in fq'' m1 ++ [p] ++ fq'' m2
