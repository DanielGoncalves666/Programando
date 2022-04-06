-- File containing utility functions for lists.

funçãoExemploR x y = x+y

funçãoExemploL x y = x+y


{-
Resolva os seguintes exercícios sobre Entrada e Saída.
Use funções implementadas anteriormente para a parte funcional pura.

- Escreva um programa que leia a altura e peso de uma pessoa e imprima seu índice
de massa corporal e se este é alto, médio ou baixo.

-}

        
pegaPeso :: IO Float
pegaPeso = do
        putStrLn "Entre com o peso: "
        p <- getLine
        return $ read p
        
pegaAltura :: IO Float
pegaAltura = do
        putStrLn "Entre com a altura: "
        a <- getLine
        return $ read a

imprimirIMC :: IO ()
imprimirIMC = do
        p <- pegaPeso
        a <- pegaAltura
        putStrLn $ imc p a
        
        

imc p a
    | valor <= 18.5 = "IMC: " ++ show(valor) ++ ", Baixo" 
    | valor <= 25.0 = "IMC: " ++ show(valor) ++ ", Normal"
    | valor <= 30.0 = "IMC: " ++ show(valor) ++ ", Alto"
    | valor > 30.0 = "IMC: " ++ show(valor) ++ ", Obesidade"
    where valor = p / a ^ 2

{-
- Escreva um programa que leia linha por linha e, para cada linha lida, inverta 
as palavras em cada linha. Use as funções words e unwords para quebrar e reconstruir linhas
> unwords $ reverse $ words "lala lele lili"
"lili lele lala"

unwords :: [String] -> String
words :: String -> [String]
-}

inverterTexto :: IO ()
inverterTexto = do
        linha <- getLine
        putStrLn $ unwords $ reverse $ words linha
        if linha == "sair" then return ()
                           else inverterTexto


{-
- Escreva uma função que entre em um loop infinito em que
  - leia um inteiro
  - coloque o inteiro, se válido, em uma árvore de busca binária
  - imprima a árvore

Escreva pelo menos 2 testes para cada função, no arquivo FinderSpec.hs
-}

data Arvore a = Nada | Nó a (Arvore a) (Arvore a)  deriving (Show)

adicionar :: Int -> Arvore Int -> Arvore Int 
adicionar inteiro Nada = Nó inteiro Nada Nada
adicionar inteiro tree@(Nó raiz subtreeE subtreeD)
        | inteiro == raiz = tree
        | inteiro < raiz = Nó raiz (adicionar inteiro subtreeE) subtreeD
        | otherwise = Nó raiz subtreeE (adicionar inteiro subtreeD)
        
imprimirTree :: (Show a) => Arvore a -> String
imprimirTree (Nada) = "."
imprimirTree (Nó dado Nada Nada) = " " ++  show dado
imprimirTree (Nó dado Nada subtreeD) = " " ++ show dado ++ " " ++ imprimirTree subtreeD
imprimirTree (Nó dado subtreeE Nada) = " " ++ imprimirTree subtreeE ++ " " ++ show dado
imprimirTree (Nó dado subtreeE subtreeD) = " " ++ imprimirTree subtreeE ++ " " ++ show dado ++ " " ++ imprimirTree subtreeD

arvore :: Arvore Int -> IO ()
arvore tree = do
        inteiro <- getLine
        novatree <- return $ adicionar (read inteiro) tree
        putStrLn $ imprimirTree novatree
        arvore novatree

