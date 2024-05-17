main :: IO ()
main = do
  input1 <- getLine
  input2 <- getLine
  
  let n = read input1 :: Int
  let lista = read ("[" ++ input2 ++ "]") :: [Int]

  putStrLn $ show lista
  
  --print $ maxInterval x y