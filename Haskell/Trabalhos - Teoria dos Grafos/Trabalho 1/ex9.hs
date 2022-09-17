-- não consegui terminar

import System.Random
import Data.Time.Clock.POSIX

sorteia :: Int -> Int -> Int -> IO ()
sorteia n ini fim = do
    lista <-gerarAleatorios n (ini,fim)
    putStrLn $ show lista

gerarAleatorios :: Int -> (Int,Int) -> IO [(Int,Int)]
gerarAleatorios 0 _ = do return []
gerarAleatorios n (ini,fim) = do
    tempo <- getPOSIXTime
    resto <- gerarAleatorios (n - 1) (ini,fim)
    return IO primeiro:resto
    where primeiro = (fst $ uniformR (ini,fim) $ mkStdGen tempo :: Int, fst $ uniformR (ini,fim) $ mkStdGen tempo:: Int)
