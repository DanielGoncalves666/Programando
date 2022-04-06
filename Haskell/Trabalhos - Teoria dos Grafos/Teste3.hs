module Teste3 where

import Grafo
import GrafosEspeciais
import BaseGrafo

g1 = vazio 5
g2 = roda 7
g3 = completo 6
g4 = grade 3 4
g5 = peterson 
g6 = novoVértice (ciclo 4) 5
g7 = estrela 5
g8 = vazio 1

-- ok
teste1_1 = éVértIsolado g1 1 -- True
teste1_2 = éVértIsolado g3 3 -- False
teste1_3 = éVértIsolado g6 5 -- True

-- ok
teste2_1 = éVértTerminal g7 2 -- True
teste2_2 = éVértTerminal g7 1 -- False
teste2_3 = éVértTerminal g1 1 -- False 
teste2_4 = éVértTerminal g6 5 -- False

-- ok
teste3_1 = éVértPar g2 7 -- True
teste3_2 = éVértPar g2 2 -- False
teste3_3 = éVértPar g1 1 -- True
teste3_4 = éVértPar g3 3 -- False

-- ok
teste4_1 = éVértImpar g1 1 -- False
teste4_2 = éVértImpar g2 2 -- True
teste4_3 = éVértImpar g1 1 -- False
teste4_4 = éVértImpar g3 3 -- True

-- ok
teste5_1 = sãoArestasAdjs g1 (1,2) (2,3) -- False
teste5_2 = sãoArestasAdjs g2 (1,2) (2,3) -- True
teste5_3 = sãoArestasAdjs g7 (1,2) (1,3) -- True

-- ok
teste6_1 = éTrivial g8 -- True
teste6_2 = éTrivial g1 -- False
teste6_3 = éTrivial g7 -- False

-- ok
teste7_1 = seqGraus g1 -- [0,0,0,0,0]
teste7_2 = seqGraus g2 -- [3,3,3,3,3,3,6]
teste7_3 = seqGraus g3 -- [5,5,5,5,5,5]

-- ok
teste8_1 = grauMax g1 -- 0
teste8_2 = grauMax g7 -- 5
teste8_3 = grauMax g4 -- 4

-- ok
teste9_1 = grauMin g1 -- 0
teste9_2 = grauMin g7 -- 1
teste9_3 = grauMin g4 -- 2

-- ok
teste10_1 = éRegular g3 -- True
teste10_2 = éRegular g1 -- True
teste10_3 = éRegular g4 -- False

-- ok
teste11_1 = ékRegular g3 5 -- True
teste11_2 = ékRegular g1 0 -- True
teste11_3 = ékRegular g1 1 -- False

-- ok
teste12_1 = éVazio g1 -- True
teste12_2 = éVazio g3 -- False
teste12_3 = éVazio g7 -- False

-- ok
teste13_1 = éNulo g1 -- False
teste13_2 = éNulo (novoGrafo [] []) -- True
teste13_3 = éNulo g3 -- False

-- ok
teste14_1 = éKn g3 6 -- True
teste14_2 = éKn g2 7 -- False 
teste14_3 = éKn g1 5 -- False

-- ok
teste15_1 = éCompleto g3 -- True 
teste15_2 = éCompleto g2 -- False
teste15_3 = éCompleto g1 -- False 

-- ok
teste16_1 = éSubgrafo g8 g1 -- True
teste16_2 = éSubgrafo g1 g3 -- True
teste16_3 = éSubgrafo g4 g3 -- False

-- ok
teste17_1 = éSubgrafoPróprio g1 g1 -- False
teste17_2 = éSubgrafoPróprio g8 g1 -- True
teste17_3 = éSubgrafoPróprio g4 g3 -- False

-- ok
teste18_1 = éSubgrafoInduzidoVértices g8 g1 [1]    -- True
teste18_2 = éSubgrafoInduzidoVértices g8 g1 [1,2]  -- False
teste18_3 = éSubgrafoInduzidoVértices g2 g3 [1,2,3] -- False

-- ok
teste19_1 = éSubgrafoInduzidoArestas (novoGrafo [1..3] [(1,2),(2,3)]) g4 [(1,2),(2,3)] -- True
teste19_2 = éSubgrafoInduzidoArestas (novoGrafo [1..4] [(1,2),(2,3)]) g4 [(1,2),(2,3)] -- False
teste19_3 = éSubgrafoInduzidoArestas g1 g2 [(1,2)] -- False

teste20_1 = éClique g8 g1 -- True
teste20_2 = éClique g1 g3 -- False
teste20_3 = éClique g7 g3 -- False

teste21_1 = éCjIndependenteVértices g8 g1 -- True
teste21_2 = éCjIndependenteVértices g1 g3 -- True
teste21_3 = éCjIndependenteVértices g2 g3 -- False

-- ok
teste22_1 = insereVértices g1 [6..10] -- [1..10]
teste22_2 = insereVértices g2 [7..10] -- [1..10]
teste22_3 = insereVértices g3 [7] -- [1..7]

-- ok
teste23_1 = removeVértices g1 [2,3,5] -- [1,4]
teste23_2 = removeVértices g2 [7] -- ciclo 1 .. 6
teste23_3 = removeVértices g3 [5,6] -- [1..4], todos com grau 3

-- ok
teste24_1 = insereArestas g1 [(1,2),(2,3)] -- lista das arestas conterá apenas essas duas
teste24_2 = insereArestas g2 [(1,8)] -- retornará um erro
teste24_3 = insereArestas g3 [(1,2),(3,5),(5,4)] -- a lista de arestas de g3 permanece inalterada

-- ok
teste25_1 = removeArestas g1 [(1,2),(2,3)] -- arestas que não existem são ignoradas
teste25_2 = removeArestas g2 [(1,7),(2,7),(3,7),(4,7),(5,7),(6,7)] -- lista de arestas conterá as arestas de um ciclo
teste25_3 = removeArestas g3 [(1,2),(1,3),(1,4),(1,5),(1,6)] -- vértice um será um vértice isolado

-- ok
teste26_1 = fundeVértices g1 1 2    -- os vértices 1 e 2 se tornam o vértice 1
teste26_2 = fundeVértices g2 2 3    -- a roda passa a ter um aro a menos, mas o grau de 7 permanece igual a 5
teste26_3 = fundeVértices g3 1 2    -- o novo vértice 1 terá grau 10

-- ok
teste27_1 = contraiVértices g1 1 2   -- os vértices 1 e 2 se tornam o vértice 1
teste27_2 = contraiVértices g2 2 3   -- a roda passa a ter um aro a menos, mas o grau de 7 vira 5
teste27_3 = contraiVértices g3 1 2   -- o novo vértice 1 terá grau 4

-- ok
teste28_1 = contraiAresta g1 (1,2)   -- como a aresta não existe, retornará um erro
teste28_2 = contraiAresta g3 (1,2)   
teste28_3 = contraiAresta g7 (1,2)
