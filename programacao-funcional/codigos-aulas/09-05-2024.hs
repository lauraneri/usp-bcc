main = do
    putStrLn $ show $ felicidade Dom
    --putStrLn $ show $ Dom
    putStrLn $ show $ 1 == 2
    putStrLn $ show $ Dom == Qua
    --putStrLn $ show $ av1
    putStrLn $ show $ arr
    putStrLn $ show $ a1 == a2
    putStrLn $ nome a1
    putStrLn $ show $ map nome $ filter (\a -> (media a) > 9.5) $ arr
    putStrLn $ show $ map nome $ filter ((>9.5).media) $ arr

data DiaDaSemana = Dom | Seg | Ter | Qua | Qui | Sex | Sab
    deriving(Show, Eq)

data Sexo = M | F

data ArvoreBB a = Nulo | No a (ArvoreBB a) (ArvoreBB a)
    deriving(Show)

numNos :: (ArvoreBB a) -> Integer
numNos Nulo = 0
numNos (No _ av1 av2) = 1 + (numNos av1) + (numNos av2)

--data ArvoreBBStruct a = NuloStruct | NoStruct {val :: a, left :: ArvoreBBStruct a, right :: ArvoreBBStruct a}

felicidade :: DiaDaSemana -> Integer
felicidade Sex = 10
felicidade Sab = 15
felicidade Dom = 7
felicidade Qui = 20
felicidade _ = 5

data Aluno = Aluno { nome :: String, curso :: String, media :: Float}
    deriving(Show, Eq, Ord)

a1 = Aluno { nome = "Adenilso Simão", curso = "BCC", media = 9.5 }
a2 = Aluno { nome = "Kayane Silva", curso = "EngComp", media = 9.7 }
a3 = a1 { media = 9.0 }

arr = [a1, a2, a3]