main = do
    putStrLn $ show $  maximoRadical [4]
    putStrLn $ show $ maximo [4]
    putStrLn $ show $ maximo ([] :: [Int])
    putStrLn $ show $ case maximo [4, 8, 0, 1] of
                        Nothing -> 0
                        Just x -> x
    --putStrLn $ x
    putStrLn "Hello World"
    --putStrLn $ show $ y
    putStrLn $ show $ sum $ take 10 $ ss
    putStrLn $ show $ take 10 $ iter 0 (+1)
    putStrLn $ show $ take 5 $ iter 1 (*2)
    putStrLn $ show $ takeWhile (<1000) $ iter 1 (*2)
    putStrLn $ show $ take 100 $ bagaca

--undef :: a
--undef = undef

maximoRadical :: (Ord a) => [a] -> a
maximoRadical [] = undefined
maximoRadical [x] = x
maximoRadical (x:xs) = if x > y then x else y
    where
        y = maximoRadical xs

maximo :: (Ord a) => [a] -> Maybe a
maximo [] = Nothing
maximo [x] = Just x
maximo (x:xs) = case maximo xs of
    Nothing -> Just x
    Just y -> Just $ if x > y then x else y

soma2 :: [Int] -> Int -> Int
soma2 l x = case maximo l of
    Nothing -> x
    Just y -> x + y

--acha :: (a -> Bool) -> [a] -> Maybe a

x = x + 1

y = 1:y

ss = let
        s n = n:(s (n +1))

    in
        s 1

iter n f = n:(iter (f n) f)

bagaca = let
            b (x:xs) = x:(b $ filter((/=0).(`mod` x)) xs)
        in
            b $ iter 2 (+1)