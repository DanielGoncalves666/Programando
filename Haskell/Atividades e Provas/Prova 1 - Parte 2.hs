-- File containing utility functions for lists.

module Root.Src.Exercise where

--Eu
nome = "Daniel Gonçalves 12011BCC011"   -- coloque seu nome e matrícula aqui, como uma String
-- juro pela minha honra, que serei ético na realização desta avaliação, 
-- não consultando nada e nem ninguém, além das notas de aulas e das 
-- minha soluções para exercícios anteriores.



{-
Escreva uma função **recursiva**  que calculo a soma dos quadrados dos números inteiros entre os parâmetros passados, inclusive.

Entrada:
    - i - Inteiro
    - n - Inteiro
Resultado
    - i^2 + (i+1)^2 + ... + n^2

>>>somaDosQuadrados 1 3

>>>somaDosQuadrados 3 6

>>>somaDosQuadrados 5 2

>>>somaDosQuadrados 3 (-2)

-}

somaDosQuadrados :: Int -> Int -> Int
somaDosQuadrados i n
        | i == n = quadradoI
        | i > n = quadradoN + somaDosQuadrados i (n + 1)
        | i < n = quadradoI + somaDosQuadrados (i + 1) n
        where quadradoI = i ^ 2
              quadradoN = n ^ 2



{-
Dado um período, escreva uma função que decida se é uma afirmação, interrogação, exclamação, ou nenhum.

Entrada:
    - periodo - String

Resultado:
    - "afirmacao", se período termina com . , ou "exclamacao" se período termina com !, ou "interrogacao" se período
    termina  com ?, ou "nada", caso contrário.
    Ignorar espaços no fim do período.

>>>tipoPeríodo "Oi."
"afirmacao"

>>>tipoPeríodo "Oi?"
"interrogacao"

>>>tipoPeríodo "Oi!"
"exclamacao"

>>>tipoPeríodo "Oi"
"nada"

>>>tipoPeríodo "Oi^"
"nada"

>>>tipoPeríodo "Oi."
"afirmacao"

>>>tipoPeríodo "Oi?     "
"interrogacao"

-}


trim periodo
        | last periodo == ' ' = trim ( reverse (tail (reverse periodo)))
        | otherwise = periodo

tipoPeríodo :: [Char] -> [Char]
tipoPeríodo período
        | ultimo == '.' = "afirmacao"
        | ultimo == '!' = "exclamacao"
        | ultimo == '?' = "interrogacao"
        | otherwise = "nada"
        where ultimo = last (trim período)



{-
Defina uma função que remova as primeiras duplicatas de uma lista de inteiros.

Entrada:
    - l - lista de inteiros.

Resultado:
    - lista em que as primeiras ocorrências repetidas de qualquer valor foram removidas.

>>>removeDuplicatas [1,2,3,4,5,3,7,8,3]
[1,2,4,5,7,8,3]

-}

removeDuplicatas :: [Int] -> [Int]
removeDuplicatas [] = []
removeDuplicatas l
        | elem cabeca resto = recursao
        | otherwise = concat [[cabeca], recursao]
        where cabeca = head l
              resto = tail l
              recursao = removeDuplicatas resto

{-
Defina uma função que remova as últimas duplicatas de uma lista de inteiros.

Entrada:
    - l - lista de inteiros.

Resultado:
    - lista em que as primeiras ocorrências repetidas de qualquer valor foram removidas.

>>>removeDuplicatas2 [1,2,3,4,5,3,7,8,3]
[1,2,3,4,5,7,8]

-}

removeDuplicatas2 :: [Int] -> [Int]
removeDuplicatas2 [] = []
removeDuplicatas2 l
        | elem cabecaFinal restoFinal = recursao
        | otherwise = concat [recursao, [cabecaFinal]]
        where cabecaFinal = head (reverse l)
              restoFinal = tail (reverse l)
              recursao = removeDuplicatas2 (reverse restoFinal)


{-
Mastermind 1.

Dado uma lista com 4 de 8 possíveis cores, determinar se a lista é válida.

Entrada:
    - l - Lista de inteiro, onde cada inteiro vai de 1 a 8 e representa uma cor.

Resultado:
    - True se não há repetições e tem tamanho 4
    - False se há repetições ou tamanho diferente de 4

>>>mmVálido [1,2,3,4]
True

>>>mmVálido [1,2,3,9]
False

>>>mmVálido [1,2,3,4,5]
False

>>>mmVálido [1,2,4,4]
False

-}

temRepeticao :: [Int] -> Bool
temRepeticao [] = False
temRepeticao l 
        | elem cabeca resto = True
        | otherwise = temRepeticao resto
        where cabeca = head l
              resto = tail l

mmVálido :: [Int] -> Bool
mmVálido l 
        | length l /= 4 = False
        | maximum l > 8 || minimum l < 1 = False
        | temRepeticao l = False
        | otherwise = True

{-
Mastermind 2

Dado duas listas, se alguma não é válida, lançar uma exceção (use error).
Se as duas são válidas, retornar uma tupla com a quantidade de acertos bons e ótimos da jogada.

Entrada
    - config - lista de inteiro
    - jogada - lista de inteiro

Resultado
    - tupla (o,b) onde o é um inteiro com a quantidade de cores em jogada e que aparecem na mesma posição em config
    e b é quantidade de cores em jogada e que aparecem em posições diferentes em config.


>>>tentativa [1,2,3,4] [5,6,7,8]
(0,0)

>>>tentativa [1,2,3,4] [1,2,3,4]
(4,0)

>>>tentativa [1,2,3,4] [4,3,2,1]
(0,4)

>>>tentativa [1,2,3,4] [2,1,3,4]
(2,2)

>>>tentativa [1,2,3,4,5] [2,1,3,4]
error "não válido"
-}

acertosOtimos :: [Int] -> [Int] -> Int
acertosOtimos [] [] = 0
acertosOtimos config jogada
        | cabecaC == cabecaJ = 1 + acertosOtimos tailC tailJ
        | otherwise = acertosOtimos tailC tailJ
        where cabecaC = head config
              cabecaJ = head jogada
              tailC = tail config
              tailJ = tail jogada

--calcula a quantidade bons acertos + otimos
acertosBons :: [Int] -> [Int] -> Int
acertosBons _ [] = 0
acertosBons config jogada
        | elem cabecaJ config = 1 + acertosBons config tailJ
        | otherwise = acertosBons config tailJ
        where cabecaJ = head jogada
              tailJ = tail jogada           
              

tentativa :: [Int] -> [Int] -> (Int, Int)
tentativa config jogada
        | not (mmVálido config) || not (mmVálido jogada) = error "não válido"
        | otherwise = (acertosOtimos config jogada, acertosBons config jogada - acertosOtimos config jogada)
