-- >>> combinações [1,2,3,4] 2
-- [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

combinações :: (Ord a) => [a] -> Int -> [[a]]
combinações [] _ = []
combinações ls@(l:lx) k
    | k <= 0 || length ls < k = []
    | k == 1 = [[e] | e <- ls]
    | k == 2 = [[p,e] | p <- ls, e <- tail ls, p /= e, p < e]
    | otherwise = [ l:e | e <- combinações lx (k - 1)] ++ combinações lx k
