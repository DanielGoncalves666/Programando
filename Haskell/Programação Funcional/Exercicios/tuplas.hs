{-
>>> (1,1) `soma2p` (2,2)
(3,3)

>>> soma2p (1,1) (2,2)
(3,3)

-}
soma2p (x1,y1) (x2,y2) = (x1 + x2, y1 + y2)

{-
>>> fst (0,1)
0

>>> snd (0,1)
1

>>> fst (0,0,0)
Couldn't match expected type ‘(a, b0)’
            with actual type ‘(a0, b1, c0)’

-}

fst1 (a,b) = a
snd1 (a,b) = b

fst2 (a,_b) = a
snd2 (_a, b) = b


prim (a,_,_,_) = a
seg (_,b,_,_) = b
terc (_,_,c,_) = c
quar (_,_,_,d) = d

{-
>>> sinal (-10)
(True,10)

-}
sinal :: Int -> (Bool,Int)
sinal inteiro = (inteiro < 0, abs inteiro)



type Pessoa = (String, String, String, String)

fazPessoa :: String -> String -> String -> String -> Pessoa
fazPessoa nome telefone cpf endereco = (nome,telefone,cpf,endereco)

{-
>>> (1,1) < (1,1)
False

>>> (1,1) < (1,2)
True

>>> (1,2) < (2,1)
True

>>> (2,1) < (2,2)
True

>>> (1,2) < (2,0)
True

-}
