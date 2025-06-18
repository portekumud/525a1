graph01=graph01-initial
graph02=graph02-afterLocalCom
a=a
script=script01-showOutput
thisIsDollar=$

kumud01:
	> REMOVEunnecessary.sh
	> toBeremoved.sh
	> listOfAllFIles
	> fileReverseDuplicate.sh
	echo "for file in *; do" >> fileReverseDuplicate.sh
	echo -n "	if [[ \"" >> fileReverseDuplicate.sh
	echo -n "$(thisIsDollar)" >> fileReverseDuplicate.sh
	echo -n "file\" == \"01-kumud-localComplementationOnSingleVertexOnly.cpp\"" >> fileReverseDuplicate.sh
	echo -n " || \"" >> fileReverseDuplicate.sh
	echo -n "$(thisIsDollar)" >> fileReverseDuplicate.sh
	echo "file\" == \"Makefile\" ]]; then" >> fileReverseDuplicate.sh
	echo "		continue" >> fileReverseDuplicate.sh
	echo "	fi" >> fileReverseDuplicate.sh
	echo -n "	echo \"" >> fileReverseDuplicate.sh
	echo -n "$(thisIsDollar)" >> fileReverseDuplicate.sh
	echo "file\"" >> fileReverseDuplicate.sh
	echo "done" >> fileReverseDuplicate.sh
	bash fileReverseDuplicate.sh >> listOfAllFIles
	echo "while read line; do" >> toBeremoved.sh
	echo -n "	echo rm \"" >> toBeremoved.sh
	echo -n "$(thisIsDollar)" >> toBeremoved.sh
	echo "line\" >> REMOVEunnecessary.sh" >> toBeremoved.sh
	echo "done < listOfAllFIles" >> toBeremoved.sh
	bash toBeremoved.sh
	bash REMOVEunnecessary.sh
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
	
	g++ 01-kumud-localComplementationOnSingleVertexOnly.cpp
	./a.out ../input/$(graph) $(vertex) 
	ls | grep py >> allPythonFiles
	echo "while read line; do" >> runPython.sh
	echo -n "	echo python3 \"" >> runPython.sh
	echo -n "$(thisIsDollar)" >> runPython.sh
	echo "line\" >> RUNallPythonFiles" >> runPython.sh
	echo "done < allPythonFiles" >> runPython.sh
	bash runPython.sh
	bash RUNallPythonFiles 
	
	ls | grep pdf >> allPDFFiles
	echo "while read line; do" >> runPDF.sh
	echo -n "	echo evince \"" >> runPDF.sh
	echo -n "$(thisIsDollar)" >> runPDF.sh
	#echo -n "." >> runPDF.sh
	echo "line\"  \&>> script01-showOutput.sh" >> runPDF.sh
	echo "done < allPDFFiles" >> runPDF.sh
	bash runPDF.sh
	bash script01-showOutput.sh
	
	
	
	
	#python3 graph0-graphInitial.py 
	#python3 graph02-afterLocalCom.py 
	#evince graph01-initial.pdf &
	#evince graph02-afterLocalCom.pdf &
	
	#touch script01-showOutput.sh
	#echo "#!"/"bin"/"bash" > script01-showOutput.sh
	#echo "okular graph01-initial.pdf &" >> script01-showOutput.sh
	#echo "okular graph02-afterLocalCom.pdf &" >> script01-showOutput.sh
clean:
	if [ -f $(a).out ]; then \
		echo "$(a).out file exists."; \
		rm $(a).out; \
	else\
		echo "$(a).out file does not exist."; \
	fi
	
	if [ -f $(graph01).pdf ]; then \
		echo "$(graph01).pdf file exists."; \
		rm $(graph01).pdf; \
	else\
		echo "$(graph01).pdf file does not exist."; \
	fi
	
	if [ -f $(graph01).py ]; then \
		echo "$(graph01).py file exists."; \
		rm $(graph01).py; \
	else\
		echo "$(graph01).py file does not exist."; \
	fi
	
	if [ -f $(graph02).pdf ]; then \
		echo "$(graph02).pdf file exists."; \
		rm $(graph02).pdf; \
	else\
		echo "$(graph02).pdf file does not exist."; \
	fi
	
	if [ -f $(graph02).py ]; then \
		echo "$(graph02).py file exists."; \
		rm $(graph02).py; \
	else\
		echo "$(graph02).py file does not exist."; \
	fi
	
	if [ -f $(script).sh ]; then \
		echo "$(script).sh file exists."; \
		rm $(script).sh; \
	else\
		echo "$(script).sh file does not exist."; \
	fi



