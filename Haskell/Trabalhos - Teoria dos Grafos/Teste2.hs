module Teste2 where

-- Testes

import GrafosEspeciais
import BaseGrafo

-- grafo da pagina 14 do livo de exercicios
-- u = 1, v = 2, w = 3, x = 4, y = 5, z = 6, t = 7
teste1 :: Grafo Int
teste1 = novoGrafo [1..7] [(1,4),(1,2),(2,3),(3,4),(4,5),(5,6)] 
teste2 = completo 5
teste3 = estrela 6


vazio1 = vazio 10
caminho1 = caminho 6
grade1 = grade 3 4
dama1 = dama 5
cavalo1 = cavalo 5
bispo1 = bispo 5
torre1 = torre 5
rei1 = rei 5
cubo1 = cubo 5
peterson1 = peterson 
kneser1 = kneser 6 3
gArestas1 = grafoArestas teste1
gArestas2 = grafoArestas teste2
gArestas3 = grafoArestas teste3

completo1 = completo 5
ciclo1 = ciclo 5
amigo1 = amigo 5
roda1 = roda 5
biparCompleto1 = bipartidoCompleto 4 5 
estrela1 = estrela 5
gA1 = grafoAleatório 6 10
biparAlea = bipartido 3 5 10 




-- > vértices $ grafoArestas teste1
-- [(1,2),(1,4),(2,3),(3,4),(4,5),(5,6)]

-- > vértices $ grafoArestas teste2
-- [(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5)]

-- > vértices $ grafoArestas teste3
-- [(1,2),(1,3),(1,4),(1,5),(1,6),(1,7)]

-- > arestas $ grafoArestas teste1
-- [((1,2),(1,4)),((2,3),(1,2)),((3,4),(2,3)),((3,4),(1,4)),((4,5),(3,4)),((4,5),(1,4)),((5,6),(4,5))]

-- > arestas $ grafoArestas teste2
-- [((1,3),(1,2)),((1,4),(1,3)),((1,4),(1,2)),((1,5),(1,4)),((1,5),(1,3)),((1,5),(1,2)),((2,3),(1,3)),((2,3),(1,2)),
--  ((2,4),(2,3)),((2,4),(1,4)),((2,4),(1,2)),((2,5),(2,4)),((2,5),(2,3)),((2,5),(1,5)),((2,5),(1,2)),((3,4),(2,4)),
--  ((3,4),(2,3)),((3,4),(1,4)),((3,4),(1,3)),((3,5),(3,4)),((3,5),(2,5)),((3,5),(2,3)),((3,5),(1,5)),((3,5),(1,3)),
--  ((4,5),(3,5)),((4,5),(3,4)),((4,5),(2,5)),((4,5),(2,4)),((4,5),(1,5)),((4,5),(1,4))]

-- > arestas $ grafoArestas teste3
-- [((1,3),(1,2)),((1,4),(1,3)),((1,4),(1,2)),((1,5),(1,4)),((1,5),(1,3)),((1,5),(1,2)),((1,6),(1,5)),((1,6),(1,4)),
--  ((1,6),(1,3)),((1,6),(1,2)),((1,7),(1,6)),((1,7),(1,5)),((1,7),(1,4)),((1,7),(1,3)),((1,7),(1,2))]



-- precisa usar o operador <- antes de poder aplicar em outras funções
-- g1 <- grafoAleatório 3 2
