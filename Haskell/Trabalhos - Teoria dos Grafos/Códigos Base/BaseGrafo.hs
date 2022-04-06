 module BaseGrafo
   (Grafo,
    novoGrafo,      -- Int -> [(Int, Int)] -> Grafo
    vértices,       -- Grafo -> [Int]
    novoVértice,    -- Grafo -> Int -> Grafo
    removeVértice,  -- Grafo -> Int -> Grafo
    adjacente,      -- Grafo -> Int -> Int -> Bool
    grau,           -- Grafo -> Int -> Int
    vizinhos,       -- Grafo -> Int -> [Int]
    pertence,       -- Grafo -> Int -> Bool
    lista_adj,
    arestas,        -- Grafo -> [(Int, Int)]
    converte_matriz_adj,     -- Grafo -> Matriz Int
    novaAresta,     -- Grafo -> (Int, Int) -> Grafo
    removeAresta    -- Grafo -> (Int, Int) -> Grafo
   ) where


-- import DebuLAdj.Trace
import Data.Array
import Data.List
import Data.Map (Map)        -- Isto apenas importa o nome do tipo
import qualified Data.Map as Map -- Importa tudo, mas com os nomes
                                 -- prefixados com `Map`

import qualified ListaAdj  as Ladj
import qualified MatrizAdj as Madj

data Grafo r = Gr Int (Map r Int) (Map Int r) Ladj.Grafo
   deriving Show

-- Cria um grafo com os vértices `vs` e arestas `as` usando uma
-- lista de adjacência

-- O primeiro argumento é uma lista explícita de todos os vértices.
-- Note que agora os vértices podem ter qualquer tipo de rótulo e 
-- não apenas números inteiros. Internamente, os vértices são
-- numerados, mas externamente isso não é visível.
-- O segundo argumento são as arestas.
novoGrafo :: Ord r => [r] ->  [(r, r)] -> Grafo r
novoGrafo vs ars = Gr n rótulos idents grafo
   where
     n = length vs
     rótulos = Map.fromList [ a | a <- zip vs [1..n] ]
     idents = Map.fromList [ a | a <- zip [1..n] vs ]
     ars' = numera_arestas rótulos ars
     grafo = Ladj.novoGrafo n ars'

--- Operações sobre vértices

-- Devolve a lista de vértices
vértices :: Grafo r -> [r]
vértices (Gr _ rs _ _) = Map.keys rs


-- Adiciona um vértice ao grafo
novoVértice :: Ord r => Grafo r -> r ->  Grafo r
novoVértice (Gr n rs ids g) v
   | Map.member v rs =  Gr n rs ids g
   | otherwise = Gr n' (Map.insert v n' rs) (Map.insert n' v ids) (Ladj.novoVértice g n')
   where
     n' = n + 1

-- Remove um vértice do grafo e todas as arestas nele incidentes
removeVértice :: Ord r => Grafo r -> r ->  Grafo r
removeVértice (Gr n rs ids g) v = Gr n rs' ids' g'
   where
     rs'  = Map.delete v rs
     v'   = Map.findWithDefault 0 v rs
     ids' = Map.delete v' ids
     g'   = Ladj.removeVértice g v'

-- Testa se o vértice u é adjacente ao vértice v
adjacente :: Ord r => Grafo r -> r -> r -> Bool
adjacente (Gr _ rs _ g) u v = Ladj.adjacente g u' v'
   where
     u' = Map.findWithDefault 0 u rs
     v' = Map.findWithDefault 0 v rs

-- Grau de um vértice
grau :: Ord r => Grafo r -> r -> Int
grau (Gr _ rs _ g) v = Ladj.grau g (Map.findWithDefault 0 v rs)

-- Devolve a lista de vértices vizinhos ao vértice dado
vizinhos :: Ord r => Grafo r -> r -> [r]
vizinhos (Gr _ rs ids g) v = [ Map.findWithDefault v u ids  | u <- vs ]
   where
     vs = Ladj.vizinhos g (Map.findWithDefault 0 v rs)

-- Verifica se um dado vértice está no grafo
pertence :: Ord r => Grafo r -> r -> Bool
pertence (Gr _ rs _ _) v = Map.member v rs

--- Operações sobre arestas

-- lista_adj: recebe um grafo no novo formato e o transforma
-- em um grafo representado por uma lista de adjacências
lista_adj :: Ord r => Grafo r -> [(r, [r])]
lista_adj (Gr _ _ ids g) = [ (rótulo idents v, map (rótulo idents) ars) | (v,ars) <- adjs]
    where
      adjs = Ladj.lista_adj g
      idents = Map.assocs ids


-- converte_matriz_adj: recebe um grafono novo formato e o 
-- transforma em um grafo representado por uma matriz de adjacências                            
converte_matriz_adj :: Grafo r -> ( [(Int,r)], Madj.Grafo)
converte_matriz_adj (Gr n _ ids g) = (Map.assocs ids,Madj.novoGrafo n ars)
  where
    ars = Ladj.arestas g

-- Devolve a lista de arestas
arestas ::  Ord r => Grafo r -> [(r,r)]
arestas (Gr _ _ ids g) = rotula_arestas ids (Ladj.arestas g)

-- Adiciona uma nova aresta ao grafo. As pontas das arestas já devem existir no
-- grafo
novaAresta ::  Ord r => Grafo r -> (r,r) -> Grafo r
novaAresta (Gr n rs ids g) (u,v) = if (u' == 0) || (v' == 0)
                                   then error "vértice não existente em aresta"
                                   else let g' = Ladj.novaAresta g (u',v')
                                        in (Gr n rs ids g')
  where
     u' = Map.findWithDefault 0 u rs
     v' = Map.findWithDefault 0 v rs


-- Remove uma aresta do grafo
removeAresta ::  Ord r => Grafo r -> (r,r) -> Grafo r
removeAresta (Gr n rs ids g) (u,v) = if (u' == 0) || (v' == 0)
                                     then error "vértice não existente em aresta"
                                     else let g' = Ladj.removeAresta g (u',v')
                                          in (Gr n rs ids g')
  where
     u' = Map.findWithDefault 0 u rs
     v' = Map.findWithDefault 0 v rs




-- Funções auxiliares

numera_arestas :: (Ord r) => Map r Int -> [(r, r)] -> [(Int, Int)]
numera_arestas rs as = converte as []
  where
    converte [] ac = ac
    converte ((u,v) : ars) ac =
        let u' = Map.findWithDefault 0 u rs
            v' = Map.findWithDefault 0 v rs
        in if (u' == 0) || (v' == 0)
           then error "vértice não existente em aresta"
           else converte ars ((u',v') : ac)

rótulo :: Eq a => [(a, r)] ->  a -> r
rótulo idents v = case lookup v idents of
                    Just u -> u
                    Nothing -> error "Rótulo não encontrado"


rotula_arestas :: (Ord r) => Map Int r -> [(Int, Int)] -> [(r, r)]
rotula_arestas ids ars = map rotula ars
  where
    idents = Map.assocs ids
    rotula (u,v) = (rótulo idents u, rótulo idents v)
