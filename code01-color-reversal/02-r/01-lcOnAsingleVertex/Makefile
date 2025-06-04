graph01=graph01-initial
graph02=graph02-afterLocalCom
a=a


kumud01:
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
	./a.out ../input/input1 $(vertex) 
	#python3 graph01-initial.py
	python3 graph01-initial.py 
	python3 graph02-afterLocalCom.py 
	evince graph01-initial.pdf &
	evince graph02-afterLocalCom.pdf &
	
	touch script01-showOutput.sh
	echo "okular graph01-initial.pdf &" >> script01-showOutput.sh
	echo "okular graph02-afterLocalCom.pdf &" >> script01-showOutput.sh
clean:
	if [ -f $(a).out ]; then \
		echo "$(a).out File exists."; \
		rm $(a).out; \
	else\
		echo "$(a).out File does not exist."; \
	fi
	
	if [ -f script01-showOutput.sh ]; then \
		echo "Output viewer File exists."; \
		rm script01-showOutput.sh; \
	else\
		echo "Output viwer file does not exist."; \
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


