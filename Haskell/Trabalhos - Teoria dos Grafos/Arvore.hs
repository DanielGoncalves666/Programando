module Arvore where

import BaseGrafo
import Grafo
import FuncoesAuxiliares

-- ============================================================================================================================================= --
--                                                                  Lista 6
-- ============================================================================================================================================= --

-- 2
-- Pelo teorema 1, propriedade 2
éÁrvore :: Grafo Int -> Bool
éÁrvore g = éConexo g && qtdA == qtdV - 1
    where qtdA = length $ arestas g
          qtdV = length $ vértices g

-- 3
-- verifica se o menor grau é 1, o maior grau é |V| - 1, e o penultimo grau é 1
éEstrela :: Grafo Int -> Bool
éEstrela g = if not $ éÁrvore g then error "Não é uma árvore."
                                else grauMin g == 1 && grauMax g == qtd - 1 && grau g penultimo == 1
    where qtd = length $ vértices g
          penultimo = last $ init $ seqGraus g

-- 5
folhas :: Grafo Int -> [Int]
folhas a = if not $ éÁrvore a then error "Não é uma árvore."
                              else [ f | f <- vértices a, grau a f < 2] -- Folhas são todos os vértices cujo grau é menor que 2

-- 6
internos :: Grafo Int -> [Int]
internos a = if not $ éÁrvore a then error "Não é uma árvore."
                                else[ f | f <- vértices a, grau a f > 1] -- Vértices internos são aqueles cujo grau é pelo menos 2

-- 7 
centro :: Grafo Int -> [Int]
centro a
    | not $ éÁrvore a =  error "Não é uma árvore."
    | length (vértices a) > 2 = centro nG
    | otherwise = vértices a
    where nG = centroAux a (folhas a)

-- remove todas as folhas
centroAux :: Grafo Int -> [Int] -> Grafo Int
centroAux a [] = a
centroAux a leaves = centroAux nG (tail leaves)
    where nG = removeVértice a (head leaves)

-- ============================================================================================================================================= --
--                                                                  Lista 7
-- ============================================================================================================================================= --

-- 1
prufer :: Grafo Int -> [Int]
prufer a
    | not $ éÁrvore a = error "Não é uma árvore"
    | length (vértices a ) > 2 = u ++ prufer nA
    | otherwise = []
    where leaves = quicksort $ folhas a -- lista das folhas em ordem crescente de rótulo
          v = head leaves
          u = vizinhos a v -- único vizinho de v (o pai dele)
          nA = removeVértice a v -- remove o vértice v da árvore (a folha) 

-- 2
decodPrufer :: [Int] -> Grafo Int
decodPrufer c = decodAux c leaves nA
    where qtdVert = length c + 2
          nA = novoGrafo [1..qtdVert] []
          leaves = quicksort $ [a | a <- [1..qtdVert], a `notElem` c]

decodAux :: [Int] -> [Int] -> Grafo Int -> Grafo Int
decodAux [] f a = novaAresta a (head f, last f)
decodAux c f a = decodAux (tail c) novoF nA
    where u = head c
          v = head f
          nA = novaAresta a (u,v)
          novoF = if u `elem` tail c then tail f
                                     else quicksort (u:tail f)

-- 3
éSeqVálida :: [Int] -> Bool
éSeqVálida s = soma == (2 * numVert - 2)
    where soma = sum s
          numVert = length s

-- 4
numÁrvRotuladas :: [Int] -> Int
numÁrvRotuladas s
    | not $ éSeqVálida s = 0
    | otherwise = numerador `div` denominador
    where numVert = length s
          numerador = fatorial (numVert - 2) 1
          denominador = product [fatorial (a - 1) 1 | a <- s]

-- 5
árvoresRotuladas :: [Int] -> [Grafo Int]
árvoresRotuladas s 
    | not $ éSeqVálida s = []
    | otherwise = [decodPrufer a | a <- permutacoes]
    where sB = seqBasica 1 [a - 1| a <- s]
          permutacoes = permutaSemDup sB
          
