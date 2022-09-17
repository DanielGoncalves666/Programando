module BaseGrafoValorado
   (Grafo,
    nulo,
    vazio,
    novoGrafo,
    vértices,
    novoVértice,
    removeVértice,
    adjacente,
    grau,
    vizinhos,
    pertence,
    lista_adj,
    arestas,
    pertenceAresta,
    novaAresta,
    removeAresta
   ) where


import Data.List
import Data.Map (Map)        -- Isto apenas importa o nome do tipo
import qualified Data.Map as Map -- Importa tudo, mas com os nomes
                                 -- prefixados com `Map`

data Grafo vért peso = Grafo (Map vért [ (vért,peso) ])
   deriving Show

type Aresta v p = (v, p, v)


-- cria um grafo nulo
nulo :: (Ord v, Show v, Num p) => Grafo v p
nulo = Grafo (Map.empty)


-- cria um grafo vazio com os vértices dados
vazio :: (Ord v, Show v, Num p) => [v] -> Grafo v p
vazio vs = Grafo (Map.fromList [ (v,[]) | v <- nub vs ])


-- Cria um grafo com os vértices `vs` e arestas `as` usando uma
-- lista de adjacência

-- O primeiro argumento é uma lista explícita de todos os vértices.
-- O segundo argumento é uma lista de arestas, cada uma da forma
-- (u,p,v), com u e v sendo vértices e p sendo um número indicativo
-- do peso da aresta.
novoGrafo :: (Ord v, Show v, Show p, Num p) => [v] -> [Aresta v p] -> Grafo v p
novoGrafo vs ars = Grafo m where
    m0 = Map.fromList [ (v,[]) | v <- nub vs ]
    m = foldl insereAresta m0 ars


--- Operações sobre vértices

-- Devolve a lista de vértices
vértices :: (Ord v, Num p) => Grafo v p -> [v]
vértices (Grafo m) = Map.keys m


-- Adiciona um vértice v ao grafo apenas se v não está no grafo.
novoVértice :: (Ord v, Num p) => Grafo v p -> v -> Grafo v p
novoVértice (Grafo m) v
   | Map.member v m =  Grafo m
   | otherwise = Grafo (Map.insert v [] m)


-- Remove um vértice do grafo e todas as arestas nele incidentes
removeVértice :: (Ord v, Num p) => Grafo v p -> v -> Grafo v p
removeVértice (Grafo m) v = Grafo m'
   where
      f m (w,_) = Map.adjust (filter (\ (x,_) -> x /= v)) w m
      m' = case Map.lookup v m of
             Nothing -> m
             Just vizinhos -> Map.delete v (foldl f m vizinhos)

-- Testa se o vértice u é adjacente ao vértice v
adjacente :: (Ord v, Num p) => Grafo v p -> v -> v -> Bool
adjacente (Grafo m) u v =
   case Map.lookup u m of
      Nothing -> False
      Just vz -> elem v (map fst vz)


-- Grau de um vértice
grau :: (Ord v, Num p) => Grafo v p -> v -> Int
grau (Grafo m) v =
   case Map.lookup v m of
      Nothing -> -1
      Just vz -> length vz


-- Devolve a lista de vértices vizinhos ao vértice dado
vizinhos :: (Ord v, Num p) => Grafo v p -> v -> [v]
vizinhos (Grafo m) v = sort (map fst (Map.findWithDefault [] v m))


-- Verifica se um dado vértice está no grafo
pertence :: (Ord v, Num p) => Grafo v p -> v -> Bool
pertence (Grafo m) v = Map.member v m


--- Operações sobre arestas

-- Devolve a lista de adjacências do grafo
lista_adj :: (Ord v, Num p) => Grafo v p -> [ (v, [(v,p)]) ]
lista_adj (Grafo m) = Map.assocs m


-- Devolve a lista de arestas
arestas :: (Ord v, Num p, Eq p) => Grafo v p -> [ Aresta v p ]
arestas (Grafo m) = procuraArestas lista []
   where
      lista = Map.assocs m
      geraArestas u as [] = as
      geraArestas u as ((v,p):vs)
         | elem (u,p,v) as || elem (v,p,u) as = geraArestas u as vs
         | otherwise = geraArestas u ((u,p,v):as) vs
      procuraArestas [] as = as
      procuraArestas ((v,vz):ls) as =
         procuraArestas ls (geraArestas v as vz)

-- verifica se a aresta com o dado peso p pertence ao grafo
pertenceAresta :: (Ord v, Num p, Eq p) => Grafo v p -> Aresta v p -> Bool
pertenceAresta (Grafo m) (u,p,v) =
    case Map.lookup u m of
      Nothing -> False
      Just vz -> elem (v,p) vz


-- Adiciona uma nova aresta ao grafo. As pontas das arestas já devem existir no
-- grafo
novaAresta :: (Ord v, Show v, Num p, Eq p, Show p) => Grafo v p -> Aresta v p -> Grafo v p
novaAresta (Grafo m) a = Grafo (insereAresta m a)


-- Remove uma aresta do grafo
removeAresta :: (Ord v, Num p, Eq p) => Grafo v p -> Aresta v p -> Grafo v p
removeAresta (Grafo m) (u,p,v) = Grafo (Map.adjust (filter (\ (x,p) -> x /= u)) v m')
   where
      m' = Map.adjust (filter (\ (x,p) -> x /= v)) u m



--------------------------------------------------------------------------------
--                       Funções auxiliares                                   --
--------------------------------------------------------------------------------

insereAresta m (u,p,v)
    | Map.member u m && Map.member v m = Map.adjust ((v,p):) u (Map.adjust ((u,p):) v m)
    | otherwise = error ("A aresta " ++ show (u,p,v) ++
                         " possui extremidade não pertencente ao grafo")
