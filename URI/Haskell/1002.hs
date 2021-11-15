import Text.Printf

main = do
    r <- getLine
    printf "A=%.4f\n" (area $ read r) 

area :: Double -> Double   
area r = r ^ 2 * 3.14159