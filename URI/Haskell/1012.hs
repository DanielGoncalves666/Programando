import Text.Printf

main = do
    l <- getLine
    let lista = words l
    printf "TRIANGULO: %.3f\n" $ areaTriangulo (read $ head lista) (read $ lista !! 2)
    printf "CIRCULO: %.3f\n" $ areaCirculo (read $ lista !! 2)
    printf "TRAPEZIO: %.3f\n" $ areaTrapezio (read $ head lista) (read $ lista !! 1) (read $ lista !! 2)
    printf "QUADRADO: %.3f\n" $ areaQuadrado (read $ lista !! 1)
    printf "RETANGULO: %.3f\n" $ areaRetangulo (read $ head lista) (read $ lista !! 1)

areaTriangulo :: Double -> Double -> Double 
areaTriangulo a c = (a * c) / 2

areaCirculo :: Double -> Double
areaCirculo c = 3.14159 * c ^ 2

areaTrapezio :: Double -> Double -> Double -> Double 
areaTrapezio a b c = ((a + b) * c) / 2

areaQuadrado :: Double -> Double
areaQuadrado b = b ^ 2

areaRetangulo :: Double -> Double -> Double
areaRetangulo a b = a * b