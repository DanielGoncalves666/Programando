import Text.Printf

main = do
    p1 <- getLine 
    p2 <- getLine
    let lp1 = words p1
        lp2 = words p2
    printf "%.4f\n" $ distancia (read $ head lp1) (read $ lp1 !! 1) (read $ head lp2) (read $ lp2 !! 1)
    
distancia :: Double -> Double -> Double -> Double -> Double 
distancia x1 y1 x2 y2 = sqrt $ (x2 - x1) ^ 2 + (y2 - y1) ^ 2