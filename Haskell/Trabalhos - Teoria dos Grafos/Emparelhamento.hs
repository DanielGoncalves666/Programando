module Emparelhamento where

import BaseGrafo
import FuncoesAuxiliares
import Grafo

-- ============================================================================================================================================= --
--                                                                  Lista 8
-- ============================================================================================================================================= --

-- 3
éEmparelhamento :: Grafo Int -> [(Int,Int)] -> Bool
éEmparelhamento g m
    | not existemTodas = error "Alguma aresta não existe no grafo."
    | otherwise = not repetidos
    where existemTodas = length [ a | a <- m, a `elem` arestas g] == length m -- a mesma quantidade em m precisa estar presente no grafo
          ocorrencias = [ a | (a,b) <- m] ++ [b | (a,b) <- m] -- lista todos os vértices que ocorrem nas arestas
          repetidos = existeRepetidos $ quicksort ocorrencias -- se um vértice ocorrer mais de uma vez em m, então existem duas arestas adjascentes
                                                              -- e por consequência, não é um emparelhamento
          
-- 4
éMaximal :: Grafo Int -> [(Int,Int)] -> Bool 
éMaximal g m 
    | not $ éEmparelhamento g m = error "Não é um emparelhamento"
    | otherwise = not existeInsaturadosVizinhos
    where vetSaturados = [a | (a,b) <- m] ++ [b | (a,b) <- m]
          vetInsaturados = [ a | a <- vértices g, a `notElem` vetSaturados]
          existeInsaturadosVizinhos = or [ or [ b `elem` vetInsaturados  | b <- vizinhos g a] | a <- vetInsaturados]


-- 5
éPerfeito :: Grafo Int -> [(Int,Int)] -> Bool
éPerfeito g m 
    | not $ éEmparelhamento g m = error "Não é um emparelhamento"
    | otherwise = length m * 2 == numVert -- a quantidade de arestas no emparelhamento tem que ser a metade do total de vértices
    where numVert = length $ vértices g

-- 6
éCaminhoAlternante :: Grafo Int -> [(Int,Int)] -> [Int] -> Bool 
éCaminhoAlternante g [] _ = False 
éCaminhoAlternante g _ [] = False
éCaminhoAlternante g m c
    | not $ éEmparelhamento g m = error "Não é um emparelhamento"
    | comecoCaminho = and [ (x,y) `elem` m || (y,x) `elem` m | (x,y) <- posicoesPares] && and [ (x,y) `notElem` m && (y,x) `notElem` m | (x,y) <- posicoesImpares] -- posicoes pares tem que fazer parte do emparelhamento
    | otherwise = and [ (x,y) `notElem` m && (y,x) `notElem` m | (x,y) <- posicoesPares] && and [ (x,y) `elem` m || (y,x) `elem` m | (x,y) <- posicoesImpares]
    where cc@((a,b):cs) = caminhoEmArestas c
          comecoCaminho = (a,b) `elem` m || (b,a) `elem` m -- se uma das duas for verdade, então o começo do caminho é uma aresta do emparelhamento
          tamanho = length cc
          posicoesPares = [ cc !! d | d <- [0,2..(tamanho-1)]]
          posicoesImpares = [ cc !! d | d <- [1,3..(tamanho-1)]]

caminhoEmArestas :: [Int] -> [(Int,Int)]
caminhoEmArestas [] = []
caminhoEmArestas [c1] = []
caminhoEmArestas (c1:c2:cs) = (c1,c2):caminhoEmArestas (c2:cs)

-- 7
éCaminhoAumentador :: Grafo Int -> [(Int,Int)] -> [Int] -> Bool
éCaminhoAumentador g m c 
    | not $ éCaminhoAlternante g m c = False
    | otherwise = and [ a `notElem` m | a <- inicioFim]
    where cc = caminhoEmArestas c 
          (x,y) = head cc
          (u,v) = last cc
          inicioFim = [(x,y),(y,x),(u,v),(v,u)]                 -- contém as arestas de inicio e fim do caminho, nas duas ordens possíveis

-- 8
máximo :: Grafo Int -> [(Int,Int)]
máximo g = error "Implementar"


-- 9
éDesconectador :: Grafo Int -> Int -> Int -> [(Int,Int)] -> Bool 
éDesconectador g v w as = not $ existeCaminho nG [v] [v] w
    where nG = removeArestas g as

-- 10
éSeparador :: Grafo Int -> Int -> Int -> [Int] -> Bool
éSeparador g v w vs = not $ existeCaminho nG [v] [v] w
    where nG = removeVértices g vs

-- as dus listas passadas possuem um elemento, sendo ele o primeiro vértice
existeCaminho :: Grafo Int -> [Int] -> [Int] -> Int -> Bool
existeCaminho g [] _ fim = False
existeCaminho g fila visitados fim
    | fim `elem` esteNivel = True
    | null esteNivel = existeCaminho g filaNova visitadosNovo fim
    | otherwise = existeCaminho g filaNova visitadosNovo fim
    where vizPrimeiro = vizinhos g (head fila)
          esteNivel = [a | a <- vizPrimeiro, a `notElem` visitados]
          filaNova = tail fila ++ esteNivel
          visitadosNovo = visitados ++ esteNivel