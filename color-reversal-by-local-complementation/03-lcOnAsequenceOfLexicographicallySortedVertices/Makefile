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
	#source env01-kumud-localComplementation/bin/activate
	#python3 -m venv env01-kumud-localComplementation
	#source env01-kumud-localComplementation/bin/activate
	#pip install networkx
	#pip install matplotlib
	#echo "import networkx as nx " > graph01-initial.py
	#echo "import matplotlib.pyplot as plt " >> graph01-initial.py
	#echo "G = nx.Graph() " >> graph01-initial.py
	#echo "plt.figure(figsize =(9, 12)) " >> graph01-initial.py
	#echo "" >> graph01-initial.py
	#echo "plt.subplot(211) " >> graph01-initial.py
	#echo "print(\"The original Graph\") " >> graph01-initial.py
	#echo "nx.draw_networkx(G) " >> graph01-initial.py
	#echo "plt.savefig('graph01-initial.png')" >> graph01-initial.py 
	#echo "" > read.sh
	#if [ -f $(read) ]; then \
	#	echo "ok 1"; \
	#else\
	#	echo "ok 2"; \
	#	touch $(read); \
	#fi
	
	
	
	
	#if [ -f $(lopf) ]; then \
	#	echo "$(lopf) File exists."; \
	#	rm $(lopf); \
	#else\
	#	echo "$(lopf) File does not exist."; \
	#fi
	#if [ -f $(wao).sh ]; then \
	#	echo "$(wao).sh File exists."; \
	#	rm $(wao).sh; \
	#else\
	#	echo "$(wao).sh File does not exist."; \
	#fi
	#if [ -f $(fileReverse).sh ]; then \
	#	echo "$(fileReverse).sh File exists."; \
	#	rm $(fileReverse).sh; \
	#else\
	#	echo "$(fileReverse).sh File does not exist."; \
	#fi
	
	> $(fileReverseDuplicate).sh
	> $(lopf).sh	
	> $(loafe).sh
	echo "1111111111111111111111111"	
	> $(deleteFileReverseDuplicate).sh
	> $(deleteFileReverseActual).sh
	> equalOrNot	
	> theoutput	
	
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
	ls | grep py >> $(lopf)
	
	
	echo "while read line; do" >> runPythonDuplicate.sh
	echo -n "	echo python3 \"" >> runPythonDuplicate.sh
	echo -n "$(thisIsDollar)" >> runPythonDuplicate.sh
	echo "line\" >> runPythonActual.sh" >> runPythonDuplicate.sh
	echo "done < listOfPythonFiles" >> runPythonDuplicate.sh
	bash runPythonDuplicate.sh
	bash runPythonActual.sh
	#cat equalOrNot

	
	
	
	#ls | grep .py >> $(lopf)
	#echo "while read line; do" >> $(file1)
	##rm j.txt
	#echo -n "	echo python3 " >> $(file1)
	#echo -n "\"" >> $(file1)
	#echo -n "$(msg1)" >> $(file1)
	#echo -n "line" >> $(file1)
	#echo -n "\"" >> $(file1)
	#echo -n " >> " >> $(file1)
	#echo "wao.sh" >> $(file1)
	#echo "	done < listOfPythonFiles" >>$(file1)
	#bash read.sh
	#bash wao.sh
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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

