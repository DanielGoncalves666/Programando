module Teste8 where

import Emparelhamento
import ArvoreGeradora
import GrafosEspeciais
import BaseGrafoValorado

g1 = completo 6
g2 = ciclo 5
g3 = estrela 5
g4 = grade 2 4
g5 = caminho 10
g6 = BaseGrafoValorado.novoGrafo [1..9] [(1,10,2),(1,30,3),(3,20,5),(5,25,6),(6,4,7),(4,30,6),(3,11,4),(2,5,9),(4,10,9),(4,5,8)]
g7 = BaseGrafoValorado.novoGrafo [1..10] [(1,10,5),(4,5,5),(5,12,8),(1,8,2),(1,7,6),(5,1,6),(8,6,9),(9,2,10),(7,5,10),(6,5,9),(6,1,7),(2,8,6),(2,1,3),(3,8,7),(3,4,6)]
-- Exemplo dado para o algoritmo de kruskal

teste1_1 = kruskal g6 -- [(1,10,2),(3,20,5),(5,25,6),(6,4,7),(3,11,4),(2,5,9),(4,10,9),(4,5,8)]
teste1_2 = kruskal g7 -- [(9,2,10),(8,6,9),(6,1,7),(6,5,9),(5,1,6),(4,5,5),(3,4,6),(2,1,3),(1,7,6)]

teste2_1 = prim g6 -- [(1,10,2),(3,20,5),(5,25,6),(6,4,7),(3,11,4),(2,5,9),(4,10,9),(4,5,8)]
teste2_2 = prim g7 -- [(9,2,10),(8,6,9),(6,1,7),(6,5,9),(5,1,6),(4,5,5),(3,4,6),(2,1,3),(1,7,6)]

-- ok
teste3_1 = éEmparelhamento g1 [(1,2),(3,4),(5,6)] -- True
teste3_2 = éEmparelhamento g2 [(1,2),(3,4)] -- True
teste3_3 = éEmparelhamento g3 [(1,2),(3,4)] -- Error
teste3_4 = éEmparelhamento g3 [(1,2),(1,3)] -- False

-- ok
teste4_1 = éMaximal g1 [(1,2),(3,4)] -- False
teste4_2 = éMaximal g2 [(1,2),(3,4)] -- True
teste4_3 = éMaximal g4 [(1,2),(3,4),(5,6),(7,8)] -- True

--- ok
teste5_1 = éPerfeito g1 [(1,2),(3,4),(5,6)] -- True
teste5_2 = éPerfeito g2 [(1,2),(3,4)] -- False
teste5_3 = éPerfeito g3 [(1,2),(1,3)] -- Error

-- ok
teste6_1 = éCaminhoAlternante g5 [(1,2),(3,4),(5,6)] [1,2,3,4,5,6] -- True
teste6_2 = éCaminhoAlternante g2 [(2,3),(4,5)] [1..5] -- True
teste6_3 = éCaminhoAlternante g1 [(1,3),(2,4),(5,6)] [1,2,5,6] -- False

-- ok
teste7_1 = éCaminhoAumentador g5 [(2,3),(4,5),(6,7)] [1..7] -- False
teste7_2 = éCaminhoAumentador g5 [(2,3),(4,5),(6,7)] [1..8] -- True
teste7_3 = éCaminhoAumentador g1 [(1,2),(3,4)] [6,1,2,3,4,5] -- True
teste7_4 = éCaminhoAumentador g3 [(1,2)] [3,1,2] -- False

-- ok
teste9_1 = éDesconectador g1 1 6 [(1,2),(1,3),(1,4),(1,6)] -- False
teste9_2 = éDesconectador g1 1 6 [(1,2),(1,3),(1,4),(1,5),(1,6)] -- True
teste9_3 = éDesconectador g5 1 10 [(3,4)] -- True
teste9_4 = éDesconectador g2 2 4 [(2,3)] -- False

teste10_1 = éSeparador g1 1 6 [2,3,4,5] -- False
teste10_2 = éSeparador g5 1 10 [3,4,5] -- True
teste10_3 = éSeparador g2 2 4 [1,3] -- True