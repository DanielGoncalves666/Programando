{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module ArvoreGeradora where

import BaseGrafoValorado
import Data.List

-- ============================================================================================================================================= --
--                                                                  Lista 8
-- ============================================================================================================================================= --

-- 1
kruskal :: Grafo Int Int -> Grafo Int Int
kruskal g = kruskalAux nG arestasCrescente
    where nG = novoGrafo (vértices g) [] -- Passo 1
          arestasCrescente = quicksortArestas $ arestas g -- Passo 2

kruskalAux :: Grafo Int Int -> [(Int,Int,Int)] -> Grafo Int Int
kruskalAux g [] = error "Não foi possível criar uma árvore geradora pois não era um grafo conexo."
kruskalAux g (b:bs)
    | numCompConexas g == 1 = g -- Passo 4
    | numCompConexas g == numCompConexas nG + 1 = kruskalAux nG bs -- Passo 3.1
    | otherwise = kruskalAux g bs -- Passo 3.2
    where nG = novaAresta g b

-- 2
prim :: Grafo Int Int -> Grafo Int Int
prim g
    | not $ éConexo g = error "Grafo não é conexo."
    | otherwise = primAux g t b
    where b = [head $ vértices g]
          t = novoGrafo b []

primAux :: Grafo Int Int -> Grafo Int Int -> [Int] -> Grafo Int Int
primAux g t b
    | length (vértices g) == length (vértices t) = t
    | otherwise = primAux g nT nB
    where arestasIncidentesEmB = [ (x,c,y) | (x,c,y) <- arestas g, (x `elem` b && y `elem` vértices g \\ b) || (y `elem` b && x `elem` vértices g \\ b)]
          arestasIncidentesCrescentes = quicksortArestas arestasIncidentesEmB
          (m,c,n) = head arestasIncidentesCrescentes 
          verticeAdicionar = [d | d <- [m,n], d `notElem` b]
          nTT = novoVértice t (head verticeAdicionar)
          nT = novaAresta nTT (m,c,n)
          nB = b ++ verticeAdicionar


-- ============================================================================================================================================= --
--                                             Funções Adaptadas de módulos de grafos não valorados
-- ============================================================================================================================================= --

quicksortArestas :: [(Int,Int,Int)] -> [(Int,Int,Int)]
quicksortArestas [] = []
quicksortArestas [x] = [x]
quicksortArestas ((x,chave,y):ls) =
    let menoresIguais = [(x,c,y) | (x,c,y) <- ls, c <= chave]
        maiores = [(x,c,y) | (x,c,y) <- ls, c > chave]
    in quicksortArestas menoresIguais ++ [(x,chave,y)] ++ quicksortArestas maiores

numCompConexas :: Grafo Int Int -> Int
numCompConexas g
    | éConexo g = 1
    | otherwise = 1 + numCompConexas nG
    where
        verticesFora = vértices g \\ largura g
        nG = novoGrafo verticesFora [(v,c,w) | (v,c,w) <- arestas g, v `elem` verticesFora && w `elem` verticesFora]

éConexo :: Grafo Int Int -> Bool
éConexo g = éConexoAux g [primeiro] [primeiro]
    where primeiro = head (vértices g)

-- a lista de abertos contém os vértices que foram visitados mas que seus vizinhos não foram
éConexoAux :: Grafo Int Int -> [Int] -> [Int] -> Bool
éConexoAux g visitados [] = length visitados == length (vértices g)
éConexoAux g visitados abertos = éConexoAux g listaVisitadosNova listaAbertosNova
    where vizAberto = vizinhos g (head abertos)       -- lista dos vértices adjascentes ao primeiro vértice da lista de abertos
          novosVisitados = [ a | a <- vizAberto, a `notElem` visitados] -- lista dos vértices que não foram visitados antes
          novosAbertos = [a | a <- vizAberto, a `notElem` visitados && a `notElem` abertos] -- lista dos novos vértices abertos
          listaVisitadosNova = visitados ++ novosVisitados
          listaAbertosNova = tail abertos ++ novosAbertos

largura :: Grafo Int Int -> [Int]
largura g = larguraAux g [primeiro] [primeiro] -- v marcado como visitado e colocado no final da fila
    where primeiro = head $ vértices g

larguraAux :: Grafo Int Int-> [Int] -> [Int] -> [Int]
larguraAux g [] visitados = visitados -- quando a fila for vazia, retornamos a lista de visitados
larguraAux g fila visitados = larguraAux g filaNova visitadosNovo
    where vizPrimeiro = vizinhos g (head fila) -- vizinhos do primeiro vértice da fila
          filaNova = tail fila ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- primeiro elemento da fila removido. 
          -- adicionams à fila os vértices que não foram visitados ainda
          visitadosNovo = visitados ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- vértices não visitados são marcados como visitados