import Text.Printf

main = do
    r <- getLine 
    printf "VOLUME = %.3f\n" $ volume (read r)

volume :: Int -> Double 
volume r = (4.0/3.0) * 3.14159 * fromIntegral r ** 3