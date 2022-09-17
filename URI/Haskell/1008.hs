import Text.Printf

main = do
    a <- getLine 
    b <- getLine
    c <- getLine 
    putStrLn $ "NUMBER = " ++ a
    printf "SALARY = U$ %.2f\n" $ salario (read b) (read c)

salario :: Int -> Double -> Double 
salario horas preco = preco * fromIntegral horas