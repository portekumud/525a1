while read line; do
	echo evince "$line"  \&>> RUNallPDFFiles.sh
done < allPDFFiles
