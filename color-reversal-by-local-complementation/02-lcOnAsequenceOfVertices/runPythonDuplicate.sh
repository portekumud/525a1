while read line; do
	echo python3 "$line" >> runPythonActual.sh
done < listOfPythonFiles
