while read line; do
	echo python3 ../allFilesPython/"$line" >> part7.sh
done < pythonFIlesInDifferentDirectory
