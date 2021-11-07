-- File containing utility functions for lists.

module Root.Src.Exercise where

--Eu
nome = "Daniel Gonçalves"   --coloque seu nome aqui, como uma String
-- juro pela minha honra, que serei ético na realização desta avaliação, 
-- não consultando nada e nem ninguém, além das notas de aulas e das 
-- minha soluções para exercícios anteriores.

{-
A função maximum procura retorna o maior elemento em uma lista.
Escreva uma função com comportamento similar, recursiva.
-}

máximo :: [Int] -> Int
máximo [] = []
máximo l
        | length l == 1 = cabeca 
        | otherwise = if cabeca > valorMaximo then cabeca
                                              else valorMaximo  
        where valorMaximo = máximo (tail l)
              cabeca = head l

{-
A fórmula de Bhaskara permite calcular as raízes de uma equação de segundo grau
na forma ax^2 + bx + c = 0. A resolução é normalmente dividida em duas partes, o
cálculo do discriminante, Delta, e das raízes. O Delta é calculado pela equação
seguinte:
 Delta  = b^2 - 4ac

Calculado o delta, a seguinte equação calcula as raízes.
 raiz1 = (-b + Delta^(1/2)) / 2a
 raiz2 = (-b - Delta^(1/2)) / 2a

Observe que:
 Se Delta > 0, a equação do segundo grau tem 2 raízes.
 Se Delta = 0, 1 raiz.
 Se Delta < 0, tem 0 raízes reais.


1 - Escreva uma função que receba uma tripla com os coeficientes da equação,
isto é, (a,b,c), e retorne o valor de Delta.

2 - Escreva uma função que receba uma tripla com os coeficientes da equação,
isto é, (a,b,c), retorne uma lista com as raízes da equação de segundo
grau. Defina a função usando guardas. Utilize a função delta.
-}

delta :: (Float, Float, Float) -> Float
delta (a,b,c) = b ^ 2 - 4 * a * c

raízes :: (Float,Float,Float) -> [Float]
raízes (a,b,c)
          | valorDelta < 0 = []
          | valorDelta == 0 = [ (negate b) / (2 * a) ]
          | valorDelta > 0 = [ ((negate b) + raiz) / (2 * a) , ((negate b) - raiz) / (2 * a) ]
          where valorDelta = delta (a,b,c)
                raiz = sqrt valorDelta

{-
Considere que o preço de uma passagem de ônibus intermunicipal pode variar dependendo
da idade do passageiro
- crianças menos de 10 anos pagam 40% e bebês (abaixo de 2 anos) pagam apenas 15%. 
- pessoas com 70 anos ou mais pagam apenas 50% do preço total. 
- os demais passageiros pagam a tarifa normal, 100%. 

Faça uma função que tenha como entrada:
- o valor total da passagem,
- a data atual e 
- a data de nascimento do passageiro. 

Como saída, a função retorna o valor a ser pago. 

Obs. 1: na solução, deve ser definido o tipo data para representar a tupla de inteiros (d,m,a).
Obs. 2: assuma que as datas estão corretas.
Obs. 3: assuma que todos os meses tem 30 dias e o ano tem 360 dias.
-}

type Data = (Int, Int, Int)

first (um,_,_) = um
second (_,dois,_) = dois
third (_,_,tres) = tres

idade :: Data -> Data -> Int
idade dataNasc dataHoje = (totalDias + totalMeses * 30 + totalAnos * 360) `quot` 360
        where totalDias = first dataHoje + (30 - first dataNasc)
              totalMeses = (second dataHoje - 1) + (12 - second dataNasc)
              totalAnos = third dataHoje - third dataNasc - 1

valorFinal :: Float -> Data -> Data -> Float
valorFinal preço dataNasc dataHoje
        | calcIdade < 2 = preço * 0.15
        | calcIdade < 10 =  preço * 0.40
        | calcIdade >= 70 =  preço * 0.5
        | otherwise = preço
        where calcIdade = idade dataNasc dataHoje



data Filtro = Menor | Maior | Igual deriving Eq

{-
O tipo Filtro pode ter um dos três valores definidos na linha anterior.
Escreva uma função recursiva que receba como entrada
- tupla com Filtro f na primeira posição e inteiro i na segunda posição.
- lista de inteiros l

Retorne
- Lista com todos os inteiros em l que são menores que i, se f for Menor, maiores que i se
f for Maior, e iguais a i, se f for Igual.
-}

filtre :: (Filtro,Int) -> [Int] -> [Int]
filtre f l
        | length l == 0 = []
        | fst f == Menor = if snd f > primeiro then concat [[primeiro], filtrarFim]
                                             else filtrarFim
        | fst f == Maior = if snd f < primeiro then concat [[primeiro], filtrarFim]
                                             else filtrarFim
        | fst f == Igual = if snd f == primeiro then concat [[primeiro], filtrarFim]
                                             else filtrarFim
        where filtrarFim = filtre f (tail l)
              primeiro = head l

{-
Sabendo que:
- no mercado de ações brasileiro, ações são negociadas em lotes de 100 unidades;
- cada ação é identificada por um nome único, o "ticker", por exemplo VALE3 ou BOVA11;
- quando se compra um lote de ações, ele vai para a "carteira" do comprador;
- os proprietários das ações usam o custo médio das ações para calcular lucros e prejuízos.

Implemente as seguintes funções:
* compre
  - Entrada
     + uma tupla com o ticker (String) e o preço da ação (por unidade)
     + a quantidade de ações a comprar (múltiplo do tamanho de um lote)
     + a carteira a atual, na forma de uma lista de tuplas com ticker e custo médio das ações.
  - Retorna
     + a nova carteira, corrigida pela adição das ações compradas e com preços médios atualizados.

* venda
  - Entrada
     + uma tupla com o ticker (String) e o preço da ação (por unidade)
     + a quantidade de ações a vender (múltiplo do tamanho de um lote)
     + a carteira a atual, na forma de uma lista de tuplas com ticker e custo médio das ações.
  - Retorna
     + a nova carteira, corrigida pela remoção das ações vendidas. Se a venda não for possível,
     a carteira permanece intacta.


-}

primeiro :: (String, Float, Int) -> String
primeiro (nome, _, _) = nome

segundo :: (String, Float, Int) -> Float
segundo (_, preco, _) = preco

terceiro :: (String, Float, Int) -> Int
terceiro (_, _, inteiro) = inteiro

-- devia ser média ponderada
media f1 f2 = (f1 + f2) / 2

compre :: (String, Float) -> Int -> [(String, Float, Int)] -> [(String, Float, Int)]
compre compra qtd carteira
        | length carteira == 0 = [(fst compra, snd compra, qtd)]
        | otherwise = if primeiro primeiroCarteira == fst compra then concat [ [( fst compra , media (snd compra) (segundo primeiroCarteira), qtd + terceiro primeiroCarteira)] , tail carteira]
                                                                 else concat [ [primeiroCarteira], compre compra qtd (tail carteira)] 
        where primeiroCarteira = head carteira


venda :: (String, Float) -> Int -> [(String, Float, Int)] -> [(String, Float, Int)]
venda vender quantidade carteira
        | length carteira == 0 = []
        | primeiro primeiroCarteira == fst vender && terceiro primeiroCarteira - quantidade > 0 = concat [ [( fst vender , segundo primeiroCarteira, terceiro primeiroCarteira - quantidade)] , fim]
        | primeiro primeiroCarteira == fst vender && terceiro primeiroCarteira - quantidade == 0 = fim
        | otherwise = concat [[primeiroCarteira], venda vender quantidade fim]
        where primeiroCarteira = head carteira
              fim = tail carteira


