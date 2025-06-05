while read line; do
	echo python3 "$line" >> wao.sh
	done < listOfPythonFiles
