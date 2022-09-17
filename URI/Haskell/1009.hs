import Text.Printf

main = do
    a <- getLine 
    b <- getLine
    c <- getLine 
    printf "TOTAL = R$ %.2f\n" $ salario (read b) (read c)

salario :: Double -> Double -> Double 
salario base vendas = base + 0.15 * vendas