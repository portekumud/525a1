#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <string>


using namespace std;

void f01_read_input(vector<vector<int>> &, vector<int> &, char *, int &);
void f02_extractIntegerWords(string str,vector<vector<int>> &);
void f03_local_complementation(vector<vector<int>> &, string, 	vector<vector<int>> &, vector<int>, vector<int> &, vector<int> &);
void f04_color_reversal();
void f05_showMyGraph(vector<vector<int>> &, vector<int> &myBicoloration);
void f06_drawGraph(vector<vector<int>>, vector<int>, string, string);
void f07_gen_len(int, string &, string &, vector<string> &);
void f08_createLexicograohicalStringsUptoLengthN(vector<string> &, int);





int main(int argc, char **argv) {
	vector<vector<int>> theGraph;
	vector<int> theBicoloration;
	vector<int> theNewBicoloration;
	vector<vector<int>> myNewGraph;
	vector<int> theNeighborsOfA;
	string a;
	vector<string> setOfAllLexicographicallyStrings;
	int theNumberOfVertices;



	f01_read_input(theGraph, theBicoloration, *(argv + 1), theNumberOfVertices);
	std::cout << "theNumberOfVertices: " << theNumberOfVertices << endl;


	/////////////////////////////////////////



	f08_createLexicograohicalStringsUptoLengthN(setOfAllLexicographicallyStrings, theNumberOfVertices);


	//string ALPHABET2 = "01234";
	    /////////////////////////////////

	a = "031";
	f03_local_complementation(theGraph, a, myNewGraph, theBicoloration, theNeighborsOfA, theNewBicoloration);
	//f04_color_reversal();


	//cout << endl << "Test arguments: " << argc << ": " << *(argv + 0) << *(argv + 1);

	return 0;
}

void f01_read_input(vector<vector<int>> &myGraph, vector<int> &myBicoloration, char *theFilename, int &theNumberOfVertices) {
	//cout << endl << "In read input:  " << fileName[1] << endl;
    	//vector<vector<int>> v2;
        //vector<int> v1;
	vector<vector<int>>::iterator p1_myGraph;
	vector<int>::iterator p2;
	vector<int> temp1;
	void *temp2;

	std::ifstream readFile(theFilename);

	//cout << "theFilename: " << theFilename;

	cout << "Hy 2" << endl;

	if (readFile.is_open()) {
		std::string line;

		//v1.clear();

		while (std::getline(readFile, line)) {
			std::cout << line << std::endl;
			//v1.push_back(line);
			//
			f02_extractIntegerWords(line, myGraph);


	//	    v2.push_back({7, 8, 9});

		}
		readFile.close();

	} else {
		std::cerr << "Unable to open file " << theFilename << "." << std::endl;
	}

   	//myBicoloration.push_back(myGraph[myGraph.size() - 1]);
	//
	//
	cout << endl << "The length is: " << myGraph.size() << endl;
	//cout << endl << "The length is: " << myBicoloration.size() << " : ";// << *p1_myGraph;
	//
	//cout << *p1_myGraph[0];


	/*

	p1_myGraph = myGraph.begin();
		//p2 = (*p1_myGraph).begin();
		cout << "Hy 1" << endl;
		//p2 = (*p1_myGraph).begin();
		cout << typeid(p2).name() << endl;
		cout << typeid((*p1_myGraph).begin()).name() << endl;

		while(p1_myGraph != myGraph.end()) {
			cout << "Hy";
			cout << "ok" << (*p1_myGraph)[0] << " : ";
			//temp1 = *p1_myGraph;
			p2 = (*p1_myGraph).begin();

			while(p2 != (*p1_myGraph).end()) {
					cout << "p2: " << *p2 << endl;
					p2++;
					}
			p1_myGraph++;
		}


		*/

//
	p1_myGraph = myGraph.end() - 1;
	p2 = (*p1_myGraph).begin();
	while(p1_myGraph != myGraph.end()) {
				cout << "Hy color" << endl;
				cout << "ok color: " << (*p1_myGraph)[0] << " : ";
				//temp1 = *p1_myGraph;
				p2 = (*p1_myGraph).begin();

				while(p2 != (*p1_myGraph).end()) {
						cout << "p2: " << *p2 << endl;
						myBicoloration.push_back(*p2);
						p2++;
						}
				p1_myGraph++;
	}
	p1_myGraph  = p1_myGraph - 1;

	myGraph.erase(p1_myGraph, p1_myGraph + 1);



	/*for (int i = 0; i < myGraph.size() - 1; ++i) {
		(*p1_myGraph).pop_back();
	}
*/


	cout << endl << "yahoo 1" << endl;
	theNumberOfVertices = myBicoloration.size();
	f05_showMyGraph(myGraph, myBicoloration);
	f06_drawGraph(myGraph, myBicoloration, "01", "initial");




	return;
}

void f02_extractIntegerWords(string str,vector<vector<int>> &v2) {
    stringstream ss;

    vector<int> v1;
	cout << endl << "Yahoo 1" << endl;
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
        if (stringstream(temp) >> found)
            cout << ":" << found << " ";
	v1.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    v2.push_back(v1);
    cout << endl << "Yahoo 2" << endl;

    cout << endl << "printing vector: " << endl;
    for (unsigned int i = 0; i < v2.size(); i++) {
	    for (unsigned int j = 0; j < v2[i].size(); j++) {
		    cout << v2[i][j] << " ";
	    }

	    cout << endl;
    }

        cout << endl << "---------------" << endl;

}

void f03_local_complementation(vector<vector<int>> &myGraph, string a11, vector<vector<int>> &myNewGraph, vector<int> theBicoloration, vector<int> &theNeighborsOfA, vector<int> &theNewBicoloration) {

	//vector<int> theNeighborsOfA;
	vector<int>::iterator p1_myGraphSingle;
	vector<vector<int>>::iterator p1_myGraphDouble;
	vector<int>::iterator p2_theNeighborsOfA;
	vector<int>::iterator p3_theNeighborsOfA;
	vector<vector<int>> ::iterator p4_theLCtoDo;
	vector<vector<int>> theLCtoDo;
	vector<vector<int>>::iterator p5_myNewGraph;
	vector<int> temp1, temp2;
	string lastChar;
	int a;
	vector<int>::iterator p6_theBicoloration;

	lastChar = a11[a11.length() - 1];

	a = stoi(lastChar);

	cout << stoi(lastChar);


	int i = 0;

	cout << endl << "In f02_local_complementation";
	cout << endl << "Print v2 and a" << endl;

	for (unsigned int i = 0; i < myGraph.size(); i++) {
	    for (unsigned int j = 0; j < myGraph[i].size(); j++) {
		    cout << myGraph[i][j] << " ";
	    }

	    cout << endl;
    }


	p1_myGraphSingle = myGraph[a].begin();


	cout << endl << "Value of a: " << a << endl;
	cout << endl << "Neighbors of a: " << endl;

	while(p1_myGraphSingle != myGraph[a].end()) {
		if(*p1_myGraphSingle == 1) {
			cout << "One at: " << i << endl;
			theNeighborsOfA.push_back(i);
		}
		p1_myGraphSingle++;
		i++;
	}

	//for(p2_theNeighborsOfA = theNeighborsOfA.begin(), p3_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(), p3_theNeighborsOfA != theNeighborsOfA; p2_theNeighborsOfA++, p3_theNeighborsOfA++) {
	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		for(p3_theNeighborsOfA =theNeighborsOfA.begin(); p3_theNeighborsOfA != theNeighborsOfA.end(); p3_theNeighborsOfA++) {
			if (*p2_theNeighborsOfA < *p3_theNeighborsOfA) {

		cout << *p2_theNeighborsOfA << " : " << *p3_theNeighborsOfA << endl;
		//theLCtoDo.push_back(__x)
		temp1.push_back(*p2_theNeighborsOfA);
		temp1.push_back(*p3_theNeighborsOfA);
		theLCtoDo.push_back(temp1);
		temp1.clear();
			}
		}
		cout << endl;
	}



for(p1_myGraphDouble = myGraph.begin(); p1_myGraphDouble != myGraph.end(); p1_myGraphDouble++) {
	vector<int> oneRow = *p1_myGraphDouble;
	for(vector<int>::iterator p2_oneRow = (*p1_myGraphDouble).begin(); p2_oneRow != (*p1_myGraphDouble).end(); p2_oneRow++) {
		cout << *p2_oneRow << " ";
		temp2.push_back(*p2_oneRow);

	}
	myNewGraph.push_back(temp2);
	temp2.clear();
	cout << endl << "***" << endl;
}


	p6_theBicoloration = theBicoloration.begin();
	while(p6_theBicoloration != theBicoloration.end()) {
		theNewBicoloration.push_back(*p6_theBicoloration);
		p6_theBicoloration++;
	}

	p1_myGraphDouble = myGraph.begin();
	for(p4_theLCtoDo = theLCtoDo.begin(); p4_theLCtoDo != theLCtoDo.end(); p4_theLCtoDo++) {
		cout << endl  << "---------" << endl << (*p4_theLCtoDo)[0] << " - " << (*p4_theLCtoDo)[1] << endl;


		if(p1_myGraphDouble[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] == 1) {
			cout << ": conected. Change it" << endl;
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 0;
		}
		else {
			cout << ": Not conected. Change it" << endl;
			myNewGraph[(*p4_theLCtoDo)[0]][(*p4_theLCtoDo)[1]] = 1;
				}

		if(p1_myGraphDouble[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] == 1) {
					cout << ": conected. Change it" << endl;
					myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 0;
				}
				else {
					cout << ": Not conected. Change it" << endl;
					myNewGraph[(*p4_theLCtoDo)[1]][(*p4_theLCtoDo)[0]] = 1;
				}
	}





	//kumud start

	//int arr[3];

	//f05_showMyGraph(myGraph, theBicoloration);

	//f05_showMyGraph(myNewGraph, theBicoloration);




	p6_theBicoloration = theNewBicoloration.begin();

	cout << "The new bicoloration before change" << endl;
	while(p6_theBicoloration != theNewBicoloration.end()) {
		cout << *p6_theBicoloration << " ";
		p6_theBicoloration++;
	}


	for(p2_theNeighborsOfA = theNeighborsOfA.begin(); p2_theNeighborsOfA != theNeighborsOfA.end(); p2_theNeighborsOfA++) {
		cout << "Change this only: " << *p2_theNeighborsOfA << endl;

		if(theNewBicoloration[*p2_theNeighborsOfA] == 1) {
			theNewBicoloration[*p2_theNeighborsOfA] = -1;
		}
		else if (theNewBicoloration[*p2_theNeighborsOfA] == -1) {
			theNewBicoloration[*p2_theNeighborsOfA] = 1;

		}
		else {
			cout << "Wrong code" << endl;
		}

	}



	cout << "The new bicoloration after change" << endl;
	p6_theBicoloration = theNewBicoloration.begin();
	while(p6_theBicoloration != theNewBicoloration.end()) {
		cout << *p6_theBicoloration << " ";
		p6_theBicoloration++;
	}


	f06_drawGraph(myNewGraph, theNewBicoloration, "02", "afterLocalCom");




	//kumud end

	return;
}

void f04_color_reversal() {
	cout << endl << "In f03_color_reversal";
	return;
}


void f05_showMyGraph(vector<vector<int>> &myGraph, vector<int> &myBicoloration) {
	vector<vector<int>>::iterator p1_myGraph;
	vector<int>::iterator p2;
	vector<int> temp1;

	cout << "Showing graph" << endl;

	p1_myGraph = myGraph.begin();
	//p2 = (*p1_myGraph).begin();
	cout << "Hy 1" << endl;
	//p2 = (*p1_myGraph).begin();
	cout << typeid(p2).name() << endl;
	cout << typeid((*p1_myGraph).begin()).name() << endl;

	while(p1_myGraph != myGraph.end()) {
		cout << endl << "Hy" << endl;
		cout << "ok" << (*p1_myGraph)[0] << " : ";
		//temp1 = *p1_myGraph;
		p2 = (*p1_myGraph).begin();

		while(p2 != (*p1_myGraph).end()) {
			cout << "p2: " << *p2 << endl;
			p2++;
		}
		p1_myGraph++;
	}

	cout << "Showing color" << endl;

	p2 = myBicoloration.begin();
	while(p2 != myBicoloration.end()) {
		cout << *p2 << " ";
		p2++;
	}
	return;
}

void f06_drawGraph(vector<vector<int>> myGraph, vector<int> myBicoloration, string nameIndex, string nameTitle) {
	vector<vector<int>>::iterator p1_myGraph;
	string name = "graph" + nameIndex + "-" + nameTitle + ".py";
	vector<int>::iterator p2;
	int i = 0, j, k = 0;
	int theNumberOfVertices;
	//ofstream file("graph01-initial.py");


    std::ofstream file(name);



	cout << endl << "In f06_drawGrap. name: " << name;


	p1_myGraph = myGraph.begin();
	//k = myGraph.size();
	//cout << "k is: " << k;

	file << "import networkx as nx" << endl;
	file << "import matplotlib.pyplot as plt" << endl;
	file << "G = nx.Graph() " << endl;
	file << "plt.subplot(211)" << endl;
	file << "G.add_edges_from([";



	while(p1_myGraph != myGraph.end()) {
		cout << endl << "Hy" << endl;
		cout << "ok" << (*p1_myGraph)[0] << " : ";
		//temp1 = *p1_myGraph;
		p2 = (*p1_myGraph).begin();
		j = 0;
		while(p2 != (*p1_myGraph).end()) {
			if (*p2 == 1) {

				if (k == 0) {
					cout << " (one: " << i << ", " << j << " :one) ";
					file << "(" << i << ", " << j << ")";
					k++;
				}
				else {

					cout << " (one: " << i << ", " << j << " :one) ";
					file << ", (" << i << ", " << j << ")";
				}
			}
			cout << "p2: " << *p2 << endl;
			p2++;
			j++;
		}
		p1_myGraph++;
		i++;
	}

		cout << "Showing color" << endl;

		p2 = myBicoloration.begin();
		while(p2 != myBicoloration.end()) {
			cout << *p2 << " ";
			p2++;
		}

		file << "])";

		if (k == 1) {
			file << endl << "nx.set_node_attributes(G, {";
			theNumberOfVertices = myBicoloration.size();
			cout << endl << "theNumberOfVertices: " << theNumberOfVertices << endl;
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
											cout << endl << "Wrong code";
										}
					file << "\'";

				}
			}
			file << "}, name=\'color\')";
			file << endl << "nx.draw(G, with_labels=True, node_color=list(nx.get_node_attributes(G, \'color\').values()))";
		}

//		file << "#This is the graph.";
	//	file << "#This is the graph.";

		//file <<  endl <<"plt.subplot(211)" << endl;
		//file << "nx.draw_networkx(G)" << endl;
		file << endl << "plt.savefig('graph";
		file << nameIndex;
		file << "-";
		file << nameTitle;
		file << ".png')" << endl;

		file.close();

	return;
}


void f07_gen_len(int target_len, string &current, string &ALPHABET, vector<string> &setOfAllLexicographicallyStrings) {
    if (static_cast<int>(current.size()) == target_len) {
        std::cout << current << ' ';
        setOfAllLexicographicallyStrings.push_back(current);
        return;
    }

    for (char c : ALPHABET) {
        current.push_back(c);
       // gen_len(target_len, current, ALPHABET);
        f07_gen_len(target_len, current, ALPHABET, setOfAllLexicographicallyStrings);
      //gen_len(int, string &, string &);

        current.pop_back();   // back-track
    }
    return;
}


void f08_createLexicograohicalStringsUptoLengthN(vector<string> &setOfAllLexicographicallyStrings, int theNumberOfVertices) {
	int n;
	string ALPHABET = "";



	for(int i = 0; i < theNumberOfVertices; i++) {
		//std::cout << i;
		ALPHABET = ALPHABET + to_string(i);
	}

	std::cout << "ALPHABET: " << ALPHABET << endl;



	vector<string>::iterator p1_setOfAllLexicographicallyStrings;

		    std::cout << "Enter maximum length n: ";
		    if (!(std::cin >> n) || n <= 0)
		    	return;

		    std::string current;
		    for (int len = 1; len <= n; ++len) {
		        std::cout << "\nLength " << len << ":\n";
		      f07_gen_len(len, current, ALPHABET, setOfAllLexicographicallyStrings);
		        // void gen_len(int, string &, string &);

		        std::cout << '\n';   // end of this length group
		    }

		    cout << "The setOfAllLexicographicallyStrings: ";
		    p1_setOfAllLexicographicallyStrings = setOfAllLexicographicallyStrings.begin();
		    while(p1_setOfAllLexicographicallyStrings != setOfAllLexicographicallyStrings.end()) {
		    	std::cout << *p1_setOfAllLexicographicallyStrings << " ";
		    	p1_setOfAllLexicographicallyStrings++;

		    }
		    cout << endl;
		    return;

}
