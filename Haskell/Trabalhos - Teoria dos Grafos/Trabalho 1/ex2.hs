import Data.Char (isUpper)

-- Assumindo que as letras do acrônimo já estão em maiúsculo
{- Tentar construir os acronimos usando outros métodos, como o do espaço antes da letra geraria
acronimos maiores. A tentativa de retirar as letras de palavras como 'de', 'e', entre outros,
deixaria a função demasiadamente complexa
-}

acronimo :: String -> String 
acronimo frase = [e | e <- frase, isUpper e]
