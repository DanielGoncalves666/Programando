import Text.Printf

main = do
    a <- getLine 
    b <- getLine
    c <- getLine
    printf "MEDIA = %.1f\n" $ media (read a) (read b) (read c)

media :: Double -> Double -> Double -> Double 
media a b c = (a * 2 + b * 3 + c *  5) / 10