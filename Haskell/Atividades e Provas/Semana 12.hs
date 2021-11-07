{- 
Defina um tipo Ponto que represente um ponto no R2 como uma dupla de números reais.

p1 :: Ponto
p1 = (10.0,11.0)
-}

type Ponto = (Double, Double)

{-
Defina um tipo algébrico FormaGeo que represente as formas geométricas básicas círculo, quadrado, retângulo e triângulo retângulo.
Cada forma deve ser posicionada usando um Ponto e ter suas dimensões fundamentais, por exemplo o raio, para o círculo.

f1 :: FormaGeo
f1 = Círculo p1 3

f2 :: FormaGeo
f2 = Quadrado p1 10.0

f3 :: FormaGeo
f2 = Retângulo p1 3 4

f3 :: FormaGeo
f3 = Triângulo p1 b a
-}

data FormaGeo = Círculo Ponto Double | Quadrado Ponto Double | Retângulo Ponto Double Double | Triângulo Ponto Double Double

{-
Defina uma função área que tenha como parâmetro formal uma FormaGeo e retorne a área da forma correspondente.
Use Casamento de Padrões.

>>> área (Círculo (1,1) 2)
12.5656

-}

área :: FormaGeo -> Double
área (Círculo _ r) = 3.1415 * r ^ 2
área (Quadrado _ l) = l ^ 2
área (Retângulo _ a b) = a * b
área (Triângulo _ b h) = (b * h) / 2


{-
Defina um tipo algébrico Mão que represente os possíveis valores do jogo Pedra/Tesoura/Papel.
Defina um tipo algébrico Jogo que tenha os valores Empate e Ganha x, onde x é uma Mão.
Defina uma função que receba duas Mão como parâmetros e retorne um Jogo.
- Se uma mão for vencedora, o Jogo deve ser Ganha x, onde x é a mão ganhadora.
- Se houver empate, o Jogo deve ser Empate.

>>> ganha Tesoura Tesoura
Empate

Defina uma função que receba uma lista de tuplas de Mão e retorne uma lista de Jogo com os respectivos resultados.
- Faça uma versão que use recursão sobre listas.
- Faça uma versão que use compreensão de listas.

>>> listaJogos' [(Pedra,Tesoura),(Papel, Pedra)]
[Ganha Pedra,Ganha Papel]

>>> listaMãosGanhadoras [Ganha Pedra, Ganha Papel,Empate, Ganha Tesoura]
[Pedra,Papel,Tesoura]

Defina uma função que receba um lista de Jogo e retorne uma lista com as Mão ganhadoras, dos jogos onde não houve empate.
- Use compreensão de listas.
-}
data Mão = Pedra | Tesoura | Papel deriving (Eq,Show)

data Jogo = Empate | Ganha Mão deriving (Show)


ganha :: Mão -> Mão -> Jogo
ganha Pedra Tesoura = Ganha Pedra
ganha Tesoura Papel = Ganha Tesoura
ganha Papel Pedra = Ganha Papel
ganha m1 m2 = if m1 == m2 then Empate
                          else Ganha m2
                          
listaJogos :: [(Mão, Mão)] -> [Jogo]
listaJogos [] = []
listaJogos (x:xs) = 
    let (m1,m2) = x
    in ganha m1 m2 : listaJogos xs

listaJogos' :: [(Mão, Mão)] -> [Jogo]
listaJogos' l = [ganha m1 m2 | (m1,m2) <- l]

listaMãosGanhadoras :: [Jogo] -> [Mão]
listaMãosGanhadoras l = [ x | Ganha x <- l]

{-
Defina um tipo algébrico Operação com valores que representem as seguintes operações matemáticas básicas:
- Add (adição), Mult (multiplicação), Div (divisão), Dif (diferença) e Neg (negação do sinal).
- As operações tem 2 ou 1 operandos (somente a negação).
- As parâmetros são números inteiros.
Escreva uma função que receba uma operação e retorne o resultado da execução da operação.
- Os resultados são números inteiros (div é a divisão inteira)
- Use casamento de padrões.

>>> execução (Neg (-1))
1
-}

data Operação = Add Int Int | Mult Int Int | Div Int Int | Dif Int Int | Neg Int 

execução :: Operação -> Int
execução (Add a b) = a + b
execução (Mult a b) = a * b
execução (Div a b) = a `div` b
execução (Dif a b) = a - b
execução (Neg a) = - a

{-
Defina um tipo algébrico Expressão com valores que representem as seguintes operações matemáticas básicas ou, recursivamente, outras expressões.
- Add (adição), Mult (multiplicação), Div (divisão), Dif (diferença) e Neg (negação do sinal).
- As operações tem 2 ou 1 operandos (somente a negação).
- As parâmetros são números inteiros OU outra expressão.
Escreva uma função que receba uma expressão e retorne o cálculo expressão.
- Use recursão e casamento de padrões.
- Os resultados são números inteiros (div é a divisão inteira)

Exemplo: A expressão  -1 * ((3*4) + 1) é representada assim

        EMult
       /     \
    ENeg      EAdd
   /         /     \
ENum   EMult       ENum
  |    /   \         |
  1   ENum  ENum     1
       |     |
       3     4

>>>calculaE (Número 1)
1

>>>calculaE (Neg' (Número 1))
-1

>>>calculaE (Mult' (Número 3) (Número 4))
12

>>>calculaE (Mult' (Neg' (Número 1)) (Add' (Mult' (Número 3) (Número 4)) (Número 1)))
-13
-}

data Exp = Número Int | Add' Exp Exp | Mult' Exp Exp | Div' Exp Exp | Dif' Exp Exp | Neg' Exp 

calculaE :: Exp -> Int
calculaE (Número n) = n
calculaE (Add' e1 e2) = calculaE e1 + calculaE e2
calculaE (Mult' e1 e2) = calculaE e1 * calculaE e2
calculaE (Div' e1 e2) = calculaE e1 `div` calculaE e2
calculaE (Dif' e1 e2) = calculaE e1 - calculaE e2
calculaE (Neg' e1) = negate (calculaE e1)
