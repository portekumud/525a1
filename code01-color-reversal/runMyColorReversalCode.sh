if test -f a.out; then
	#echo "File exists."
	rm a.out
else
	echo "File does not exist."
fi
g++ colorReversal.cpp
./a.out
