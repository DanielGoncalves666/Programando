
{- Uso de if then else
   Para todo if, precisa existir um else -}

{-
>>> maior 1 1
0

>>> maior 1 2
1

>>> maior 2 1
-1

-1, se a for maior, 0 se iguais, 1 se b maior
-}

maior a b = 
    if a > b then -1
             else if a < b then 1
                           else 0

{- Alternativamente, podemos utilizar guardas para esse tipo de operação -}
{- No uso de guardas n se usa o = após os parâmetros
    Utilizamos a | para delimitar cada opção, fazemos a avaliação condicional e com o = indicamos oq deve ser feito
    O otherwise é opcional, apesar de aqui dar erro de não for colocado e serve para indicar todos os casos restantes.
 -}

{-
>>> maiorGuarda 1 1
0

>>> maiorGuarda 1 2
1

>>> maiorGuarda 2 1
-1

-1, se a for maior, 0 se iguais, 1 se b maior
-}

maiorGuarda a b
    | a > b = -1
    | a < b = 1
    | otherwise = 0
