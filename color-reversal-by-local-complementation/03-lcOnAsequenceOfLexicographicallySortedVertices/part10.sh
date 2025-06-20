while read line; do
	echo mv "$line" ../allFilesPNG/ >> part9.sh
done < pngFIlesInDifferentDirectory
