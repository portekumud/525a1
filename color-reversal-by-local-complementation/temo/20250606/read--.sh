while read line; do
     echo python3 "$line" >> waoIamMAD.sh
     # Perform actions with each line
   done < listOfPythonFiles
