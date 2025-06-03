runIt:
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
	./a.out ../input/input1
	#python3 graph01-initial.py
	python3 graph01-initial.py 
	python3 graph02-afterLocalCom.py 
	evince graph01-initial.pdf &
	evince graph02-afterLocalCom.pdf &
clean:
	rm a.out
	rm graph01-initial.pdf
	rm graph01-initial.py
	rm graph02-afterLocalCom.pdf
	rm graph02-afterLocalCom.py
