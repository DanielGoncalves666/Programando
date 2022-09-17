{-
Nos seguintes exercícios, implemente suas soluções de forma recursiva
Defina os tipos das funções.
-}


{-
Uma função que calcule x * y

Entrada:
    - x
    - y

Resultado: 
    - x * y

Exemplos:
>>>multiplique 2 3
6
>>>multiplique 3 3
9

>>>multiplique 3 (-3)
-9

>>>multiplique (-3) 3
-9

>>>multiplique (-3) (-3)
9

-}

multiplique :: Int -> Int -> Int
multiplique x n 
        | n == 0 = 0
        | n > 0 = x + multiplique x (n - 1)
        | x > 0 = n + multiplique n (x - 1)             {-- as duas últimas guardas são para n < 0 --}
        | x < 0 = negate x + multiplique x (n + 1)




{-
Uma função que calcule a n-ésima potência de um número x.

Entrada:
    - x: base
    - n: expoente

Resultado: 
    - x elevado a n

Exemplos:
>>>potência 2 3
8
>>>potência (-3) 2
9
-}

potência :: Int -> Int -> Int
potência x 0 = 1
potência x n = x * potência x (n - 1)



{-
Uma função que calcule log base 2 de n por divisões sucessivas por 2.

Entrada:
    - n

Resultado: 
    - log_2 (n)

Exemplos:
>>>logBase2 100
6

>>>logBase2 16
4

-}
logBase2 :: Int -> Int
logBase2 1 = 0
logBase2 n = 1 + logBase2 (quot n 2)


{-
Uma função que rotacione os elementos de uma tupla n vezes.

Entrada:
    - t: tupla de 5 inteiros.
    - n: número de rotações a ser feito. Rotacionar à direita se n é positivo e a esquerda se n é negativo.

Resultado: 
    - t rotacionado n vezes.

Exemplos:
>>>rotacionar (1,2,3,4,5) 2
(4,5,1,2,3)
>>>rotacionar (1,2,3,4,5) (-2)
(3,4,5,1,2)
-}

rotacionar :: (Int, Int, Int, Int, Int) -> Int -> (Int, Int, Int, Int, Int)
rotacionar (a, b, c, d, e) 0 = (a, b, c, d, e)
rotacionar (a, b, c, d, e) n 
        | n > 0 = rotacionar (e, a, b, c, d) (n - 1)
        | n < 0 = rotacionar (b, c, d, e, a) (n + 1)



{-
Uma função que jogue fora os caracteres inicias de uma string s até que o restante da string se inicie com um caractere c ou que a string fique fazia.

Entrada:
    - s: string
    - c: caractere.

Resultado: 
    - a string resultante.

Exemplos:
>>>jogarForaAté "Eu quis dizer, você não quis escutar." ','
", voc\234 n\227o quis escutar."

>>>jogarForaAté "Eu quis dizer, você não quis escutar." 'z'
"zer, voc\234 n\227o quis escutar."

>>>jogarForaAté "Eu quis dizer, você não quis escutar." 'v'
"voc\234 n\227o quis escutar."

-}
jogarForaAté :: String -> Char -> String
jogarForaAté s c
        | length s == 0 || s !! 0 == c = s
        | otherwise = jogarForaAté (drop 1 s) c


{-
Desafio!!

A fórmula de Leibniz para pi (http://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80)
estabelece que a constante pode ser calculada como a série

pi = (4/1) - (4/3) + (4/5) - (4/7)...
   1 - 2 + 3 - 4 + 5 - 6     
   - 6 + 5 - 4 + 3 - 2 + 1
Implemente uma função recursiva que calcule a constante até uma quantidade n de termos.

Entrada:
    - n: quantidade de termos

Resultado:
    - pi, calculado com n passos da série

Exemplos:

>>>piDeLeibniz 1
4.0

>>>piDeLeibniz 2
2.666666666666667

>>>piDeLeibniz 3
3.466666666666667

>>>piDeLeibniz 2000
3.1410926536210413

>>>piDeLeibniz 3000
3.1412593202657186


        2 * n - 1 --> enésimo número impar 
-}

piDeLeibniz :: Int -> Double
piDeLeibniz 1 = 4.0
piDeLeibniz n = 
        if n `rem` 2 == 0 then piDeLeibniz (n - 1) - 4.0 / (2 * (fromIntegral n) - 1)
                else piDeLeibniz (n - 1) + 4.0 / (2 * (fromIntegral n) - 1)
