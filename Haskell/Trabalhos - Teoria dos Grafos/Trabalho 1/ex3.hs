romano :: Int -> String
romano num
    | num == 1 = "I"
    | num <= 3 = "I" ++ romano (num - 1)
    | num == 4 = "IV"
    | num == 5 = "V"
    | num <= 8 = "V" ++ romano (num - 5)
    | num == 9 = "IX"
    | num == 10 = "X"
    | num <= 39 = "X" ++ romano (num - 10)
    | num <= 49 = "XL" ++ romano (num - 40)
    | num <= 50 = "L"
    | num <= 89 = "L" ++ romano (num - 50)
    | num <= 99 = "XC" ++ romano (num - 90)
    | num == 100 = "C"
    | num <= 399 = "C" ++ romano (num - 100)
    | num <= 499 = "CD" ++ romano (num - 400)
    | num == 500 = "D"
    | num <= 899 = "D" ++ romano (num - 500)
    | num <= 999 = "CM" ++ romano (num - 900)
    | num == 1000 = "M"
    | num <= 3999 = "M" ++ romano (num - 1000)
    | num >= 4000 = "Número além da representação básica."
    | otherwise = "" -- para valores negativos e quando o parâmetro é zero por conta das subtrações