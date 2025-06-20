graph01=graph01-initial
graph02=graph02-afterLocalCom
a=a
read=read.sh
msg1=$
line=line
c="${msg1}${line}"
wao=wao
lopf=listOfPythonFiles
loafe=listOfAllFilesExcept
fileReverseDuplicate=fileReverseDuplicate
fileReverseActual=fileReverseActual
deleteFileReverseDuplicate=deleteFileReverseDuplicate
deleteFileReverseActual=deleteFileReverseActual
thisIsDollar=$
kumud03:
	echo "make  kumud03 graph=../input/input5 lexicographyLimit=9"
	mkdir -p ../allFilesPNG
	mkdir -p ../allFilesPython
	mkdir -p ../log
	mkdir -p ../output
	# going to different directory python
	> part1.sh
	> part2.sh
	> pythonFIlesInDifferentDirectory
	ls ../allFilesPython/ | grep py >> pythonFIlesInDifferentDirectory
	echo "while read line; do" >> part2.sh
	echo -n "	echo rm ../allFilesPython/\"" >> part2.sh
	echo -n "$(thisIsDollar)" >> part2.sh
	echo "line\" >> part1.sh" >> part2.sh
	echo "done < pythonFIlesInDifferentDirectory" >> part2.sh
	bash part2.sh 
	bash part1.sh
	# going to different directory: log
	> part3.sh
	> part4.sh
	> logFIlesInDifferentDirectory
	ls ../log/ >> logFIlesInDifferentDirectory
	echo "while read line; do" >> part4.sh
	echo -n "	echo rm ../log/\"" >> part4.sh
	echo -n "$(thisIsDollar)" >> part4.sh
	echo "line\" >> part3.sh" >> part4.sh
	echo "done < logFIlesInDifferentDirectory" >> part4.sh
	bash part4.sh 
	bash part3.sh
	# going to different directory: png
	> part5.sh
	> part6.sh
	> pngFIlesInDifferentDirectory
	ls ../allFilesPNG/ >> pngFIlesInDifferentDirectory
	echo "while read line; do" >> part6.sh
	echo -n "	echo rm ../allFilesPNG/\"" >> part6.sh
	echo -n "$(thisIsDollar)" >> part6.sh
	echo "line\" >> part5.sh" >> part6.sh
	echo "done < pngFIlesInDifferentDirectory" >> part6.sh
	bash part6.sh 
	bash part5.sh
	# On the present directory	
	> $(fileReverseDuplicate).sh
	> $(lopf).sh	
	> $(loafe).sh
	echo "1111111111111111111111111"	
	> $(deleteFileReverseDuplicate).sh
	> $(deleteFileReverseActual).sh
	echo "for file in *; do" >> $(fileReverseDuplicate).sh
	echo -n "	if [[ \"" >> $(fileReverseDuplicate).sh
	echo -n "$(msg1)" >> $(fileReverseDuplicate).sh
	echo -n "file\" == \"03-kumud-localComplementation.cpp\"" >> $(fileReverseDuplicate).sh
	echo -n " || \"" >> $(fileReverseDuplicate).sh
	echo -n "$(msg1)" >> $(fileReverseDuplicate).sh
	echo "file\" == \"Makefile\" ]]; then" >> $(fileReverseDuplicate).sh
	echo "		continue" >> $(fileReverseDuplicate).sh
	echo "	fi" >> $(fileReverseDuplicate).sh
	echo -n "	echo \"" >> $(fileReverseDuplicate).sh
	echo -n "$(msg1)" >> $(fileReverseDuplicate).sh
	echo "file\"" >> $(fileReverseDuplicate).sh
	echo "done" >> $(fileReverseDuplicate).sh
	bash $(fileReverseDuplicate).sh >> $(loafe).sh
	echo "22222222222222"
	
	echo "while read line; do" >> $(deleteFileReverseDuplicate).sh
	echo -n "	echo rm \"" >> $(deleteFileReverseDuplicate).sh
	echo -n "$(thisIsDollar)" >> $(deleteFileReverseDuplicate).sh
	echo "line\" >> $(deleteFileReverseActual).sh" >> $(deleteFileReverseDuplicate).sh
	echo "done < $(loafe).sh" >> $(deleteFileReverseDuplicate).sh
	bash $(deleteFileReverseDuplicate).sh
	bash $(deleteFileReverseActual).sh
	
	g++ 03-kumud-localComplementation.cpp
	./a.out ../input/$(graph) $(lexicographyLimit)
	###########################################################
	#cat equalOrNot
	cd ../allFilesPNG/
	#python3 ../allFilesPython/graph03-2.py 
	> part7.sh
	> part8.sh
	> pythonFIlesInDifferentDirectory
	ls ../allFilesPython/ | grep py >> pythonFIlesInDifferentDirectory
	echo "while read line; do" >> part8.sh
	echo -n "	echo python3 ../allFilesPython/\"" >> part8.sh
	echo -n "$(thisIsDollar)" >> part8.sh
	echo "line\" >> part7.sh" >> part8.sh
	echo "done < pythonFIlesInDifferentDirectory" >> part8.sh
	bash part8.sh 
	bash part7.sh
		
	
	> part9.sh
	> part10.sh
	> pngFIlesInDifferentDirectory
	ls | grep .png >> pngFIlesInDifferentDirectory
	echo "while read line; do" >> part10.sh
	echo -n "	echo mv \"" >> part10.sh
	echo -n "$(thisIsDollar)" >> part10.sh
	echo "line\" ../allFilesPNG/ >> part9.sh" >> part10.sh
	echo "done < pngFIlesInDifferentDirectory" >> part10.sh
	bash part10.sh 
	bash part9.sh
	
	
	
	
	
	
	
	
	
	
	
	
	
	#echo "	echo python3 \"$(msg1)$(line) $(ms2) a $(c)" >> $(file1)
	#echo "${msg1}msg1" >> $(file1)

	#echo "while read line; do" >> read.sh
	#python3 graph01-initial.py
	#python3 graph01-initial.py 
	#python3 graph02-afterLocalCom.py 
	#evince graph01-initial.pdf &
	#evince graph02-afterLocalCom.pdf &
clean:
	if [ -f $(a).out ]; then \
		echo "$(a).out File exists."; \
		rm $(a).out; \
	else\
		echo "$(a).out File does not exist."; \
	fi
	
	if [ -f $(graph01).pdf ]; then \
		echo "$(graph01).pdf File exists."; \
		rm $(graph01).pdf; \
	else\
		echo "$(graph01).pdf File does not exist."; \
	fi
	
	if [ -f $(graph01).py ]; then \
		echo "$(graph01).py File exists."; \
		rm $(graph01).py; \
	else\
		echo "$(graph01).py File does not exist."; \
	fi
	
	if [ -f $(graph02).pdf ]; then \
		echo "$(graph02).pdf File exists."; \
		rm $(graph02).pdf; \
	else\
		echo "$(graph02).pdf File does not exist."; \
	fi
	
	if [ -f $(graph02).py ]; then \
		echo "$(graph02).py File exists."; \
		rm $(graph02).py; \
	else\
		echo "$(graph02).py File does not exist."; \
	fi


