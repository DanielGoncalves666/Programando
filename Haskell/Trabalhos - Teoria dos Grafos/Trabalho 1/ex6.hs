import Data.Array

mat = array ((1,1),(2,3)) [((1,1),4),((1,2),0),((1,3),8),((2,1),7),((2,2),1),((2,3),7)]

quadrado x = x * x

-- >>> mapMat quadrado mat
-- array ((1,1),(2,3)) [((1,1),16),((1,2),0),((1,3),64),((2,1),49),((2,2),1),((2,3),49)]

mapMat :: (Ix b) => (a -> a) -> Array (b,b) a -> Array (b,b) a
mapMat f matriz = 
    let elementos = [((x,y), f $ matriz!(x,y)) | (x,y) <- range $ bounds matriz]
    in array (bounds matriz) elementos

{- elementos é uma lista que contém tuplas. Cada tupla contém uma tupla que indica as coordenadas e um
valor do tipo especificado. Essas coordenadas são geradas pela range e o valor da matriz original é alterado
posição por posição pela função f.
-}