redO=$(printf "\033[31mO\033[32m")
redo=$(printf "\033[31mo\033[32m")
blueX=$(printf "\033[34mX\033[32m")
bluex=$(printf "\033[34mx\033[32m")
green=$(printf "\033[32m#")
piece=$(printf "\033[35mPiece")
got=$(printf "\033[32m<")

sed "s|X|$blueX|g" |
sed "s|Piece|$piece|g" |
sed "s|#|$green|g" |
sed "s|O|$redO|g" |
sed "s|<|$got|g" |
sed "/^0.. /s|o|$redo|g" |
sed "/^0.. /s|x|$bluex|g" |
sed "s|fin|player|g" 