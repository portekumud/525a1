while read line; do
	echo evince "$line"  \&>> script01-showOutput.sh
done < allPDFFiles
