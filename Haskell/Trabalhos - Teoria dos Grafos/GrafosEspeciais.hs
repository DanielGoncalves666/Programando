module GrafosEspeciais where

import BaseGrafo
import FuncoesAuxiliares

-- adiciona múltiplas arestas de forma recursiva
-- primeiro parâmetro é um grafo
-- segundo parâmetro é uma lista de arestas
adicionarArestas :: (Ord r) => Grafo r -> [(r,r)] -> Grafo r
adicionarArestas gr [] = gr
adicionarArestas gr n
   | (x,y) `elem` arestas gr || (y,x) `elem` arestas gr = adicionarArestas gr (tail n) -- ignora arestas já presentes
   | otherwise = adicionarArestas (novaAresta gr (head n)) (tail n)
   where (x,y) = head n

-- 1
vazio :: Int -> Grafo Int
vazio n = novoGrafo [1..n] []

-- 2
caminho :: Int -> Grafo Int
caminho n = novoGrafo [1..n] [ (a, a + 1) | a <- [1..(n - 1)]]

{-
Tabuleiro

1 2 3 4
5 6 7 8

dimensões p por q
p*i + j, com i = [0..(p - 1)] e j = [1..q]

Dados (i,j) e (k,l) as coordenadas de duas casa de acordo com o modelo acima:
    i == k significa que as duas casas estão na mesma linha
    k == l significa que as duas casas estão na mesma coluna
    abs (i - k) == abs (j - l) significa que a casa (k,l) está em uma das diagonais de (i,j)
    not $ i == k && j == l significa que a própria casa não pode ser incluída
-}

-- 3
grade :: Int -> Int -> Grafo Int
grade p q =
    let nG = novoGrafo [ a | a <- [1..(p*q)]] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(q * i + j, q * k + l) | i <- [0..(p - 1)], j <- [1..q], k <- [0..(p - 1)], l <- [1..q], (i == k && abs (j - l) == 1) || (j == l && abs (i - k) == 1)]


-- 4
dama :: Int -> Grafo Int
dama t =
    let nG = novoGrafo [1.. (t ^ 2)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(t * i + j, t * k + l) | i <- [0..(t - 1)], j <- [1..t], k <- [0.. (t - 1)], l <- [1..t], i == k || j == l || abs (i - k) == abs (j - l) , not $ i == k && j == l]

-- 5
cavalo :: Int -> Grafo Int
cavalo t =
    let nG = novoGrafo [1.. (t ^ 2)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(t * i + j, t * (i + k) + (j + l)) | i <- [0..(t - 1)], j <- [1..t], (k,l) <- [(-2,-1),(-2,1),(-1,-2),(-1,2),(1,-2),(1,2),(2,-1),(2,1)], not $ i + k < 0 || i + k >= t || j + l < 1 || j + l > t]

-- 6 
bispo :: Int -> Grafo Int
bispo t =
    let nG = novoGrafo [1..(t ^ 2)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(t * i + j, t * k + l) | i <- [0..(t - 1)], j <- [1..t], k <- [0.. (t - 1)], l <- [1..t], abs (i - k) == abs (j - l), not $ i == k && j == l]

-- 7
torre :: Int -> Grafo Int
torre t =
    let nG = novoGrafo [1..(t ^ 2)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(t * i + j, t * k + l) | i <- [0..(t - 1)], j <- [1..t], k <- [0.. (t - 1)], l <- [1..t], i == k || j == l,  not $ i == k && j == l]

-- 8
rei :: Int -> Grafo Int
rei t =
    let nG = novoGrafo [1..(t ^ 2)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(t * i + j, t * (i + k) + (j + l)) | i <- [0..(t - 1)], j <- [1..t], k <- [-1,0,1], l <- [-1,0,1], not $ i + k < 0 || i + k >= t || j + l < 1 || j + l > t || (i + k == i && j + l == j)]

-- 9
cubo :: Int -> Grafo Int
cubo k =
    let nG = novoGrafo [1..(2 ^ k)] [] -- cria o grafo com os vértices
    in adicionarArestas nG [(a, b) | a <- [1..(2 ^ k)], b <- [1..(2 ^ k)], comparar (representação 2 (a - 1) ) (representação 2 (b - 1)) 0 k]

-- 10
peterson :: Grafo Int
peterson =
    let totalVet = fatorial 5 1 `div` (fatorial 2 1 * fatorial 3 1)
        elemDosVertices = zip [1..totalVet] $ combinações [1..5] 2
        nG = novoGrafo [1..totalVet] []
    in adicionarArestas nG [(a, b) | (a,la) <- elemDosVertices, (b,lb) <- elemDosVertices, null $ intersecao la lb]

-- 11
kneser :: Int -> Int -> Grafo Int
kneser n k
    | k > n `div` 2 = error "Parâmetros inválidos"
    | otherwise = adicionarArestas nG [(a, b) | (a,la) <- elemDosVertices, (b,lb) <- elemDosVertices, null $ intersecao la lb]
    where totalVet = fatorial n 1 `div` (fatorial k 1 * fatorial (n - k) 1)
          elemDosVertices = zip [1..totalVet] $ combinações [1..n] 2
          nG = novoGrafo [1..totalVet] []

-- 12
grafoArestas :: Grafo Int -> Grafo (Int,Int)
grafoArestas g =
    let vet = arestas g
        nG = novoGrafo vet []
    in adicionarArestas nG [((a1,a2),(b1,b2)) | (a1,a2) <- vet, (b1,b2) <- vet, not $ a1 == b1 && a2 == b2, a1 == b1 || a1 == b2 || a2 == b1 || a2 == b2]

-- 13
-- Como não consegui fazer essa questão, pedir a um colega para poder usá-la para os testes de trabalhos futuros.
regular :: Int -> Int -> Grafo Int
regular n r
    | (n `mod` 2 == 1 && r `mod` 2 == 1) || r > (n-1) = error "Invalido"
    | even r = novoGrafo [1..n] par
    | otherwise = novoGrafo [1 .. n] impar
    where
        m = if even r then r `div` 2 else (r-1) `div` 2
        par = [(x,y)| x <- [1..n], y <- [1..n], x /= y, x < y, dist x y <= m]
        impar = [(x,y)| x <- [1..n], y <- [1..n], x /= y, x < y, dist x y <= m || dist x y == n `div` 2]
        dist x y = if abs (x - y) > n `div` 2 then n - abs (x - y) else abs (x - y)

-- 14
completo :: Int -> Grafo Int
completo n =
    let nG = novoGrafo [1..n] []
    in adicionarArestas nG [(a,b) | a <- [1..n], b <- [1..n], a /= b]

-- 15
ciclo :: Int -> Grafo Int
ciclo n =
    let nG = novoGrafo [1..n] []
    in adicionarArestas nG ([(a, a + 1) | a <- [1..(n - 1)]] ++ [(1,n)])

-- 16
amigo :: Int -> Grafo Int
amigo n =
    let nG = novoGrafo [1..(2*n + 1)] [(1,b) | b <- [2..(2*n + 1)]] -- grafo estrela, sem arestas repetidas
    in adicionarArestas nG [(a,a+1) | a <- [2,4..(2*n)]] -- completa com a aresta restante todos os grafos cíclicos de 3 vértices

-- 17
roda :: Int -> Grafo Int
roda n =
    let nG = ciclo (n - 1) -- grafo ciclo
        nGV = novoVértice nG n -- adiciona o vértice universal, que é o n
    in adicionarArestas nGV [(n,b)| b <- [1..(n - 1)]] -- adiciona as arestas ligando o vértice universal com os outros

-- 18
bipartidoCompleto :: Int -> Int -> Grafo Int
bipartidoCompleto p q = novoGrafo [1..(p + q)] [(a,b) | a <- [1..p], b <- [(p+1)..(p+q)]] -- sem arestas repetidas

-- 19
estrela :: Int -> Grafo Int
estrela n = novoGrafo [1..(n+1)] [(1,b) | b <- [2..(n+1)]] -- sem arestas repetidas

-- 20
grafoAleatório :: Int -> Int -> IO (Grafo Int)
grafoAleatório n m = do
    let nG = novoGrafo [1..n] []
        com = completo n
        maximo = (n ^ 2 - n) `div` 2

    if m > maximo then return com
                  else aleatorioAux nG n m


aleatorioAux :: Grafo Int -> Int -> Int -> IO (Grafo Int)
aleatorioAux g n m = do
    let listA = arestas g
    a1 <- sorteia 1 n
    a2 <- sorteia 1 n

    if m == 0 then return g
              else if a1 == a2 || (a1,a2) `elem` listA || (a2,a1) `elem` listA then aleatorioAux g n m -- já elimina arestas repetidas
                                                                   else aleatorioAux (novaAresta g (a1,a2)) n (m - 1)

-- 21
bipartido :: Int -> Int -> Int -> IO (Grafo Int)
bipartido p q m = do
    let nG = novoGrafo [1..(p+q)] []
        com = bipartidoCompleto p q
        maximo = p * q

    if m > maximo then return com
                  else aleatorioBiAux nG p q m

aleatorioBiAux :: Grafo Int -> Int -> Int -> Int -> IO (Grafo Int)
aleatorioBiAux g p q m = do
    let listA = arestas g
    a1 <- sorteia 1 p
    a2 <- sorteia (p + 1) (p + q)

    if m == 0 then return g
              else if (a1,a2) `elem` listA || (a2,a1) `elem` listA then aleatorioBiAux g p q m -- já elimina arestas repetidas
                                                                   else aleatorioBiAux (novaAresta g (a1,a2)) p q (m - 1)
