import Data.Char
import GHC.Real (fromIntegral)

-- Questão 1 --
{-
Um palíndromo é uma sequência que é igual ao seu reverso.
Não considere caracteres maiúsculos e minúsculos como iguais.
Defina uma função que dado uma String, verifique se ela é um palíndromo.

>>> éPalíndromo [1,2,3,2,1]
True

>>> éPalíndromo "abba"
True

>>> éPalíndromo "abBA"
False

>>> éPalíndromo [1.0,1.0,2.0]
False

>>> éPalíndromo []
True
-}

éPalíndromo :: Eq a => [a] -> Bool
éPalíndromo [] = True -- Defini como true mas poderia ser false também. 
éPalíndromo [l] = True
éPalíndromo (primeira:ls) = primeira == ultima && éPalíndromo meio
    where (ultima:meio) = reverse ls


-- Questão 2 --
{-
Um pangrama é uma **frase** que contem todas as letras do alfabeto, ignorando-se diferenças entre maiúsculas 
e minúsculas.
Escreva uma função que, dado uma String, verifique se é um pangrama.

>>>éPangrama "Bancos fúteis pagavam-lhe queijo, whisky e xadrez"
True

>>>éPangrama "Já fiz vinho com toque de kiwi para belga sexy"
True

>>>éPangrama "The quick brown fox jumps over the lazy dog"
True

>>>éPangrama "Huguinho, Zézinho e Luisinho"
False

>>> éPangrama []
False
-}

listaEmMinusculo :: String -> String
listaEmMinusculo [] = ""
listaEmMinusculo (l:ls) = (toLower l) :  listaEmMinusculo ls

éPangrama :: String -> Bool
éPangrama [] = False
éPangrama l =  null [ e | e <- ['a'..'z'], e `notElem` listaEmMinusculo l]




-- Questão 3 --
{-
1 - Defina um tipo algébrico para representar árvores binárias de qualquer tipo de dados.

2 - Defina uma função que calcule a profundidade de uma árvore, onde profundidade é a maior distância 
entre a raiz e alguma folha da árvore.
Por exemplo, a profundidade da seguinte árvore é 3, devido ao comprimento do caminho a-c-e-g na árvore.
  a
 /  \
b    c
|    | \
d    e  f
     |
     g

3 Defina uma função que retorne uma lista com os valores nas folhas de uma árvore, da esquerda para
 a direita. Para a árvore anterior, o resultado é [d,g,f]

4 Usando uma função fold, gere uma representação textual da sua escolha da árvore. Por exemplo

a (b (d) ()) (c (e (g) ()) (f))

-----------------
>>> profundidade Vazio
-1

>>> profundidade (Nó 1 Vazio Vazio)
0

>>> profundidade (Nó 1 (Nó 2 Vazio Vazio) (Nó 3 Vazio (Nó 4 Vazio Vazio)))
2

>>> folhas (Nó 1 Vazio Vazio) 
[1]

>>> folhas (Nó 1 Vazio (Nó 2 Vazio Vazio))
[2]

>>> folhas (Nó 1 (Nó 3 Vazio Vazio) (Nó 2 Vazio Vazio))
[3,2]

>>> imprimirArvoreFold (Nó 1 (Nó 3 Vazio Vazio) (Nó 2 (Nó 4 Vazio Vazio) Vazio))
"1 (3) (2 (4) () ) "
"1 (3) (2 (4) () ) "

-}

data Arvore a = Vazio | Nó a (Arvore a) (Arvore a) deriving (Show)

profundidade :: Arvore a -> Int
profundidade Vazio = -1;
profundidade (Nó x Vazio Vazio) = 0
profundidade (Nó x esq dir) = max (profundidade esq) (profundidade dir) + 1

folhas :: Arvore a -> [a]
folhas Vazio = []
folhas (Nó x Vazio Vazio) = [x]
folhas (Nó x esq dir) = folhas esq ++ folhas dir

-- imprimir sem fold
imprimirArvore :: Show a => Arvore a -> String
imprimirArvore Vazio = ""
imprimirArvore (Nó a Vazio Vazio) = show a
imprimirArvore (Nó a esq dir) = show a ++ " (" ++ imprimirArvore esq ++ ") (" ++ imprimirArvore dir ++ ") "

converte :: Show a => Arvore a -> [String]
converte Vazio = ["() "]
converte (Nó a Vazio Vazio) = [show a]
converte (Nó a esq dir) = [show a] ++ [" ("] ++ [imprimirArvore esq] ++ [") ("] ++ [imprimirArvore dir] ++ [") "]

imprimirArvoreFold :: Show a => Arvore a -> String
imprimirArvoreFold a = foldl1 (++) $ converte a
-- Essa foi a única maneira que pensei pra poder usar o fold

-- Questão 4 --
{-
*aplicação* é uma função de ordem superior que recebe uma função f e um número n como parâmetros e
 retorna (f n).

>>>aplicação (^2) 3
9

>>> aplicação (2 ^) 3
8

*x2Aplicação* é uma função de ordem superior que recebe uma função f e um número n como parâmetros e 
retorna (f (f n)).

>>>x2Aplicação (^2) 3
81

>>>x2Aplicação (2^) 3
256


xXAplicação é uma função de ordem superior que recebe uma função f, um número n e um número x como 
parâmetros e retorna (f (f ... (f n))), onde f aparece x vezes.

>>>xXAplicação (+1) 3 (-4)
7

>>> xXAplicação (2-) 1 (-4)
1
-}

aplicação :: (Num a) => (a -> a) -> a -> a
aplicação f n = f n

x2Aplicação :: (Num a) => (a -> a) -> a -> a
x2Aplicação f n = f (f n)

xXAplicação :: (Eq a, Num a, Ord a) => (a -> a) -> a -> a -> a
xXAplicação f _ 0 = 0
xXAplicação f n 1 = f n
xXAplicação f n x
    | x < 0 = f (xXAplicação f n $ negate x - 1) -- caso que o x é negativo, simplesmente invertemos o sinal
    | otherwise = f (xXAplicação f n $ x - 1)

-- Questão 5 --
{-
1 Escreva uma função recursiva que calcule a média dos valores em uma lista.
2 Escreva uma função que calcule as médias das listas em uma lista, usando map.

A média de uma lista vazia não existe.

>>> média [1,2,3]
2.0

>>> médias [[1,2,3],[4,5,6]]
[2.0,5.0]
-}

média :: [Float] -> Float
média [] = error "Lista vazia.";
média [l] = l;
média la = soma la / fromIntegral (length la)

soma :: [Float] -> Float
soma [] = 0
soma (l:ls) = l + soma ls

médias :: [[Float]] -> [Float]
médias l = map média l

-- Questão 6 --
{-
Uma árvore de decisão é uma árvore binária em que o nó tem um critério de decisão D, o filho da esquerda
 contém uma subárvore em que D é satisfeito e o filho da direita uma subárvore em que D não é satisfeito. 
 Para um exemplo, veja a imagem.

Escreva uma função que receba uma árvore de decisão e uma lista de respostas e retorne a folha correspondente
da árvore.
No exemplo, ["Sim","Não","Não"] retorna o resultado "Cochilar"

>>> decisaoFeita arvoreTeste ["Não","Não"]
"V\225 correr"

>>> decisaoFeita arvoreTeste ["Sim","Não","Não"] 
"Cochilar"
-}

--data Arvore a = Vazio | Nó a (Arvore a) (Arvore a) deriving (Show)

arvoreTeste :: Arvore String
arvoreTeste = Nó "Cansado" ( Nó "É noite" (Nó "Dormir" Vazio Vazio) (Nó "Trabalhando" (Nó "Complicou" Vazio Vazio) (Nó "Cochilar" Vazio Vazio))) (Nó "Trabalhando" (Nó "Promoção" Vazio Vazio) (Nó "Vá correr" Vazio Vazio))


decisaoFeita :: Arvore String -> [String] -> String
decisaoFeita Vazio _ = ""
decisaoFeita (Nó a esq dir) [] = a
decisaoFeita (Nó a Vazio Vazio) _ = a
decisaoFeita (Nó a esq dir) la@(l:ls)
    | l == "Sim" = decisaoFeita esq ls
    | otherwise = decisaoFeita dir ls


-- Questão 7 --
{-
Escreva uma função que receba uma lista e retorne uma lista de tuplas em que os primeiros elementos
 são os elementos da lista e os segundos elementos são as quantidades de vezes que os elementos aparecem
 na lista.

>>> quantidades [1,5,3,6,8,4,3,2,1,1,1]
[(1,4),(5,1),(3,2),(6,1),(8,1),(4,1),(2,1)]

>>> quantidades [1..5]
[(1,1),(2,1),(3,1),(4,1),(5,1)]

Não funciona com strings.

-}

quantidades :: (Eq a, Ord a) => [a] -> [(a,Int)]
quantidades [] = []
quantidades [l] = [(l,1)]
quantidades (l:ls)
    | l `elem` ls = (l,pegarValorAnterior cauda + 1) : removeRepetido cauda
    | otherwise = (l, 1) : quantidades ls
    where cauda = quantidades ls
          removeRepetido [] = []
          removeRepetido (a:as) = if fst a == l then as   -- usado com a garantia de ter um repetido
                                                else a : removeRepetido as
          pegarValorAnterior [] = 0
          pegarValorAnterior (a:as) = if fst a == l then snd a
                                                    else pegarValorAnterior as

