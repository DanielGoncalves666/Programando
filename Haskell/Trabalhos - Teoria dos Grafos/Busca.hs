module Busca where

import BaseGrafo

-- ============================================================================================================================================= --
--                                                                  Lista 5
-- ============================================================================================================================================= --


-- 1
-- Segue da melhor forma o algoritmo passado no material
-- No fim todas as arestas são exploradas
-- Por definição do algoritmo, apenas um componente conexo é explorado
genérica :: Grafo Int -> [Int]
genérica g = genéricaAux g [] [primeiro] [primeiro]
    where primeiro = head $ vértices g

-- exploradas é uma lista que guarda as arestas já exploradas. Por questões de ordem da forma (v1, v2), tanto (v1,v2) como (v2,v1) são armazenadas.
-- visitados guarda os vértices na ordem de visita
-- visitadosInexplorados guarda os vértices visitados cujos vizinhos não foram todos visitados.
genéricaAux :: Grafo Int -> [(Int,Int)] -> [Int] -> [Int] -> [Int]
genéricaAux _ _ visitados [] = visitados
genéricaAux g exploradas visitados visitadosInexplorados
    | null novasExploradasParcial = genéricaAux g exploradas visitados (tail visitadosInexplorados) -- se o vértice já tiver sido totalmente explorado 
    | otherwise = genéricaAux g novasExploradasFinal visitadosFinal visitadosInexploradosFinal
    where primeiro = head visitadosInexplorados
          viz = vizinhos g primeiro
          novasExploradasParcial = [ (primeiro,a) | a <- viz, (primeiro,a) `notElem` exploradas && (a,primeiro) `notElem` exploradas]
          novasExploradasFinal = exploradas ++ novasExploradasParcial
          visitadosFinal = visitados ++ [ a | a <- viz, a `notElem` visitados]
          visitadosInexploradosFinal = tail visitadosInexplorados ++ [ a | a <- viz, a `notElem` visitados]

-- 2
largura :: Grafo Int -> [Int]
largura g = larguraAux g [primeiro] [primeiro] -- v marcado como visitado e colocado no final da fila
    where primeiro = head $ vértices g

larguraAux :: Grafo Int -> [Int] -> [Int] -> [Int]
larguraAux g [] visitados = visitados -- quando a fila for vazia, retornamos a lista de visitados
larguraAux g fila visitados = larguraAux g filaNova visitadosNovo
    where vizPrimeiro = vizinhos g (head fila) -- vizinhos do primeiro vértice da fila
          filaNova = tail fila ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- primeiro elemento da fila removido. 
          -- adicionams à fila os vértices que não foram visitados ainda
          visitadosNovo = visitados ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- vértices não visitados são marcados como visitados

-- 3
profundidade :: Grafo Int -> [Int]
profundidade g = profundidadeAux g [primeiro] []
    where primeiro = head $ vértices g

profundidadeAux :: Grafo Int -> [Int] -> [Int] -> [Int]
profundidadeAux g [] visitados = visitados
profundidadeAux g fila visitados
    | v `elem` visitados = profundidadeAux g (tail fila) visitados -- caso um vértice já tenha sido visitado, ele é ignorado
    | otherwise = profundidadeAux g filaNova visitadosNovo
    where v = head fila
          vizFila = vizinhos g v -- vértices adjascentes à v
          filaNova = [a | a <- vizFila, a `notElem` visitados] ++  tail fila
          -- Para os vértices adjascentes à v que não tenham já sido visitados, eles são adicionados no ínicio da fila, em ordem crescente
          visitadosNovo = visitados ++ [v] -- adiciona o vértice v ao final da lista de visitados

-- 4 
-- grafo não-valorado
menorCaminho :: Grafo Int -> Int -> Int -> [Int]
menorCaminho g u v
    | u `notElem` vet || v `notElem` vet || u == v = error "Pelo menos um dos vértices não existe no grafo e eles não podem ser iguais."
    | otherwise = u : [head a | a <- listasLargReduzida]
    where vet = vértices g
          listasLarg = verticesLarguraN g [u] [u] v
          listasLargReduzida = reverse (geraCaminhosValidos g (reverse listasLarg))

-- retorna uma lista de lista, cada uma contendo os vértices a uma distância n da origem. A última lista contém apenas o vértice que finaliza o caminho
verticesLarguraN :: Grafo Int -> [Int] -> [Int] -> Int -> [[Int]]
verticesLarguraN g [] _ fim = error ("O vértice " ++ show fim ++ " não pode ser alcançado.")
verticesLarguraN g fila visitados fim
    | fim `elem` esteNivel = [[fim]]
    | null esteNivel = verticesLarguraN g filaNova visitadosNovo fim
    | otherwise = esteNivel : verticesLarguraN g filaNova visitadosNovo fim
    where vizPrimeiro = vizinhos g (head fila)
          esteNivel = [a | a <- vizPrimeiro, a `notElem` visitados]
          filaNova = tail fila ++ esteNivel
          visitadosNovo = visitados ++ esteNivel

-- retorna uma lista de lista, cada uma contendo os vértices que podem ser escolhidos para um caminho 
geraCaminhosValidos :: Grafo Int -> [[Int]] -> [[Int]]
geraCaminhosValidos g ll
    | length ll == 1 = ll
    | otherwise = ultimo : geraCaminhosValidos g (vizUltimosEmPenultimo : tail (tail ll))
    where ultimo = head ll
          penultimo = head (tail ll)
          vizUltimos = concat [ vizinhos g a | a <- ultimo] -- contém todo os vizinhos dos vértices em ultimo. Ocorrerá duplicação aqui
          vizUltimosEmPenultimo = [ a | a <- penultimo, a `elem` vizUltimos]


-- 5
dijkstra :: Grafo Int -> Int -> ([Int],[Int])
dijkstra g v = error "implementar"
    where viz = vizinhos g v

dijkstraAux :: Grafo Int -> Int -> ([Int],[Int]) -> ([Int],[Int])
dijkstraAux g v (x,y) =error "implementar"

{-
dijkstra g v, recebe um grafo g e um vértice v e devolve um par (d,p) de vetores
contendo em d as menores distâncias de v até qualquer outro vértice de g e em p os
predecessores. Use o algoritmo de Dijkstra.

-}

-- ============================================================================================================================================= --
--                                                                  Lista 7
-- ============================================================================================================================================= --

{-
-- 6
-- 1 para verde, 2 para amarelo, 3 para vermelho
emProfundidade :: Grafo Int -> Int -> ([Int],[Int],[Int])
emProfundidade g v = exploraBEP g v cor pai td tf 0
    where numVert = length $ vértices g
          cor = [1 | a <- [1..numVert]]
          pai = [v | a <- [1..numVert]]
          td = [0 | a <- [1..numVert]]
          tf = [0 | a <- [1..numVert]]
           
exploraBEP :: Grafo Int -> Int -> [Int] -> [Int] -> [Int] -> [Int] -> Int -> ([Int],[Int],[Int],Int)
exploraBEP g v cor pai td tf t = 
    where corN = substituiPosicao cor v 2
          tN = t + 1
          tdN = substituiPosicao td v tN
          vizV = vizinhos g v -- vértices adjascentes
          (corNN, paiNN, tdNN, tfNN, tNN) = exploraBEPAux g vizV v corN pai tdN tf tN

exploraBEPAux :: Grafo Int -> [Int] -> Int -> [Int] -> [Int] -> [Int] -> [Int] -> Int -> ([Int],[Int],[Int],[Int],Int)
exploraBEPAux g [] v cor pai td tf t =  (cor, pai, td, tf, t)
exploraBEPAux g viz v cor pai td tf t
    | corU == 1 = exploraBEP g u cor paiN td tf    -- verde
    | otherwise = 
    where u = head viz
          corU = cor !! (u - 1)
          paiN = substituiPosicao pai u v
-}