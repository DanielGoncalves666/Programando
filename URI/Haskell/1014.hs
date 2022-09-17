import Text.Printf

main = do
    dist <- getLine 
    gastos <- getLine
    printf "%.3f km/l\n" $ media (read dist) (read gastos)

media :: Double -> Double -> Double 
media distancia litros = distancia / litros