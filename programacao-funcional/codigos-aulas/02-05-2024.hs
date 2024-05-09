main = do
    putStrLn "Hello World"
    putStrLn $ show $ reduce (+) 0 [1, 3, 2, 6, 7, 8, 3]
    putStrLn $ show $ len [2, 4, 5]

reduce :: (b -> a -> a) -> a -> [b] -> a
reduce _ base [] = base
reduce op base (x:xs) = op x $ reduce op base xs

soma l = reduce (+) 0

produto = reduce (*) 1

concatenar = reduce (++) ""

len = reduce (\x y -> 1 + y) 0
len1 = reduce ((+).(const 1)) 0

mapa f = reduce ((:).f) []

len2 l = reduce (+)