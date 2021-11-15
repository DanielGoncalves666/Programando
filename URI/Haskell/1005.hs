import Text.Printf

main = do
    a <- getLine 
    b <- getLine 
    printf "MEDIA = %.5f\n" $ media (read a) (read b)

media :: Double -> Double -> Double 
media a b = (a * 3.5 + b * 7.5) / 11