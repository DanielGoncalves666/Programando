import Text.Printf

main = do
    l1 <- getLine
    l2 <- getLine

    let lista1 = words l1
        lista2 = words l2
    printf "VALOR A PAGAR: R$ %.2f\n" $ total lista1 lista2

total :: [String] -> [String] -> Double 
total l1 l2 =
    let n1 = l1 !! 1
        n2 = l2 !! 1
        v1 = l1 !! 2
        v2 = l2 !! 2
    in read n1 * read v1 + read n2 * read v2 