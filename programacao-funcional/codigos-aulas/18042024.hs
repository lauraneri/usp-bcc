main = do
--    line <- getLine
--    let x :: Integer
--        x = read line
--    let f = fatorial x
--    let str = show f
    let l = [1, 5, 3, 8, 9, 4, 2]
    let p = somapares l
    let str = show p
    putStrLn str

sinal :: Integer -> Integer
sinal x
    | x < 0 = -1
    | x == 0 = 0
    | otherwise = 1

fat :: Int -> Int
fat n
    | n == 0 = 1
    | otherwise = n * fat (n - 1)

fatorial :: Integer -> Integer
fatorial 0 = 1
fatorial n = n * (fatorial (n - 1))

tempo :: Integer -> String
tempo t
    | t < 0 = "Congelante"
    | t < 15 = "Fresco"
    | t < 25 = "Agradável"
    | t < 35 = "Quente"
    | t < 45 = "Escaldante"
    | otherwise = "Morto"

imc :: Float -> Float -> String
imc h w
    | b < 20 = "Abaixo"
    | b < 30 = "Normal"
    | b < 35 = "Sobrepeso"
    | otherwise = "Obeso"
    where
        b = w / (h * h)

baskara :: Float -> Float -> Float -> [Float]
baskara a b c
    | delta > 0 = [(-b + sqdelta) / (2*a), (-b - sqdelta) / (2*a)]
    | delta == 0 = [-b / (2*a)]
    | otherwise = []
    where
        delta = b*b - 4*a*c
        sqdelta = delta ** 0.5

f :: Integer -> Integer -> Integer
f 5 5 = 15
f 3 6 = 12
f 4 y = y + 3
f x 5 = x + 9
f _ _ = 42

soma1 l = if l == []
        then 0
        else (head l) + (soma1 (tail l))

soma2 l
    | l == [] = 0
    | otherwise = (head l) + (soma2 (tail l))

soma3 [] = 0
soma3 l = (head l) + (soma3 (tail l))

soma :: [Integer] -> Integer
soma [] = 0
soma (x:xs) = x + (soma xs)

-- [4, 3, 1, 9, 5, 4] -> [7, 10, 9]
-- [] -> []
-- [3] -> [3]

somapares :: [Integer] -> [Integer]
somapares [] = []
somapares [x] = [x]
somapares (x1:x2:xs) = (x1 + x2):(somapares xs)

somaconsec :: [Integer] -> [Integer]
somaconsec [] = []
somaconsec [x] = [x]
somaconsec (x1:x2:xs) = (x1 + x2):(somaconsec (x2:xs))

invertepares :: [Integer] -> [Integer]
invertepares [] = []
invertepares [x] = [x]
invertepares (x1:x2:xs) = x2:x1:(invertepares xs)

posimpar :: [Integer] -> [Integer]
posimpar [] = []
posimpar [x] = [x]
posimpar (x1:_:xs) = x1:(posimpar xs)

f [] = 0
f [[x]:_]
