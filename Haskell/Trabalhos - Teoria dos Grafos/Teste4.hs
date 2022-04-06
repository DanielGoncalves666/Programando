module Teste4 where

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
g9 = regular 6 4

-- ok
teste1_1 = grafoComplemento g1 -- grafo k5
teste1_2 = grafoComplemento g3 -- grafo vazio com 6 vértices
teste1_3 = grafoComplemento g8 -- grafo g8

-- ok
teste2_1 = união g1 g3 -- grafo g3
teste2_2 = união g7 (novoGrafo [2..6] [(2,3),(3,4),(4,5),(5,6),(2,6)]) -- grafo da Roda (porém o vértice universal aqui é o 1, invés do 6)
teste2_3 = união g8 g1 -- grafo vazio com 5 vértices

-- ok
teste3_1 = interseção g1 g8 -- g8
teste3_2 = interseção g3 g1 -- grafo vazio com 5 vértices
teste3_3 = interseção g2 g3 -- ciclo com 6 vértices (o grafo universal é eliminado)

-- ok
teste4_1 = soma (novoGrafo [1..4] [(1,2),(1,3),(1,4),(3,4)]) (novoGrafo [1,2,4,5] [(1,2),(2,4),(1,4)]) -- k5, exemplo retirado do material
teste4_2 = soma g1 g8 -- grafo estrela com 5 vértices
teste4_3 = soma g3 g2 -- k7

-- ok
teste5_1 = éPasseio g2 [1,2,3,4,5,6,7] -- True
teste5_2 = éPasseio g7 [1,2,1,3,4] -- False
teste5_3 = éPasseio g3 [1,2,3,4,5,6,7] -- False

-- ok
teste6_1 = éPasseioAberto g3 [1,2,3,4,5,6,1] -- False
teste6_2 = éPasseioAberto g7 [1,2,1,3,1,4] -- True
teste6_3 = éPasseioAberto g4 [1,2,3,4,5] -- False

-- ok
teste7_1 = éPasseioFechado g3 [1,2,3,4,5,6,1] -- True
teste7_2 = éPasseioFechado g7 [1,2,1,3,1,4] -- False
teste7_3 = éPasseioFechado g4 [1,2,3,4,5] -- False

-- ok
teste8_1 = éTrilha g3 [1,2,3,4,5,6,1,3,5,2] -- True
teste8_2 = éTrilha g7 [2,1,3,1,4,1] -- False
teste8_3 = éTrilha g4 [1,2,3,4,3] -- False

-- ok
teste9_1 = éCaminho g3 [1,2,3,4,5,6] -- True
teste9_2 = éCaminho g7 [1,2,1] -- False
teste9_3 = éCaminho g4 [1,2,3,4,8,7,6,5,9,10,11,12] -- True 

-- ok
teste10_1 = éCiclo g3 [1,2,3,4,5,6,1] -- True
teste10_2 = éCiclo g7 [1,2,1] -- True
teste10_3 = éCiclo g4 [1,2,3,4,8,7,3,2,1] -- False

-- ok
teste11_1 = éGrafoCíclico g3  -- False
teste11_2 = éGrafoCíclico g6  -- False
teste11_3 = éGrafoCíclico (ciclo 10) -- True

-- ok
teste12_1 = éCn g3 6 -- False
teste12_2 = éCn (ciclo 10) 10 -- True
teste12_3 = éCn (ciclo 10) 11 -- False

-- ok
teste13_1 = éGrafoCaminho g1 -- False
teste13_2 = éGrafoCaminho (grade 1 10) -- True
teste13_3 = éGrafoCaminho (novoVértice (grade 1 10) 11) -- False

-- ok
teste14_1 = éPn (grade 1 10) 10 -- true
teste14_2 = éPn (grade 1 10) 8 -- False
teste14_3 = éPn g1 5 -- False

-- ok
teste15_1 = éGrafoBipartido g3 [1..3] [4..6] -- False
teste15_2 = éGrafoBipartido (bipartidoCompleto 4 5) [1..4] [5..10]-- True
--teste15_3 = Testar com a função de bipartido aleatória -- True

-- ok
teste16_1 = éTrilhaEuleriana g7 [1,2,1,3,1,4,1,5,1,6] -- False
teste16_2 = éTrilhaEuleriana g1 [1,2,3,4] -- False
teste16_3 = éTrilhaEuleriana (ciclo 5) [1,2,3,4,5,1] -- True

-- ok
teste17_1 = éGrafoEuleriano g3 -- False
teste17_2 = éGrafoEuleriano g9 -- True
teste17_3 = éGrafoEuleriano g2 -- False

-- ok
teste18_1 = éSemiEuleriano g3 -- False
teste18_2 = éSemiEuleriano g9 -- False
teste18_3 = éSemiEuleriano (grade 1 5) -- True

-- ok
teste19_1 = éHamiltonianoOre g3 -- True
teste19_2 = éHamiltonianoOre g2 -- False, apesar de g2 ter um ciclo hamiltoniano pois para a maioria dos pares de vértices a soma dos graus é menor que 7
teste19_3 = éHamiltonianoOre g4 -- False
teste19_4 = éHamiltonianoOre g9 -- True

-- ok
teste20_1 = éHamiltonianoDirac g3 -- True
teste20_2 = éHamiltonianoDirac g2 -- False
teste20_3 = éHamiltonianoDirac g4 -- False
teste20_4 = éHamiltonianoDirac g9 -- True

