module Teste7 where

import BaseGrafo
import Grafo
import Arvore

-- árvore do slide 45 da apresentação de Árvores
a1 = insereArestas (novoGrafo [1..8] []) [(1,2),(1,3),(1,4),(4,5),(4,7),(6,7),(7,8)]
a2 = insereArestas (novoGrafo [1..5] []) [(1,2),(1,3),(1,4),(1,5)]
a3 = insereArestas (novoGrafo [1..7] []) [(1,2),(1,3),(2,4),(2,5),(3,6),(3,7)]

-- ok
teste1_1 = prufer a1 -- [1,1,4,4,7,7]
teste1_2 = prufer a2 -- [1,1,1]
teste1_3 = prufer a3 -- [2,2,1,3,3]

-- ok
teste2_1 = decodPrufer [1,1,4,4,7,7] -- a1
teste2_2 = decodPrufer [1,1,1]       -- a2
teste2_3 = decodPrufer [2,2,1,3,3]   -- a3

-- ok
teste3_1 = éSeqVálida  [1, 1, 1, 1, 2, 3, 3] -- True
teste3_2 = éSeqVálida  [1, 1, 1, 1, 2, 4] -- True
teste3_3 = éSeqVálida  [1,2,2,2,3] -- False

-- ok
teste4_1 = numÁrvRotuladas [1, 1, 1, 1, 2, 3, 3] -- 30
teste4_2 = numÁrvRotuladas [1, 1, 1, 1, 2, 4] -- 4
teste4_3 = numÁrvRotuladas [1,2,2,2,3]  -- 0

-- ok
teste5_1 = árvoresRotuladas [1, 1, 1, 1, 2, 4] -- 5666 6566 6656 6665
