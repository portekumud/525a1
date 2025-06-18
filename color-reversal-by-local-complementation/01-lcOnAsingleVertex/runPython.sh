while read line; do
	echo python3 "$line" >> RUNallPythonFiles
done < allPythonFiles
