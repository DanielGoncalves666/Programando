module Teste9 where

import Grafo
import GrafosEspeciais
import BaseGrafo

g1 = completo 6
g2 = ciclo 5
g3 = estrela 5
g4 = grade 2 4
g5 = caminho 10
g6 = novoGrafo [1..5] [(1,2),(2,3),(3,4),(1,4),(4,5)] -- grafo do exemplo 9 dos slides, com os vértices numerados na ordem das letras
g7 = novoGrafo [1..5] [(4,1),(1,5),(5,3),(4,3),(3,2)] -- grafo do exemplo 9 dos slides, com os vértices numerados na ordem de visita
-- b, e, d, a, c.

-- ok
teste1_1 = coberturaVértices g1 -- [1,2,3,4,5]
teste1_2 = coberturaVértices g3 -- [1] 
teste1_3 = coberturaVértices g4 -- 1,2,3,4,6,7]

-- ok
teste2_1 = subdivideAresta g2 (1,2) 5  
teste2_2 = subdivideAresta g5 (5,6) 2
teste2_3 = subdivideAresta g1 (1,6) 3

-- ok
teste3_1 = suavizaVértices g1 1 -- inalterado
teste3_2 = suavizaVértices g2 1
teste3_3 = suavizaVértices g5 2

-- ok
teste4_1 = suaviza g1 -- inalterado
teste4_2 = suaviza g2 -- sobra dois vértices
teste4_3 = suaviza g5 -- sobra 2 vértices

-- ok
teste5_1 = éBipartido g4 -- True
teste5_2 = éBipartido g5 -- True
teste5_3 = éBipartido g1 -- False

-- ok
teste6_1 = coloreVérticesIngênuo g6 -- [1,2,1,2,1]
teste6_2 = coloreVérticesIngênuo g1 -- [1,2,3,4,5,6]
teste6_3 = coloreVérticesIngênuo g5 -- [1,2,1,2,1,2,1,2,1,2]
teste6_4 = coloreVérticesIngênuo g7 -- [1,1,2,3,3]

-- ok
teste7_1 = coloreVértices g6 -- [1,2,1,2,1]
teste7_2 = coloreVértices g1 -- [1,2,3,4,5,6]
teste7_3 = coloreVértices g5 -- [1,2,1,2,1,2,1,2,1,2]
teste7_4 = coloreVértices g7 -- [1,1,2,3,3]

-- ok
teste8_1 = coloreMaiorPrimeiro g6 -- [2,1,2,1,2]
teste8_2 = coloreMaiorPrimeiro g1 -- [1,6,5,4,3,2]
teste8_3 = coloreMaiorPrimeiro g5 -- [2,1,2,1,2,1,2,1,2,1]
teste8_4 = coloreMaiorPrimeiro g7 -- [1,2,1,2,2]