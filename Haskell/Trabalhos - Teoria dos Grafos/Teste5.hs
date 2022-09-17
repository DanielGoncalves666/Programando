module Teste5 where

import BaseGrafo
import GrafosEspeciais
import Busca 

g1 = completo 5
g2 = ciclo 5
g3 = estrela 5
g4 = grade 2 4
g5 = amigo 3

-- ok
teste1_1 = genérica g1  -- [1..5]
teste1_2 = genérica g2  -- [1,2,5,3,4]
teste1_3 = genérica g5  -- [1..7]

-- ok
teste2_1 = largura g1 -- [1..5]
teste2_2 = largura g2 -- [1,2,5,3,4]
teste2_3 = largura g4 -- [1,2,5,3,6,4,7,8]
teste2_4 = largura g5 -- [1..7]

-- ok
teste3_1 = profundidade g1 -- [1..5]
teste3_2 = profundidade g2 -- [1..5]
teste3_3 = profundidade g4 -- [1,2,3,4,8,7,6,5]
teste3_4 = profundidade g5 -- [1..7]

teste4_1 = menorCaminho g2 1 3 -- [1,2,3]
teste4_2 = menorCaminho g4 1 8 -- [1,2,3,4,8]
teste4_3 = menorCaminho g1 1 5 -- [1,5]