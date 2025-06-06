for file in *; do
	if [[ "$file" == "02-kumud-localComplementationOnAsequenceOfVertices.cpp" || "$file" == "Makefile" ]]; then
		continue
	fi
	echo "$file"
done
