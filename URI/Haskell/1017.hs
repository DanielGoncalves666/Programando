import Text.Printf

main = do
    tempo <- getLine 
    velocidade <- getLine
    printf "%.3f\n" $ quantidadeLitros (read tempo) (read velocidade)

quantidadeLitros :: Double -> Double -> Double 
quantidadeLitros t v = (t * v) / 12.0