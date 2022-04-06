{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module Grafo where

import BaseGrafo
import FuncoesAuxiliares
import Busca

import Data.List

-- ============================================================================================================================================= --
--                                                                  Lista 3
-- ============================================================================================================================================= --

-- 1
éVértIsolado :: Grafo Int -> Int -> Bool
éVértIsolado g v = grau g v == 0

-- 2
éVértTerminal :: Grafo Int -> Int -> Bool
éVértTerminal g v = grau g v == 1

-- 3
éVértPar :: Grafo Int -> Int -> Bool
éVértPar g v = even $ grau g v

-- 4
éVértImpar :: Grafo Int -> Int -> Bool
éVértImpar g v = odd $ grau g v

{-
(a,b) e (c,d)

a == c e b == d      (I)
a == d e b == c      (II)
b == c e a == d      (II) Desnecessário
b == d e a == c      (I) Desnecessário
-}

-- 5
sãoArestasAdjs :: Grafo Int -> (Int,Int) -> (Int,Int) -> Bool
sãoArestasAdjs g (t,u) (v,w) =
    let listAres = arestas g
        existem = ((t,u) `elem` listAres || (u,t) `elem` listAres) && ((v,w) `elem` listAres || (w,v) `elem` listAres)
        iguais = (t == v && u == w) || (t == w && u == v)
    in existem && not iguais && (t == v || t == w || u == v || u == w)

-- 6
éTrivial :: Grafo Int -> Bool
éTrivial g = length (vértices g) == 1

-- 7
seqGraus :: Grafo Int -> [Int]
seqGraus g =
    let listGrauDesor = [grau g a | a <- vértices g]
    in quicksort listGrauDesor

-- 8
grauMax :: Grafo Int -> Int
grauMax g = last $ seqGraus g

-- 9
grauMin :: Grafo Int -> Int
grauMin g = head $ seqGraus g

-- 10
éRegular :: Grafo Int -> Bool
éRegular g = grauMin g == grauMax g

-- 11
ékRegular :: Grafo Int -> Int -> Bool
ékRegular g k = grauMin g == k && grauMax g == k

-- 12
éVazio :: Grafo Int -> Bool
éVazio g = not (null (vértices g)) && null (arestas g)

-- 13
éNulo :: Grafo Int -> Bool
éNulo g = null (vértices g)

-- 14
éKn :: Grafo Int -> Int -> Bool
éKn g k =
    let qtdVert = length $ vértices g
    in k == qtdVert && grauMin g == k - 1 && grauMax g == k - 1

-- 15
éCompleto :: Grafo Int -> Bool
éCompleto g =
    let qtd = length $ vértices g
    in grauMin g == qtd - 1 && grauMax g == qtd - 1

-- 16
éSubgrafo :: Grafo Int -> Grafo Int -> Bool
éSubgrafo h g = intersecao (vértices h) (vértices g) == vértices h && intersecao (arestas h) (arestas g) == arestas h

-- 17
éSubgrafoPróprio :: Grafo Int -> Grafo Int -> Bool
éSubgrafoPróprio h g =
    let interVert = intersecao (vértices h) (vértices g)
        interArest = intersecao (arestas h) (arestas g)
    in interVert == vértices h && interArest == arestas h && (interVert /= vértices g || interArest /= arestas g)

--18
éSubgrafoInduzidoVértices :: Grafo Int -> Grafo Int -> [Int] -> Bool
éSubgrafoInduzidoVértices h g vh =
    let inter = intersecao (vértices h) vh -- a ordem dos elementos da interseção é de acordo com sua aparição na primeira lista
        ehIgual = inter == vértices h && length (vértices h) == length vh -- A lista vh é exatamente igual (desconsiderando a ordem) a lista de vértices de H
        existeGH = and [(a,b) `elem` arestas h | a <- vértices h, b <- vértices h, (a,b) `elem` arestas g]
        existeHG = and [a `elem` arestas g | a <- arestas h]
    in éSubgrafo h g && ehIgual && existeGH && existeHG
{-
Todas as arestas possíveis entre os vértices de H são geradas, porém apenas aquelas arestas presentes em g passam pela verificação de que existem
também em H. No fim, temos uma lista de Bools cujos valores precisam ser todos True para que o resultado final seja True. Caso alguma aresta
que está em G não estiver em H, então o grafo passado não é induzido.
É necessário que mais uma verificação seja feita para garantir que não existam arestas em H que não estão em G.
-}

-- 19
éSubgrafoInduzidoArestas :: Grafo Int -> Grafo Int -> [(Int,Int)] -> Bool
éSubgrafoInduzidoArestas h g ars =
    let inter = intersecao (arestas h) ars
        ehIgual = inter == arestas h && length (arestas h) == length ars -- ars precisa ser igual às arestas de h
        vetInduzidos = [ fst a | a <- ars] ++ [ snd a | a <- ars] -- toda ocorrência dos vértices nas arestas é listada
        nenhumExtra = and [ a `elem` vetInduzidos | a <- vértices h] -- todos os vértices de H precisam ocorrer na lista dos vértices induzidos pelas arestas
    in éSubgrafo h g && ehIgual && nenhumExtra
{-
A lista de arestas ars precisa ser igual às arestas de H para que H seja induzido pelas arestas. 
Além disso, H não pode ter vértices além daqueles induzidos pelas arestas
-}


-- 20
éClique :: Grafo Int -> Grafo Int -> Bool
éClique h g = éSubgrafo h g && éCompleto h

-- 21
éCjIndependenteVértices :: Grafo Int -> Grafo Int -> Bool
éCjIndependenteVértices h g = éSubgrafo h g && éVazio h
-- Qualquer subconjunto Ah de A em que Eh seja vazio é um conjunto independente de vértices

-- 22
insereVértices :: Grafo Int -> [Int] -> Grafo Int
insereVértices g [] = g
insereVértices g (v:vs)
    | v `elem` vértices g = insereVértices g vs
    | otherwise = insereVértices (novoVértice g v) vs

-- 23
removeVértices :: Grafo Int -> [Int] -> Grafo Int
removeVértices g [] = g
removeVértices g (v:vs)
    | v `notElem` vértices g = removeVértices g vs
    | otherwise = removeVértices (removeVértice g v) vs

-- 24
insereArestas :: Grafo Int -> [(Int,Int)] -> Grafo Int
insereArestas g [] = g
insereArestas g ((x,y):ars)
    | x `notElem` vértices g || y `notElem` vértices g = error $ "Um dos vértices de (" ++ show x ++ "," ++ show y ++ ") não existe no grafo."
    | (x,y) `elem` arestas g || (y,x) `elem` arestas g || x == y = insereArestas g ars -- arestas já existentes e laços são ignorados
    | otherwise = insereArestas (novaAresta g (x,y)) ars

-- função extra que remove o mecanismo que impede adição de laços e arestas paralelas
insereArestasIrrestritas :: Grafo Int -> [(Int,Int)] -> Grafo Int
insereArestasIrrestritas g [] = g
insereArestasIrrestritas g ((x,y):ars)
    | x `notElem` vértices g || y `notElem` vértices g = error $ "Um dos vértices de (" ++ show x ++ "," ++ show y ++ ") não existe no grafo."
    | otherwise = insereArestasIrrestritas (novaAresta g (x,y)) ars


-- 25
removeArestas :: Grafo Int -> [(Int,Int)] -> Grafo Int
removeArestas g [] = g
removeArestas g ((x,y):ars)
    | (x,y) `elem` arestas g = removeArestas (removeAresta g (x,y)) ars
    | (y,x) `elem` arestas g = removeArestas (removeAresta g (y,x)) ars
    | otherwise = removeArestas g ars

-- 26
-- arestas paralelas e laços são permitidas
fundeVértices :: Grafo Int -> Int -> Int -> Grafo Int
fundeVértices g v w =
    let menor = min v w -- menor rótulo
        maior = max v w -- maior rótulo 
        viz = [ a | a <- vizinhos g maior] -- lista de vizinhos do vértice com rótulo maior.
        remMaior = removeVértice g maior -- remove o vértice de rótulo maior e suas arestas 
    in insereArestasIrrestritas remMaior [(menor,a) | a <- viz] -- adiciona as arestas que o vértice maior tinha

-- 27
-- arestas paralelas e laços são removidos
contraiVértices :: Grafo Int -> Int -> Int -> Grafo Int
contraiVértices g v w =
    let menor = min v w -- menor rótulo
        maior = max v w -- maior rótulo 
        viz = [ a | a <- vizinhos g maior, a /= menor, a `notElem` vizinhos g menor]
        -- lista de vizinhos do vértice com rótulo maior. Remove a ocorrência de laços e arestas paralelas no grafo final.
        remMaior = removeVértice g maior -- remove o vértice de rótulo maior e suas arestas 
    in insereArestas remMaior [(menor,a) | a <- viz] -- adiciona as arestas que o vértice maior tinha

-- 28
contraiAresta :: Grafo Int -> (Int,Int) -> Grafo Int
contraiAresta g (v,w)
    | (v,w) `notElem` arestas g && (w,v) `notElem` arestas g = error "Aresta inexistente."
    | otherwise = let remAresta = removeAresta g (v,w)
                  in fundeVértices remAresta v w

-- ============================================================================================================================================= --
--                                                                  Lista 4
-- ============================================================================================================================================= --

-- 1
grafoComplemento :: Grafo Int -> Grafo Int
grafoComplemento g
    | n == 0 || n == 1 = g -- grafo nulo e grafo vazio com um vértice
    | otherwise = insereArestas nG [(a,b) |(a,b) <- arestasCompleto, (a,b) `notElem` arestas g && (b,a) `notElem` arestas g]
    where nG = novoGrafo (vértices g) []
          n = length $ vértices g
          arestasCompleto = [(a,b) | a <- [1..n], b <- [1..n], a /= b] -- arestas do Grafo Completo duplicadas

-- 2
união :: Grafo Int -> Grafo Int -> Grafo Int
união g h =
    let uniaoVertices = vértices g ++ [a | a <- vértices h, a `notElem` vértices g] -- só adiciona vértices e arestas que não existem no grafo g
        uniaoArestas = arestas g ++ [a | a <- arestas h, a `notElem` arestas g]
    in novoGrafo uniaoVertices uniaoArestas

-- 3
-- tomar cuidado que no módulo FuncoesAuxiliares existe uma funcao intersecao.
interseção :: Grafo Int -> Grafo Int -> Grafo Int
interseção g h =
    let intersectVertices = intersecao (vértices g) (vértices h) -- função intersecao do módulo FuncoesAuxiliares
        intersectArestas = intersecao (arestas g) (arestas h)
    in novoGrafo intersectVertices intersectArestas

-- 4
soma :: Grafo Int -> Grafo Int -> Grafo Int
soma g h =
    let nG = união g h
    in insereArestas nG [(a,b) | a <- vértices g, b <- vértices h, a /= b] -- se a aresta já existir nada acontece

-- 5
éPasseio :: Grafo Int -> [Int] -> Bool
éPasseio g vs
    | not contem = False -- se os vértices da lista não estão todos no grafo
    | null vs = False
    | otherwise = éPasseioAux g vs
    where contem = and [ a `elem` vértices g | a <- vs]

éPasseioAux :: Grafo Int -> [Int] -> Bool
éPasseioAux g vs
    | length vs == 1 = True -- significa que é um passeio com apenas um vértice ou que é o fim de um passeio válido
    | segundo `elem` vizinhos g primeiro = éPasseioAux g (tail vs)
    | otherwise = False -- caso o segundo não seja um vizinho do primeiro, então o passeio não existe
    where primeiro = head vs
          segundo = head (tail vs)

-- 6
éPasseioAberto :: Grafo Int -> [Int] -> Bool
éPasseioAberto g vs = éPasseio g vs && head vs /= last vs

-- 7
éPasseioFechado :: Grafo Int -> [Int] -> Bool
éPasseioFechado g vs = éPasseio g vs && head vs == last vs

-- 8
éTrilha :: Grafo Int -> [Int] -> Bool
éTrilha g vs =
    let semUltimo = reverse (tail (reverse vs))
        arestasPasseio = zip semUltimo (tail vs) -- combina 1 e 2, 2 e 3, ..., penultimo e ultimo. Concatena com [1,ultimo] 
    in éPasseio g vs && not (contemDuplicados arestasPasseio)

contemDuplicados :: [(Int,Int)] -> Bool
contemDuplicados [] = False
contemDuplicados ((a,b):ars)
    | (a,b) `elem` ars || (b,a) `elem` ars = True -- existem duplicados
    | otherwise  = contemDuplicados ars

-- 9
-- Todo caminho é uma trilha, mas nem toda trilha é um caminho
éCaminho :: Grafo Int -> [Int] -> Bool
éCaminho g vs = éPasseio g vs && not (contemDuplicados' vs)

contemDuplicados' :: [Int] -> Bool
contemDuplicados' [] = False
contemDuplicados' (v:vs)
    | v `elem` vs = True
    |otherwise = contemDuplicados' vs

-- 10
éCiclo :: Grafo Int -> [Int] -> Bool
éCiclo g vs = éPasseio g vs && éCaminho g (init vs) && (head vs == last vs)

-- 11
-- O grafo precisa ser conexo e 2-regular.
éGrafoCíclico :: Grafo Int -> Bool
éGrafoCíclico g = ékRegular g 2 && éConexo g

-- 12
éCn :: Grafo Int -> Int -> Bool
éCn g n = éGrafoCíclico g && length (vértices g) == n

-- 13
-- Um caminho é um grafo com apenas 2 vértices com d = 1 e todos os outros com d = 2. Além disso, o grafo precisa ser conexo
éGrafoCaminho :: Grafo Int -> Bool
éGrafoCaminho g
    | length (vértices g) < 2 = False
    | length (vértices g) == 2 && grauMin g == 1 = True
    | otherwise = éConexo g && grauMin g == 1 && grauMax g == 2 && terceiro == 2
    where terceiro = seqGraus g !! 2

-- 14
éPn :: Grafo Int -> Int -> Bool
éPn p n = éGrafoCaminho p && length (vértices p) == n

-- 15
éGrafoBipartido :: Grafo Int -> [Int] -> [Int] -> Bool
éGrafoBipartido g v1 v2 = verificar'' g v1 v1 && verificar'' g v2 v2

-- verifica se os vértices de uma partição possuem vizinhos dentro dela
verificar'' :: Grafo Int -> [Int] -> [Int] -> Bool
verificar'' g [] particao = True
verificar'' g v particao = not final && verificar'' g (tail v) particao
    where final = or [ a `elem` particao | a <- vizinhos g (head v)]

-- 16
-- trilhas não repetem arestas, logo o passeio precisa ser uma trilha e a quantidade de arestas nessa trilha igual a quantidade do grafo
éTrilhaEuleriana :: Grafo Int -> [Int] -> Bool
éTrilhaEuleriana g t = éTrilha g t && length arestasPasseio == length (arestas g)
    where semUltimo = reverse (tail (reverse t))
          arestasPasseio = zip semUltimo (tail t)

-- 17
-- Um grafo conexo é euleriano se todos os seus vértices possuírem grau par
éGrafoEuleriano :: Grafo Int -> Bool
éGrafoEuleriano g = éConexo g && todosPar
    where todosPar = and [ even a | a <- seqGraus g]

-- 18
-- Um grafo é semi-euleriano se apenas dois vértices possuírem grau ímpar.
éSemiEuleriano :: Grafo Int -> Bool
éSemiEuleriano g = éConexo g && doisImpares
    where doisImpares = length [a | a <- seqGraus g, odd a] == 2

-- 19
éHamiltonianoOre :: Grafo Int -> Bool
éHamiltonianoOre g = n >= 3 && verificar g (vértices g)
    where n = length $ vértices g

verificar :: Grafo Int -> [Int] -> Bool
verificar g [] = True
verificar g (v:vs)
    | somas = verificar g vs
    | otherwise = False
    where adjascente = vizinhos g v
          naoAdjascentes = [grau g a | a <- vértices g, a `notElem` adjascente]
          n = length $ vértices g
          somas = and [ a + grau g v >= n  | a <- naoAdjascentes]

-- 20
éHamiltonianoDirac :: Grafo Int -> Bool
éHamiltonianoDirac g = n >= 3 && verificar' g (vértices g)
    where n = length $ vértices g

verificar' :: Grafo Int -> [Int] -> Bool
verificar' g [] = True
verificar' g (v:vs)
    | grau g v >= n `div` 2 && even n = verificar' g vs
    | grau g v >= (n `div` 2 + 1) && odd n = verificar' g vs
    | otherwise = False
    where n = length $ vértices g

-- 21
fecho :: Grafo Int -> Bool
fecho g = error "Implementar"


-- ============================================================================================================================================= --
--                                                                  Lista 5
-- ============================================================================================================================================= --

-- 6
{-
    É realizada uma busca em largura à partir do primeiro vértice da lista de vértices. A lista de vértices visitados precisa ter tamanho
    igual à lista de vértices do grafo.
-}
éConexo :: Grafo Int -> Bool
éConexo g = éConexoAux g [primeiro] [primeiro]
    where primeiro = head (vértices g)

-- a lista de abertos contém os vértices que foram visitados mas que seus vizinhos não foram
éConexoAux :: Grafo Int -> [Int] -> [Int] -> Bool
éConexoAux g visitados [] = length visitados == length (vértices g)
éConexoAux g visitados abertos = éConexoAux g listaVisitadosNova listaAbertosNova
    where vizAberto = vizinhos g (head abertos)       -- lista dos vértices adjascentes ao primeiro vértice da lista de abertos
          novosVisitados = [ a | a <- vizAberto, a `notElem` visitados] -- lista dos vértices que não foram visitados antes
          novosAbertos = [a | a <- vizAberto, a `notElem` visitados && a `notElem` abertos] -- lista dos novos vértices abertos
          listaVisitadosNova = visitados ++ novosVisitados
          listaAbertosNova = tail abertos ++ novosAbertos

-- 7
numCompConexas :: Grafo Int -> Int
numCompConexas g
    | éConexo g = 1
    | otherwise = 1 + numCompConexas nG
    where
        verticesFora = vértices g \\ largura g
        nG = novoGrafo verticesFora [(v,w) | (v,w) <- arestas g, v `elem` verticesFora && w `elem` verticesFora]

-- 16
-- se o grafo for completo, será n-1
-- se o grafo não for completo, será o menor grau do grafo
conectividade :: Grafo Int -> Int
conectividade g = error "Implementar"

-- 17
-- um grafo é biconexo se todos os vértices tiverem grau 2 e ele for conexo
éBiconexo :: Grafo Int -> Bool
éBiconexo g = error "Implementar"

-- ============================================================================================================================================= --
--                                                                  Lista 6
-- ============================================================================================================================================= --

éSubgrafoGerador :: Grafo Int -> Grafo Int -> Bool
éSubgrafoGerador g h = error "Implementar"

-- ============================================================================================================================================= --
--                                                                  Lista 9
-- ============================================================================================================================================= --

-- 1
-- uma cobertura qualquer(não necessáriamente a mínima)
-- organiza os vértices de forma decrescente em graus
-- retira todas as arestas que contém o primeiro vértice da lista de as, remove o vértice da lista.
-- se não existir nenhuma aresta com o vértice ele é ignorado
-- fazer isso até que não sobre nenhuma aresta
coberturaVértices :: Grafo Int -> [Int]
coberturaVértices g = coberturaAux g arest vetGrausDecr []
    where arest = arestas g
          vetGrausDecr = [a2 | (a1,a2) <- reverse $ seqGrausLigada g]

coberturaAux :: Grafo Int -> [(Int,Int)] -> [Int] -> [Int] -> [Int]
coberturaAux g [] _ cobert = cobert
coberturaAux g as (v:vs) cobert
    | null contem = coberturaAux g as vs cobert
    | otherwise = coberturaAux g asN vs cobertN
    where contem = [(a1,a2) | (a1,a2) <- as, a1 == v || a2 == v] -- lista com todas as arestas que possuem v
          cobertN = quicksort (v:cobert) -- adiciona o vértice na cobertura
          asN = as \\ contem

-- 2
subdivideAresta :: Grafo Int -> (Int, Int) -> Int -> Grafo Int
subdivideAresta g (v,w) n
    | (v,w) `notElem` arestas g && (w,v) `notElem` arestas g = error "Aresta inexistente."
    | n == 0 = g
    | otherwise = subdivideAresta nG'' (v,novoVet) (n - 1) -- como a aresta original não existe mais, passamos uma das que foram criadas para ser subdividida novamente
    where novoVet = length (vértices g) + 1
          nG = novoVértice g novoVet -- adiciona o vértice que irá subdividir a aresta
          nG' = removeAresta nG (v,w) -- remove a aresta entre v e w
          nG'' = insereArestas nG' [(v,novoVet),(w,novoVet)] -- adiciona as duas arestas que substituem a original

-- 3
suavizaVértices :: Grafo Int -> Int -> Grafo Int
suavizaVértices g v
    | grau g v /= 2 = g
    | otherwise = contraiVértices g v (head viz)
    where viz = vizinhos g v

-- 4
suaviza :: Grafo Int -> Grafo Int
suaviza g
   | 2 `notElem` seqGraus g = g
   | otherwise = suaviza nG
   where dois = [a | a <- vértices g, grau g a == 2]
         nG = suavizaVértices g (head dois)

-- 5
éBipartido :: Grafo Int -> (Bool,[Int],[Int])
éBipartido g = éBipartidoAux g cor [primeiro] [primeiro] 2
    where primeiro = head $ vértices g
          cor = [ 0 | a <- vértices g]
          corN = substituiPosicao cor 0 1

éBipartidoAux :: Grafo Int -> [Int] -> [Int] -> [Int] -> Int -> (Bool,[Int],[Int])
éBipartidoAux g cores [] visitados _ = (True, particao1, particao2)
    where particao1 = [ a | a <- vértices g, cores !! (a - 1) == 1]
          particao2 = [ a | a <- vértices g, cores !! (a - 1) == 2]
éBipartidoAux g cores fila visitados c
    | not verifica = (False,[],[])
    | otherwise =  éBipartidoAux g coresN filaNova visitadosNovo (if c == 1 then 2 else 1)
    where vizPrimeiro = vizinhos g (head fila) -- vizinhos do primeiro vértice da fila
          cReal = ((cores !! (head fila - 1)) `mod` 2) + 1
          verifica = and [ cores !! (a - 1) == cReal | a <- vizPrimeiro, cores !! (a - 1) /= 0] -- verifica se um vertice vizinho já está colorido com uma cor diferente de c (se tiver, então não é bipartido)
          coresN = substituiVarios cores vizPrimeiro cReal -- colore todos os vértices vizinhos (aqui vai ocorrer a coloração novamente de um vértice com a cor c com c)
          filaNova = tail fila ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- primeiro elemento da fila removido. 
          -- adicionams à fila os vértices que não foram visitados ainda
          visitadosNovo = visitados ++ [a | a <- vizPrimeiro, a `notElem` visitados]
          -- vértices não visitados são marcados como visitados

-- 6
coloreVérticesIngênuo :: Grafo Int -> [Int]
coloreVérticesIngênuo g = ingênuoAux g cor (vértices g) 1
    where cor = [ 0 | a <- vértices g]

ingênuoAux :: Grafo Int -> [Int] -> [Int] -> Int -> [Int]
ingênuoAux g cores [] i
    | null vetIncolor = cores
    | otherwise = ingênuoAux g cores vetIncolor (i + 1) -- i <- i + 1 no algoritmo
    where vetIncolor = [ a + 1 | a <- elemIndices 0 cores] -- se for vazia, então o enquanto do algoritmo chegou ao fim
ingênuoAux g cores vet@(l:ls) i -- o para do algoritmo
    | colorirI = ingênuoAux g coresN ls i -- se nenhum vértices adjascente tiver a cor i
    | otherwise = ingênuoAux g cores ls i
    where colorirI =  and [(cores !! (a - 1)) /= i | a <- vizinhos g l]
          coresN = substituiPosicao cores l i
          vetIncolor = [ a + 1 | a <- elemIndices 0 coresN] -- vértices incolores  

-- 7
coloreVértices :: Grafo Int -> [Int]
coloreVértices g = coloreAux g corN (tail (vértices g)) 1
    where cor = [ 0 | a <- vértices g]
          corN = substituiPosicao cor 1 1 -- cor[1] <- 1

coloreAux :: Grafo Int -> [Int] -> [Int] -> Int -> [Int]
coloreAux g cores [] _ = cores -- fim do para
coloreAux g cores (v:vs) c
    | null coresNaoVizinhas = coloreAux g coresN1 vs (c + 1)-- se estiver vazio então toda as cores até o momento estão coloridas nos vértices vizinhos
    | otherwise = coloreAux g coresN2 vs c
    where coresViz = [ cores !! (a - 1) | a <- vizinhos g v, cores !! (a - 1) /= 0] -- lista as cores vizinhas
          coresNaoVizinhas = [1..c] \\ coresViz -- retira da lista de cores todas as cores que estão em vizinhos
          coresN1 = substituiPosicao cores v (c + 1)
          coresN2 = substituiPosicao cores v (head coresNaoVizinhas) -- coloca a primeira cor da lista

-- 8
coloreMaiorPrimeiro :: Grafo Int -> [Int]
coloreMaiorPrimeiro g = coloreMPAux g cor vetOrdenados 1
     where vetOrdenados = [a2 | (a1,a2) <- reverse $ seqGrausLigada g]
           cor = [ 0 | a <- vértices g]

coloreMPAux :: Grafo Int -> [Int] -> [Int] -> Int -> [Int]
coloreMPAux g cores [] c
    | null listGrauDesor = cores -- fim do enquanto
    | otherwise = coloreMPAux g cores vetOrdenados (c + 1)
    where listGrauDesor = [ (grau g a, a) | a <- vértices g, cores !! (a - 1) == 0] -- lista os vértices e seus graus, de todos não coloridos
          vetOrdenados = [a2 | (a1,a2) <- reverse $ quicksort listGrauDesor]
coloreMPAux g cores (v:vs) c
    | coresViz = coloreMPAux g coresN vs c
    | otherwise = coloreMPAux g cores vs c
    where coresViz = and [ cores !! (a - 1) /= c | a <- vizinhos g v, cores !! (a - 1) /= 0] -- False se existir um vizinho com a cor c
          coresN = substituiPosicao cores v c -- atribuição


-- (grau,vértice)
seqGrausLigada :: Grafo Int -> [(Int,Int)]
seqGrausLigada g =
    let listGrauDesor = [ (grau g a, a) | a <- vértices g]
    in quicksortTupla listGrauDesor

quicksortTupla :: Ord a => [(a,a)] -> [(a,a)]
quicksortTupla [] = []
quicksortTupla [x] = [x]
quicksortTupla ((c1,c2):ls) =
    let menoresIguais = [(a1,a2) | (a1,a2) <- ls, a1 <= c1]
        maiores = [(a1,a2) | (a1,a2) <- ls, a1 > c1]
    in quicksortTupla menoresIguais ++ [(c1,c2)] ++ quicksortTupla maiores

-- ============================================================================================================================================= --
--                                                                  Lista 10
-- ============================================================================================================================================= --

-- 1
intervaloÍndiceCromático :: Grafo Int -> (Int,Int)
intervaloÍndiceCromático g = (grauMaximo, grauMaximo + 1)
    where grauMaximo = last (seqGraus g)

-- 2
-- tem um vértice com grau n - 1
-- todos os outros vértices tem grau 3
éRoda :: Grafo Int -> Bool
éRoda g = éConexo g && grauMaximo == n - 1 && todos3
    where grauMaximo = last (seqGraus g)
          n = length $ vértices g
          todos3 = and [ grau g a == 3 | a <- take (n - 1) (seqGraus g)]

-- 3
índiceCromCiclo :: Grafo Int -> Int
índiceCromCiclo g
    | not $ éGrafoCíclico g = 0
    | even n = 2
    | otherwise = 3
    where n = length $ vértices g

-- 4
índiceCromRoda :: Grafo Int -> Int
índiceCromRoda g 
    | not $ éRoda g = 0
    | otherwise = n - 1
    where n = length $ vértices g

-- 5
índiceCromKn :: Grafo Int -> Int
índiceCromKn g 
    | not $ éCompleto g = 0
    | even n = n - 1
    | otherwise = n
    where n = length $ vértices g

-- 6
-- pega uma aresta qualquer e dá a cor 1
-- pega um dos vizinhos e dá a cor seguinte
-- pega o vizinho do vizinho e dá a próximo cor (repete a cor da primeira se for um ciclo par)
coloreArestasCiclo :: Grafo Int -> [((Int,Int),Int)]
coloreArestasCiclo g 
    | not $ éGrafoCíclico g = []
    | otherwise = coloreArestasCicloAux g coloridas indCrom
    where indCrom = índiceCromCiclo g
          ar = head $ arestas g
          coloridas = [(ar,1)]

coloreArestasCicloAux :: Grafo Int -> [((Int,Int),Int)] -> Int -> [((Int,Int),Int)]
coloreArestasCicloAux g coloridas iC
    | length coloridas == length (arestas g) = coloridas
    | otherwise = coloreArestasCicloAux g novoColoridas iC
    where ultimo@(ar,c) = last coloridas
          vizinhos = [ a | a <- arestas g, sãoArestasAdjs g ar a, notElemColorida coloridas a] -- arestas vizinhas da última colorida que não são coloridas
          novoColoridas = coloridas ++ [(head vizinhos, if c + 1 > iC then 1 else c + 1)]


-- retorna um bool indicando se a aresta já foi colorida
notElemColorida :: [((Int,Int),Int)] -> (Int,Int) -> Bool 
notElemColorida coloridas ar = null existe
    where existe = [(a,b) | ((a,b),n) <- coloridas, (a,b) == ar || (b,a) == ar]

-- 7
coloreArestasRoda :: Grafo Int -> [((Int,Int),Int)]
coloreArestasRoda g  
    | not $ éRoda g = []
    | otherwise = coloreArestasRodaAux g coloridasCentrais indCrom
    where indCrom = índiceCromRoda g
          numVet = length $ vértices g
          vetCentral = head [a | a <- vértices g, grau g a == (numVet - 1)]
          coloridasCentrais = zip [(a,b)| (a,b) <- arestas g, a == vetCentral || b == vetCentral] [1..indCrom]

coloreArestasRodaAux :: Grafo Int -> [((Int,Int),Int)] -> Int -> [((Int,Int),Int)]
coloreArestasRodaAux g coloridas iC
    | null naoColoridas = coloridas
    | otherwise = coloreArestasRodaAux g novoColoridas iC
    where naoColoridas = arestas g \\ [a | (a,b) <- coloridas]
          coresDisponiveis = [1..iC] \\ [b | (a,b) <- coloridas, sãoArestasAdjs g a (head naoColoridas)]
          novoColoridas = coloridas ++ [(head naoColoridas,head coresDisponiveis)]

-- 8
coloreArestasKn :: Grafo Int -> [((Int,Int),Int)]
coloreArestasKn g = error "Implementar"

{-
    | not $ éCompleto g || length (vértices g) == 1 = []
    | length (vértices g) == 2 = coloridas
    | otherwise = coloreArestasKnAux g coloridas indCrom           
    where indCrom = índiceCromKn g -- n - 1 se par, n se ímpar
          ar = head $ arestas g
          coloridas = [(ar,1)] -- k2 colorido

coloreArestasKnAux :: Grafo Int -> [((Int,Int),Int)] -> Int -> [((Int,Int),Int)]
coloreArestasKnAux g coloridas iC 
    | null nextVet = coloridas
    | otherwise = coloreArestasKnAux g novaColoridas iC
    where vetKnAnterior = concat [[a,b] | ((a,b),c) <- coloridas]
          nextVet = vértices g \\ vetKnAnterior
          arColorir = [(a,b) | (a,b) <- arestas g, (a == head nextVet && b `elem` vetKnAnterior) || (b == head nextVet && a `elem` vetKnAnterior)]
          novaColoridas = determinarCor g coloridas arColorir iC

determinarCor :: Grafo Int -> [((Int,Int),Int)] -> [(Int,Int)] -> Int -> [((Int,Int),Int)]
determinarCor g coloridas [] _ = coloridas
determinarCor g coloridas (a:as) iC = determinarCor g novaColoridas as iC
    where coresDisponíveis = [1..iC] \\ [c | (b,c) <- coloridas, sãoArestasAdjs g a b]
          novaColoridas = coloridas ++ [(a, head coresDisponíveis)]
-}

-- 9
coloreArestasBipartido :: Grafo Int -> [((Int,Int),Int)]
coloreArestasBipartido g 
    | not resul = []
    | otherwise = coloreArestasBipartidoAux g [] um indCrom
    where (resul,um,dois) = éBipartido g
          indCrom = max (length um) (length dois)

coloreArestasBipartidoAux :: Grafo Int -> [((Int,Int),Int)] -> [Int] -> Int -> [((Int,Int),Int)]
coloreArestasBipartidoAux g coloridas [] _ = coloridas
coloreArestasBipartidoAux g coloridas particao@(p:ps) iC = coloreArestasBipartidoAux g novaColoridas ps iC
    where pArestas = [(a,b) | (a,b) <- arestas g, a == p || b == p] -- arestas incidentes no vértice p
          novaColoridas = determinarCor' g coloridas pArestas iC

determinarCor' :: Grafo Int -> [((Int,Int),Int)] -> [(Int,Int)] -> Int -> [((Int,Int),Int)]
determinarCor' _ coloridas [] _ = coloridas
determinarCor' g coloridas (a:as) iC = determinarCor' g novaColoridas as iC
    where coresDisponiveis = [1..iC] \\ [b | (c,b) <- coloridas, sãoArestasAdjs g c a]
          novaColoridas = coloridas ++ [(a,head coresDisponiveis)]

-- 10
-- tinha que ser aleatória
coloreArestasGuloso :: Grafo Int -> [((Int,Int),Int)]
coloreArestasGuloso g = coloreArestasGulosoAux g rotulagem []
    where rotulagem = arestas g

coloreArestasGulosoAux :: Grafo Int -> [(Int,Int)] -> [((Int,Int),Int)] -> [((Int,Int),Int)]
coloreArestasGulosoAux g [] coloridas = coloridas
coloreArestasGulosoAux g (c:cs) coloridas = coloreArestasGulosoAux g cs novoColoridas
    where coresVizinhas = [b | (a,b) <- coloridas, sãoArestasAdjs g a c]
          corDisponível = head ([1..] \\ coresVizinhas)
          novoColoridas = coloridas ++ [(c,corDisponível)]

-- 11
coloreArestas :: Grafo Int -> [((Int,Int),Int)]
coloreArestas g 
    | éGrafoCíclico g = coloreArestasCiclo g
    | éRoda g = coloreArestasRoda g
    | éCompleto g = coloreArestasKn g
    | resul = coloreArestasBipartido g
    | otherwise = coloreArestasGuloso g
    where (resul,_,_) = éBipartido g
