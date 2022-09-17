module Teste10 where

import Grafo
import GrafosEspeciais

g1 = completo 6
g2 = ciclo 5
g3 = roda 6
g4 = bipartidoCompleto 3 4

-- ok
teste1_1 = intervaloÍndiceCromático g1 -- (5,6)
teste1_2 = intervaloÍndiceCromático g2 -- (2,3)
teste1_3 = intervaloÍndiceCromático g3 -- (5,6)

-- ok
teste2_1 = éRoda g1 -- false
teste2_2 = éRoda g3 -- true
teste2_3 = éRoda g4 -- false

-- ok
teste3_1 = índiceCromCiclo g2 -- 3
teste3_2 = índiceCromCiclo (ciclo 6) -- 2
teste3_3 = índiceCromCiclo (ciclo 7) -- 3

-- ok
teste4_1 = índiceCromRoda g3 -- 5
teste4_2 = índiceCromRoda (roda 5) -- 4
teste4_3 = índiceCromRoda g1 -- 0

-- ok
teste5_1 = índiceCromKn g1 -- 5
teste5_2 = índiceCromKn g2 -- 0
teste5_3 = índiceCromKn (completo 9) -- 9

-- ok
teste6_1 = coloreArestasCiclo g2 -- [((4,5),1),((3,4),2),((2,3),3),((1,2),1),((1,5),2)]
teste6_2 = coloreArestasCiclo g1 -- []
teste6_3 = coloreArestasCiclo (ciclo 4) -- [((3,4),1),((2,3),2),((1,2),1),((1,4),2)]

-- ok
teste7_1 = coloreArestasRoda g3 -- [((5,6),1),((4,6),2),((3,6),3),((2,6),4),((1,6),5),((4,5),3),((3,4),1),((2,3),2),((1,2),1),((1,5),2)]
teste7_2 = coloreArestasRoda g1 -- []
teste7_3 = coloreArestasRoda (roda 4) -- [((1,2),1),((1,3),2),((1,4),3),((3,4),1),((2,3),3),((2,4),2)]

teste8_1 = coloreArestasKn g1
teste8_2 = coloreArestasKn g2 -- []
teste8_3 = coloreArestasKn (completo 5)

-- ok
teste9_1 = coloreArestasBipartido g4 -- [((3,4),1),((2,4),2),((1,4),3),((3,5),2),((2,5),1),((1,5),4),((3,6),3),((2,6),4),((1,6),1),((3,7),4),((2,7),3),((1,7),2)]
teste9_2 = coloreArestasBipartido g1 -- []
teste9_3 = coloreArestasBipartido (bipartidoCompleto 2 2) -- [((2,3),1),((1,3),2),((2,4),2),((1,4),1)]

-- ok
teste10_1 = coloreArestasGuloso g1
teste10_2 = coloreArestasGuloso g2 -- [((4,5),1),((3,4),2),((2,3),1),((1,2),2),((1,5),3)]
teste10_3 = coloreArestasGuloso g3 -- [((5,6),1),((4,5),2),((4,6),3),((3,4),1),((3,6),2),((2,3),3),((2,6),4),((1,2),1),((1,5),3),((1,6),5)]

