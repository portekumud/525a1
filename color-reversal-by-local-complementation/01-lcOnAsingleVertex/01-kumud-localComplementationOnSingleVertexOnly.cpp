#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <string>


using namespace std;

/*
 *	Function prototypes are declared here
 * */

void f01_read_input(vector<vector<int>> &, vector<int> &, char *, int &);
void f02_extractIntegerWords(string str,vector<vector<int>> &);
void f03_local_complementation(vector<vector<int>> &, string, 	vector<vector<int>> &, vector<int>, vector<int> &, vector<int> &);
void f04_drawGraph(vector<vector<int>>, vector<int>, string, string);

/*
 *	Main function
 * */
int main(int argc, char **argv) {
	vector<vector<int>> theGraph;
	vector<int> theBicoloration;
	vector<int> theNewBicoloration;
	vector<vector<int>> myNewGraph;
	vector<int> theNeighborsOfA;
	string a;
	vector<string> setOfAllLexicographicallyStrings;
	int theNumberOfVertices;


	/*
	 * Checking whether the number of arguments is three of not: the first argument is the program name, the second argument is the input file name, and the third argument is an identification for the pivot vertex.
	 * */
	if(argc != 3) {
		cerr << "Mismatch run-time arguments. Read the usage from the Github and try again";
		return 0;
	}
	else {
		/*
		 * Reading the input file, and assigning the required values to appropriate variables
		 */
		f01_read_input(theGraph, theBicoloration, *(argv + 1), theNumberOfVertices);

		/*
		 * a is the pivot vertex which is the 3rd command-line argument
		 */
		a = *(argv + 2);


		/*
		 * The value of a must be greater than or equal to zero and less than or equal to the maximum integer indicating a vertex in the set of vertices
		 */
		if(0 <= stoi(a) && stoi(a) <= theNumberOfVertices - 1) {
			/*
			 * This function computes the local complementation
			 */
			f03_local_complementation(theGraph, a, myNewGraph, theBicoloration, theNeighborsOfA, theNewBicoloration);
		}
		else {
			cerr << "The graph has " << theNumberOfVertices << " vertices. You entered vertex index as " << a << ". It is incorrect vertex index.";
		}
	}
	cout << endl;
	return 0;
}

/*
 * This function reads the input file. The input file is a two-dimensional matrix with (n+1) rows and n columns.
 */
void f01_read_input(vector<vector<int>> &myGraph, vector<int> &myBicoloration, char *theFilename, int &theNumberOfVertices) {
	vector<vector<int>>::iterator p1_myGraph;
	vector<int>::iterator p2;
	vector<int> temp1;
	void *temp2;

	ifstream readFile(theFilename);
	if (readFile.is_open()) {
		string line;

		while (std::getline(readFile, line)) {
			f02_extractIntegerWords(line, myGraph);
		}
		readFile.close();

	} else {
		cerr << "Unable to open file " << theFilename << "." << std::endl;
	}

	/*
	 * p1_myGraph points to the last row of myGraph. p2 points to the first element of p1_myGraph
	 */
	p1_myGraph = myGraph.end() - 1;
	p2 = (*p1_myGraph).begin();

	/*
	 * This while loop iterates over the last row of the input file element-by-element and push each of them to the myBicoloration vector.
	 */
	while(p1_myGraph != myGraph.end()) {
		p2 = (*p1_myGraph).begin();

		while(p2 != (*p1_myGraph).end()) {
			myBicoloration.push_back(*p2);
			p2++;
		}

		p1_myGraph++;
	}

	/*
	 * Come back to the beginning of the last row, delete that row, and draw the graph
	 */
	p1_myGraph  = p1_myGraph - 1;
	myGraph.erase(p1_myGraph, p1_myGraph + 1);
	theNumberOfVertices = myBicoloration.size();
	//cout << "theNumberOfVertices: " << theNumberOfVertices << endl; 
	f04_drawGraph(myGraph, myBicoloration, "01", "initial");

	return;
}

void f02_extractIntegerWords(string str,vector<vector<int>> &v2) {
	stringstream ss;
	vector<int> v1;

	/* Storing the whole string into string stream */
	ss << str;

	/* Running loop till the end of the stream */
	string temp;
	int found;
	v1.clear();

	while (!ss.eof()) {
		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */

		stringstream(temp) >> found;
		//if (stringstream(temp) >> found)
			//cout << ":" << found << " ";
		v1.push_back(found);

		/* To save from space at the end of string */
		temp = "";
	}

	v2.push_back(v1);
	return;
}

void f03_local_complementation(vector<vector<int>> &myGraph, string a11, vector<vector<int>> &myNewGraph, vector<int> theBicoloration, vector<int> &theNeighborsOfA, vector<int> &theNewBicoloration) {
	vector<int>::iterator p1_myGraphSingle;
	vector<vector<int>>::iterator p1_myGraphDouble;
	vector<int>::iterator p2_theNeighborsOfA;
	vector<int>::iterator p3_theNeighborsOfA;
	vector<vector<int>> ::iterator p4_theLCtoDo;
	vector<vector<int>> theLCtoDo;
	vector<vector<int>>::iterator p5_myNewGraph;
	vector<int> temp1, temp2;
	string lastChar;
	int a, i = 0;
	vector<int>::iterator p6_theBicoloration;

	/*
	 * Converting the string to an integer
	 */
	a = stoi(a11);
	p1_myGraphSingle = myGraph[a].begin();

	while(p1_myGraphSingle != myGraph[a].end()) {
		if(*p1_myGraphSingle == 1) {
			theNeighborsOfA.push_back(i);
		}
		p1_myGraphSingle++;
		i++;
	}

	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		for(p3_theNeighborsOfA =theNeighborsOfA.begin(); p3_theNeighborsOfA != theNeighborsOfA.end(); p3_theNeighborsOfA++) {
			if (*p2_theNeighborsOfA < *p3_theNeighborsOfA) {
				temp1.push_back(*p2_theNeighborsOfA);
				temp1.push_back(*p3_theNeighborsOfA);
				theLCtoDo.push_back(temp1);
				temp1.clear();
			}
		}
	}

	for(p1_myGraphDouble = myGraph.begin(); p1_myGraphDouble != myGraph.end(); p1_myGraphDouble++) {
		vector<int> oneRow = *p1_myGraphDouble;
		for(vector<int>::iterator p2_oneRow = (*p1_myGraphDouble).begin(); p2_oneRow != (*p1_myGraphDouble).end(); p2_oneRow++) {
			temp2.push_back(*p2_oneRow);
		}
		myNewGraph.push_back(temp2);
		temp2.clear();
	}

	p6_theBicoloration = theBicoloration.begin();
	while(p6_theBicoloration != theBicoloration.end()) {
		theNewBicoloration.push_back(*p6_theBicoloration);
		p6_theBicoloration++;
	}

	p1_myGraphDouble = myGraph.begin();
	for(p4_theLCtoDo = theLCtoDo.begin(); p4_theLCtoDo != theLCtoDo.end(); p4_theLCtoDo++) {
		if(p1_myGraphDouble[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] == 1) {
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 0;
		}
		else {
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 1;
		}

		if(p1_myGraphDouble[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] == 1) {
			myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 0;
		}
		else {
			myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 1;
		}
	}

	p6_theBicoloration = theNewBicoloration.begin();

	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		if(theNewBicoloration[*p2_theNeighborsOfA] == 1) {
			theNewBicoloration[*p2_theNeighborsOfA] = -1;
		}
		
		else if (theNewBicoloration[*p2_theNeighborsOfA] == -1) {
			theNewBicoloration[*p2_theNeighborsOfA] = 1;
		}
		else {
			cerr << "Wrong code" << endl;
		}
	}

	f04_drawGraph(myNewGraph, theNewBicoloration, "02", "afterLocalCom");
	return;
}

void f04_drawGraph(vector<vector<int>> myGraph, vector<int> myBicoloration, string nameIndex, string nameTitle) {
	vector<vector<int>>::iterator p1_myGraph;
	string name = "graph" + nameIndex + "-" + nameTitle + ".py";
	vector<int>::iterator p2;
	int i = 0, j, k = 0;
	int theNumberOfVertices;
	std::ofstream file(name);
	p1_myGraph = myGraph.begin();

	file << "import networkx as nx" << endl;
	file << "import matplotlib.pyplot as plt" << endl;
	file << "G = nx.Graph() " << endl;
	file << "plt.subplot(211)" << endl;
	file << "G.add_edges_from([";

	while(p1_myGraph != myGraph.end()) {
		p2 = (*p1_myGraph).begin();
		j = 0;
		while(p2 != (*p1_myGraph).end()) {
			//cout << *p2 << " - ";
			if (*p2 == 1) {
				if (k == 0) {
					file << "(" << i << ", " << j << ")";
					k++;
				}
				else {
					file << ", (" << i << ", " << j << ")";
				}
			}
			p2++;
			j++;
		}
		//cout << endl;
		p1_myGraph++;
		i++;
	}

	p2 = myBicoloration.begin();
	//cout << endl << "==================" << endl;
	//cout << endl << "Again size: " << myBicoloration.size() << endl;
	while(p2 != myBicoloration.end()) {
		//cout << *p2 << " *  ";
		p2++;
	}
	//cout << endl << "==================" << endl;

	file << "])";

	if (k == 1) {
		file << endl << "nx.set_node_attributes(G, {";
		theNumberOfVertices = myBicoloration.size();
		for (int t1 = 0; t1 < theNumberOfVertices; t1++) {
			if(t1 == 0) {
				file << t1 << ": \'";
				if(myBicoloration[t1] == 1) {
					file << "yellow";
				}
				else if (myBicoloration[t1] == -1){
					file << "green";
				}
				else {
					cout << endl << "Wrong code";
				}
				file << "\'";
			}
			else {
				file << ", " << t1 << ": \'";
				if(myBicoloration[t1] == 1) {
					file << "yellow";
				}
				else if (myBicoloration[t1] == -1){
					file << "green";
				}
				else {
					cerr << endl << "Wrong code";
				}
				file << "\'";
			}
		}
		file << "}, name=\'color\')";
		file << endl << "nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, \'color\').values()))";
	}

	file << endl << "plt.savefig('graph";
	file << nameIndex;
	file << "-";
	file << nameTitle;
	file << ".pdf')" << endl;
	file.close();

	return;
}

