{-
Assim como Bool pode assumir os valores True e False, o tipo Naipe pode assumir um dos valores Copas, Espada, Ouro e Paus, tal que
Copas < Espada < Ouro < Paus

>>>Copas > Espada
False

>>> Espada > Ouro
False

>>> Paus > Copas
True

>>>maiorDeTres Copas Espada Paus
Paus

>>>maiorDeTres Copas Copas Copas
Copas

-}
data Naipe = Copas | Espada | Ouro | Paus deriving (Ord,Eq,Show)


{-
Seja o tipo de dados Carta tupla em que 
 - o primeiro elemento é o valor da carta (1,2,3,4,5,6,7,8,9,10,11,12,13) 
 - o segundo é um Naipe
-}
type Carta = (Int, Naipe)


-- Defina as seguintes funções usando apenas casamento de padrões do lado esquerdo das equações.

{-
Uma função que receba uma carta retorne seu Naipe.

Entrada:
    - c1: carta

Resultado: 
    - naipe da carta

Exemplos:
>>>naipe (1,Ouro)
Ouro
-}
naipe :: Carta -> Naipe
naipe c = snd c


{-
Uma função que receba uma carta retorne seu valor.

Entrada:
    - c1: carta

Resultado: 
    - valor da carta

Exemplos:
>>>valor (1,Ouro)
1
-}
valor :: Carta -> Int
valor c = fst c


{-
Uma função que receba duas cartas retorne se seus naipes são iguais.

Entrada:
    - c1: carta
    - c2: carta

Resultado: 
    - naipe de c1 igual a naipe de c2?

Exemplos:
>>>naipeIgual (1,Ouro) (2,Ouro)
True
>>>naipeIgual (1,Ouro) (2,Paus)
False
-}

naipeIgual :: Carta -> Carta -> Bool
naipeIgual c1 c2 = naipe c1 == naipe c2

{-
Uma função que receba uma carta e retorne seu valor por extenso.

Entrada:
    - c1: carta

Resultado: 
    - valor de c1 por extenso

Exemplos:
>>>valorPorExtenso (1,Ouro)
"Um"
>>>valorPorExtenso (2,Paus)
"Dois"
>>>valorPorExtenso (12,Ouro)
"Dama"
-}


valorPorExtenso :: Carta -> String
valorPorExtenso c = case valor c of 1 -> "Um"
                                    2 -> "Dois"
                                    3 -> "Três"
                                    4 -> "Quatro"
                                    5 -> "Cinco"
                                    6 -> "Seis"
                                    7 -> "Sete"
                                    8 -> "Oito"
                                    9 -> "Nove"
                                    10 -> "Dez"
                                    11 -> "Valete"
                                    12 -> "Dama"
                                    13 -> "Rei"
                                    _ -> error "Indefinido"

{-
Uma função que receba uma carta e retorne seu naipe por extenso.

Entrada:
    - c1: carta

Resultado: 
    - naipe de c1 por extenso

Exemplos:
>>>naipePorExtenso (1,Ouro)
"Ouro"
>>>naipePorExtenso (2,Paus)
"Paus"
>>>naipePorExtenso (12,Ouro)
"Ouro"
-}
naipePorExtenso :: Carta -> String
naipePorExtenso c1 = case naipe c1 of Copas -> "Copas"
                                      Espada -> "Espada"
                                      Ouro -> "Ouro"
                                      Paus -> "Paus"

{-
Uma função que receba três cartas e retorne um booleano dizendo se formam uma sequencia, isto é, se estão
aparecem dentro da seguinte sequência: Copas Espada Ouro Paus Copas Espada

Entrada:
    - Carta
    - Carta
    - Carta

Resultado: 
    - Estão em sequência?

Exemplos:
>>>sequênciaDeNaipes (1,Paus) (2,Ouro) (7,Copas)
False

>>>sequênciaDeNaipes (1,Paus) (7,Copas) (2,Ouro) 
False

>>>sequênciaDeNaipes (1,Paus) (2,Espada) (7,Copas)
False

>>>sequênciaDeNaipes (1,Espada) (2,Copas) (7,Ouro)
False
-}
sequênciaDeNaipes :: Carta -> Carta -> Carta -> Bool
sequênciaDeNaipes (_,n1) (_,n2) (_,n3)
        | n1 == Copas && n2 == Espada && n3 == Ouro = True
        | n1 == Espada && n2 == Ouro && n3 == Paus = True
        | n1 == Ouro && n2 == Paus && n3 == Copas= True
        | n1 == Paus && n2 == Copas && n3 == Espada = True
        | otherwise = False

{-
Uma função que recebe uma data na forma de três inteiros e retorna a da por extenso.

Entrada:
    - Dia
    - Mês
    - Ano

Resultado
    - Data por extenso
    - Quando o dia for 1, usar Primeiro como extenso.

Exemplos:
>>>dataPorExtenso 1 1 2001
"Primeiro de Janeiro de 2001"

>>>dataPorExtenso 10 3 2010
"Dez de Março de 2010"
-}

diaPorExtenso :: Int -> String
diaPorExtenso 1 = "Primeiro"
diaPorExtenso 2 = "Dois"
diaPorExtenso 3 = "Três"
diaPorExtenso 4 = "Quatro"
diaPorExtenso 5 = "Cinco"
diaPorExtenso 6 = "Seis"
diaPorExtenso 7 = "Sete"
diaPorExtenso 8 = "Oito"
diaPorExtenso 9 = "Nove"
diaPorExtenso 10 = "Dez"
diaPorExtenso 11 = "Onze"
diaPorExtenso 12 = "Doze"
diaPorExtenso 13 = "Treze"
diaPorExtenso 14 = "Quatorze"
diaPorExtenso 15 = "Quinze"
diaPorExtenso 16 = "Desesseis"
diaPorExtenso 17 = "Dezessete"
diaPorExtenso 18 = "Dezoito"
diaPorExtenso 19 = "Dezenove"
diaPorExtenso 20 = "Vinte"
diaPorExtenso 21 = "Vinte e um"
diaPorExtenso 22 = "Vinte e dois"
diaPorExtenso 23 = "Vinte e três"
diaPorExtenso 24 = "Vinte e quatro"
diaPorExtenso 25 = "Vinte e cinco"
diaPorExtenso 26 = "Vinte e seis"
diaPorExtenso 27 = "Vinte e sete"
diaPorExtenso 28 = "Vinte e oito"
diaPorExtenso 29 = "Vinte e nove"
diaPorExtenso 30 = "Trinta"
diaPorExtenso 31 = "Trinta e um"
diaPorExtenso _ = "Trinta e um"

mesPorExtenso :: Int -> String
mesPorExtenso 1 = "Janeiro"
mesPorExtenso 2 = "Fevereiro"
mesPorExtenso 3 = "Março"
mesPorExtenso 4 = "Abril"
mesPorExtenso 5 = "Maio"
mesPorExtenso 6 = "Junho"
mesPorExtenso 7 = "Julho"
mesPorExtenso 8 = "Agosto"
mesPorExtenso 9 = "Setembro"
mesPorExtenso 10 = "Outubro"
mesPorExtenso 11 = "Novembro"
mesPorExtenso 12 = "Dezembro"
mesPorExtenso _ = "Nenhum"


dataPorExtenso :: Int -> Int -> Int -> String
dataPorExtenso dia mes ano = diaPorExtenso dia ++ " de " ++ mesPorExtenso mes ++ " de " ++ show ano