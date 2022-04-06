import BaseGrafo

-- O primeiro argumento é uma lista explícita de todos os vértices.
-- Note que agora os vértices podem ter qualquer tipo de rótulo e 
-- não apenas números inteiros. Internamente, os vértices são
-- numerados, mas externamente isso não é visível.
-- O segundo argumento são as arestas.

-- O grafo abaixo é aqule do exemplo de construção da árvore de 
-- profundidade
g1 = novoGrafo ['a' .. 'g'] [ ('a', 'b'), ('a','c'), ('a','d'),
                              ('b','d'),
                              ('c','d'), ('c','e'),
                              ('e','f'), ('e','g'),
                              ('f','g')]
                              
                              
-- Todas as demais funções do módulo funcionam normalmente com 
-- o grafo criado.
-- Acrescentei duas novas funções:

-- lista_adj: que recebe um grafo no novo formato e o transforma
-- em um grafo representado por uma lista de adjacências

-- converte_matriz_adj: que recebe um grafono novo formato e o 
-- transforma em um grafo representado por uma matriz de adjacências

-- Uso:
--    ghci TestaGrafo.hs           
